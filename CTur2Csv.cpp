// CTur2Csv.cpp
#include "stdafx.h"

#include <stdio.h>

//#include <winbase.h> helyett :
#include <afx.h>
#include <afxtempl.h>
#include <afxinet.h>

#include "CPar.h"
#include "SEgyMinta.h"
#include "CCsvFile.h"
#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"
#include "CTur2Csv.h"

CTur2Csv::CTur2Csv()
{
}

void CTur2Csv::UtolsoHibaKiir()
{
  LPVOID lpMsgBuf = NULL ;
  CString sAblCim ;

 
  FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                 NULL,
                 GetLastError(),
                 MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                 (LPTSTR) &lpMsgBuf,
                 0,
                 NULL) ;

//  printf( "GetLastError : %s\n", lpMsgBuf) ;
//  CWnd::GetWindowText( sAblCim) ;
//  CWinThread::GetMainWnd()
  MessageBox( NULL, (LPCTSTR) lpMsgBuf, "CTur2Csv::UtolsoHibaKiir()", MB_ICONEXCLAMATION | MB_OK) ;

  // Free the buffer.
  LocalFree( lpMsgBuf) ;
}

void CTur2Csv::FindDataKiir( WIN32_FIND_DATA* pFindData)
{
  if ( pFindData == NULL )
  {
    return ;
  }

  printf( "dwFileAttributes:%d\n", &(pFindData->dwFileAttributes)) ;

  DatumKiir( "ftCreationTime", &(pFindData->ftCreationTime)) ;
  DatumKiir( "ftLastAccessTime", &(pFindData->ftLastAccessTime)) ;
  DatumKiir( "ftLastWriteTime", &(pFindData->ftLastWriteTime)) ;

  printf( "nFileSizeHigh:%d\n", pFindData->nFileSizeHigh) ;
  printf( "nFileSizeLow:%d\n", pFindData->nFileSizeLow) ;
//  printf( "dwFileAttributes:%d\n", ) ;  DWORD    dwReserved0; 
//  printf( "dwFileAttributes:%d\n", ) ;  DWORD    dwReserved1; 
  printf( "cFileName:%s\n", pFindData->cFileName) ;
  printf( "cAlternateFileName:%s\n", pFindData->cAlternateFileName) ;
}

int CTur2Csv::DatumKiir( char* pszDatumNeve, FILETIME* pFileTime)
{
  FILETIME   aLocalTime  ;
  SYSTEMTIME aSystemTime ;

  if ( pFileTime == NULL || pszDatumNeve == NULL )
  {
    return -1 ;
  }

  // FileTimeToLocalFileTime() -> FileTimeToSystemTime( FILETIME, SYSTEMTIME)
	if ( !FileTimeToLocalFileTime( pFileTime, &aLocalTime) )
	{
		return -1 ;
	}

	if ( !FileTimeToSystemTime( &aLocalTime, &aSystemTime) )
	{
		return -1 ;
	}

  printf( "%s:%d.%d.%d %d:%d:%d\n", pszDatumNeve, (int)aSystemTime.wYear, (int)aSystemTime.wMonth, (int)aSystemTime.wDay,(int)aSystemTime.wHour, (int)aSystemTime.wMinute, (int)aSystemTime.wSecond) ;

  return 0 ;  
}

int CTur2Csv::Hasznalat()
{
  printf( "Converts one or more tour files into Excel type CSV files\n") ;
  printf( "(tour_file_name.tur -> tour_file_name.csv\n") ;
  printf( "\n") ;
  printf( "Usage :\n") ;
  printf( " CTur2Csv file1.tur ... filen.tur\n") ;
  printf( " CTur2Csv a*.tur b*.tur\n") ;
  printf( " CTur2Csv *.tur\n") ;
  printf( " CTur2Csv *.*\n") ;
  printf( " Caution :\n") ;
  printf( " The used Win32 API functions filter the DOS-style 8.3 names :\n") ;
  printf( " instead of 1234567890.tur_ 123456~1.tur will be checked for pattern match\n") ;

  return 0 ;
}

int CTur2Csv::Futtat( char* pszFileNevMinta)
{
  WIN32_FIND_DATA sFindData ;
  HANDLE          pHandle = NULL ;
  BOOL            bRC     = TRUE ; 

  if ( pszFileNevMinta == NULL )
  {
    return -1 ;
  }

	pHandle = ::FindFirstFile( pszFileNevMinta, &sFindData) ;

	if ( pHandle == INVALID_HANDLE_VALUE )
	{
    UtolsoHibaKiir() ;

    return -1 ;
	}

  while ( bRC == TRUE && pHandle != INVALID_HANDLE_VALUE )
  {
//    FindDataKiir( &sFindData) ; debug

    m_cKonverter.Konvertal( sFindData.cFileName) ;

    bRC = FindNextFile( pHandle, &sFindData) ;
  }

  if ( FALSE == FindClose( pHandle) )
  {
    UtolsoHibaKiir() ;

    return -1 ;
	}

  return 0 ;
}

CTur2Csv::~CTur2Csv()
{
}

int main( int argc, char* argv[])
{
/*
  SEgyMinta* pEgyMinta = NULL ;
  char pszBuff[] = { 0x88, 0x85, 0xD9, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                     0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x0F, 0xE9, 0x12, 0x00} ;

  pEgyMinta = (SEgyMinta*) pszBuff ;

  printf( "m_nIdo%d\n", pEgyMinta->m_nIdo) ;
  printf( "m_nElteltIdo%d\n", pEgyMinta->m_nElteltIdo) ;
  printf( "m_nTavolsag%d\n", pEgyMinta->m_nTavolsag) ;
  printf( "m_nMagassag%d\n", pEgyMinta->m_nMagassag) ;
  printf( "m_nPulzus%d\n", pEgyMinta->m_nPulzus) ;
  printf( "m_nPedFsz%d\n", pEgyMinta->m_nPedFsz) ;
  printf( "m_nHomers%d\n", pEgyMinta->m_nHomers) ;
  printf( "m_aIsmeretlen[]:%d, m_aIsmeretlen[]:%d, m_aIsmeretlen[]:%d\n", pEgyMinta->m_aIsmeretlen[0], pEgyMinta->m_aIsmeretlen[1], pEgyMinta->m_aIsmeretlen[2]) ;
  printf( "-----------------------------------------------\n") ;
*/

  CTur2Csv cTur2Csv ;

  int nIdx = 0 ;

  if ( argc <= 1 )
  {
    cTur2Csv.Hasznalat() ;

    return -1 ;
  }

  for ( nIdx = 1 ; nIdx < argc ; nIdx++ )
  {
    cTur2Csv.Futtat( argv[nIdx]) ;
  }
 
  return 0 ;
}