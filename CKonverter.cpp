// CKonverter.cpp
#include "stdafx.h"

// CFile
#include <afx.h>
#include <string.h>

#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"
#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"

//const char CKonverter::m_nElvKar = 0x0A  ;
//const UINT m_nReadBufferMeret  = 4096;

CKonverter::CKonverter()
{
//  m_nElvKar = 0x0A ;
//  m_nReadBufferMeret = 4096 ;
  memset( m_pszReadBuffer, 0, N_READ_BUFFER_MERET+1) ;
}

int CKonverter::Konvertal( char* pszFileNev, CEdzes* pKiCEdzes)
{
  UINT  nBeoByteok   = 0 ;
  char* pTalPoz      = NULL ;
  char* pElozoTalPoz = NULL ;
  UINT  nTmpMer      = 0 ;
  int   nParIdx      = 0 ;
  int   nOsszParIdx  = 0 ;

//  CEdzes* pLokCEdzes = NULL ;

  int nRC = 0 ;

//TRACE( "CKonverter::Konvertal() <\n") ;
  //example for CFile::Open
  if ( pszFileNev == NULL || (pKiCEdzes == NULL && pKiCEdzes->Kijelzendo()==FALSE) )
  {
    TRACE( "CKonverter::Konvertal() > -1:1\n") ;
    return -1 ;
  }

  // A beolvasando *.tur-file megnyitasa
  if( !m_cFile.Open( pszFileNev, CFile::modeRead, &m_cFileException ) )
	{
    printf( "File could not be opened : %d", m_cFileException.m_cause) ;

    TRACE( "CKonverter::Konvertal() > -1:2\n") ;
    return -1 ;
	}

  m_cCsvFile.Init() ;
  m_cSzovPar.Init() ;
  m_cBinPar.Init()  ;

  try
  {
    // Az alabbi algoritmus feltetelezi, hogy mindegyik parameter
    // (ket 0x0A kozti byte-ok) belefernek egy bufferbe !
    // A file vegen 0x0A elvalaszto karakter elvart (es a peldakban van is)
    do
    {
      nBeoByteok = m_cFile.Read( m_pszReadBuffer, N_READ_BUFFER_MERET) ;

      // A szoveges, elso resz feldolgozasa
      nParIdx = m_cSzovPar.BufferFeld( m_pszReadBuffer, nBeoByteok) ;
//TRACE( "CKonverter::Konvertal() nParIdx:%d>\n", nParIdx) ;

      if ( nParIdx < 0 )
      {
//TRACE( "CKonverter::Konvertal() > -1:3\n") ;
        return -1 ;
      }
    }
    while ( nBeoByteok == N_READ_BUFFER_MERET && m_cSzovPar.MindenParFeld() == FALSE ) ;

    // Az eppen beolvasott buffer vegen levo binaris adatok beolvasasa
    // Ez mostmar helyet is foglal
    m_cBinPar.Init( m_cSzovPar.BinMintakSzama()) ;
//TRACE( "CKonverter::Konvertal() BinMintakSzama:%d>\n", m_cSzovPar.BinMintakSzama()) ;

    // Sikerult a mintaknak helyet foglalni ?
    if ( m_cBinPar.BinMintakSzama() == 0 )
    {
//TRACE( "CKonverter::Konvertal() > -1:4\n") ;
      return -1 ;
    }

//    m_cBinPar.BinMintakSzamaBeall( m_cSzovPar.BinMintakSzama()) ;
    nParIdx = m_cBinPar.BufferFeld( m_cSzovPar.Tmp(), m_cSzovPar.TmpMer()) ;

    if ( nParIdx < 0 )
    {
//TRACE( "CKonverter::Konvertal() > -1:5\n") ;
      return -1 ;
    }

//int i = 0 ; //dbg
//    do
    while ( nBeoByteok == N_READ_BUFFER_MERET && m_cBinPar.MindenParFeld() == FALSE )
    {
      nBeoByteok = m_cFile.Read( m_pszReadBuffer, N_READ_BUFFER_MERET) ;

      // A binaris, masodik resz feldolgozasa
      nParIdx = m_cBinPar.BufferFeld( m_pszReadBuffer, nBeoByteok) ;
//printf( "i:%d\n", i) ; //dbg
//i++ ;//dbg

      if ( nParIdx < 0 )
      {
//TRACE( "CKonverter::Konvertal() > -1:6\n") ;
        return -1 ;
      }
    }
//    while ( nBeoByteok == N_READ_BUFFER_MERET && m_cBinPar.MindenParFeld() == FALSE ) ;

    // A beolvasott adatok egy CEdzes-be attoltese
//TRACE( "CKonverter::Konvertal() Nev:%s\n", (const char*)m_cSzovPar.GetNev()) ;
//TRACE( "CKonverter::Konvertal() Datum:%s\n", (const char*)m_cSzovPar.GetDatum()) ;
//TRACE( "CKonverter::Konvertal() Megjegyzes:%s\n", (const char*)m_cSzovPar.GetMegjegyzes()) ;
    pKiCEdzes->AltInfoBeall( m_cSzovPar.GetNev(), m_cSzovPar.GetDatum(), m_cSzovPar.GetMegjegyzes()) ;

    // A beolvasott mintak atadasa
    pKiCEdzes->MintakAtvesz( m_cBinPar.MintakVisszaad(), m_cSzovPar.BinMintakSzama()) ;

//    m_cCsvFile.FileLezar() ; // maradek kiir ?
  }
  catch ( CFileException cFileException)
  {
    printf( "File could not be read : %s", cFileException.m_cause) ;
  }

//TRACE( "CKonverter::Konvertal() >\n") ;
 return 0 ;
}

CKonverter::~CKonverter()
{
}