// ju -- 26-Dez-18 -- string.c
/*
  In C ist ein "String" kein eigener Datentyp, sondern ein Array von char,
  das mit einem unsichtbaren Nullbyte '\0' (ASCII 0) ENDET. Funktionen wie
  printf("%s") lesen Zeichen fuer Zeichen bis zu diesem '\0'. Fehlt es, wird
  ueber das Array hinaus weitergelesen -> Fehler. Darum muss bei char-Arrays
  immer Platz fuer das '\0' eingeplant werden.
*/
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek (hier nicht genutzt)
int main(void){
	// String: msg ist ein Zeiger auf ein konstantes Stringliteral im Speicher.
	char *msg = "String";
	printf("%s\n", msg);

	// Zeichenkette als beschreibbares Array. "Hallo Welt!" sind 11 Zeichen,
	// dazu kommt automatisch das '\0' -> genau 12 Bytes, also passt [12] exakt.
	char var[12] = "Hallo Welt!";
	printf("%s\n", var);
	for(int i=0;i<12;i++){
		// var[11] ist das '\0' und wird als unsichtbares Zeichen ausgegeben.
		printf("var[%i] = %c\n", i, var[i]);
	}
	// ASCII: jedes Zeichen ist intern eine Zahl. 33..126 sind die sichtbaren
	// (druckbaren) Zeichen; 32 ist das Leerzeichen, unter 32 liegen Steuerzeichen.
	printf("\nASCII-Code\n");
	for(int i=33;i<127;i++){
		printf("Dez %i = Hex 0x%x  = ASCII %c\n", i, i, i);
	}
	// Klein - Grossschreibung: Im ASCII liegen Gross- und Kleinbuchstaben genau
	// 32 auseinander ('A'=65, 'a'=97). Darum: +32 macht klein, -32 macht gross.
	printf("\nKlein-Grossschreibung:\n");
	char wertGross[2] = "A";  // [2]: Zeichen + abschliessendes Nullbyte
	char wertKlein[2] = "a";
	char kleinschreibung = wertGross[0] + 32;  // 'A'(65) + 32 = 'a'(97)
	char grossschreibung = wertKlein[0] - 32;  // 'a'(97) - 32 = 'A'(65)
	printf("wertGross: %c = %d\n", wertGross[0], wertGross[0]);
  printf("wertKlein: %c = %d\n", wertKlein[0], wertKlein[0]);
	printf("wertGross: %c -> kleinschreibung: %c\n", wertGross[0], kleinschreibung);
	printf("wertKlein: %c -> grossschreibung: %c\n", wertKlein[0], grossschreibung);
	return 0;
}
