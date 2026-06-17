// ju -- https://bw1.eu -- 5-Jan-19 -- funktionen.h 
/* Deklaration eig. Bibliothek	*/

#ifndef BIB_H // Include-Guard
#define BIB_H

#ifdef __cplusplus
extern "C" {          // C-Linkage, damit auch aus C++ nutzbar
#endif

// Fakultaet
int fac( int i );
// Quersumme in beliebigem Zahlensystem
int quersumme(int z, int b); 
// ganze Zahlen potenzieren
int quadriere(int z);
// dritte Potenz
int drittePotenz(int z);
// x hoch y, für x,y >= 0
unsigned long potenziere(int x, int y);

#ifdef __cplusplus
}
#endif

#endif



