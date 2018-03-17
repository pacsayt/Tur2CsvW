// CSzovPar.cpp
#include "stdafx.h"

#include <afx.h>
#include <string.h>

#include "CPar.h"
#include "CSzovPar.h"

CPar::CPar()
{
  Init() ;
}

void CPar::Init()
{
  m_nTmpMer = 0 ;
  m_nParIdx = 0 ;
  m_nBinMintakSzama = 0 ;

 memset( m_pszTmp, 0, N_READ_BUFFER_MERET+1) ;

  m_nFeldParamSzama = N_BIN_PARAM_SZAMA ;

  m_bMindenParFeld = FALSE ;
}

int CPar::BufferFeld( char* pszReadBuffer, UINT nBeoByteok)
{
  return m_nParIdx ;
}

CPar::~CPar()
{
}
