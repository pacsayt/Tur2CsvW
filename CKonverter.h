// CKonverter.h
//#define N_READ_BUFFER_MERET 32
#define N_READ_BUFFER_MERET 16384

// class CSzovPar ;

class CKonverter
{
  public :
    CKonverter() ;

  protected :

    char m_pszReadBuffer[N_READ_BUFFER_MERET+1] ;

    CSzovPar m_cSzovPar ;
    CBinPar  m_cBinPar  ;

    CFile m_cFile ;
    CFileException m_cFileException ;

    CCsvFile m_cCsvFile ;

  public :
    // pCEdzes-nek itt foglal helyet, ha rc==0, kul. nem valtoztatja
    int Konvertal( char* pszFileNev, CEdzes* pCEdzes) ;

  public :
    ~CKonverter() ;
} ;