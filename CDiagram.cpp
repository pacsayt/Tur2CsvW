// CDiagram.cpp
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

// static const CDiagram::m_dLOG10 = Math.log( 10.0) ;
//double pow( double x, double y );
//double log( double x );
//double log10( double x );

CDiagram::CDiagram()
{
  m_cClientRect = CRect( 0, 0, 0, 0) ;

  m_nHatterSzin = RGB( 0, 0, 0)     ;
  m_nRacsSzin   = RGB( 45, 140, 85) ;

  // Sajnos nem tudok jobbat :
  m_aGorbeSzinek[0] = RGB( 255,   0,   0) ;
  m_aGorbeSzinek[1] = RGB(  20, 255,  20) ;
  m_aGorbeSzinek[2] = RGB(  20,  20, 255) ;
  m_aGorbeSzinek[3] = RGB( 220, 220,  40) ;
  m_aGorbeSzinek[4] = RGB( 255,  90, 180) ;

  m_fNyuzsX = 1.0f ;
  m_fNyuzsY = 1.0f ;

  m_fSkalafaktorX = 1.0f ;
  m_fSkalafaktorY = 1.0f ;

//  m_nRacsMagassag  = 0 ;
//  m_nRacsSzelesseg = 0 ;
//  m_nCliRectMagassag = 0 ;
  m_cRacsMeretRect = CRect( 0, 0, 0, 0) ;

  m_nMinErtek = CEdzes::m_nMaxShort ;
  m_nMaxErtek = CEdzes::m_nMinShort ;
  m_nMaxMintakSzama = 0 ;
  m_nMaxIdo = 0 ;

  m_nTolIdo = 0 ;
  m_nIgIdo  = 0 ;

  // BOOL
  m_cBrush.CreateSolidBrush( m_nHatterSzin) ;
  m_cRacsPen.CreatePen( PS_SOLID, 1, m_nRacsSzin) ;
  m_cEdzesPen.CreatePen( PS_SOLID, 1, m_aGorbeSzinek[0]) ;

  m_cSzovMeret = CSize( 0, 0) ;

//  m_cGrafikaMeret = CRect( 0, 0, 0, 0) ;
}
/* ???
int CDiagram::RacsMeretBeall( int nBalFelsoX, int nBalFelsoY, int nJobbAlsoX, int nJobbAlsoY)
{
  m_cRacsMeret = CRect( nBalFelsoX, nBalFelsoY, nJobbAlsoX, nJobbAlsoY) ;

  return 0 ;
}
*/
void CDiagram::ClientRectBeall( const CRect& cClientRect)
{ 
  m_cClientRect   = cClientRect ;
//      m_cGrafikaMeret = cClientRect ;
}

void CDiagram::NyuzsoritasBeall( float fNyuzsX, float fNyuzsY)
{
  m_fNyuzsX = fNyuzsX ;
  m_fNyuzsY = fNyuzsY ;
}


void CDiagram::SzovmeretBeall( CDC* pDC/*, CRect cClientRect*/)
{
//  CFont* pCurrentFont = NULL ;
//  m_cClientRect = cClientRect ;

  // Mintasztring : egy ertek, max. varhato merettel, mert az idoosztasnal
  // csak a magassag az erdekes
  m_cSzovMeret = pDC->GetTextExtent( "8888", 4) ;
  pDC->DPtoLP( &m_cSzovMeret) ;

//  pCurrentFont = pDC->GetCurrentFont() ;

  pDC->DPtoLP( &m_cClientRect) ;

	pDC->FillRect( m_cClientRect, &m_cBrush) ;

  m_nCliRectMagassag = m_cClientRect.Height() ;

  // Y iranyu osztasok left, top, right, and bottom 
  m_cRacsMeretRect.left   = m_cSzovMeret.cx ;
  m_cRacsMeretRect.top    = 0 ;
  m_cRacsMeretRect.right  = m_cClientRect.Width() ;
  m_cRacsMeretRect.bottom = m_cClientRect.Height() - m_cSzovMeret.cy ;

//  m_nRacsMagassag  = m_cClientRect.Height() - m_cSzovMeret.cy ;
//  m_nRacsSzelesseg = m_cClientRect.Width() - m_cSzovMeret.cx ;

//  m_fSkalafaktorX = (float)m_nRacsSzelesseg / (float)m_nMaxMintakSzama ;
////  m_fSkalafaktorY = (float)m_nRacsMagassag / (float)m_nMaxErtek ;
//  m_fSkalafaktorY = (float)m_nRacsMagassag / (float)(m_nMaxErtek-m_nMinErtek) ;
//TRACE( "CDiagram::SzovmeretBeall() : m_nRacsMagassag=%d, m_nRacsSzelesseg=%d\n", m_nRacsMagassag, m_nRacsSzelesseg) ;
//TRACE( "CDiagram::SzovmeretBeall() : m_fSkalafaktorX=%f, m_fSkalafaktorY=%f\n", m_fSkalafaktorX, m_fSkalafaktorY) ;
}

void CDiagram::MinMaxBeallit( CEdzes* pEdzesek)
{
}

void CDiagram::SkalafaktorBeallit()
{
//  m_fSkalafaktorX = (float)m_nRacsSzelesseg / (float)m_nMaxMintakSzama ;
  m_fSkalafaktorX = (float)(m_cRacsMeretRect.right-m_cRacsMeretRect.left) / (float)m_nMaxIdo ;
  m_fSkalafaktorY = (float)(m_cRacsMeretRect.bottom-m_cRacsMeretRect.top) / (float)(m_nMaxErtek-m_nMinErtek) ;
//TRACE( "CDiagram::SkalafaktorBeallit() : m_nMaxIdo=%d, m_fSkalafaktorY=%f\n", m_nMaxIdo, m_fSkalafaktorY) ;
TRACE( "CDiagram::SkalafaktorBeallit() : m_nMaxIdo=%d, m_cRacsMeretRect x=%d\n", m_nMaxIdo, m_cRacsMeretRect.right-m_cRacsMeretRect.left) ;
TRACE( "CDiagram::SkalafaktorBeallit() : m_fSkalafaktorX=%f, m_fSkalafaktorY=%f\n\n", m_fSkalafaktorX, m_fSkalafaktorY) ;
}

// A nyuzsoritas eltolas kimarad, mert ugyis a leszarmaztatott osztalyok futnak
int CDiagram::DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CEdzes* pEdzesek)
{
  int  nIdx = 0 ;
  long nEdzOsszIdo = 0 ;
  BOOLEAN bVanEdzNyitva = FALSE ;

  // Hulyeseg : m_cClientRect-vel allitja m_cClientRect-t !
  SzovmeretBeall( pDC/*, m_cClientRect*/) ;

  m_nMinErtek    = (short)(m_cRacsMeretRect.bottom-m_cRacsMeretRect.top) ; // 0 ;
  m_nMaxErtek    = CEdzes::m_nMinShort ; // m_nRacsMagassag ;
  m_nMaxMintakSzama = 0 ; // m_nRacsSzelesseg ;
  m_nMaxIdo = 0 ;

  // A skalazashoz szukseges maximumok es minimumok
  for ( nIdx = 0 ; nIdx < CTur2CsvWDoc::nMaxEdzSzam ; nIdx++ )
  {
    if ( pEdzesek[nIdx].Kijelzendo() == TRUE )
    {
//TRACE( "CDiagram::DiagramKirjzol() : nIdx=%d, MinMagassag=%d, MaxMagassag=%d, MintakSzama=%d\n", nIdx, pEdzesek[nIdx].GetMinMagassag(), pEdzesek[nIdx].GetMaxMagassag(), pEdzesek[nIdx].GetMintakSzama()) ;
      m_nMinErtek = min( m_nMinErtek, pEdzesek[nIdx].GetMinMagassag()) ;
      m_nMaxErtek = max( m_nMaxErtek, pEdzesek[nIdx].GetMaxMagassag()) ;

      nEdzOsszIdo = pEdzesek[nIdx].ElteltIdo( 0, pEdzesek[nIdx].GetMintakSzama()-1) ;
      if ( m_nMaxIdo < nEdzOsszIdo )
      {
        m_nMaxIdo = nEdzOsszIdo ;
        m_nMaxMintakSzama = pEdzesek[nIdx].GetMintakSzama() ;
      }

      bVanEdzNyitva = TRUE ;
    }
  }

  // Ha nem volt edzes, ne min_short legyen
  if ( bVanEdzNyitva == FALSE )
  {
    m_nMinErtek = 0 ;
    m_nMaxErtek = (short)(m_cRacsMeretRect.bottom - m_cRacsMeretRect.top) ; //m_nRacsMagassag ;
    m_nMaxMintakSzama = (short)(m_cRacsMeretRect.right - m_cRacsMeretRect.left) ; //m_nRacsSzelesseg ;
    m_nMaxIdo   = (short)(m_cRacsMeretRect.right - m_cRacsMeretRect.left) ; //m_nRacsSzelesseg ;
  }

//TRACE( "CDiagram::DiagramKirjzol() : m_nMinErtek=%d, m_nMaxErtek=%d, m_nMaxMintakSzama=%d\n", m_nMinErtek, m_nMaxErtek, m_nMaxMintakSzama) ;
  RacsKirajzol( pDC/*, cClientRect*/, pEdzesek) ;

//  EdzesekKirajzol( pDC, cClientRect, pEdzesek) ;

  return 0 ;
}

void CDiagram::TolIdoBeallit( long nUjTolIdo)
{
  m_nTolIdo = nUjTolIdo ;
}

void CDiagram::IgIdoBeallit( long nUjIgIdo)
{
  m_nIgIdo = nUjIgIdo ;
}

/*
void CDiagram::IgIdoBeallit( CEdzes* pEdzesek)
{
  int nIdx = 0 ;

//  m_nTolIdo = 0 ;
  m_nIgIdo  = 0 ;

  for ( nIdx = 0 ; nIdx < CTur2CsvWDoc::nMaxEdzSzam ; nIdx++ )
  {
    if ( pEdzesek[nIdx].Kijelzendo() == TRUE )
    {
//TRACE( "CDiagram::TolIgIdoBeallit() : nIdx=%d, MinMagassag=%d, MaxMagassag=%d, MintakSzama=%d\n", nIdx, pEdzesek[nIdx].GetMinMagassag(), pEdzesek[nIdx].GetMaxMagassag(), pEdzesek[nIdx].GetMintakSzama()) ;
      m_nIgIdo = max( m_nIgIdo, pEdzesek[nIdx].ElteltIdo( 0, pEdzesek[nIdx].GetMintakSzama()-1)) ;
    }
  }
}
*/

int CDiagram::RacsKirajzol( CDC* pDC,/* CRect cClientRect,*/ CEdzes* pEdzesek)
{
  float fSzelessegKm = 0.0f ;
  long nKmOsztas = 0 ;
  long nKm = 0 ;

  long nBalFelsoKm = 0 ;

  int nBalFelsoX = 0 ;
  int nBalFelsoY = 0 ;

  int nOsztasY = 0 ;
  int nAktErt  = 0 ;
  int nX       = 0 ;
  int nAktY    = 0 ;
  int nAktY0   = 0 ;

  int nElsoRacsX = 0 ;
  int nSorTav    = 0 ;
  int nOszlopTav = 0 ;

  char pszSzoveg[256] ;

  CPen*  pRegiPen     = NULL ;

  pszSzoveg[0] = '\0' ;

//  pDC->DPtoLP( &m_cClientRect) ; // ??? kell-e ez minden fv elejen (osszesen tobbszor is) ?
  pDC->FillRect( m_cClientRect, &m_cBrush) ;

//TRACE( "CDiagram::RacsKirajzol() nOsztasY=%d", nOsztasY) ;
//TRACE( "CDiagram::RacsKirajzol() nRacsMagassag=%d",  nRacsMagassag) ;
  // m_nMaxErtek DiagramKirjzol()-ban beallitva
  nAktY = m_nMaxErtek-m_nMinErtek ; // A JAVA-s programban a max. HR volt
  nOsztasY = (int)Osztas( (float)(m_nMaxErtek-m_nMinErtek), 4, 12) ;

  nSorTav = (int)(m_fSkalafaktorY*nOsztasY) ;

//TRACE( "CDiagram::RacsKirajzol() nSorTav=%d", nSorTav) ;
  
  pRegiPen = pDC->SelectObject( &m_cRacsPen) ;

  // Sorracsok kirajzolasa --------------------------------------------
  //                                 + ???
  for ( nAktY=m_cRacsMeretRect.bottom, nAktErt=m_nMinErtek, nBalFelsoX=m_cSzovMeret.cx ;
        nAktY > m_cRacsMeretRect.top /*nBalFelsoY*/;
        nAktY-=nSorTav, nAktErt+=nOsztasY )
  {
//BOOL Polyline( LPPOINT lpPoints, int nCount ) ; egesz tombnyi pontot rajzol ki egyszerre
    pDC->MoveTo( nBalFelsoX, nAktY) ;
    pDC->LineTo( m_cRacsMeretRect.right, nAktY) ;

    // A pulzusosztas skalazasanak kiirasa
    pDC->SetTextAlign( TA_BASELINE | TA_RIGHT) ; // TA_BOTTOM / TA_TOP
    pDC->SetTextColor( m_aGorbeSzinek[0]) ;
    pDC->SetBkMode( TRANSPARENT) ;

    sprintf( pszSzoveg, "%d", nAktErt) ;

    pDC->TextOut( nBalFelsoX, nAktY, pszSzoveg) ;
  }

  // A racs tetejenek kirajzolasa -------------------------------------
  pDC->MoveTo( m_cSzovMeret.cx, nBalFelsoY) ;
  pDC->LineTo( m_cRacsMeretRect.right/*m_cSzovMeret.cx+m_nRacsSzelesseg*/, nBalFelsoY) ;
  
  // X iranyu osztasok
  // Ha nincsenek adatok, valamit kezdetnek...
//  m_nRacsSzelesseg   = m_cClientRect.Width() - m_cSzovMeret.cx ;
  // fSzelessegKm = m_nMaxIdo ;
//TRACE( "CDiagram::RacsKirajzol() m_fNyuzsX=%f\n", m_fNyuzsX) ;
//TRACE( "CDiagram::RacsKirajzol() m_nTolIdo=%d, m_nIgIdo=%d\n", m_nTolIdo, m_nIgIdo) ;

  fSzelessegKm = (m_nIgIdo-m_nTolIdo)/m_fNyuzsX ; // ??? /m_fNyuzsX -> CTur2CsvWDoc::OnMoveZoomShrink/Stretch()

  nBalFelsoKm = m_nTolIdo ;

  //szelesseg, tenyl. kilometer \/ = szelesseg pontban
  nKmOsztas = (long)Osztas( fSzelessegKm, 4, 20) ; // long Osztas() ???

  nOszlopTav = (int)(m_fSkalafaktorX*m_fNyuzsX*nKmOsztas) ; // ??? m_fNyuzsX*
//TRACE( "CDiagram::RacsKirajzol() fSzelessegKm=%f, nKmOsztas=%d\n", fSzelessegKm, nKmOsztas) ;
//TRACE( "CDiagram::RacsKirajzol() nOszlopTav=%d\n", nOszlopTav) ;

  nX    = nBalFelsoX ;
  nAktY = m_cClientRect.Height() ;
//TRACE( "CDiagram::RacsKirajzol() fKm=%f\n", fKm) ;

  // Hova keruljon az elso osztas
  nElsoRacsX = nOszlopTav - (int)(m_fSkalafaktorX*m_fNyuzsX*nBalFelsoKm)%nOszlopTav ;
//TRACE( "CDiagram::RacsKirajzol() nElsoRacsX=%d\n", nElsoRacsX) ;

  nKm = m_nTolIdo ;

  // A bal szelso oszlopracs kirajzolasa --------------------------------
  // nBalFelsoX=cSzovMeret.cx a sorracsok kirajzolasanal : +cSzovMeret.cx torolve
  pDC->MoveTo( nBalFelsoX, nBalFelsoY) ;
  pDC->LineTo( nBalFelsoX, m_cRacsMeretRect.bottom/*nBalFelsoY+m_nRacsMagassag*/) ;

  pDC->SetTextAlign( TA_BASELINE | TA_LEFT) ;
  pDC->SetTextColor( m_aGorbeSzinek[0]) ;
  pDC->SetBkMode( TRANSPARENT) ;

  sprintf( pszSzoveg, "%d", nKm) ;

  pDC->TextOut( nX, m_cRacsMeretRect.bottom+m_cSzovMeret.cy, pszSzoveg) ;

//TRACE( "CDiagram::RacsKirajzol() Oszlopracsok kirajzolasa nX=%d->m_cRacsMeretRect.right=%d, nOszlopTav=%d\n",
//       nX, m_cRacsMeretRect.right, nOszlopTav) ;

  // Oszlopracsok kirajzolasa -------------------------------------------
  // 
  for ( nX=nBalFelsoX+nElsoRacsX,nKm=(m_nTolIdo/nKmOsztas+1)*nKmOsztas ;
        nX<m_cRacsMeretRect.right ;
        nX+=nOszlopTav,nKm+=nKmOsztas )
  {
    pDC->MoveTo( nX, nBalFelsoY) ;
    pDC->LineTo( nX, m_cRacsMeretRect.bottom) ;

    pDC->SetTextAlign( TA_BASELINE | TA_LEFT) ;
    pDC->SetTextColor( m_aGorbeSzinek[0]) ;
    pDC->SetBkMode( TRANSPARENT) ;

    sprintf( pszSzoveg, "%d", nKm) ;

    pDC->TextOut( nX, m_cRacsMeretRect.bottom+m_cSzovMeret.cy, pszSzoveg) ;
//TRACE( "GrafRacsKirajzol(): fKm=" + Float.toString( fKm)) ;
  }

  // A racs jobb oldalanak kirajzolasa ----------------------------------
  pDC->MoveTo( m_cRacsMeretRect.right/*m_nRacsSzelesseg+nBalFelsoX*/-1, m_cRacsMeretRect.top/*nBalFelsoY*/) ;
  pDC->LineTo( m_cRacsMeretRect.right/*m_nRacsSzelesseg+nBalFelsoX-1*/, m_cRacsMeretRect.bottom/*nBalFelsoY+m_nRacsMagassag*/) ;

  pDC->SelectObject( pRegiPen) ;

//TRACE( "CDiagram::RacsKirajzol() : Vege\n\n") ;

  return 0 ;
}

/*
int CDiagram::EdzesekKirajzol( CDC* pDC, CEdzes* pEdzesek)
int CDiagram::EdzesekKirajzol( CDC* pDC, CRect cClientRect, CEdzes* pEdzesek)
{
  float fSkalafaktorY = 1.0f ;

  int   nEdzIdx   = 0 ;
  int   nMintaIdx = 0 ;
  int   nTmpX     = 0 ;
  int   nTmpY     = 0 ;

  CPen* pRegiPen  = NULL ;

  pRegiPen = pDC->SelectObject( &m_cEdzesPen) ;
  fSkalafaktorY = (float)m_nRacsMagassag/(float)(m_nMaxErtek-m_nMinErtek) ;

  for ( nEdzIdx = 0 ; nEdzIdx < CTur2CsvWDoc::nMaxEdzSzam ; nEdzIdx++ )
  {
    if ( pEdzesek[nEdzIdx].Kijelzendo() == TRUE )
    {
      m_cEdzesPen.CreatePen( PS_SOLID, 1, m_aGorbeSzinek[nEdzIdx]) ; // ASSERTION
      pDC->SelectObject( &m_cEdzesPen) ; // Hatha igy nem marad fekete
      pDC->MoveTo( m_cSzovMeret.cx, (int)(m_nRacsMagassag-m_fSkalafaktorY*(pEdzesek[nEdzIdx].GetMagassag( 0)-m_nMinErtek))) ;

      for ( nMintaIdx = 1 ; nMintaIdx < m_nMaxMintakSzama && pEdzesek[nEdzIdx].GetMintakSzama ; nMintaIdx++ )
      {
        // DPToLP
        nTmpX = (int)(m_cSzovMeret.cx+m_fSkalafaktorX*nMintaIdx) ;
        nTmpY = (int)(m_nRacsMagassag-m_fSkalafaktorY*(pEdzesek[nEdzIdx].GetMagassag(nMintaIdx)-m_nMinErtek)) ;
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
*/

// Minimalis erteknel 0 van feltetelezve 
// A nOsztSzamaMax/nOsztSzamaMin > fOsztasok[1], mert kulonben nem fog megfelelo
// osztast talalni
float CDiagram::Osztas( float fMaxErtek, int nOsztSzamaMin, int nOsztSzamaMax)
{
  int nIdx = 0 ;
  int nNagysagrend = 0 ;
  int nOsztSzama   = 0 ;
  int nOsztasokMer = 0 ;
  float fOsztasok[] = { 1.0f, 2.5f, 5.0f, 7.5f, 10.0f, 25.0f, 50.0f, 75.0f} ;
  float f ;
  double dLog10MaxErtek = 1.0 ;

  nOsztasokMer = sizeof( fOsztasok)/sizeof( float) ;

//TRACE( "Osztas(): fMaxErtek=%f nOsztSzamaMin=%d nOsztSzamaMax=%d\n", fMaxErtek, nOsztSzamaMin, nOsztSzamaMax) ;
//TRACE( "Osztas(): nOsztasokMer=%d\n", nOsztasokMer) ;

  dLog10MaxErtek = log10( fMaxErtek) ;
//TRACE( "Osztas(): dLog10MaxErtek=%f\n", dLog10MaxErtek) ;

  nNagysagrend = (int)(dLog10MaxErtek - 1.0) ; // f=83.0-ra 0-t adott vissza a fv.
//  nNagysagrend = (int)(dLog10MaxErtek) ;
//TRACE( "Osztas(): nNagysagrend=%d\n", nNagysagrend) ;

  // 10 <= f <= 999
  f = (float) pow( 10, nNagysagrend) ;
//TRACE( "Osztas(): f=%f\n", f) ;

  nIdx = 0 ;
  nOsztSzama = (int)(fMaxErtek/(f*fOsztasok[nIdx])) ;
//TRACE( "Osztas(): nOsztSzama=%d\n", nOsztSzama) ;

  // 1.0:(10..999) 2.5:(4..39.2) 5.0:(2..19.8) 7.5:(1.3..13.2)
  while ( nIdx < nOsztasokMer && (nOsztSzama < nOsztSzamaMin || nOsztSzamaMax < nOsztSzama) )
  {
    nIdx++ ;
    nOsztSzama = (int)(fMaxErtek/(f*fOsztasok[nIdx])) ;
//TRACE( "Osztas(): nIdx=%d nOsztSzama=%d\n", nIdx, nOsztSzama) ;
  }

  // Ha az osztasszam nem teljesul, legalabb ne dobjon exceptiont
// Ez ugyan mar nem fordulhat elo 20 < nOsztSzama miatt
  if ( nIdx >= nOsztasokMer )
  {
    nIdx = nOsztasokMer - 1 ;
  }

//TRACE( "Osztas(): return=%f\n", f*fOsztasok[nIdx]) ;
  return f*fOsztasok[nIdx] ;
}

CDiagram::~CDiagram()
{
}