// CloseTaining.cpp : implementation file
//

#include "stdafx.h"

#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"

#include "Tur2CsvW.h"

#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"
#include "Tur2CsvWDoc.h"

#include "CloseTaining.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCloseTaining dialog
CCloseTaining::CCloseTaining( CTur2CsvWDoc* pTur2CsvWDoc, CWnd* pParent /*=NULL*/)
	: CDialog(CCloseTaining::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCloseTaining)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

  m_pTur2CsvWDoc = pTur2CsvWDoc ;
}

CCloseTaining::CCloseTaining(CWnd* pParent /*=NULL*/)
	: CDialog(CCloseTaining::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCloseTaining)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

  m_pTur2CsvWDoc = NULL ;
}

BOOL CCloseTaining::OnInitDialog()
{
  CListBox* pListaAbl = (CListBox*) GetDlgItem(IDC_BETOLT_EDZ_LST) ;

  CEdzes* pEdzes = NULL ;

  int nAktSdzIdx = 0 ;

//  POSITION poz ;

//  CString  sHibaSzov, sSzov ;

//  char     pszHibaSzov[75] ;
//  long     nRC ;
  
  CDialog::OnInitDialog() ;

//      MessageBox( m_sAktNev, NULL, MB_OK | MB_ICONSTOP ) ;
//      CDialog::OnCancel() ;
//      nKivNev = pListaAbl->GetCurSel() ;
//      m_uiKivNevKulcsa = (unsigned) pListaAbl->GetItemData( nKivNev) ;
//      pListaAbl->SetItemData(pListaAbl->AddString(pVNevAdat->m_sVezNev+",\t"+pVNevAdat->m_sKerNev), uiKulcs) ;
  if ( m_pTur2CsvWDoc == NULL || pListaAbl == NULL )
  {
    return FALSE ;
  }
  
  for ( nAktSdzIdx = 0 ; nAktSdzIdx < CTur2CsvWDoc::nMaxEdzSzam ; nAktSdzIdx++ )
  {
    pEdzes = m_pTur2CsvWDoc->GetEdzes( nAktSdzIdx) ;

    if ( pEdzes != NULL && pEdzes->Kijelzendo() == TRUE )
    {
      pListaAbl->SetItemData( pListaAbl->AddString( pEdzes->GetNev()), nAktSdzIdx) ;
    }
  }

  return TRUE ;
}

void CCloseTaining::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCloseTaining)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCloseTaining, CDialog)
	//{{AFX_MSG_MAP(CCloseTaining)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCloseTaining message handlers

void CCloseTaining::OnOK()
{
  CListBox* pListaAbl = (CListBox*) GetDlgItem(IDC_BETOLT_EDZ_LST) ;

  CEdzes* pEdzes = NULL ;

  int nLstElmSzma = 0 ;
  int nAktLstIdx  = 0 ;
  int nAktEdzIdx  = 0 ;
  int nKijelolve  = 0 ;

  if ( pListaAbl == NULL )
  {
    return ;
  }

  nLstElmSzma = pListaAbl->GetCount() ;

  if ( nLstElmSzma == LB_ERR )
  {
    return ;
  }

  for ( nAktLstIdx = 0 ; nAktLstIdx < nLstElmSzma ; nAktLstIdx++ )
  {

    nAktEdzIdx = pListaAbl->GetItemData( nAktLstIdx) ;

    if ( nAktEdzIdx == LB_ERR )
    {
      continue ;
    }

    nKijelolve = pListaAbl->GetSel( nAktLstIdx) ;

    // + - ha kiv., 0 - ha nem kiv.
    if ( nKijelolve != LB_ERR && nKijelolve != 0 )
    {
      pEdzes = m_pTur2CsvWDoc->GetEdzes( nAktEdzIdx) ;
      pEdzes->SetKijelzendo( FALSE) ;
    }
  }

  CDialog::OnOK() ;
}
