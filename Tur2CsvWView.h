// Tur2CsvWView.h : interface of the CTur2CsvWView class
//
/////////////////////////////////////////////////////////////////////////////

class CTur2CsvWView : public CView
{
public: // create from serialization only
	CTur2CsvWView();
	DECLARE_DYNCREATE(CTur2CsvWView)

// Attributes
protected:

  // A kijeloleshez szukseges valtozok
  BOOL   m_bKijeloles   ;
  CPoint m_cKijelKezd   ;
  CPoint m_cKijelUtolso ;

  CEdzDiagram m_cEdzDiagram ;

// Operations
public:

  void TolIdoBeallit( long nUjTolIdo) ;

  // Edzes megnyitasa eseten a tol/ig idot vosszaallitja (0,maxidore)
//  void IgIdoBeallit( CEdzes* pEdzesek) ;
  void IgIdoBeallit( long nUjIgIdo) ;

	CTur2CsvWDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTur2CsvWView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTur2CsvWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTur2CsvWView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint cAktPont);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint cAktPont);
	afx_msg void OnMouseMove(UINT nFlags, CPoint cAktPont);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Tur2CsvWView.cpp
inline CTur2CsvWDoc* CTur2CsvWView::GetDocument()
   { return (CTur2CsvWDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
