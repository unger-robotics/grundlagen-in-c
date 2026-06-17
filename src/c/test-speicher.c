// ju -- 17-Jun-26 -- test-speicher.c
/* Selbsttest der Speicherverwaltung: malloc/realloc/free, verkettete
   Liste und char-Puffer. Prueft Korrektheit der Inhalte UND gibt allen
   Speicher wieder frei. Aussagekraeftig besonders unter AddressSanitizer:
     make clean && make SANITIZE=address,undefined test
   meldet dann Lecks / Use-after-free / Pufferueberlaeufe.
   Exit 0 = alle bestanden, sonst Exit 1. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tests = 0, fehler = 0;

// Einen Einzelwert gegen den Erwartungswert pruefen
static void pruefe(const char *name, long erwartet, long erhalten) {
  tests++;
  if (erwartet == erhalten) {
    printf("[OK]     %s = %ld\n", name, erhalten);
  } else {
    printf("[FEHLER] %s: erwartet %ld, erhalten %ld\n", name, erwartet, erhalten);
    fehler++;
  }
}

// --- verkettete Liste (analog verkettete-liste.c) ---
typedef struct Knoten {
  int wert;
  struct Knoten *next;
} Knoten;

static Knoten *einfuegenVorne(Knoten *kopf, int wert) {
  Knoten *neu = malloc(sizeof(Knoten));
  if (neu == NULL)
    return kopf; // bei Speichermangel Liste unveraendert lassen
  neu->wert = wert;
  neu->next = kopf;
  return neu;
}

static void freigeben(Knoten *kopf) {
  while (kopf != NULL) {
    Knoten *weg = kopf;
    kopf = kopf->next;
    free(weg);
  }
}

int main(void) {
  printf("Test Speicher (malloc/realloc/free, Liste, Puffer):\n\n");

  // 1) malloc -> fuellen -> realloc (waechst) -> alte Werte erhalten -> free
  int n = 5;
  int *feld = malloc(n * sizeof(int));
  if (feld == NULL) {
    fprintf(stderr, "malloc fehlgeschlagen\n");
    return 1;
  }
  for (int i = 0; i < n; i++)
    feld[i] = (i + 1) * (i + 1); // Quadratzahlen 1,4,9,16,25
  pruefe("feld[0] nach malloc", 1, feld[0]);
  pruefe("feld[4] nach malloc", 25, feld[4]);

  n = 8;
  int *groesser = realloc(feld, n * sizeof(int));
  if (groesser == NULL) {
    free(feld); // alten Block bei Fehler freigeben
    fprintf(stderr, "realloc fehlgeschlagen\n");
    return 1;
  }
  feld = groesser;
  for (int i = 5; i < n; i++)
    feld[i] = (i + 1) * (i + 1);
  pruefe("feld[4] nach realloc (erhalten)", 25, feld[4]);
  pruefe("feld[7] nach realloc (neu)", 64, feld[7]);
  free(feld);

  // 2) verkettete Liste: 5 Knoten, Laenge und Summe pruefen, dann freigeben
  Knoten *liste = NULL;
  for (int i = 1; i <= 5; i++)
    liste = einfuegenVorne(liste, i);
  int laenge = 0, summe = 0;
  for (const Knoten *k = liste; k != NULL; k = k->next) {
    laenge++;
    summe += k->wert;
  }
  pruefe("Listenlaenge", 5, laenge);
  pruefe("Listensumme", 15, summe); // 1+2+3+4+5
  freigeben(liste);

  // 3) char-Puffer sicher fuellen (strncpy + manuelles '\0'), kein Ueberlauf
  char puffer[16];
  strncpy(puffer, "Speicher", sizeof(puffer) - 1);
  puffer[sizeof(puffer) - 1] = '\0';
  pruefe("strlen(puffer)", 8, (long)strlen(puffer));
  pruefe("puffer == \"Speicher\"", 0, strcmp(puffer, "Speicher"));

  printf("\n%d von %d Tests bestanden.\n", tests - fehler, tests);
  return fehler != 0;
}
