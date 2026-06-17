// ju -- https://bw1.eu -- 26-Dez-18  -- string.c 
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek
int main(void){
	// String
	char *msg = "String";
	printf("%s\n", msg);
	// Zeichenkette
	char var[12] = "Hallo Welt!";
	printf("%s\n", var);
	for(int i=0;i<12;i++){
		printf("var[%i] = %c\n", i, var[i]);
	}
	// ASCII
	printf("\nASCII-Code\n");
	for(int i=33;i<127;i++){
		printf("Dez %i = Hex 0x%x  = ASCII %c\n", i, i, i);
	}
	// Klein - Grossschreibung
	printf("\nKlein-Grossschreibung:\n");
	char wertGross[2] = "A";  // [2]: Zeichen + abschliessendes Nullbyte
	char wertKlein[2] = "a";
	char kleinschreibung = wertGross[0] + 32;
	char grossschreibung = wertKlein[0] - 32;
	printf("wertGross: %c = %d\n", wertGross[0], wertGross[0]);
  printf("wertKlein: %c = %d\n", wertKlein[0], wertKlein[0]);
	printf("wertGross: %c -> kleinschreibung: %c\n", wertGross[0], kleinschreibung);
	printf("wertKlein: %c -> grossschreibung: %c\n", wertKlein[0], grossschreibung);
	return 0;
}
