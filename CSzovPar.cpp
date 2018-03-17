// CSzovPar.cpp
#include "stdafx.h"

#include <afx.h>
#include <string.h>

#include "CPar.h"
#include "SEgyMinta.h"
#include "CCsvFile.h"
#include "CBinPar.h"
#include "CSzovPar.h"

const char CSzovPar::m_nElvKar = 0x0A  ;

CSzovPar::CSzovPar()
{
  Init() ;
}

void CSzovPar::Init()
{
  CPar::Init() ;

//  m_nFeldParamSzama = N_BIN_PARAM_SZAMA ;
  m_nPluszSorok     = 0 ;
//  m_nBinMintakSzama = 0 ;
  m_nUtolsoPar = 0 ;
}

int CSzovPar::BufferFeld( char* pszReadBuffer, UINT nBeoByteok)
{
  char* pTalPoz       = NULL ;
  char* pElozoTalPoz  = NULL ;
  int   nKovParDarMer = 0  ;
//  char  pszTmp[N_READ_BUFFER_MERET] ;
//  UINT  nTmpMer      = 0 ;
//  int   nParIdx      = 0 ;
  int nAtalakitott = 0 ;

  if ( pszReadBuffer == NULL /*int nBufferMer*/)
  {
    return -1 ; // ???
  }

  pElozoTalPoz = pszReadBuffer ;

  do
  {
    pTalPoz = strchr( pElozoTalPoz, m_nElvKar) ;

    if ( pTalPoz != NULL )
    {
      // Itt mar ugyis (?) talatunk egy parametert, 
      // es hogy a switch-ben ne kelljen 1-et levonni
      // Szamoljuk a parametereket (mert csak egyesek erdekesek)
//      m_nParIdx++ ; // < ??? ha egy param masodik fele jon

      // Ha az egyik fele a parameternek mar benne van ... remelhetoleg a 
      // masik teljesen ebben a bufferben es a ketto egyutt belefer a bufferbe
      if ( m_nTmpMer > 0 )
      {
        nKovParDarMer = pTalPoz - pszReadBuffer ;

        while ( nKovParDarMer > 0 )
        {
          // Befer-e meg a bufferbe az aktualis parameter aktualis resze
          if ( nKovParDarMer + m_nTmpMer < N_READ_BUFFER_MERET )
          {
            // Igen
            memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, nKovParDarMer) ;
            m_pszTmp[m_nTmpMer+nKovParDarMer] = '\0' ;
            nKovParDarMer = 0 ;
          }
          else
          {
// Ez igy mindig a m_nTmpMer utani reszre masolgatja be a maradekot (korabbi adatokat persze felulirva)
            // Nem : darabonkent kiirjuk, remelve, hogy egy atalakitando parameter sem hosszabb,
            //       mint a buffer
            memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, (N_READ_BUFFER_MERET - m_nTmpMer) ) ;
            m_pszTmp[N_READ_BUFFER_MERET] = '\0' ;
            nKovParDarMer = nKovParDarMer - (N_READ_BUFFER_MERET - m_nTmpMer) ;
          }         

//TRACE( ">%s<\n", m_pszTmp) ;
        }

//TRACE( ">%s<\n", m_pszTmp) ;
        // Ha egy parameter nem fer bele egy bufferbe, akkor csak a veget probalja atalakitani
        switch ( m_nParIdx - m_nPluszSorok )
        {
          case N_NEV_PARAM_SZAMA  : // 4
            m_sNev = m_pszTmp ;
            break ;
          case N_DATUM_PARAM_SZAMA : // 7
            m_sDatum = m_pszTmp ;
            break ;
          case N_NOTE_SOROK_SZAMA : // 9
            if ( m_nUtolsoPar < N_NOTE_SOROK_SZAMA )
            {
              m_nUtolsoPar = N_NOTE_SOROK_SZAMA ;

              // A "note" tobb soros is lehet, hany sorbol all
              nAtalakitott = atoi( m_pszTmp) ;
              // 1\nnote de lehet : 0\n is -> igen (mod_4.tur)!
              m_nPluszSorok = m_nPluszSorok + nAtalakitott ;
              m_nFeldParamSzama = m_nFeldParamSzama + nAtalakitott ;
            }

            break ;
          case N_BIN_PARAM_SZAMA : // 53
            m_nBinMintakSzama = atoi( m_pszTmp) ;
            break ;
          default :
            ;
        }

        m_nTmpMer = 0 ;
      }
      else // if ( m_nTmpMer > 0 )
      {
        *pTalPoz = '\0' ;
//TRACE( ">%s<\n", pElozoTalPoz) ;

        switch ( m_nParIdx - m_nPluszSorok )
        {
          case N_NEV_PARAM_SZAMA  : // 4
            m_sNev = pElozoTalPoz ;
            break ;
          case N_DATUM_PARAM_SZAMA : // 7
            m_sDatum = pElozoTalPoz ;
            break ;
          case N_NOTE_SOROK_SZAMA : // 9
            if ( m_nUtolsoPar < N_NOTE_SOROK_SZAMA )
            {
              m_nUtolsoPar = N_NOTE_SOROK_SZAMA ;

              // A "note" tobb soros is lehet, hany sorbol all
              nAtalakitott = atoi( pElozoTalPoz) ;
              // 1\nnote de lehet : 0\n is -> igen (mod_4.tur)!
              m_nPluszSorok = m_nPluszSorok + nAtalakitott ;
              m_nFeldParamSzama = m_nFeldParamSzama + nAtalakitott ;
            }

            break ;
          case N_BIN_PARAM_SZAMA : // 53
            m_nBinMintakSzama = atoi( pElozoTalPoz) ;
            break ;
          default :
            ;
        }
      }

      // Az aktualis parameter utan uj jon : nemcsak, ha annak mar megvan a vege
      m_nParIdx++ ;
      pTalPoz++ ;
      pElozoTalPoz = pTalPoz ;
    }
    else // if ( pTalPoz != NULL ), a parameter vege nincs mar ebben a bufferben
    {
      if ( m_nTmpMer > 0 )
      {
        m_pszTmp[m_nTmpMer] = '\0' ;
//TRACE( "%s\n", m_pszTmp) ;
      }

      // A feldolgozas soran hasznalt parametereket nem eleg csak kiirni 
      // bufferhataron keresztul
      switch ( m_nParIdx - m_nPluszSorok )
      {
        case N_NEV_PARAM_SZAMA  : // 4
          if ( m_nUtolsoPar >= N_NEV_PARAM_SZAMA )
          {
            break ;
          }
        case N_DATUM_PARAM_SZAMA : // 7
          if ( m_nUtolsoPar >= N_DATUM_PARAM_SZAMA )
          {
            break ;
          }
        case N_NOTE_SOROK_SZAMA :// 9 utan, mikor olvassa a sorokat ide belemegy
          if ( m_nUtolsoPar >= N_NOTE_SOROK_SZAMA )
          {
            break ;
          }
        case N_BIN_PARAM_SZAMA  : // 53
          m_nTmpMer = N_READ_BUFFER_MERET - (pElozoTalPoz-pszReadBuffer) ;
          memcpy( m_pszTmp, pElozoTalPoz, m_nTmpMer) ;

          // \0 az utolso masolt ertek utan, mert, ha a kov buffer \0-val
          // kezdodik, a \0 lemarad pTalPoz == NULL miatt
          if ( m_nTmpMer < N_READ_BUFFER_MERET )
          {
            m_pszTmp[m_nTmpMer] = '\0' ;
          }
          else
          {
            m_pszTmp[N_READ_BUFFER_MERET] = '\0' ;
          }

//TRACE( "%s\n", m_pszTmp) ;

          break ;
        default :
          ;
      }

//      pszReadBuffer[nBeoByteok-1] = '\0' ; // ez felulirja a   m_nFeldParamSzama-t 0-ra
      pszReadBuffer[nBeoByteok] = '\0' ;
//TRACE( "%s\n", pElozoTalPoz) ;
    }
  }
  while ( pTalPoz != NULL && pTalPoz < (pszReadBuffer + nBeoByteok) && m_nParIdx <= m_nFeldParamSzama ) ;

  // A maradek a binaris resz szamara (?)
  if ( m_nParIdx > m_nFeldParamSzama)
  {
    m_nTmpMer = N_READ_BUFFER_MERET - (pElozoTalPoz-pszReadBuffer) ;
    memcpy( m_pszTmp, pElozoTalPoz, m_nTmpMer) ;

    m_bMindenParFeld = TRUE ;
  }

  return m_nParIdx ;
}

CSzovPar::~CSzovPar()
{
//  m_nElvKar = 0x0A ;
//  m_nReadBufferMeret = 4096 ;
}
