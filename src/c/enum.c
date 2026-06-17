// ju -- https://bw1.eu -- 17-Jun-26 -- enum.c
/* Aufzaehlungstypen (enum): benannte ganzzahlige Konstanten */
#include <stdio.h>

// Ampelzustand -- Werte zaehlen ab 0 automatisch hoch
enum Ampel { ROT, GELB, GRUEN };

// Wochentag -- Startwert frei waehlbar, danach jeweils +1
enum Wochentag { MO = 1, DI, MI, DO, FR, SA, SO };

// Ampelzustand als Text
const char *ampelText(enum Ampel a) {
  switch (a) {
    case ROT:   return "rot";
    case GELB:  return "gelb";
    case GRUEN: return "gruen";
  }
  return "unbekannt";
}

int main(void) {
  printf("Ampel-Werte: ROT=%d GELB=%d GRUEN=%d\n", ROT, GELB, GRUEN);

  for (enum Ampel a = ROT; a <= GRUEN; a++) {
    printf("Ampel %d ist %s\n", a, ampelText(a));
  }

  enum Wochentag heute = MI;
  printf("\nWochentag MI hat den Wert %d\n", heute);
  printf("Wochenende: SA=%d, SO=%d\n", SA, SO);
  return 0;
}
