// CSzovPar.h

class CSzovPar : public CPar
{
  public :
    CSzovPar() ;

  protected :
    const static char m_nElvKar ;

    // Ha egy parameter tobb, mint 1 sorbol all, itt veszem f.-be 
    // (eredetileg 1 sor : 1 parameter
    int m_nPluszSorok ;

    int m_nUtolsoPar ;

    // CEdzes szamara :
    CString m_sNev ;
    CString m_sDatum ;
    CString m_sMegjegyzes ;

  public :
    void Init() ;

    int BufferFeld( char* pszReadBuffer, UINT nBeoByteok) ;

    inline CString GetNev() const { return m_sNev ; } ;
    inline CString GetDatum() const { return m_sDatum ; } ;
    inline CString GetMegjegyzes() const { return m_sMegjegyzes ; } ;

  public :
    ~CSzovPar() ;
} ;