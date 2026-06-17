// ju -- https://bw1.eu -- 17-Jun-26 -- mehrdim-array.c
/* Mehrdimensionale Arrays: 2D-Matrix anlegen und verarbeiten */
#include <stdio.h>

#define ZEILEN  3
#define SPALTEN 4

int main(void) {
  int matrix[ZEILEN][SPALTEN] = {
    {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 },
  };

  // Ausgabe als Tabelle
  printf("Matrix %dx%d:\n", ZEILEN, SPALTEN);
  for (int z = 0; z < ZEILEN; z++) {
    for (int s = 0; s < SPALTEN; s++) {
      printf("%4d", matrix[z][s]);
    }
    printf("\n");
  }

  // Zeilensummen berechnen
  printf("\nZeilensummen:\n");
  for (int z = 0; z < ZEILEN; z++) {
    int summe = 0;
    for (int s = 0; s < SPALTEN; s++) summe += matrix[z][s];
    printf("Zeile %d: %d\n", z, summe);
  }
  return 0;
}
