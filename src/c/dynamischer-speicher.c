// ju -- 17-Jun-26 -- dynamischer-speicher.c
/* Dynamische Speicherverwaltung: malloc / realloc / free */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 5;

  // Speicher fuer n ints zur Laufzeit anfordern
  int *feld = malloc(n * sizeof(int));
  if (feld == NULL) {
    fprintf(stderr, "Speicher konnte nicht reserviert werden\n");
    return 1;
  }
  for (int i = 0; i < n; i++) feld[i] = (i + 1) * (i + 1);  // Quadratzahlen

  printf("Feld (%d Elemente): ", n);
  for (int i = 0; i < n; i++) printf("%d ", feld[i]);
  printf("\n");

  // Feld vergroessern -- realloc behaelt die bisherigen Werte
  n = 8;
  int *groesser = realloc(feld, n * sizeof(int));
  if (groesser == NULL) {
    free(feld);
    fprintf(stderr, "realloc fehlgeschlagen\n");
    return 1;
  }
  feld = groesser;
  for (int i = 5; i < n; i++) feld[i] = (i + 1) * (i + 1);

  printf("Feld (%d Elemente): ", n);
  for (int i = 0; i < n; i++) printf("%d ", feld[i]);
  printf("\n");

  free(feld);   // angeforderten Speicher immer wieder freigeben!
  return 0;
}
