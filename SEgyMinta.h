// SEgyMinta.h

struct SEgyMinta
{
  // UNIX ido [s]
  /*unsigned*/ long m_nIdo ;
  // UNIX ido [s]
  /*unsigned*/ long m_nElteltIdo ;
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
