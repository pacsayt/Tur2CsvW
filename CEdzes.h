// CEdzes.h

class CEdzes : CObject
{
  public :
    CEdzes() ;
    DECLARE_SERIAL( CEdzes)

    // Attributes
  protected :
    BOOL m_bKijelzendo ;

    // Altalanos informaciok a szoveges reszbol
    CString m_sNev ;
    CString m_sDatum ;
    CString m_sMegjegyzes ;

    // A mintak
    int m_nMintakSzama ;
    SEgyMinta* m_aMintak ;

    static const int m_nFoglBlokkMer ;
    int m_nFoglBlokkSzama ;

  public :
    static const short m_nMinShort ;
    static const short m_nMaxShort ;
    static const int   m_nMinInt   ;
    static const int   m_nMaxInt   ;
    static const long  m_nMinLong  ;
    static const long  m_nMaxLong  ;

  protected :
    // Magassag [m] 
    // Ha tobb mindent kellene kiirni erdemesebb lenne a 
    // int m_aSpeed[] / int m_aCadence[] / int m_aHeartRate[] / m_aAltitude[] ...
    // int m_aParTombok[][]-nek megfeleloen
    // De : 1 es 4 byte-os parameterek is vannak !

    short m_nMinMagassag ;
    short m_nMaxMagassag ;

    // m_aMagassagKul[n] = m_nMagassag[n+1] - m_nMagassag[n]
    // A statisztikak soran ezt hasznalom, a normalizalas okozta pontatlansagok
    // elkerulesere
    short* m_aMagassagKul ;

    // A m_aMagassagKul normalizalt verzioja, a kijelzesnel ezt az adatot
    // gyorsabb kirajzolni, mint a m_aMagassagKul-t normalizalni (/m_nMvFrekv)
    short* m_aNormMagassagKul ;

//    short m_nMinMagassagKul ;
//    short m_nMaxMagassagKul ;
    short m_nNormMinMagassagKul ;
    short m_nNormMaxMagassagKul ;

    // A mintaveteli frekvencia = m_aMintak[1].m_nIdo - m_aMintak[0].m_nIdo
    // MintakAtvesz()           /\ 
    short m_nMvFrekv ;

  // Operations
  public:
    int MintakAtvesz( SEgyMinta* pIniMintak, int nIniMintakSzama) ;

    inline int GetMintakSzama() { return m_nMintakSzama ; } ;

    inline CString GetNev() { return m_sNev ; } ;

    long GetElteltIdo( int nIdx) ;
    int  IdoBolIdx( long nElteltIdo) ;

    inline short GetMvFrekv() { return m_nMvFrekv ; } ;

    inline short GetMinMagassag() { return m_nMinMagassag ; } ;
    inline short GetMaxMagassag() { return m_nMaxMagassag ; } ;

    short GetMagassag( int nIdx) ;

//    inline short GetMinMagassagKul() { return m_nMinMagassagKul ; } ; 
//    inline short GetMaxMagassagKul() { return m_nMaxMagassagKul ; } ; 
    inline short GetNormMinMagassagKul() { return m_nNormMinMagassagKul ; } ;
    inline short GetNormMaxMagassagKul() { return m_nNormMaxMagassagKul ; } ;

    short GetMagassagKul( int nIdx) ;

    short GetNormMagassagKul( int nIdx) ;

    inline void AltInfoBeall( const CString& sIniNev, const CString& sIniDatum, const CString& sIniMegjegyzes)
    {
      m_sNev = sIniNev ;
      m_sDatum = sIniDatum ;
      m_sMegjegyzes = sIniMegjegyzes ;
    }  ;

//    int MintakTombFoglal( int nIniMintakSzama) ; 

    inline void SetKijelzendo( BOOL bKijelzendo) { m_bKijelzendo = bKijelzendo ; } ;

    // 
    inline BOOL Kijelzendo() const { return m_bKijelzendo ; } ;
  // Overrides

    long  ElteltIdo( int nIdxTol, int nIdxIg) ;
    short Magassagnyereseg( int nIdxTol, int nIdxIg) ;
    short MaxEmelkedes( int nIdxTol, int nIdxIg) ;

  // Implementation
  public:
    virtual ~CEdzes() ;
} ;