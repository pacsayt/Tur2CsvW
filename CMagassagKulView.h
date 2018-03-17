// CMagassagKulView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagassagKulView view

class CMagassagKulView : public CView
{
protected:
	CMagassagKulView() ;           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMagassagKulView)

// Attributes
protected:
  CMagKulDiagram m_cMagKulDiagram ;

// Operations
public:

  void TolIdoBeallit( long nUjTolIdo) ;

  // Edzes megnyitasa eseten a tol/ig idot vosszaallitja (0,maxidore)
//  void IgIdoBeallit( CEdzes* pEdzesek) ;
  void IgIdoBeallit( long nUjIgIdo) ;

  CTur2CsvWDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagassagKulView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMagassagKulView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMagassagKulView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Tur2CsvWView.cpp
inline CTur2CsvWDoc* CMagassagKulView::GetDocument()
   { return (CTur2CsvWDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
