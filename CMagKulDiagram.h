// CMagKulDiagram.h

class CMagKulDiagram : public CDiagram
{
  public :
    CMagKulDiagram() ;

    int DiagramKirajzol( CDC* pDC, const CRect& cClientRect, CTur2CsvWDoc* pDoc) ;

  protected :
    void MinMaxBeallit( CEdzes* pEdzesek) ;
    int MagKulKirajzol( CDC* pDC/*, CRect cClientRect*/, CEdzes* pEdzesek) ;

  public :
    ~CMagKulDiagram() ;
} ;