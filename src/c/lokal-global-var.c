// ju -- https://bw1.eu -- 26-Dez-18  -- lokal-global-var.c 
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek
int var1 = 0;// global
int main(void){
  // lokale-globale-Variablen
  var1 = 21;    // ok
  int var1 = 23;// Fehler, weil global
  int var2 = 22;// lokal
	printf("lokale-globale-Variablen\n");
  printf("var1 = %i, var2 = %i", var1, var2);
	return 0;
}
