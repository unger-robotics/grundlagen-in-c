// ju -- 17-Jun-26 -- suchen.c
/* Suchverfahren: lineare Suche und binaere Suche */
#include <stdio.h>

// Lineare Suche: Element fuer Element pruefen (Feld beliebig)
int lineareSuche(const int *feld, int n, int gesucht) {
  for (int i = 0; i < n; i++) {
    if (feld[i] == gesucht)
      return i; // Index gefunden
  }
  return -1; // nicht gefunden
}

// Binaere Suche: nur auf SORTIERTEM Feld; halbiert den Suchbereich
int binaereSuche(const int *feld, int n, int gesucht) {
  int links = 0, rechts = n - 1;
  while (links <= rechts) {
    int mitte = (links + rechts) / 2;
    if (feld[mitte] == gesucht)
      return mitte;
    if (feld[mitte] < gesucht)
      links = mitte + 1;
    else
      rechts = mitte - 1;
  }
  return -1;
}

int main(void) {
  int feld[] = {1, 3, 5, 7, 9, 11, 13}; // sortiert
  int n = (int)(sizeof(feld) / sizeof(feld[0]));

  int gesucht = 7;
  printf("lineare Suche nach %d: Index %d\n", gesucht, lineareSuche(feld, n, gesucht));
  printf("binaere Suche nach %d: Index %d\n", gesucht, binaereSuche(feld, n, gesucht));

  gesucht = 8;
  printf("binaere Suche nach %d: Index %d (-1 = nicht gefunden)\n", gesucht,
         binaereSuche(feld, n, gesucht));
  return 0;
}
