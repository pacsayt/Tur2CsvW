int CBinPar::BufferFeld( char* pszReadBuffer, UINT nBeoByteok)
{
  int        nAktBuffPoz = 0 ;
  SEgyMinta* pEgyMinta   = NULL ;

  if ( pszReadBuffer == NULL || nBeoByteok <= 0 )
  {
    return -1 ;
  }

  nMintaMerete  = sizeof( SEgyMinta) ;

  // Ennyi olvasasra van szukseg :
  //  |             |    |                  |      | 
  //   <-m_nTmpMer->     |                   <-  ->
  //   <-1*nMintaMerete-> <-n*nMintaMerete-> maradek
  nMintakBuffben = (nBeoByteok+m_nTmpMer)/nMintaMerete ;

  // Van-e maradek ?
  nMaradek = (nBeoByteok+m_nTmpMer) - nMintakBuffben*nMintaMerete ;
  if ( nMaradek > 0 )
  {
    nMintakBuffben++ ;
  }

  // Ha az elozo feldolgozasbol maradt meg valami a minta elejeben
  if ( m_nTmpMer > 0 )
  {
    // Van-e eleg adat, hogy a temporalis bufferben levoket egy mintara egeszitse ki ?
    if ( nMintaMerete > m_nTmpMer + nBeoByteok )
    {
      // Nincs: a beolvasott buffer tartalmat csak hozzaadjuk a temporalis bufferehez, mert nem teljes meg 
      memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, nBeoByteok) ;
      m_nTmpMer = m_nTmpMer + nBeoByteok ;

      return 0 ;
    }

    // Van : kiegeszit teljes meretre
    memcpy( m_pszTmp + m_nTmpMer, pszReadBuffer, nMintaMerete-m_nTmpMer) ;

    pEgyMinta = (SEgyMinta*)( m_pszTmp) ;
    m_rEgyMinta = *pEgyMinta ;

    nAktBuffPoz = /*nAktBuffPoz + */(nMintaMerete - m_nTmpMer) ;
    m_nTmpMer = 0 ;
    nMintaIdx++ ;
    m_nBinMintakIdx++ ;

    if ( m_pCsvFile->EgyMintaKiir( &m_rEgyMinta) < 0 )
    {
      return -1 ;
    }
  }

  while ( nMintaIdx < nMintakBuffben && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    pEgyMinta = (SEgyMinta*)( pszReadBuffer+nAktBuffPoz+nMintaMerete*nMintaIdx) ;
    m_rEgyMinta = *pEgyMinta ;

    if ( m_pCsvFile->EgyMintaKiir( &m_rEgyMinta) < 0 )
    {
      return -1 ;
    }

    nMintaIdx++ ;
    m_nBinMintakIdx++ ;
  }

  if ( nMaradek > 0 && m_nBinMintakIdx < m_nBinMintakSzama )
  {
    // +m_nTmpMer - hatha van mar egy reszlet a bufferben
    memcpy( m_pszTmp, pszReadBuffer+nAktBuffPoz+nMintaMerete*nMintaIdx, nMaradek) ;
    // Ha egy   \/ bufferben nem fer el teljesen egy minta sem
    m_nTmpMer = m_nTmpMer + nMaradek ;
  }

/*
  if ( m_pCsvFile->EgyMintaKiir( &m_rEgyMinta) < 0 )
  {
    return -1 ;
  }
*/
  return 0 ;
}