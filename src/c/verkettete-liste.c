// ju -- 17-Jun-26 -- verkettete-liste.c
/* Einfach verkettete Liste mit dynamischem Speicher (malloc/free) */
#include <stdio.h>
#include <stdlib.h>

// Ein Knoten kennt seinen Wert und den naechsten Knoten
typedef struct Knoten {
  int            wert;
  struct Knoten *next;
} Knoten;

// Neuen Knoten am Anfang einfuegen, gibt den neuen Listenkopf zurueck
Knoten *einfuegenVorne(Knoten *kopf, int wert) {
  Knoten *neu = malloc(sizeof(Knoten));
  if (neu == NULL) return kopf;
  neu->wert = wert;
  neu->next = kopf;
  return neu;
}

void ausgeben(const Knoten *kopf) {
  for (const Knoten *k = kopf; k != NULL; k = k->next) {
    printf("%d -> ", k->wert);
  }
  printf("NULL\n");
}

// Gesamte Liste freigeben
void freigeben(Knoten *kopf) {
  while (kopf != NULL) {
    Knoten *weg = kopf;
    kopf = kopf->next;
    free(weg);
  }
}

int main(void) {
  Knoten *liste = NULL;
  for (int i = 1; i <= 5; i++) {
    liste = einfuegenVorne(liste, i);   // 5,4,3,2,1 (jeweils vorne)
  }
  printf("Liste: ");
  ausgeben(liste);
  freigeben(liste);
  return 0;
}
