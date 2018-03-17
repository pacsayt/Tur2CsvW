// CSzovPar.cpp
#include "stdafx.h"

#include <afx.h>
#include <string.h>

#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"
#include "CBinPar.h"

CBinPar::CBinPar()
{
  Init() ;
}

void CBinPar::Init()
{
  CPar::Init() ;

  m_nBinMintakIdx = 0 ;
  m_pCsvFile      = NULL ;

  m_nAktIdx       = 0 ;
  m_pMintak       = NULL ;
}

void CBinPar::Init( int nIniBinMintakSzama)
{
  Init() ;

  // Ugyan a Cpar::BinMintakSzamaBeall() is megcsinalna, de itt egyben akarok 
  // helyet foglalni a m_pMintak tombnek 
  m_nBinMintakSzama = nIniBinMintakSzama ;

  m_pMintak = new SEgyMinta[m_nBinMintakSzama] ;

  if ( m_pMintak == NULL )
  {
    m_nBinMintakSzama = 0 ;
  }
}

void CBinPar::CsvFileBeall( CCsvFile* pIniCsvFile)
{
  if ( pIniCsvFile != NULL)
  {
    m_pCsvFile = pIniCsvFile ;
  }
}

int CBinPar::BufferFeld( char* pszReadBuffer, UINT nBeoByteok)
{
  UINT nMintaMerete   = 0 ;
  UINT nMintakBuffben = 0 ;
  UINT nMintaIdx      = 0 ;
  UINT nMaradek       = 0 ;
  UINT nAktBuffPoz    = 0 ;

  SEgyMinta* pEgyMinta = NULL ;

//TRACE( "CBinPar::BufferFeld() <\n") ;
  if ( pszReadBuffer == NULL || nBeoByteok <= 0 )
  {
    m_nBinMintakSzama = 0 ;
    delete [] m_pMintak ;
    m_pMintak = NULL ;
//TRACE( "CBinPar::BufferFeld() >\n") ;
    return -1 ;
  }

  nMintaMerete  = sizeof( SEgyMinta) ;

  // Ennyi olvasasra van szukseg :
  //  |             |    |                  |      | 
  //   <-m_nTmpMer->     |                   <-  ->
  //   <-1*nMintaMerete-> <-n*nMintaMerete-> maradek
  nMintakBuffben = (nBeoByteok+m_nTmpMer)/nMintaMerete ;

  // Van-e maradek ?
  nMaradek = (nBeoByteok+m_nTmpMer) - nMintakBuffben*nMintaMerete ;

  // Ha az elozo feldolgozasbol maradt meg valami a minta elejeben
  if ( m_nTmpMer > 0 )
  {
    // Van-e eleg adat, hogy a temporalis bufferben levoket egy mintara egeszitse ki ?
    if ( nMintaMerete > m_nTmpMer + nBeoByteok )
    {
      // Nincs: a beolvasott buffer tartalmat csak hozzaadjuk a temporalis bufferehez, mert nem teljes meg 
      memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, nBeoByteok) ;
      m_nTmpMer = m_nTmpMer + nBeoByteok ;

//TRACE( "CBinPar::BufferFeld() >\n") ;
      return 0 ;
    }

    // Van : kiegeszit teljes meretre
    memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, nMintaMerete-m_nTmpMer) ;

    // Nem tudom, SEgyMinta::unsigned char m_aIsmeretlen[3] is helyesen masolodik ...
    pEgyMinta = (SEgyMinta*)m_pszTmp ;
    m_pMintak[m_nBinMintakIdx] = *pEgyMinta ;
    
    nAktBuffPoz = /*nAktBuffPoz + */(nMintaMerete - m_nTmpMer) ;
    m_nTmpMer = 0 ;

    m_nBinMintakIdx++ ;
  }

  while ( nAktBuffPoz + nMintaMerete <= nBeoByteok && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    pEgyMinta = (SEgyMinta*)( pszReadBuffer+nAktBuffPoz) ;

    m_pMintak[m_nBinMintakIdx] = (SEgyMinta)(*pEgyMinta) ;

    nAktBuffPoz = nAktBuffPoz + nMintaMerete ;
    m_nBinMintakIdx++ ;
  }

  if ( nMaradek > 0 && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    // +m_nTmpMer - hatha van mar egy reszlet a bufferben
//    memcpy( m_pszTmp, pszReadBuffer+nAktBuffPoz+nMintaMerete*nMintaIdx, nMaradek) ;
    memcpy( m_pszTmp, pszReadBuffer+nAktBuffPoz, nMaradek) ;
    // Ha egy   \/ bufferben nem fer el teljesen egy minta sem
    m_nTmpMer = m_nTmpMer + nMaradek ;
  }

//TRACE( "CBinPar::BufferFeld() >\n") ;
  return 0 ;
}

/*
int CBinPar::BufferFeld( char* pszReadBuffer, UINT nBeoByteok)
{
//  char* pTalPoz      = NULL ;
//  char* pElozoTalPoz = NULL ;
  int nMintaMerete   = 0 ;
  int nMintakBuffben = 0 ;
  int nMintaIdx      = 0 ;
  int nMaradek       = 0 ;

  if ( pszReadBuffer == NULL || m_pCsvFile == NULL )
  {
    return -1 ;
  }

  nMintaMerete  = sizeof( SEgyMinta) ;

  // Ennyi olvasasra van szukseg :
  //  |             |    |                  |      | 
  //   <-m_nTmpMer->     |                   <-  ->
  //   <-1*nMintaMerete-> <-n*nMintaMerete-> maradek
  nMintakBuffben = (nBeoByteok+m_nTmpMer)/nMintaMerete ;

  // Van-e maradek ?
  nMaradek = (nBeoByteok+m_nTmpMer) - nMintakBuffben*nMintaMerete ;
  if ( nMaradek > 0 )
  {
    nMintakBuffben++ ;
  }

  while ( nMintaIdx < nMintakBuffben && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    // Ha az elozo feldolgozasbol maradt meg valami a minta elejeben
    if ( m_nTmpMer > 0 )
    {
      // Itt feltetelezem, hogy a bufferben legalabb egy minta teljesen elfer
      // (max ket reszbol all ossze egy minta), ha nem : nMintaMerete - m_nTmpMer -> nMaradek
      memcpy( ((char*)(&m_rEgyMinta))+m_nTmpMer, pszReadBuffer, nMintaMerete - m_nTmpMer) ;

      m_nTmpMer = 0 ;
    }
    else
    {
      SEgyMinta* pEgyMinta = NULL ;

      pEgyMinta = (SEgyMinta*)( pszReadBuffer+nMintaMerete*nMintaIdx) ;
      m_rEgyMinta = *pEgyMinta ;

//      m_rEgyMinta = (SEgyMinta)( *(pszReadBuffer+nMintaMerete*nMintaIdx)) ;
    }

//    EgyMintaKiir() ;
    if ( m_pCsvFile->EgyMintaKiir( &m_rEgyMinta) < 0 )
    {
      return -1 ;
    }

    nMintaIdx++ ;
    m_nBinMintakIdx++ ;
  }

  if ( nMaradek > 0 && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    // +m_nTmpMer - hatha van mar egy reszlet a bufferben
    memcpy( ((char*)(&m_rEgyMinta))+m_nTmpMer, pszReadBuffer, nMaradek) ;
    // Ha egy   \/ bufferben nem fer el teljesen egy minta sem
    m_nTmpMer = m_nTmpMer + nMaradek ;
  }

  return 0 ;
}
*/

int CBinPar::EgyMintaKiir()
{
  printf( "m_nIdo%d\n", m_rEgyMinta.m_nIdo) ;
  printf( "m_nElteltIdo%d\n", m_rEgyMinta.m_nElteltIdo) ;
  printf( "m_nTavolsag%d\n", m_rEgyMinta.m_nTavolsag) ;
  printf( "m_nMagassag%d\n", m_rEgyMinta.m_nMagassag) ;
  printf( "m_nPulzus%d\n", m_rEgyMinta.m_nPulzus) ;
  printf( "m_nPedFsz%d\n", m_rEgyMinta.m_nPedFsz) ;
  printf( "m_nHomers%d\n", m_rEgyMinta.m_nHomers) ;
  printf( "m_aIsmeretlen[]:%d, m_aIsmeretlen[]:%d, m_aIsmeretlen[]:%d\n", m_rEgyMinta.m_aIsmeretlen[0], m_rEgyMinta.m_aIsmeretlen[1], m_rEgyMinta.m_aIsmeretlen[2]) ;
  printf( "-----------------------------------------------\n", m_rEgyMinta.m_nIdo) ;

  return 0 ;
}

CBinPar::~CBinPar()
{
}
