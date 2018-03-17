// CEdzes.cpp

#include "stdafx.h"

#include <afx.h>
#include <string.h>

#include "SEgyMinta.h"

#include "CEdzes.h"

#define MIN_SHORT -32768
#define MAX_SHORT  32767

IMPLEMENT_SERIAL( CEdzes, CObject, 0)

//#define N_FOGL_BLOKK_MER 10240
const int CEdzes::m_nFoglBlokkMer =  10240 ;
const short CEdzes::m_nMinShort   = -32768 ;
const short CEdzes::m_nMaxShort   =  32767 ;
const int   CEdzes::m_nMinInt     = (int)(1<<(8*sizeof(int)-1)) ; // 4 byte-os intet feltetelezve !!! 1<<(8*sizeof(int)-1)
const int   CEdzes::m_nMaxInt     =  ~(int)(1<<(8*sizeof(int)-1)) ;
const long  CEdzes::m_nMinLong    = (long)(1<<(8*sizeof(long)-1)) ;
const long  CEdzes::m_nMaxLong    =  ~(long)(1<<(8*sizeof(long)-1)) ;

CEdzes::CEdzes()
{
  m_bKijelzendo  = FALSE ;

  m_nMintakSzama = 0 ;
  m_aMintak      = NULL ;
  m_aMagassagKul = NULL ;
  m_aNormMagassagKul = NULL ;

  m_nMinMagassag = m_nMaxShort ;
  m_nMaxMagassag = m_nMinShort ;

//  m_nMinMagassagKul = m_nMaxShort ;
//  m_nMaxMagassagKul = m_nMinShort ;

  m_nNormMinMagassagKul = m_nMaxShort ;
  m_nNormMaxMagassagKul = m_nMinShort ;

  m_nMvFrekv = 1 ; // volt : 0 ???
// m_nFoglBlokkSzama = 0 ;
}

int CEdzes::MintakAtvesz( SEgyMinta* pIniMintak, int nIniMintakSzama)
{
  int nIdx = 0 ;

  // Probalok valami hibakezelest beepiteni
  if ( pIniMintak == NULL && nIniMintakSzama != 0 )
  {
    return -1 ;
  }

  if ( m_aMintak != NULL )
  {
    delete [] m_aMintak ;
  }

  m_aMintak = pIniMintak ;

  // Az uj edzes hosszabb-e, mint a regi, kell-e helyet foglalni
  if ( m_nMintakSzama < nIniMintakSzama )
  {
    delete [] m_aMagassagKul ;
    delete [] m_aNormMagassagKul ;

    m_aMagassagKul = new short[nIniMintakSzama] ;
    m_aNormMagassagKul = new short[nIniMintakSzama] ;

    if ( m_aMagassagKul == NULL || m_aNormMagassagKul == NULL )
    {
      return -1 ;
    }
  }

  m_nMintakSzama = nIniMintakSzama ;

  // Felteszem, hogy nem valtozik edzes kozben...
  if ( m_nMintakSzama > 1 )
  {
    m_nMvFrekv = (short)(m_aMintak[1].m_nIdo - m_aMintak[0].m_nIdo) ;
  }

  for ( nIdx = 0 ; nIdx < m_nMintakSzama ; nIdx++ )
  {
    m_nMinMagassag = min( m_nMinMagassag, m_aMintak[nIdx].m_nMagassag) ;
    m_nMaxMagassag = max( m_nMaxMagassag, m_aMintak[nIdx].m_nMagassag) ;
  }

  // A magassagkulonbseg tomb adatainak beirasa
  for ( nIdx = 0 ; nIdx < m_nMintakSzama - 1 ; nIdx++ )
  {
    m_aMagassagKul[nIdx] = m_aMintak[nIdx+1].m_nMagassag - m_aMintak[nIdx].m_nMagassag ;

    m_aNormMagassagKul[nIdx] = m_aMagassagKul[nIdx]/m_nMvFrekv ; 

    m_nNormMinMagassagKul = min( m_nNormMinMagassagKul, m_aNormMagassagKul[nIdx]) ;
    m_nNormMaxMagassagKul = max( m_nNormMaxMagassagKul, m_aNormMagassagKul[nIdx]) ;
  }

  // Legyen a m_aMagassagKul tomb is ugyanakkora, mint a m_aMintak - azonos ciklusszervezes
  m_aMagassagKul[m_nMintakSzama-1] = 0 ;

  m_bKijelzendo = TRUE ;

  return 0 ;
}

long CEdzes::GetElteltIdo( int nIdx)
{
  long nElteltIdo = 0 ;

  nElteltIdo = ElteltIdo( 0, nIdx) ;

  return nElteltIdo ;
}

int CEdzes::IdoBolIdx( long nElteltIdo)
{
  int nIdx = 0 ;

  nIdx = nElteltIdo / m_nMvFrekv ;

  if ( nIdx < 0 )
  {
    return 0 ;
  }

  if ( nIdx >= m_nMintakSzama )
  {
    return m_nMintakSzama - 1 ;
  }


  return nIdx ;
}

short CEdzes::GetMagassag( int nIdx)
{
  if ( 0 <= nIdx && nIdx < m_nMintakSzama )
  {
    if ( m_aMintak != NULL )
    {
      return m_aMintak[nIdx].m_nMagassag ;
    }
  }

  return 0 ;
}

short CEdzes::GetMagassagKul( int nIdx)
{
  if ( 0 <= nIdx && nIdx < m_nMintakSzama )
  {
    if ( m_aMintak != NULL )
    {
      return m_aMagassagKul[nIdx] ;
    }
  }

  return 0 ;
}

short CEdzes::GetNormMagassagKul( int nIdx)
{
  if ( 0 <= nIdx && nIdx < m_nMintakSzama )
  {
    if ( m_aMintak != NULL )
    {
      return m_aNormMagassagKul[nIdx] ;
    }
  }

  return 0 ;
}

// Az eltelt idot irja ki masodpercben. Ha valamelyik index kilog a tenyleges
// indextartomanybol, a kozos tartomany idejet adja vissza, szelsoseges esetben 0-t.
long CEdzes::ElteltIdo( int nIdxTol, int nIdxIg)
{
  if ( nIdxTol < 0 )
  {
    nIdxTol = 0 ;
  }

  if ( nIdxTol >= m_nMintakSzama)
  {
    nIdxTol = m_nMintakSzama - 1 ;
  }

  if ( nIdxIg < 0 )
  {
    nIdxIg = 0 ;
  }

  if ( nIdxIg >= m_nMintakSzama)
  {
    nIdxIg = m_nMintakSzama - 1 ;
  }

  return m_aMintak[nIdxIg].m_nElteltIdo - m_aMintak[nIdxTol].m_nElteltIdo ;
}

short CEdzes::MaxEmelkedes( int nIdxTol, int nIdxIg)
{
  int   nIdx = 0 ;
  short nMinMagassag = CEdzes::m_nMaxShort ;
  short nMaxMagassag = CEdzes::m_nMinShort ;
  short nMaxEmelkedes = 0 ;

  if ( nIdxTol < 0 )
  {
    nIdxTol = 0 ;
  }

  for ( nIdx = nIdxTol ; nIdx < nIdxIg && nIdx < m_nMintakSzama ; nIdx++ )
  {
    nMinMagassag = min( nMinMagassag, m_aMintak[nIdx].m_nMagassag) ;
    nMaxMagassag = max( nMaxMagassag, m_aMintak[nIdx].m_nMagassag) ;
//TRACE( "CEdzes::MaxEmelkedes : m_aMintak[nIdx].m_nMagassag=%d, nMinMagassag=%d, nMaxMagassag=%d\n", m_aMintak[nIdx].m_nMagassag, nMinMagassag, nMaxMagassag) ;
  }

  nMaxEmelkedes = nMaxMagassag - nMinMagassag ;

  return nMaxEmelkedes ;
}

short CEdzes::Magassagnyereseg( int nIdxTol, int nIdxIg)
{
  short nMagassagnyereseg = 0 ;
  int   nIdx = 0 ;

  if ( nIdxTol < 0 )
  {
    nIdxTol = 0 ;
  }

  // A magassagkulonbseg tomb adatainak beirasa
  for ( nIdx = nIdxTol ; nIdx < nIdxIg && nIdx < m_nMintakSzama - 1 ; nIdx++ )
  {
    if ( m_aMagassagKul[nIdx] > 0 )
    {
      nMagassagnyereseg = nMagassagnyereseg + m_aMagassagKul[nIdx] ;
    }
//TRACE( "CEdzes::Magassagnyereseg : m_aMagassagKul[nIdx]=%d, nMagassagnyereseg=%d\n", m_aMagassagKul[nIdx], nMagassagnyereseg) ;
  }

  return nMagassagnyereseg ;
}
/* m_aMagassagKul - lel nem foglalkozik, mert scak a MintakAtvesz-t hasznaljuk,
   az meg mindig pontosan foglal(, ha kell)
int CEdzes::MintakTombFoglal( int nIniMintakSzama)
{
  SEgyMinta* pIdglMintak = NULL ;

  // Kell-e az uj elem miatt ujrafoglalni az m_pNagydijak tombot
  if ( nIniMintakSzama > m_nFoglBlokkSzama*m_nFoglBlokkMer )
  {
    pIdglMintak = new SEgyMinta[(m_nFoglBlokkSzama+1)*m_nFoglBlokkMer] ;

    if ( pIdglMintak == NULL )
    {
      return -1 ;
    }

    // Mivel ez mostmar teny :
    m_nFoglBlokkSzama++ ;

    if ( m_aMintak != NULL )
    {
      memcpy( pIdglMintak, m_aMintak, m_nMintakSzama*sizeof(SEgyMinta)) ;

      delete [] m_aMintak ;
    }

    m_aMintak = pIdglMintak ;
  }

  return 0 ;
}
*/

CEdzes::~CEdzes()
{
  if ( m_aMintak != NULL )
  {
    delete [] m_aMintak ;
  }

  if ( m_aMagassagKul != NULL )
  {
    delete [] m_aMagassagKul ;
  }

  if ( m_aNormMagassagKul != NULL )
  {
    delete [] m_aNormMagassagKul ;
  }
}
