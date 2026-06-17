// ju -- 17-Jun-26 -- union-typedef.c
/* union: ein Speicherbereich, mehrere Interpretationen
   typedef: eigene Typnamen vergeben                      */
#include <stdio.h>

// typedef + union: dieselben Bytes als int, float oder Byte-Folge lesen
typedef union {
  int ganz;
  float komma;
  unsigned char byte[4];
} Wert;

// typedef erspart das Schluesselwort 'struct' bei jeder Nutzung
typedef struct {
  char name[20];
  int alter;
} Person;

int main(void) {
  Wert w;
  w.ganz = 1078530011; // dieselben 4 Bytes ...
  printf("als int:   %d\n", w.ganz);
  printf("als float: %f\n", w.komma); // ... anders interpretiert
  printf("Bytes:     %u %u %u %u\n", w.byte[0], w.byte[1], w.byte[2], w.byte[3]);
  printf("Groesse der union: %zu Byte\n", sizeof(Wert));

  Person p = {"Willi", 72};
  printf("\nPerson: %s, %d Jahre\n", p.name, p.alter);
  return 0;
}
