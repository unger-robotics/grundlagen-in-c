// ju -- 17-Jun-26 -- schleifen.c
/*
  Schleifen wiederholen Code. C kennt drei Formen:
    for       -> Zaehlschleife: Anzahl der Durchlaeufe meist im Voraus bekannt
    while     -> kopfgesteuert: prueft VOR dem Durchlauf -> evtl. 0 Durchlaeufe
    do-while  -> fussgesteuert: prueft NACH dem Durchlauf -> mind. 1 Durchlauf
  break beendet die Schleife sofort, continue springt zum naechsten Durchlauf.
*/
#include <stdio.h>

int main(void) {
  // --- for: zaehlt 1..5 ---
  printf("for:      ");
  for (int i = 1; i <= 5; i++) {
    printf("%d ", i); // Ausgabe: 1 2 3 4 5
  }
  printf("\n");

  // --- while (kopfgesteuert): gleiche Ausgabe, andere Schreibweise ---
  printf("while:    ");
  int i = 1; // Zaehler VOR der Schleife initialisieren
  while (i <= 5) {
    printf("%d ", i);
    i++; // Zaehler MUSS im Rumpf weitergezaehlt werden,
  } // sonst laeuft die Schleife endlos.
  printf("\n");

  // --- do-while (fussgesteuert): laeuft mind. einmal ---
  // Obwohl 99 die Bedingung (<= 5) nicht erfuellt, gibt es genau EINEN Durchlauf,
  // weil erst NACH dem Rumpf geprueft wird. Das ist der Unterschied zu while.
  printf("do-while: ");
  int k = 99;
  do {
    printf("%d ", k); // Ausgabe: 99
  } while (k <= 5);
  printf("\n");

  // --- break / continue ---
  // continue ueberspringt gerade Zahlen, break stoppt komplett bei 7.
  printf("break/continue: ");
  for (int n = 1; n <= 10; n++) {
    if (n % 2 == 0)
      continue; // gerade -> Rest des Rumpfes ueberspringen
    if (n == 7)
      break;          // bei 7 die Schleife ganz verlassen
    printf("%d ", n); // Ausgabe: 1 3 5
  }
  printf("\n");
  return 0;
}
