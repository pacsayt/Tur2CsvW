// CDiagram.h

class CDiagram
{
  public :
    CDiagram() ;

    int DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CEdzes* pEdzesek) ;

    CRect GetRacsMeretRect() { return m_cRacsMeretRect ;} ;

    void TolIdoBeallit( long nUjTolIdo) ;

//    void IgIdoBeallit( CEdzes* pEdzesek) ;
    void IgIdoBeallit( long nUjIgIdo) ;

    inline long GetTolIdo() {  return m_nTolIdo ; } ;

  protected :
    // a m_cClientRect beallitasat kulon fv-be kellene helyezni,
    // mert DiagramKirjzol() is hivja pl. SzovmeretBeall()-t, ami eleve hulyeseg + pDC->DPtoLP( &m_cClientRect)
    // is ketszer tortenik
    void ClientRectBeall( const CRect& cClientRect) ;

    //    int RacsMeretBeall( int nBalFelsoX = 10, int nBalFelsoY = 10, int nJobbAlsoX = 10, int nJobbAlsoY = 10) ; ???
    void NyuzsoritasBeall( float fNyuzsX = 1.0, float fNyuzsY = 1.0) ;

    void SzovmeretBeall( CDC* pDC/*, CRect cClientRect*/) ;
    void MinMaxBeallit( CEdzes* pEdzesek) ;
    void SkalafaktorBeallit() ;

    int RacsKirajzol( CDC* pDC/*, CRect cClientRect*/, CEdzes* pEdzesek) ;
//    int EdzesekKirajzol( CDC* pDC, CRect cClientRect, CEdzes* pEdzesek) ;
    float Osztas( float fMaxErtek, int nOsztSzamaMin, int nOsztSzamaMax) ;

    // A racs a view-n belul helyezkedik el, ugy, hogy legyen korulotte hely
    // kottazni, azaz kerete van
    // A CEdzDiagram alatt levo statisztika CRect-jevel osztozik a kapott ClientRect-en
    CRect m_cClientRect ;
//    CRect m_cGrafikaMeret ;
    CSize m_cSzovMeret ;

    // A kijeloles atmeretezes utani ujrarajzolasanal hasznalatos, az aranyitashoz
    CRect m_cRacsMeretRect ;
//    int m_nRacsSzelesseg   ;
//    int m_nRacsMagassag    ;
    int m_nCliRectMagassag ;

    short m_nMinErtek ; // m_nMinMagassag
    short m_nMaxErtek ; // m_nMaxMagassag

    int   m_nMaxMintakSzama ;
    long  m_nMaxIdo ;   // A leghosszabb edzes hossza (A max. kij. ido-kezdetben)

    long  m_nTolIdo ;   // A diagram bal szele (gorgetes)
    long  m_nIgIdo  ;   // A diagram jobb szele (incl. gorg/nyuzs.)

    float m_fNyuzsX ;
    float m_fNyuzsY ;

    float m_fSkalafaktorX ;
    float m_fSkalafaktorY ;


    COLORREF m_nHatterSzin ;
    COLORREF m_nRacsSzin   ;
    COLORREF m_aGorbeSzinek[N_MAX_EDZ_SZAM] ;

    CBrush m_cBrush ;
    CPen   m_cRacsPen ;
    CPen   m_cEdzesPen ;
//    static const double m_dLOG10 = Math.log( 10.0) ;
  public :
    ~CDiagram() ;
} ;