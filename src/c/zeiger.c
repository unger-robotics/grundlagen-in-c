// ju -- https://bw1.eu -- 6-Jan-19  -- zeiger.c 
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek
int main(void){
	// Zeiger - Pointer
  printf("Zeiger - Pointer\n");
  int var1 = 14;// lokale Variable mit Inhalt
  int var2 = 10;
  int var3 = 11;
  /*Zeiger = Pointer
    &var1 = Zugriff auf Adresse
    *var1 = Zugriff auf Inhalt
    int *iPointer = Zeiger auf Integervariable
    int *iPointer = &var1 //Adressen können in Zeigervariablen gespeichert werden
    *iPointer = 20 // neuer Inhalt wird auf Speicherstelle zugewiesen
  */
  int *iPointer = &var1;// Adresse wird in Zeigervariable vom Typ int gespeichert
  printf("var1 (Variable) = %d (Inhalt) = %p (%%p - Adresse) = %d (*iPointer - Inhalt)\n", var1, iPointer, *iPointer);
  *iPointer = 20;// neuer Inhalt wird der Adresse zugewiesen
  printf("var1 (Variable) = %d (Inhalt) = %p (%%p - Adresse) = %d (*iPointer - Inhalt)\n", var1, iPointer, *iPointer);
  int *iPointer2 = &var2;
  int *iPointer3 = &var3;
  // Variable - Inhalt - Adresse
  
  printf("var2 (Variable) = %d (Inhalt) = %p (Adresse)\n", var2, iPointer2);
  printf("var3 (Variable) = %d (Inhalt) = %p (Adresse)\n", var3, iPointer3);
  // Adresse - Inhalt
  printf("%p (Adresse +1) = %d\n", iPointer2+1, *iPointer2+1);
  printf("%p (Adresse)    = %d\n", iPointer2, *iPointer2);
  printf("%p (Adresse -1) = %d\n", iPointer2-1, *iPointer2-1);
  // Variable - Inhalt - Adresse
  printf("var1 (Variable) = %d (Inhalt) = %p (Adresse)\n", var1, iPointer);
  printf("var2 (Variable) = %d (Inhalt) = %p (Adresse)\n", var2, iPointer2);
  printf("var3 (Variable) = %d (Inhalt) = %p (Adresse)\n", var3, iPointer3);



	return 0;
}
