// ju -- 6-Jan-19 -- struct-led.c
/*
  struct = selbst definierter Datentyp, der mehrere Werte (Felder) UNTER-
  schiedlichen Typs zu einer Einheit buendelt. Hier beschreibt "ledTyp" eine
  LED mit Name, Farbe und Zustand. Auf die Felder greift man mit dem Punkt zu:
  led1.color. So lassen sich zusammengehoerige Daten gemeinsam verwalten.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include "funktionen.h" // eig. Bibliothek (hier nicht genutzt)
struct ledTyp { // neuer Datentyp
  // Eigenschaften: Name, Farbe, Zustand
  char name[20];
  int color;
  bool state;
};
// Fallstrick: KEIN Strichpunkt am Ende eines #define! Stuende hier "1;", wuerde
// der Text "1;" ueberall eingesetzt -- in Bedingungen/Ausdruecken bricht das.
#define GREEN 1
#define RED 2
int main(void) {
  // structs - Strukturen
  printf("structs - Strukturen\n");

  struct ledTyp led1, led2; // zwei Variablen dieses Typs anlegen
  // Zugriff led1: name ist ein festes Array, daher mit strcpy kopieren
  // (ein direktes led1.name = "led1" ist bei Arrays nicht erlaubt).
  strcpy(led1.name, "led1");
  led1.color = GREEN;
  led1.state = 1; // ON
  // Zugriff led2
  strcpy(led2.name, "led2");
  led2.color = RED;
  led2.state = 0; // OFF
  // Ausgabe: state ist ein bool und wird als 1 (ON) bzw. 0 (OFF) gedruckt.
  printf("%s %d %d\n", led1.name, led1.color, led1.state);
  printf("%s %d %d\n", led2.name, led2.color, led2.state);

  return 0;
}
