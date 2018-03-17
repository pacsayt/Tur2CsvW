// CEdzDiagram.cpp

#include "stdafx.h"

#include <afxwin.h>

#include <math.h>

#include "resource.h"
#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"
#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"

#include "Tur2CsvWDoc.h"

#include "CDiagram.h"
#include "CEdzDiagram.h"

CString CEdzDiagram::m_aStatParamNevek[] = { "Climb gain     ",
                                             "Max. climb     ",
                                             "Elapsed time" } ;

CEdzDiagram::CEdzDiagram():m_nStatSorTav(2)
{
  m_cSzovMeret = CSize( 0, 0) ;

  m_nKezdKijIdx   = 0 ;
  m_nUtolsoKijIdx = 0 ;
  m_nKijKezdIdo   = 0 ;
  m_nKijVegeIdo   = 0 ;
}

int CEdzDiagram::DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CTur2CsvWDoc* pDoc)
{
  CEdzes* pEdzesek ;
  
  pEdzesek = pDoc->GetEdzesek() ;

  NyuzsoritasBeall( pDoc->GetNyuzsoritasX(), 1.0f) ;
TolIdoBeallit( pDoc->GetTolIdo()) ;
// IgIdoBeallit( pEdzesek) ;
  IgIdoBeallit( pDoc->GetIgIdo()) ;

  ClientRectBeall( cClientRect) ;

  SzovmeretBeall( pDC) ;

  MinMaxBeallit( pEdzesek) ;

  SkalafaktorBeallit() ;
                         //-> tagvaltozoba, melyet SzovmeretBeall() allit, statiszkanak kulon masik
  RacsKirajzol( pDC/*, cClientRect*/, pEdzesek) ;
                            //-> tagvaltozoba, melyet SzovmeretBeall() allit
  EdzesekKirajzol( pDC/*, cClientRect*/, pEdzesek) ;

  return 0 ;
}

void CEdzDiagram::SzovmeretBeall( CDC* pDC/*, CRect cClientRect*/)
{
//  const int nSortavolsag = 2 ;
  int nSzovMagassag = 0 ;

  CRect cStatClientRect ;

  // Mintasztring : egy ertek, max. varhato merettel, mert az idoosztasnal
  // csak a magassag az erdekes
  m_cSzovMeret = pDC->GetTextExtent( "8888", 4) ;

//  pDC->DPtoLP( &m_cSzovMeret) ;

//  pCurrentFont = pDC->GetCurrentFont() ;
  // class CRect : public tagRECT
  // LONG left;
  // LONG top;
  // LONG right;
  // LONG bottom;                           \/ a fejlecnek
  nSzovMagassag = (CTur2CsvWDoc::nMaxEdzSzam+1)*(m_cSzovMeret.cy + m_nStatSorTav) ;

  // Y iranyu osztasok left, top, right, and bottom 
  m_cRacsMeretRect.left   = m_cSzovMeret.cx ;
  m_cRacsMeretRect.top    = 0 ;
  m_cRacsMeretRect.right  = m_cClientRect.Width() ;
  m_cRacsMeretRect.bottom = m_cClientRect.Height() - m_cSzovMeret.cy ;

  // Legyen eleg hely a grafikonnak+statisztikanak : statisztika csak akkor, ha van
  if ( m_cClientRect.Height() > 2*nSzovMagassag )
  {
    m_cStatMeret = m_cClientRect ;
    m_cRacsMeretRect.bottom = m_cClientRect.bottom - nSzovMagassag ;

    m_cStatMeret.top = m_cRacsMeretRect.bottom + m_cSzovMeret.cy ;

    pDC->DPtoLP( &m_cStatMeret) ;
  }
  else
  {
    m_cStatMeret = CRect( 0, 0, 0, 0) ;
  }

	pDC->FillRect( m_cClientRect, &m_cBrush) ;

  m_nCliRectMagassag = m_cClientRect.Height() ;

  // Y iranyu osztasok
//  m_nRacsMagassag  = m_cGrafikaMeret.Height() - m_cSzovMeret.cy ;
//  m_nRacsSzelesseg = m_cGrafikaMeret.Width()  - m_cSzovMeret.cx ;

//TRACE( "CDiagram::SzovmeretBeall() : m_nRacsMagassag=%d, m_nRacsSzelesseg=%d\n", m_nRacsMagassag, m_nRacsSzelesseg) ;
//TRACE( "CDiagram::SzovmeretBeall() : m_fSkalafaktorX=%f, m_fSkalafaktorY=%f\n", m_fSkalafaktorX, m_fSkalafaktorY) ;
}

void CEdzDiagram::MinMaxBeallit( CEdzes* pEdzesek)
{
  int  nIdx = 0 ;
  long nEdzOsszIdo = 0 ;
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
//TRACE( "CEdzDiagram::MinMaxBeallit() : nIdx=%d, MinMagassag=%d, MaxMagassag=%d, MintakSzama=%d\n", nIdx, pEdzesek[nIdx].GetMinMagassag(), pEdzesek[nIdx].GetMaxMagassag(), pEdzesek[nIdx].GetMintakSzama()) ;
      m_nMinErtek = min( m_nMinErtek, pEdzesek[nIdx].GetMinMagassag()) ;
      m_nMaxErtek = max( m_nMaxErtek, pEdzesek[nIdx].GetMaxMagassag()) ;

      nEdzOsszIdo = pEdzesek[nIdx].ElteltIdo( 0, pEdzesek[nIdx].GetMintakSzama()-1) ;

      if ( m_nMaxIdo < nEdzOsszIdo )
      {
        m_nMaxIdo = pEdzesek[nIdx].ElteltIdo( 0, pEdzesek[nIdx].GetMintakSzama()-1) ;
        m_nMaxMintakSzama = pEdzesek[nIdx].GetMintakSzama() ;
      }

//      m_nMaxMintakSzama = max( m_nMaxMintakSzama, pEdzesek[nIdx].GetMintakSzama()) ;
//      m_nMaxIdo   = max( m_nMaxIdo, pEdzesek[nIdx].GetElteltIdo( pEdzesek[nIdx].GetMintakSzama()-1)) ;

      bVanEdzNyitva = TRUE ;
    }
  }

  // Ha nem volt edzes, ne min_short legyen
  if ( bVanEdzNyitva == FALSE )
  {
    m_nMinErtek = 0 ;
    m_nMaxErtek = (short)(m_cRacsMeretRect.bottom - m_cRacsMeretRect.top) ;
    m_nMaxMintakSzama = (short)(m_cRacsMeretRect.right - m_cRacsMeretRect.left) ;
    m_nMaxIdo   = (short)(m_cRacsMeretRect.right - m_cRacsMeretRect.left) ;
  }

  // A kezdeti ertekek beallitasa, ha meg nem volt balra/jobbra gorgetve a diagram
  if ( m_nTolIdo == m_nIgIdo )
  {
    m_nTolIdo = 0 ;
    m_nIgIdo  = m_nMaxIdo ;
  }

//TRACE( "CEdzDiagram::MinMaxBeallit() : m_nMinErtek=%d, m_nMaxErtek=%d, m_nMaxMintakSzama=%d\n", m_nMinErtek, m_nMaxErtek, m_nMaxMintakSzama) ;
}

int CEdzDiagram::EdzesekKirajzol( CDC* pDC/*, CRect cClientRect*/, CEdzes* pEdzesek)
{
//  float fSkalafaktorY = 1.0f ; -> m_f...
//  int   nRacsSzelesseg = 0 ;
  int   nRacsMagassag  = 0 ;
  int   nEdzIdx   = 0 ;
  int   nMintaIdx = 0 ;
  int   nTmpX     = 0 ;
  int   nTmpY     = 0 ;
  int   nTolIdx   = 0 ;
  int   nIdxIg    = 0 ;

  CEdzes* pAktEdz = NULL ;

  CPen* pRegiPen  = NULL ;

  pRegiPen = pDC->SelectObject( &m_cEdzesPen) ;
//  fSkalafaktorY = (float)m_nRacsMagassag/(float)(m_nMaxErtek-m_nMinErtek) ;
//  nRacsSzelesseg = m_cRacsMeretRect.right - m_cRacsMeretRect.left ;
  nRacsMagassag = m_cRacsMeretRect.bottom - m_cRacsMeretRect.top ;

  for ( nEdzIdx = 0 ; nEdzIdx < CTur2CsvWDoc::nMaxEdzSzam ; nEdzIdx++ )
  {
    pAktEdz = pEdzesek+nEdzIdx ;

    if ( pAktEdz != NULL && pAktEdz->Kijelzendo() == TRUE )
    {
      nTolIdx = pAktEdz->IdoBolIdx( m_nTolIdo) ;
      nIdxIg  = pAktEdz->IdoBolIdx( m_nIgIdo) ;

      m_cEdzesPen.CreatePen( PS_SOLID, 1, m_aGorbeSzinek[nEdzIdx]) ; // ASSERTION
      pDC->SelectObject( &m_cEdzesPen) ; // Hatha igy nem marad fekete
      pDC->MoveTo( m_cSzovMeret.cx, (int)(nRacsMagassag-m_fSkalafaktorY*(pAktEdz->GetMagassag( 0)-m_nMinErtek))) ;

// At kene terni idoalapu ciklusra -> /fs -> index
      for ( nMintaIdx = nTolIdx ; nMintaIdx < nIdxIg ; nMintaIdx++ )
      {
        // DPToLP ???
        nTmpX = (int)(m_cSzovMeret.cx+m_fNyuzsX*m_fSkalafaktorX*(pAktEdz->GetElteltIdo( nMintaIdx)-m_nTolIdo)) ;
        nTmpY = (int)(nRacsMagassag-m_fNyuzsY*m_fSkalafaktorY*(pAktEdz->GetMagassag(nMintaIdx)-m_nMinErtek)) ;
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

/*
void CEdzDiagram::KijIdxBeall( const CPoint& cKijelKezd, const CPoint& cKijelUtolso)
{
  int nRacsSzelesseg = 0 ;

  // Az x-ertekek kiszamitasi modja : nTmpX = (int)(m_cSzovMeret.cx+m_fSkalafaktorX*nMintaIdx)
  // Ez mindenkeppen kell az OnDraw nal is a kijeloles kirajzolasahoz
  nRacsSzelesseg = m_cRacsMeretRect.right - m_cRacsMeretRect.left ;

ez az index a legtobb mintat tartalmazo edzesre fog vonatkozni ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
at kell szamolni idore
// m_fSkalafaktorX : diagr.meret/ido 
// l. CEdzDiagram::GetKijMeret()-ban a szamitast
  m_nKezdKijIdx   = (int)(m_nMaxMintakSzama*(cKijelKezd.x - m_cSzovMeret.cx)/m_fNyuzsX/nRacsSzelesseg) ;
  m_nUtolsoKijIdx = (int)(m_nMaxMintakSzama*(cKijelUtolso.x - m_cSzovMeret.cx)/m_fNyuzsX/nRacsSzelesseg) ;
TRACE( "CEdzDiagram::KijIdxBeall() : m_nKezdKijIdx=%d, m_nUtolsoKijIdx=%d\n", m_nKezdKijIdx, m_nUtolsoKijIdx) ;
}
*/

void CEdzDiagram::KijKezdVegeBeall( const CPoint& cKijelKezd, const CPoint& cKijelUtolso)
{
  int  nRacsSzelesseg   = 0 ;
  long nKijIdotartomany = 0 ;
  
  nRacsSzelesseg = m_cRacsMeretRect.right - m_cRacsMeretRect.left ;
  nKijIdotartomany = m_nIgIdo - m_nTolIdo ;

  // A kepernyopontok atszamitasa idove. Statisztika keszitesekor 
  m_nKijKezdIdo = (long)(m_nTolIdo + nKijIdotartomany*(cKijelKezd.x - m_cSzovMeret.cx)/nRacsSzelesseg) ;
  m_nKijVegeIdo = (long)(m_nTolIdo + nKijIdotartomany*(cKijelUtolso.x - m_cSzovMeret.cx)/nRacsSzelesseg) ;

TRACE( "CEdzDiagram::KijKezdVegeBeall() : m_nKijKezdIdo=%d, m_nKijVegeIdo=%d\n", m_nKijKezdIdo, m_nKijVegeIdo) ;
}

int CEdzDiagram::Statisztika( CDC* pDC, CEdzes* pEdzesek)
{
  int nEdzIdx    = 0 ;
  
  int nKezdKijIdx   = 0 ;
  int nUtolsoKijIdx = 0 ;

  short nMagassagnyereseg = 0 ;
  short nMaxEmelkedes     = 0 ;

  long  nElteltIdo = 0 ;

  int nStatParamSzama = sizeof(m_aStatParamNevek)/sizeof(CString) ;
  int aStatParamPoz[sizeof(m_aStatParamNevek)/sizeof(CString)] ;

  CString sStatisztika ;
  CString sStatFejlec  ;
  CSize   cSzovMeret   ;

  if ( pEdzesek == NULL )
  {
TRACE( "CEdzDiagram::Statisztika() : pEdzesek == NULL\n") ;
    return -1 ;
  }

  // Ha a magassag ablak (CTur2CsvWView) 
  if ( m_cStatMeret == CRect( 0, 0, 0, 0) )
  {
TRACE( "CEdzDiagram::Statisztika() : m_cStatMeret == CRect( 0, 0, 0, 0)\n") ;
    return -1 ;
  }

TRACE( "CEdzDiagram::Statisztika() : m_nKezdKijIdx=%d, m_nUtolsoKijIdx=%d\n", m_nKezdKijIdx, m_nUtolsoKijIdx) ;

  // A statisztika kiirasahoz hasznalt szovegstilus beallitasa
  pDC->SetTextAlign( TA_TOP | TA_LEFT) ; // TA_BOTTOM / TA_TOP
  pDC->SetTextColor( m_aGorbeSzinek[0]) ;
  pDC->SetBkMode( TRANSPARENT) ;

  // A fejlec kiirasa
  pDC->FillRect( m_cStatMeret, &m_cBrush) ;

  aStatParamPoz[0] = m_cStatMeret.left+m_cSzovMeret.cx ;
  pDC->TextOut( aStatParamPoz[0], m_cStatMeret.top, m_aStatParamNevek[0]) ;

  for ( nEdzIdx = 1 ; nEdzIdx < nStatParamSzama ; nEdzIdx++ )
  {
    // CSize GetTextExtent( const CString& str ) const;
    cSzovMeret = pDC->GetTextExtent( m_aStatParamNevek[nEdzIdx]) ;
    aStatParamPoz[nEdzIdx] = aStatParamPoz[nEdzIdx-1] + cSzovMeret.cx ;
    pDC->TextOut( aStatParamPoz[nEdzIdx], m_cStatMeret.top, m_aStatParamNevek[nEdzIdx]) ;
  }

//Itt meg mindig (ugyanaz az) index szerint megy : mas Fs-es edzeseknel ez baj

  // Az Y-ertekek visszaszamitasaval nem foglalkozunk
  for ( nEdzIdx = 0 ; nEdzIdx < CTur2CsvWDoc::nMaxEdzSzam ; nEdzIdx++ )
  {
    if ( (pEdzesek+nEdzIdx) != NULL && pEdzesek[nEdzIdx].Kijelzendo() == TRUE )
    {
      nKezdKijIdx   = pEdzesek[nEdzIdx].IdoBolIdx( m_nKijKezdIdo) ;
      nUtolsoKijIdx = pEdzesek[nEdzIdx].IdoBolIdx( m_nKijVegeIdo) ;

      nMagassagnyereseg = pEdzesek[nEdzIdx].Magassagnyereseg( nKezdKijIdx, nUtolsoKijIdx) ;
      nMaxEmelkedes     = pEdzesek[nEdzIdx].MaxEmelkedes(     nKezdKijIdx, nUtolsoKijIdx) ;
      nElteltIdo        = pEdzesek[nEdzIdx].ElteltIdo(        nKezdKijIdx, nUtolsoKijIdx) ;

      pDC->SetTextColor( m_aGorbeSzinek[nEdzIdx]) ;

      sStatisztika.Format( "%d", nMagassagnyereseg) ;
      pDC->TextOut( aStatParamPoz[0], m_cStatMeret.top+(nEdzIdx+1)*(m_cSzovMeret.cy+m_nStatSorTav), sStatisztika) ;
TRACE( "CEdzDiagram::Statisztika() : nMagassagnyereseg=%s ", (const char*)sStatisztika) ;
      sStatisztika.Format( "%d", nMaxEmelkedes) ;
      pDC->TextOut( aStatParamPoz[1], m_cStatMeret.top+(nEdzIdx+1)*(m_cSzovMeret.cy+m_nStatSorTav), sStatisztika) ;
TRACE( "CEdzDiagram::Statisztika() : nMaxEmelkedes=%s ", (const char*)sStatisztika) ;
      sStatisztika.Format( "%d", nElteltIdo) ;
      pDC->TextOut( aStatParamPoz[2], m_cStatMeret.top+(nEdzIdx+1)*(m_cSzovMeret.cy+m_nStatSorTav), sStatisztika) ;
TRACE( "CEdzDiagram::Statisztika() : nElteltIdo=%s\n", (const char*)sStatisztika) ;
    }
  }

  return 0 ;
}
/*
CRect CEdzDiagram::GetKijMeret()
{
  int nRacsSzelesseg = 0 ;

  nRacsSzelesseg = m_cRacsMeretRect.right - m_cRacsMeretRect.left ;

  // Az x-ertekek kiszamitasi modja : nTmpX = (int)(m_cSzovMeret.cx+m_fSkalafaktorX*nMintaIdx)
//  m_nKezdKijIdx   = (int)(m_nMaxMintakSzama*(cKijelKezd.x - m_cSzovMeret.cx)/nRacsSzelesseg) ;
//  m_nUtolsoKijIdx = (int)(m_nMaxMintakSzama*(cKijelUtolso.x - m_cSzovMeret.cx)/nRacsSzelesseg) ;
TRACE( "CEdzDiagram::GetKijMeret() : nRacsSzelesseg=%d m_nMaxMintakSzama=%d\n", nRacsSzelesseg, m_nMaxMintakSzama) ;
TRACE( "CEdzDiagram::GetKijMeret() : m_nKezdKijIdx=%d m_nUtolsoKijIdx=%d\n", m_nKezdKijIdx, m_nUtolsoKijIdx) ;
TRACE( "CEdzDiagram::GetKijMeret() : m_cRacsMeretRect.top=%d m_cRacsMeretRect.bottom=%d\n", m_cRacsMeretRect.top, m_cRacsMeretRect.bottom) ;

// L. hasonlo szamitas : CEdzDiagram::KijIdxBeall()
  return CRect(   (int)((m_nKezdKijIdx*nRacsSzelesseg*m_fNyuzsX)/m_nMaxMintakSzama+m_cSzovMeret.cx),
                                                                        m_cRacsMeretRect.top,
                (int)((m_nUtolsoKijIdx*nRacsSzelesseg*m_fNyuzsX)/m_nMaxMintakSzama+m_cSzovMeret.cx),
                                                                     m_cRacsMeretRect.bottom) ;
}
*/

CRect CEdzDiagram::GetKijMeret()
{
  int nKijIdotartomany = 0 ;
  int nRacsSzelesseg   = 0 ;


  nRacsSzelesseg   = m_cRacsMeretRect.right - m_cRacsMeretRect.left ;
  nKijIdotartomany = m_nIgIdo - m_nTolIdo ;

  // Az x-ertekek kiszamitasi modja : nTmpX = (int)(m_cSzovMeret.cx+m_fSkalafaktorX*nMintaIdx)
TRACE( "CEdzDiagram::GetKijMeret() : nRacsSzelesseg=%d m_nTolIdo=%d m_nIgIdo=%d\n", nRacsSzelesseg, m_nTolIdo, m_nIgIdo) ;
TRACE( "CEdzDiagram::GetKijMeret() : m_nKijKezdIdo=%d m_nKijVegeIdo=%d\n", m_nKijKezdIdo, m_nKijVegeIdo) ;
TRACE( "CEdzDiagram::GetKijMeret() : m_cRacsMeretRect.top=%d m_cRacsMeretRect.bottom=%d\n", m_cRacsMeretRect.top, m_cRacsMeretRect.bottom) ;

// L. hasonlo szamitas : CEdzDiagram::KijIdxBeall()
  return CRect(   (int)(m_cSzovMeret.cx+(m_nKijKezdIdo-m_nTolIdo)*nRacsSzelesseg/nKijIdotartomany),
                                                                           m_cRacsMeretRect.top,
                  (int)(m_cSzovMeret.cx+(m_nKijVegeIdo-m_nTolIdo)*nRacsSzelesseg/nKijIdotartomany),
                                                                        m_cRacsMeretRect.bottom) ;
}

CEdzDiagram::~CEdzDiagram()
{
}