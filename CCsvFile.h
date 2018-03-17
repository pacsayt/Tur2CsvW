// CCsvFile.h
#define N_PARAM_SZAM     7
#define N_MIN_FILE_HOSSZ 4

class CCsvFile
{
  public :
    CCsvFile() ;

  protected :

    int  m_nWriteBufferAktMer ;
    char m_pszWriteBuffer[N_READ_BUFFER_MERET+1] ;

    CFile m_cFile ;
    char* m_pszFileNev ;
    CFileException m_cFileException ;

    const char m_cMezoElvalaszto ;

    CString m_sUjKiterj ;
    CString m_aMezonevek[N_PARAM_SZAM] ;

  public :
    void Init() ;
    int  FileNevBeall( char* pszFileNev) ;
    int  FileMegnyit() ;
    int  EgyMintaKiir( SEgyMinta* pSEgyMinta) ;
    int  FileLezar() ;

  protected :
    int Flush() ;
    int Kiir( char* pszKiirando) ;

  public :
    ~CCsvFile() ;
} ;