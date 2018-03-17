// CTur2Csv.h

class CTur2Csv
{
  public :
    CTur2Csv() ;

  protected :
    CKonverter m_cKonverter ;

    void UtolsoHibaKiir() ;

    void FindDataKiir( WIN32_FIND_DATA* pFindData) ;
    int  DatumKiir( char* pszDatumNeve, FILETIME* pFileTime) ;

  public :
    int Hasznalat() ;
    int Futtat( char* pszFileNevMinta) ;

  public :
    ~CTur2Csv() ;
} ;