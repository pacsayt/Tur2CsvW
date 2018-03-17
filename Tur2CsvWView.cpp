// Tur2CsvWView.cpp : implementation of the CTur2CsvWView class
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
#include "CEdzDiagram.h"

#include "Tur2CsvWView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView

IMPLEMENT_DYNCREATE(CTur2CsvWView, CView)

BEGIN_MESSAGE_MAP(CTur2CsvWView, CView)
	//{{AFX_MSG_MAP(CTur2CsvWView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView construction/destruction

CTur2CsvWView::CTur2CsvWView()
{
	// TODO: add construction code here
  m_bKijeloles = FALSE ;
  m_cKijelKezd.x = 0 ;
  m_cKijelKezd.y = 0 ;
  m_cKijelUtolso.x = 0 ;
  m_cKijelUtolso.y = 0 ;
}

CTur2CsvWView::~CTur2CsvWView()
{
}

void CTur2CsvWView::TolIdoBeallit( long nUjTolIdo)
{
  m_cEdzDiagram.TolIdoBeallit( nUjTolIdo) ;
}

//void CTur2CsvWView::IgIdoBeallit( CEdzes* pEdzesek)
//{
//  m_cEdzDiagram.IgIdoBeallit( pEdzesek) ;
//}

void CTur2CsvWView::IgIdoBeallit( long nUjIgIdo)
{
  m_cEdzDiagram.IgIdoBeallit( nUjIgIdo) ;
}


BOOL CTur2CsvWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView drawing

void CTur2CsvWView::OnDraw(CDC* pDC)
{
  /*
  typedef struct tagRECT 
  {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECT;
  */

  RECT sAblMerRect ;
//  CSize sAblMerSize = CSize( 0, 0) ;
  static CSize sRegiAblMerSize = CSize( 0, 0) ;
  CPen* pOldPen = NULL ;
  CPen cPen ;

  CTur2CsvWDoc* pDoc = NULL ;

  CClientDC cClientDC( this) ;
  CRect     cRect ;

TRACE( "\nCTur2CsvWView::OnDraw() KEZD\n") ;
  pDoc = GetDocument() ;
  ASSERT_VALID( pDoc) ;

  // TODO: add draw code for native data here
  GetClientRect( &sAblMerRect) ;

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

  m_cEdzDiagram.DiagramKirajzol( pDC, &sAblMerRect, pDoc) ;

//  sAblMerSize = m_cEdzDiagram.GetRacsMeret() ;

  // Meg az esetleges kijelolest is ujra ki kell rajzolni, mert
  // kulonben az ujboli kijeloles kezdetenel a kepernyore kerul es ott marad
//TRACE( "CTur2CsvWView::OnDraw() : t Kezd.x=%d, Kezd.y=%d, Utolso.x=%d, Utolso.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

  cRect = m_cEdzDiagram.GetKijMeret() ;
  cRect.NormalizeRect() ;

  cClientDC.DrawFocusRect( cRect) ;
TRACE( "CTur2CsvWView::OnDraw() : DrawFocusRect (x=%d,y=%d) -> (x=%d,y=%d)\n", cRect.left, cRect.top, cRect.right, cRect.bottom) ;

  // Kirajzolas pl. atmeretezes miatt : a megvaltozott skalafaktor + kezd x + nyuzs-t az m_cEdzDiagram veszi f-be
  m_cKijelKezd.x   = cRect.left   ;
  m_cKijelKezd.y   = cRect.top    ;
  m_cKijelUtolso.x = cRect.right  ;
  m_cKijelUtolso.y = cRect.bottom ;

//  sRegiAblMerRect = sAblMerRect ;
TRACE( "CTur2CsvWView::OnDraw() : Statisztika( (x=%d,y=%d) -> (x=%d,y=%d))\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

  m_cEdzDiagram.Statisztika( (CDC*)&cClientDC, pDoc->GetEdzesek()) ;

TRACE( "CTur2CsvWView::OnDraw() VEG\n") ;
TRACE( "\n") ;

  return ;
}

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView printing

BOOL CTur2CsvWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTur2CsvWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTur2CsvWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView diagnostics

#ifdef _DEBUG
void CTur2CsvWView::AssertValid() const
{
	CView::AssertValid();
}

void CTur2CsvWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTur2CsvWDoc* CTur2CsvWView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTur2CsvWDoc)));
	return (CTur2CsvWDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTur2CsvWView message handlers

void CTur2CsvWView::OnLButtonDown(UINT nFlags, CPoint cAktPont) 
{
	// TODO: Add your message handler code here and/or call default
  CClientDC cClientDC( this) ;
  CRect     cRect ;

  cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
  cRect.NormalizeRect() ;
//TRACE( "\n") ;
//TRACE( "CSelectTool::OnLButtonDown() : m_cKijelKezd.x=%d, m_cKijelKezd.y=%d, m_cKijelUtolso.x=%d, m_cKijelUtolso.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
  cClientDC.DrawFocusRect( cRect) ;

  m_cKijelKezd   = cAktPont ;
  m_cKijelUtolso = m_cKijelKezd ;
//----------------------------------------
  cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
  cRect.NormalizeRect() ;
//TRACE( "\n") ;
//TRACE( "CSelectTool::OnMouseMove() : m_cKijelKezd.x=%d, m_cKijelKezd.y=%d, m_cKijelUtolso.x=%d, m_cKijelUtolso.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
  cClientDC.DrawFocusRect( cRect) ;
//----------------------------------------
  m_bKijeloles   = TRUE     ;
  
	CView::OnLButtonDown(nFlags, cAktPont);
}

void CTur2CsvWView::OnLButtonUp(UINT nFlags, CPoint cAktPont) 
{
//  CString sStatusBarSzov ;
  CRect     cRect ;
  CClientDC cClientDC( this) ;
  CTur2CsvWDoc* pDoc = NULL ;

  pDoc = GetDocument() ;
                   
  if ( pDoc != NULL )
  {
    // A regi kijeloles letorolve
    cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
    cRect.NormalizeRect() ;
    cClientDC.DrawFocusRect( cRect) ;
TRACE( "CTur2CsvWView::OnLButtonUp() : t (x=%d,y=%d) -> (x=%d,y=%d)\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

    cRect = m_cEdzDiagram.GetKijMeret() ;
    // Az eger felengedesenel az y-ertekek legyenek rahuzva a diagramra (ugysem szamitanak)
    m_cKijelKezd.y   = cRect.top ;
    m_cKijelUtolso.y = cRect.bottom ;

    cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
    cRect.NormalizeRect() ;
//TRACE( "\n") ;
//TRACE( "CSelectTool::OnLButtonUp() : m_cKijelKezd.x=%d, m_cKijelKezd.y=%d, m_cKijelUtolso.x=%d, m_cKijelUtolso.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
    cClientDC.DrawFocusRect( cRect) ;
TRACE( "CTur2CsvWView::OnLButtonUp() : r (x=%d,y=%d) -> (x=%d,y=%d)\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

    // A statisztiakat keszito resz felhivasa
//    m_cEdzDiagram.KijIdxBeall( m_cKijelKezd, m_cKijelUtolso) ; kul Fs-es edzeseknel az inmdex nem jo otlet
    m_cEdzDiagram.KijKezdVegeBeall( m_cKijelKezd, m_cKijelUtolso) ;
    m_cEdzDiagram.Statisztika( (CDC*)&cClientDC, pDoc->GetEdzesek()) ;

cRect = m_cEdzDiagram.GetKijMeret() ;
TRACE( "CTur2CsvWView::OnLButtonUp() : GetKijMeret() : (x=%d,y=%d) -> (x=%d,y=%d)\n", cRect.left, cRect.top, cRect.right, cRect.bottom) ;

  }

  // TODO: Add your message handler code here and/or call default
  m_bKijeloles = FALSE ;

  CView::OnLButtonUp(nFlags, cAktPont) ;
}

void CTur2CsvWView::OnMouseMove(UINT nFlags, CPoint cAktPont) 
{
	// TODO: Add your message handler code here and/or call default
  CClientDC cClientDC( this) ;
  CRect     cRect ;

  if ( m_bKijeloles == TRUE )
  {
//    cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

    cRect = CRect( m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;
    cRect.NormalizeRect() ;
//TRACE( "\n") ;
    cClientDC.DrawFocusRect( cRect) ;
//TRACE( "CSelectTool::OnMouseMove() : t Kezd.x=%d, Kezd.y=%d, Utolso.x=%d, Utolso.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, m_cKijelUtolso.x, m_cKijelUtolso.y) ;

    cRect.SetRect( m_cKijelKezd.x, m_cKijelKezd.y, cAktPont.x, cAktPont.y) ;
    cRect.NormalizeRect() ;
//TRACE( "CSelectTool::OnMouseMove() : m_cKijelKezd.x=%d, m_cKijelKezd.y=%d, cAktPont.x=%d, cAktPont.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, cAktPont.x, cAktPont.y) ;
//TRACE( "\n") ;
		cClientDC.DrawFocusRect( cRect) ;
//TRACE( "CSelectTool::OnMouseMove() : r Kezd.x=%d, Kezd.y=%d, cAktPont.x=%d, cAktPont.y=%d\n", m_cKijelKezd.x, m_cKijelKezd.y, cAktPont.x, cAktPont.y) ;

    m_cKijelUtolso = cAktPont ;
  }

	CView::OnMouseMove( nFlags, cAktPont) ;
}
