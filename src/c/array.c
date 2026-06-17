// ju -- 26-Dez-18 -- array.c
/*
  Array = mehrere Werte gleichen Typs unter EINEM Namen, fortlaufend im
  Speicher abgelegt. Der Zugriff erfolgt ueber einen Index, der bei 0 beginnt:
  iArray[0] ist das erste, iArray[2] das dritte (= letzte) Element.
  Warum 0-basiert? Der Index ist der Abstand zum Anfang -- das erste Element
  liegt am Anfang, hat also Abstand 0.
*/
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek (hier nicht genutzt)
int main(void){
	// Array - Variablenketten
	printf("Array - Variablenketten\n");

	// 3 ganze Zahlen anlegen und sofort mit Werten fuellen (Initialisierung).
	int iArray[3] = {10, 20, 30};

	// Die Schleife laeuft von Index 0 bis 2, denn die Bedingung ist i < 3.
	// Off-by-one-Falle: iArray[3] gehoert NICHT mehr zum Array -- ein Array der
	// Groesse 3 hat nur die Indizes 0, 1, 2. Zugriff darueber hinaus ist ein Fehler.
	for(int i=0;i<3;i++){
		// Ausgabe z.B.: "1 (Element) - 0 (Index) - 10 (Inhalt)"
		// Element = menschliche Zaehlung (1..3), Index = technische Zaehlung (0..2)
		printf("%d (Element) - %d (Index) - %d (Inhalt)\n",i+1, i, iArray[i]);
	}

	// Der Array-Name allein steht fuer die Adresse des ERSTEN Elements
	// (gleichbedeutend mit &iArray[0]). So werden Arrays auch an Funktionen uebergeben.
	printf("%p (Adresse des 1. Elements)\n", iArray);
	return 0;
}
