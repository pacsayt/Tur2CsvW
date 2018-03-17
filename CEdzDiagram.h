// CEdzDiagram.h
class CEdzDiagram : public CDiagram
{
  public :
    CEdzDiagram() ;

    int DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CTur2CsvWDoc* pDoc) ;
    const int m_nStatSorTav ;

  protected :
    static CString m_aStatParamNevek[] ;

    // A CEdzDiagram alatt levo statisztika CRect-jevel osztozik a kapott ClientRect-en
    CRect m_cStatMeret ;

    // A kijelolest indexben (is? - pontos torles a visszaszamolasnal) vezetem
    int m_nKezdKijIdx ;
    int m_nUtolsoKijIdx ;

    long m_nKijKezdIdo ;
    long m_nKijVegeIdo ;

    void SzovmeretBeall( CDC* pDC) ;
    void MinMaxBeallit( CEdzes* pEdzesek) ;
    int EdzesekKirajzol( CDC* pDC, CEdzes* pEdzesek) ;

  public :
//    void KijIdxBeall( const CPoint& cKijelKezd, const CPoint& cKijelUtolso) ;

    void KijKezdVegeBeall( const CPoint& cKijelKezd, const CPoint& cKijelUtolso) ;

    int Statisztika( CDC* pDC, CEdzes* pEdzesek) ;
    // m_nKezdKijIdx : (left, top), m_nUtolsoKijIdx : (right, bottom). 
    // top, bottom - a racs meretenek megfeleloen
    CRect GetKijMeret() ;

  public :
    ~CEdzDiagram() ;
} ;