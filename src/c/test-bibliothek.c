// ju -- https://bw1.eu -- 26-Dez-18  -- test-bibliothek.c 
#include <stdio.h>
#include "funktionen.h" // eig. Bibliothek
int main(void){
  // Test Bibliothek
	printf("Test Bibliothek:\n\n");
  int zahl = 2;// Eingabe
  int erg = quadriere(zahl);// ganze Zahlen potenzieren
  printf("ganze Zahlen potenzieren\n");
  printf("%i * %i = %i", zahl, zahl, erg);
	return 0;
}
