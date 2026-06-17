// ju -- https://bw1.eu -- 17-Jun-26 -- datei-io.c
/* Datei-Ein-/Ausgabe in C: fopen / fprintf / fscanf / fclose */
#include <stdio.h>

int main(void) {
  const char *dateiname = "zahlen.txt";

  // --- Schreiben ---
  FILE *aus = fopen(dateiname, "w");
  if (aus == NULL) {
    perror("Datei zum Schreiben oeffnen");
    return 1;
  }
  for (int i = 1; i <= 5; i++) {
    fprintf(aus, "%d %d\n", i, i * i);   // Zahl und ihr Quadrat
  }
  fclose(aus);
  printf("'%s' geschrieben.\n", dateiname);

  // --- Lesen ---
  FILE *ein = fopen(dateiname, "r");
  if (ein == NULL) {
    perror("Datei zum Lesen oeffnen");
    return 1;
  }
  int zahl, quadrat;
  printf("Inhalt:\n");
  while (fscanf(ein, "%d %d", &zahl, &quadrat) == 2) {
    printf("  %d^2 = %d\n", zahl, quadrat);
  }
  fclose(ein);
  return 0;
}
