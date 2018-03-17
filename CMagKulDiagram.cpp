// CMagKulDiagram.cpp

#include "stdafx.h"

#include <math.h>

#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"
#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"

#include "Tur2CsvWDoc.h"

#include "CDiagram.h"

#include "CMagKulDiagram.h"

CMagKulDiagram::CMagKulDiagram()
{
}

int CMagKulDiagram::DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CTur2CsvWDoc* pDoc)
{
  CEdzes* pEdzesek = NULL ;

  pEdzesek = pDoc->GetEdzesek() ;

  NyuzsoritasBeall( pDoc->GetNyuzsoritasX(), 1.0f) ;
TolIdoBeallit( pDoc->GetTolIdo()) ;
//IgIdoBeallit( pEdzesek) ;
  IgIdoBeallit( pDoc->GetIgIdo()) ;


  ClientRectBeall( cClientRect) ;

  SzovmeretBeall( pDC) ;

  MinMaxBeallit( pEdzesek) ; // A SzovmeretBeall() min max-ot hasznal

  SkalafaktorBeallit() ;

  RacsKirajzol( pDC/*, cClientRect*/, pEdzesek) ;

  MagKulKirajzol( pDC/*, cClientRect*/, pEdzesek) ;

  return 0 ;
}

void CMagKulDiagram::MinMaxBeallit( CEdzes* pEdzesek)
{
  int nIdx = 0 ;
  BOOLEAN bVanEdzNyitva = FALSE ;

  m_nMinErtek = CEdzes::m_nMaxShort ;
  m_nMaxErtek = CEdzes::m_nMinShort ;
  m_nMaxMintakSzama = 0 ;
  m_nMaxIdo = 0 ;

  // A skalazashoz szukseges maximumok es minimumok
  for ( nIdx = 0 ; nIdx < CTur2CsvWDoc::nMaxEdzSzam ; nIdx++ )
  {
    if ( pEdzesek[nIdx].Kijelzendo() == TRUE )
    {
      m_nMinErtek    = min(    m_nMinErtek, pEdzesek[nIdx].GetNormMinMagassagKul()) ;
      m_nMaxErtek    = max(    m_nMaxErtek, pEdzesek[nIdx].GetNormMaxMagassagKul()) ;
      m_nMaxMintakSzama = max( m_nMaxMintakSzama, pEdzesek[nIdx].GetMintakSzama()) ;
//TRACE( "CMagKulDiagram::MinMaxBeallit() : nIdx=%d, MinNormMagassagKul=%d, MaxNormMagassagKul=%d, MintakSzama=%d\n", nIdx, m_nMinErtek, m_nMaxErtek, m_nMaxMintakSzama) ;
      m_nMaxIdo = max( m_nMaxIdo, pEdzesek[nIdx].GetElteltIdo( pEdzesek[nIdx].GetMintakSzama())) ;
      bVanEdzNyitva = TRUE ;
    }
  }

  // Ha nem volt edzes, ne min_short legyen
  if ( bVanEdzNyitva == FALSE )
  {
    m_nMinErtek    = 0 ;
    m_nMaxErtek    = (short)(m_cRacsMeretRect.bottom-m_cRacsMeretRect.top) ; // m_nRacsMagassag
    m_nMaxMintakSzama = (short)(m_cRacsMeretRect.right-m_cRacsMeretRect.left) ; // m_nRacsSzelesseg ;
    m_nMaxIdo = m_cRacsMeretRect.right-m_cRacsMeretRect.left ; // m_nRacsSzelesseg ;
  }

  // A kezdeti ertekek beallitasa, ha meg nem volt balra/jobbra gorgetve a diagram
  if ( m_nTolIdo == m_nIgIdo )
  {
    m_nTolIdo = 0 ;
    m_nIgIdo  = m_nMaxIdo ;
  }

//TRACE( "CMagKulDiagram::MinMaxBeallit() : m_nMinErtek=%d, m_nMaxErtek=%d, m_nMaxMintakSzama=%d\n", m_nMinErtek, m_nMaxErtek, m_nMaxMintakSzama) ;
}

int CMagKulDiagram::MagKulKirajzol( CDC* pDC/*, CRect cClientRect*/, CEdzes* pEdzesek)
{
//  float fSkalafaktorY = 1.0f ; -> m_f...
  int nRacsMagassag  = 0 ;
  int nEdzIdx   = 0 ;
  int nMintaIdx = 0 ;
  int nTmpX     = 0 ;
  int nTmpY     = 0 ;
  int nTolIdx   = 0 ;
  int nIdxIg    = 0 ;

  CEdzes* pAktEdz = NULL ;

  CPen* pRegiPen  = NULL ;

  pRegiPen = pDC->SelectObject( &m_cEdzesPen) ;
//  fSkalafaktorY = (float)m_nRacsMagassag/(float)(m_nMaxErtek-m_nMinErtek) ;
//TRACE( "CMagKulDiagram::MagKulKirajzol() : m_fSkalafaktorY=%f\n", m_fSkalafaktorY) ;

  nRacsMagassag = (short)(m_cRacsMeretRect.bottom-m_cRacsMeretRect.top) ;

  for ( nEdzIdx = 0 ; nEdzIdx < CTur2CsvWDoc::nMaxEdzSzam ; nEdzIdx++ )
  {
    pAktEdz = pEdzesek+nEdzIdx ;

    if ( pAktEdz != NULL && pEdzesek[nEdzIdx].Kijelzendo() == TRUE )
    {
      nTolIdx = pAktEdz->IdoBolIdx( m_nTolIdo) ;
      nIdxIg  = pAktEdz->IdoBolIdx( m_nIgIdo) ;

      m_cEdzesPen.CreatePen( PS_SOLID, 1, m_aGorbeSzinek[nEdzIdx]) ; // ASSERTION
      pDC->SelectObject( &m_cEdzesPen) ; // Hatha igy nem marad fekete
      pDC->MoveTo( m_cSzovMeret.cx, (int)(nRacsMagassag-m_fSkalafaktorY*(pAktEdz->GetNormMagassagKul( 0)-m_nMinErtek))) ;

      for ( nMintaIdx = nTolIdx ; nMintaIdx < nIdxIg ; nMintaIdx++ )
      {
        // DPToLP
        nTmpX = (int)(m_cSzovMeret.cx+m_fNyuzsX*m_fSkalafaktorX*(pAktEdz->GetElteltIdo( nMintaIdx)-m_nTolIdo)) ;
        nTmpY = (int)(nRacsMagassag-m_fNyuzsY*m_fSkalafaktorY*(pAktEdz->GetNormMagassagKul(nMintaIdx)-m_nMinErtek)) ;
        pDC->LineTo( nTmpX, nTmpY) ;
        pDC->MoveTo( nTmpX, nTmpY) ;
      }

      pDC->SelectObject( pRegiPen) ;
      m_cEdzesPen.DeleteObject() ;
    }
  }

  pDC->SelectObject( pRegiPen) ;
  m_cEdzesPen.DeleteObject() ;

  return 0 ;
}

CMagKulDiagram::~CMagKulDiagram()
{
}
