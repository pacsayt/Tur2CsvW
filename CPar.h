// CPar.h

//#define N_READ_BUFFER_MERET 32
#define N_READ_BUFFER_MERET 16384
//#define N_NOTE_SOROK_SZAMA  10

#define N_NEV_PARAM_SZAMA    4
#define N_DATUM_PARAM_SZAMA  7
// Az index novelesenek hatrakerulese utan
#define N_NOTE_SOROK_SZAMA   9
//#define N_BIN_PARAM_SZAMA   54
// Az index novelesenek hatrakerulese utan
#define N_BIN_PARAM_SZAMA    53

class CPar
{
  public :
    CPar() ;

  protected :

    int  m_nFeldParamSzama ;
    BOOL m_bMindenParFeld  ;
    int  m_nBinMintakSzama ;

    char  m_pszTmp[N_READ_BUFFER_MERET+1] ;
    UINT  m_nTmpMer ;
    int   m_nParIdx ;

  public :
    void Init() ;

    inline void FeldParamSzamaBeall( int  nIniFeldParamSzama) { m_nFeldParamSzama = nIniFeldParamSzama ; } ;
    inline BOOL MindenParFeld() { return m_bMindenParFeld ; } ;

    // A szoveges resz feldolgozasa utan derul ki
    inline int  BinMintakSzama() { return m_nBinMintakSzama ; } ;
    // A binaris feldogozas elott beallitando
    inline void BinMintakSzamaBeall( int nIniBinMintakSzama) { m_nBinMintakSzama = nIniBinMintakSzama ; } ;

    // A szoveges resz vegen levo binaris resz a temporalis bufferben a binaris beolvasas szanmara
    inline char* Tmp() { return m_pszTmp ; } ;
    inline UINT  TmpMer() { return m_nTmpMer ; } ;

    int BufferFeld( char* pszReadBuffer, UINT nBeoByteok) ;

  public :
    ~CPar() ;
} ;