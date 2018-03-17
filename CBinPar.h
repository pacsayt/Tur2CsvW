// CBinPar.h

/*
struct SEgyMinta
{
  // UNIX ido [s]
  unsigned long m_nIdo ;
  // UNIX ido [s]
  unsigned long m_nElteltIdo ;
  // Tavolsag [1/100 Km]
  unsigned long m_nTavolsag ;
  // Magassag [m]
  short m_nMagassag ;
  // Pulzus [1/min]
  unsigned char m_nPulzus ;
  // Pedalfordulatszam [1/min]
  unsigned char m_nPedFsz ;
  // Homerseklet [C]
  unsigned char m_nHomers ;
  // Ismeretlen 3 byte
  unsigned char m_aIsmeretlen[3] ;
} ;
*/

class CBinPar : public CPar
{
  public :
    CBinPar() ;

  protected :
    int       m_nBinMintakIdx  ;
    SEgyMinta m_rEgyMinta ;
    CCsvFile* m_pCsvFile  ;

    // A mintakat ide olvassa be -> CEdzes
    int        m_nAktIdx ;
    SEgyMinta* m_pMintak ;

  public :
    void Init() ;
    void Init( int nIniBinMintakSzama) ;

    void CsvFileBeall( CCsvFile* pIniCsvFile) ;

    // A binaris feldogozas elott beallitando
// L. CPar.h
//    inline void BinMintakSzamaBeall( int nIniBinMintakSzama) { m_nBinMintakSzama = nIniBinMintakSzama ; } ;

    int BufferFeld( char* pszReadBuffer, UINT nBeoByteok) ;

    inline SEgyMinta* MintakVisszaad() const { return m_pMintak ; } ;

    int EgyMintaKiir() ;

  public :
    ~CBinPar() ;
} ;