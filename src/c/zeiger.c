// ju -- 6-Jan-19 -- zeiger.c
/*
  Zeiger (Pointer) speichern nicht einen Wert, sondern die ADRESSE eines Wertes.
  Zwei Operatoren gehoeren dazu:
    &var   -> "Adresse von var"   (Referenzierung)
    *zeiger-> "Inhalt an der Adresse" (Dereferenzierung)
  Deklaration: int *p;  bedeutet "p ist ein Zeiger auf int".
  Merksatz: ueber einen Zeiger kann man die Originalvariable veraendern, ohne
  ihren Namen zu kennen -- das ist die Grundlage fast aller C-Datenstrukturen.
*/
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek (hier nicht genutzt)
int main(void){
	// Zeiger - Pointer
  printf("Zeiger - Pointer\n");
  int var1 = 14;// lokale Variable mit Inhalt
  int var2 = 10;
  int var3 = 11;

  // iPointer zeigt jetzt auf var1: er enthaelt die Adresse von var1.
  int *iPointer = &var1;// Adresse wird in Zeigervariable vom Typ int gespeichert
  // %p gibt die Adresse aus, *iPointer den Inhalt an dieser Adresse (= 14).
  printf("var1 (Variable) = %d (Inhalt) = %p (%%p - Adresse) = %d (*iPointer - Inhalt)\n", var1, iPointer, *iPointer);

  // Schreiben ueber den Zeiger: *iPointer = 20 aendert var1 selbst!
  *iPointer = 20;// neuer Inhalt wird der Adresse zugewiesen -> var1 ist nun 20
  printf("var1 (Variable) = %d (Inhalt) = %p (%%p - Adresse) = %d (*iPointer - Inhalt)\n", var1, iPointer, *iPointer);

  int *iPointer2 = &var2;
  int *iPointer3 = &var3;
  // Variable - Inhalt - Adresse

  printf("var2 (Variable) = %d (Inhalt) = %p (Adresse)\n", var2, iPointer2);
  printf("var3 (Variable) = %d (Inhalt) = %p (Adresse)\n", var3, iPointer3);

  // Zeiger-Arithmetik: iPointer2+1 zaehlt NICHT +1 Byte, sondern +1 Element,
  // also um sizeof(int) Bytes (meist 4) weiter. Die Adresse springt entsprechend.
  // ACHTUNG Unterschied: *iPointer2+1 wird als (*iPointer2)+1 gelesen -- erst
  // den Inhalt holen (10), dann +1 = 11. Das hat nichts mit der Adresse zu tun.
  printf("%p (Adresse +1) = %d\n", iPointer2+1, *iPointer2+1);
  printf("%p (Adresse)    = %d\n", iPointer2, *iPointer2);
  printf("%p (Adresse -1) = %d\n", iPointer2-1, *iPointer2-1);
  // Variable - Inhalt - Adresse
  printf("var1 (Variable) = %d (Inhalt) = %p (Adresse)\n", var1, iPointer);
  printf("var2 (Variable) = %d (Inhalt) = %p (Adresse)\n", var2, iPointer2);
  printf("var3 (Variable) = %d (Inhalt) = %p (Adresse)\n", var3, iPointer3);



	return 0;
}
