// CMagassagKulView.cpp : implementation file
//

#include "stdafx.h"
#include "Tur2CsvW.h"

#include "CPar.h"
#include "SEgyMinta.h"
#include "CEdzes.h"
#include "CCsvFile.h"
//#include "Tur2CsvW.h"
#include "CSzovPar.h"
#include "CBinPar.h"
#include "CKonverter.h"

#include "Tur2CsvWDoc.h"

#include "CDiagram.h"
#include "CMagKulDiagram.h"

#include "CMagassagKulView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagassagKulView

IMPLEMENT_DYNCREATE(CMagassagKulView, CView)

CMagassagKulView::CMagassagKulView()
{
}

CMagassagKulView::~CMagassagKulView()
{
}

//  Majd meglatjuk, at kell-e venni a CTur2CsvWView-bol az ide definialt fuggvenyeket ...

BEGIN_MESSAGE_MAP(CMagassagKulView, CView)
	//{{AFX_MSG_MAP(CMagassagKulView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CMagassagKulView::TolIdoBeallit( long nUjTolIdo)
{
  m_cMagKulDiagram.TolIdoBeallit( nUjTolIdo) ;
}

//void CMagassagKulView::IgIdoBeallit( CEdzes* pEdzesek)
void CMagassagKulView::IgIdoBeallit( long nUjIgIdo)
{
//  m_cMagKulDiagram.IgIdoBeallit( pEdzesek) ;
  m_cMagKulDiagram.IgIdoBeallit( nUjIgIdo) ;
}



/////////////////////////////////////////////////////////////////////////////
// CMagassagKulView drawing

void CMagassagKulView::OnDraw(CDC* pDC)
{
  RECT sRect ;
  CPen* pOldPen = NULL ;
  CPen cPen ;

  CTur2CsvWDoc* pDoc = NULL ;

  pDoc = GetDocument() ;
  ASSERT_VALID( pDoc) ;

  // TODO: add draw code for native data here
  GetClientRect( &sRect) ;

  if ( !cPen.CreatePen(PS_SOLID, 2, RGB(0,0,0)))
  {
    return ;
  }

  pOldPen = pDC->SelectObject( &cPen) ;

//  CDC::LPtoDP()
//  pDC->DPtoLP( &sRect) ; ???
/*
  pDC->MoveTo( sRect.left, sRect.top) ;
  pDC->LineTo( sRect.right, sRect.top) ;
  pDC->LineTo( sRect.right, sRect.bottom) ;
  pDC->LineTo( sRect.left, sRect.bottom) ;
  pDC->LineTo( sRect.left, sRect.top) ;
*/
  pDC->SelectObject( pOldPen) ;

  m_cMagKulDiagram.DiagramKirajzol( pDC, &sRect, pDoc) ;

	return ;
}

/////////////////////////////////////////////////////////////////////////////
// CMagassagKulView diagnostics

#ifdef _DEBUG
void CMagassagKulView::AssertValid() const
{
	CView::AssertValid();
}

void CMagassagKulView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTur2CsvWDoc* CMagassagKulView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTur2CsvWDoc)));
	return (CTur2CsvWDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMagassagKulView message handlers
