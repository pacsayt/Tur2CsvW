// Tur2CsvWDoc.h : interface of the CTur2CsvWDoc class
//
/////////////////////////////////////////////////////////////////////////////
#define N_MAX_EDZ_SZAM 5

class CTur2CsvWDoc : public CDocument
{
public :
	CTur2CsvWDoc();
	DECLARE_DYNCREATE(CTur2CsvWDoc)

  const float m_fNyuzsFaktor ;
  const long  m_nEltLepes ;

  // Attributes
public :
//  static const int m_nMaxEdzSzam ;
  enum { nMaxEdzSzam = 5 } ;

protected :

  // skalafaktor = racsmeret/ido
  float m_fNyuzsoritasX ;
  // [s]
  long  m_nTolIdo ;
  long  m_nIgIdo ;

  CKonverter m_cKonverter ;
//  CEdzes     m_aEdzesek[N_MAX_EDZ_SZAM] ;
  CEdzes     m_aEdzesek[nMaxEdzSzam] ;
// Operations
public:

  long GetTolIdo() ;
  long GetIgIdo()  ;

  inline CEdzes* GetEdzesek() { return m_aEdzesek ; } ;

  CEdzes* GetEdzes( int nIdx) ;

  inline float GetNyuzsoritasX() { return m_fNyuzsoritasX ; } ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTur2CsvWDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
  virtual void OnMoveZoomLeft() ;
  virtual void OnMoveZoomRight() ;
  virtual void OnMoveZoomShrink() ;
  virtual void OnMoveZoomStretch() ;
  virtual void OnFileClose() ;
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTur2CsvWDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  void ViewkInicializal() ;

// Generated message map functions
protected:
	//{{AFX_MSG(CTur2CsvWDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
