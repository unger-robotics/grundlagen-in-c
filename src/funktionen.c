// ju -- https://bw1.eu -- 5-Jan-19 -- funktionen.c 
/* Definition bzw. Implementierung eig. Bibliothek	*/

#include "funktionen.h"

// Fakultaet
int fac( int i ){
	if (i <= 0) return 1;
	return i * fac( i-1 );
}

// Quersumme in beliebigem Zahlensystem
int quersumme(int z, int b){
  int q = 0;
  while(z > 0){
    q += z % b;
    z /= b;
  }
  return q;
}

// ganze Zahlen potenzieren
int quadriere(int z){
  return z*z;
}

// dritte Potenz
int drittePotenz(int z){
  return z*z*z;
}

// x hoch y, für x,y >= 0
/*
  3 hoch 4 = 1* 3 * 3 * 3 * 3
          --- //trick
  3 hoch 0 = 1
*/  
unsigned long potenziere(int x, int y){// basis, exponent
  unsigned long r = 1;
  for(int i = 0; i < y; i++){
    r *= x;
  }
  return r;
}


