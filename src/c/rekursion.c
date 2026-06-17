// ju -- 17-Jun-26 -- rekursion.c
/*
  Rekursion = eine Funktion ruft sich selbst auf. Zwei Bestandteile sind PFLICHT:
    1. Basisfall          -> beendet die Rekursion (sonst endlos -> Absturz)
    2. Rekursionsschritt  -> ruft sich mit einem "kleineren" Problem erneut auf
  Beispiel Fakultaet: n! = n * (n-1)!, und 0! = 1! = 1 (Basisfall).
  Jede Rekursion laesst sich auch iterativ (mit Schleife) schreiben -- darum hier
  beide Varianten zum Vergleich.
*/
#include <stdio.h>
#include "funktionen.h"   // eig. Bibliothek: fac() ist dort selbst rekursiv

// rekursiv: ruft sich mit n-1 erneut auf, bis der Basisfall greift
unsigned long fakultaet_rekursiv(int n) {
  if (n <= 1) return 1;                                   // Basisfall
  return (unsigned long)n * fakultaet_rekursiv(n - 1);    // Rekursionsschritt
}

// iterativ: dasselbe Ergebnis mit einer Schleife, ohne Selbstaufruf
unsigned long fakultaet_iterativ(int n) {
  unsigned long ergebnis = 1;
  for (int i = 2; i <= n; i++) {
    ergebnis *= (unsigned long)i;
  }
  return ergebnis;
}

// Fibonacci: f(n) = f(n-1) + f(n-2), mit f(0)=0, f(1)=1 (zwei Basisfaelle).
// Anschaulich, aber langsam: jeder Aufruf verzweigt sich in zwei weitere.
unsigned long fibonacci(int n) {
  if (n < 2) return (unsigned long)n;                     // Basisfaelle
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
  int n = 5;

  // --- Fakultaet: drei Wege, dasselbe Ergebnis (120) ---
  printf("Fakultaet von %d:\n", n);
  printf("  rekursiv      = %lu\n", fakultaet_rekursiv(n));   // 120
  printf("  iterativ      = %lu\n", fakultaet_iterativ(n));   // 120
  printf("  fac() aus Bib = %d\n", fac(n));                   // 120 (Bibliothek)

  // --- Fibonacci-Folge 0..9 ---
  printf("Fibonacci 0..9: ");
  for (int i = 0; i < 10; i++) {
    printf("%lu ", fibonacci(i));   // Ausgabe: 0 1 1 2 3 5 8 13 21 34
  }
  printf("\n");
  return 0;
}
