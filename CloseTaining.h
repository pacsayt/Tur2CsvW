// CloseTaining.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCloseTaining dialog

class CCloseTaining : public CDialog
{
// Construction
public:
	CCloseTaining( CTur2CsvWDoc* pTur2CsvWDoc, CWnd* pParent = NULL) ;
	CCloseTaining(CWnd* pParent = NULL);   // standard constructor

  BOOL OnInitDialog() ;

// Dialog Data
protected:
	//{{AFX_DATA(CCloseTaining)
	enum { IDD = IDD_CLOSE_TRAIN_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
  CTur2CsvWDoc* m_pTur2CsvWDoc ;

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseTaining)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCloseTaining)
		// NOTE: the ClassWizard will add member functions here
    virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
