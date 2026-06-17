// ju -- 17-Jun-26 -- test-bibliothek.c
/* Selbsttest der eig. Bibliothek (Logik): prueft jede Funktion gegen
   bekannte Erwartungswerte. Exit 0 = alle bestanden, sonst Exit 1
   (so erkennt auch die CI Logikfehler). */
#include <stdio.h>
#include "funktionen.h" // eig. Bibliothek

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

int main(void) {
  printf("Test Bibliothek (Logik):\n\n");

  // Fakultaet -- inkl. Randfall i <= 0 -> 1
  pruefe("fac(0)", 1, fac(0));
  pruefe("fac(1)", 1, fac(1));
  pruefe("fac(5)", 120, fac(5));
  pruefe("fac(-3)", 1, fac(-3));

  // Quersumme in beliebigem Zahlensystem
  pruefe("quersumme(26,10)", 8, quersumme(26, 10));    // 2+6
  pruefe("quersumme(123,10)", 6, quersumme(123, 10));  // 1+2+3
  pruefe("quersumme(7,2)", 3, quersumme(7, 2));        // 111b -> 1+1+1
  pruefe("quersumme(255,16)", 30, quersumme(255, 16)); // FF -> 15+15
  pruefe("quersumme(0,10)", 0, quersumme(0, 10));      // Schleife laeuft 0-mal

  // Quadrat
  pruefe("quadriere(2)", 4, quadriere(2));
  pruefe("quadriere(0)", 0, quadriere(0));
  pruefe("quadriere(-3)", 9, quadriere(-3));

  // dritte Potenz
  pruefe("drittePotenz(3)", 27, drittePotenz(3));
  pruefe("drittePotenz(-2)", -8, drittePotenz(-2));
  pruefe("drittePotenz(0)", 0, drittePotenz(0));

  // x hoch y
  pruefe("potenziere(3,4)", 81, (long)potenziere(3, 4));
  pruefe("potenziere(2,10)", 1024, (long)potenziere(2, 10));
  pruefe("potenziere(5,0)", 1, (long)potenziere(5, 0)); // Exponent 0
  pruefe("potenziere(1,100)", 1, (long)potenziere(1, 100));

  printf("\n%d von %d Tests bestanden.\n", tests - fehler, tests);
  return fehler != 0;
}
