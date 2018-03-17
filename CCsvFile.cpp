// CCsvFile.cpp
#include "stdafx.h"

#include <afx.h>
#include <string.h>
#include <time.h>

#include "resource.h"

#include "CPar.h"
#include "CSzovPar.h"
#include "SEgyMinta.h"
#include "CCsvFile.h"
#include "CBinPar.h"
//#include "CKonverter.h"

CCsvFile::CCsvFile():m_cMezoElvalaszto( ';')
{
  Init() ;
}

void CCsvFile::Init()
{
  m_aMezonevek[0] = "Date" ;

  m_aMezonevek[1] = "Training time" ;
  m_aMezonevek[2] = "Distance" ;
  m_aMezonevek[3] = "Altitude" ;
  m_aMezonevek[4] = "Heart rate" ;
  m_aMezonevek[5] = "Cadence" ;
  m_aMezonevek[6] = "Temperature" ;

  m_sUjKiterj = ".csv" ;

  m_pszFileNev = NULL ;

  m_nWriteBufferAktMer = 0 ;
  m_pszWriteBuffer[0]  ='\0' ;
}

int CCsvFile::FileNevBeall( char* pszFileNev)
{
  size_t nFileNevLen = 0 ;

  if ( pszFileNev == NULL )
  {
    return -1 ;
  }

  nFileNevLen = strlen(pszFileNev) ;

  if ( nFileNevLen < N_MIN_FILE_HOSSZ )
  {
    return -1 ;
  }

  if ( m_pszFileNev == NULL )
  {
    //                    + 1 a \0-nak : \/
    m_pszFileNev = new char[nFileNevLen + 1] ;
  }
  else
  {
    if ( strlen(m_pszFileNev) < nFileNevLen )
    {
      delete [] m_pszFileNev ; // tuliras miatt jon a hiba ???
      m_pszFileNev = NULL ;
      //                    + 1 a \0-nak : \/
      m_pszFileNev = new char[nFileNevLen + 1] ;
    }
  }

  if ( m_pszFileNev == NULL )
  {
    return -1 ;
  }

  // filenev.tur -> filenev.csv
  strncpy( m_pszFileNev, pszFileNev, nFileNevLen-N_MIN_FILE_HOSSZ) ;
  m_pszFileNev[nFileNevLen-N_MIN_FILE_HOSSZ] = '\0' ;

  strcat( m_pszFileNev, (const char*)m_sUjKiterj) ;

  return 0 ;
}

int CCsvFile::FileMegnyit()
{
  int nIdx ;
  CString sFejlec ;

//TRACE( "CCsvFile::FileMegnyit() <\n") ;

  if( !m_cFile.Open( m_pszFileNev, CFile::modeCreate | CFile::modeWrite, &m_cFileException) )
	{
    printf( "File could not be opened : %d", m_cFileException.m_cause) ;

//TRACE( "CCsvFile::FileMegnyit() >\n") ;
    return -1 ;
	}

  if ( N_PARAM_SZAM > 0 )
  {
    sFejlec = m_aMezonevek[0] ;

    // A fejlec kiirasa
    for ( nIdx = 1 ; nIdx < N_PARAM_SZAM ; nIdx++ )
    {
      sFejlec = sFejlec + m_cMezoElvalaszto + m_aMezonevek[nIdx] ;
    }
  }

  sFejlec = sFejlec + '\n' ;

  Kiir( (char*)(const char*)sFejlec ) ;

//TRACE( "CCsvFile::FileMegnyit() >\n") ;
  return 0 ;
}
/*
tm_hour	Hours since midnight (0-23)
tm_isdst	Positive if daylight saving time is in effect; 0 if daylight saving time is not in effect; negative if status of daylight saving time is unknown. The C run-time library assumes the United States’s rules for implementing the calculation of Daylight Saving Time (DST). 
tm_mday	Day of month (1-31)
tm_min	Minutes after hour (0-59)
tm_mon	Month (0-11; January = 0)
tm_sec	Seconds after minute (0-59)
tm_wday	Day of week (0-6; Sunday = 0)
tm_yday	Day of year (0-365; January 1 = 0)
tm_year	Year (current year minus 1900)
*/
int CCsvFile::EgyMintaKiir( SEgyMinta* pSEgyMinta)
{
  static char pszEgyMinta[256] ;
//  time_t ltime;
  struct tm *pTmpIdo ; 
  struct tm sIdo ; 
  struct tm sElteltIdo ;

  int nRC = 0 ;

//TRACE( "CCsvFile::EgyMintaKiir() <\n") ;

  if ( pSEgyMinta == NULL )
  {
//TRACE( "CCsvFile::EgyMintaKiir() >\n") ;
    return -1 ;
  }

  pTmpIdo = localtime( &(pSEgyMinta->m_nIdo)) ; // gmtime( &ltime ) ;

  // Ha az idoadatok < 1970.01.01
  if ( pTmpIdo == NULL )
  {
//TRACE( "CCsvFile::EgyMintaKiir() >\n") ;
    return -1 ;
  }

  sIdo = *pTmpIdo ;

  pTmpIdo = localtime( &(pSEgyMinta->m_nElteltIdo)) ;

  // Ha az idoadatok < 1970.01.01
  if ( pTmpIdo == NULL )
  {
//TRACE( "CCsvFile::EgyMintaKiir() >\n") ;
    return -1 ;
  }

  sElteltIdo = *pTmpIdo ;

  sprintf( pszEgyMinta, "\"%d.%d.%d %d:%d:%d\"%c\"%d.%d.%d %d:%d:%d\"%c%d%c%d%c%d%c%d%c%d\n",
                        1900+sIdo.tm_year, 1+sIdo.tm_mon, sIdo.tm_mday, sIdo.tm_hour, sIdo.tm_min, sIdo.tm_sec,
                        m_cMezoElvalaszto,
                        1900+sElteltIdo.tm_year, 1+sElteltIdo.tm_mon, sElteltIdo.tm_mday, sElteltIdo.tm_hour, sElteltIdo.tm_min, sElteltIdo.tm_sec,
                        m_cMezoElvalaszto,
                        pSEgyMinta->m_nTavolsag,
                        m_cMezoElvalaszto,
                        pSEgyMinta->m_nMagassag,
                        m_cMezoElvalaszto,
                        pSEgyMinta->m_nPulzus,
                        m_cMezoElvalaszto,
                        pSEgyMinta->m_nPedFsz,
                        m_cMezoElvalaszto,
                        pSEgyMinta->m_nHomers) ;

  nRC = Kiir( pszEgyMinta) ;

//TRACE( "CCsvFile::EgyMintaKiir() >\n") ;
  return 0 ;
}

int CCsvFile::Kiir( char* pszKiirando)
{
  int nKiirandoMer    = 0 ;
  int nBuffMaradekMer = 0 ;

//TRACE( "CCsvFile::Kiir() <\n") ;

  if ( pszKiirando == NULL )
  {
//TRACE( "CCsvFile::Kiir() >\n") ;
    return -1 ;
  }

//TRACE( "CCsvFile::Kiir() pszKiirando:%s\n", pszKiirando) ;

  nKiirandoMer = strlen( pszKiirando) ;
  nBuffMaradekMer = N_READ_BUFFER_MERET - m_nWriteBufferAktMer ;

//TRACE( "CCsvFile::Kiir() nKiirandoMer:%d, nBuffMaradekMer:%d\n", nKiirandoMer, nBuffMaradekMer) ;

  while ( nKiirandoMer > 0 )
  {
    if ( nKiirandoMer <= nBuffMaradekMer )
    {
      strcpy( m_pszWriteBuffer, pszKiirando) ; //, m_nWriteBufferAktMer) ;
//TRACE( "CCsvFile::Kiir()/1 pszKiirando:%s\n", pszKiirando) ;
      m_nWriteBufferAktMer = m_nWriteBufferAktMer + nKiirandoMer ;
      nBuffMaradekMer = nBuffMaradekMer - nKiirandoMer ;
//TRACE( "CCsvFile::Kiir()/1 m_nWriteBufferAktMer:%d, nBuffMaradekMer:%d, nKiirandoMer=0\n", m_nWriteBufferAktMer, nBuffMaradekMer) ;
      nKiirandoMer = 0 ;
    }
    else
    {
      strncpy( m_pszWriteBuffer+m_nWriteBufferAktMer, pszKiirando, nBuffMaradekMer) ;
      m_nWriteBufferAktMer = N_READ_BUFFER_MERET ;
      nKiirandoMer = nKiirandoMer - nBuffMaradekMer ;
      pszKiirando = pszKiirando + nBuffMaradekMer ;
//TRACE( "CCsvFile::Kiir()/2 m_nWriteBufferAktMer:%d, nBuffMaradekMer=0, nKiirandoMer:%d\n", m_nWriteBufferAktMer, nKiirandoMer) ;
      nBuffMaradekMer = 0 ;
    }

    if ( nBuffMaradekMer == 0 )
    {
      try
      {
//TRACE( "CCsvFile::Kiir() Write() [0]:%c, [m_nWriteBufferAktMer-1]:%c\n", m_pszWriteBuffer[0], m_pszWriteBuffer[m_nWriteBufferAktMer-1]) ;
        m_cFile.Write( m_pszWriteBuffer, m_nWriteBufferAktMer) ;
      }
      catch ( CFileException cFileException)
      {
        printf( "File could not be written : %s", cFileException.m_cause) ;

//TRACE( "CCsvFile::Kiir() >\n") ;
        return -1 ;
      }

      m_nWriteBufferAktMer = 0 ;
      nBuffMaradekMer = N_READ_BUFFER_MERET ;
    }
  }

//TRACE( "CCsvFile::Kiir() >\n") ;
  return 0 ;
}

int CCsvFile::Flush()
{
//TRACE( "CCsvFile::Flush() <\n") ;
  try
  {
    m_cFile.Write( m_pszWriteBuffer, m_nWriteBufferAktMer) ;

    m_cFile.Flush() ;
  }
  catch ( CFileException cFileException)
  {
    printf( "File could not be flushed : %s", cFileException.m_cause) ;

//TRACE( "CCsvFile::Flush() >\n") ;
    return -1 ;
  }

//TRACE( "CCsvFile::Flush() >\n") ;
  return 0 ;
}

int CCsvFile::FileLezar()
{
//TRACE( "CCsvFile::FileLezar() <\n") ;
  try
  {
    Flush() ;
    m_cFile.Close() ;
  }
  catch ( CFileException cFileException)
  {
    printf( "File could not be closed : %s", cFileException.m_cause) ;

//TRACE( "CCsvFile::FileLezar() >\n") ;
    return -1 ;
  }

//TRACE( "CCsvFile::FileLezar() >\n") ;
  return 0 ;
}

CCsvFile::~CCsvFile()
{
//TRACE( "CCsvFile::~CCsvFile() <\n") ;
  delete [] m_pszFileNev ;
//TRACE( "CCsvFile::~CCsvFile() >\n") ;
}