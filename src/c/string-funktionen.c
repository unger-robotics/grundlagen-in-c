// ju -- 17-Jun-26 -- string-funktionen.c
/*
  Die Standardbibliothek <string.h> bietet Funktionen fuer C-Strings
  (char-Arrays, die mit '\0' enden). Wichtigste Falle: das ZIEL muss gross
  genug sein -- inklusive Platz fuer das abschliessende '\0'. Schreibt man
  ueber das Array hinaus, ist das ein Pufferueberlauf (haeufige Sicherheitsluecke).
*/
#include <stdio.h>
#include <string.h>

int main(void) {
  char text[] = "Hallo Welt";

  // --- strlen: Laenge OHNE das '\0' ---
  // "Hallo Welt" = 10 Zeichen; das Array selbst belegt 11 Bytes (mit '\0').
  printf("strlen(\"%s\") = %zu\n", text, strlen(text));  // 10

  // --- strcmp: vergleicht zeichenweise, 0 = gleich ---
  // Rueckgabe ist < 0 / 0 / > 0 (nicht nur 0/1!). Beliebter Anfaengerfehler:
  // if (strcmp(a,b)) ist WAHR, wenn die Strings UNGLEICH sind.
  printf("strcmp(\"abc\",\"abc\") = %d\n", strcmp("abc", "abc"));  // 0
  printf("strcmp(\"abc\",\"abd\") = %d\n", strcmp("abc", "abd"));  // negativ

  // --- strcpy / strncpy: kopieren ---
  char ziel[20];
  strcpy(ziel, "kopiert");          // ziel muss gross genug sein!
  printf("strcpy  -> %s\n", ziel);
  // strncpy begrenzt auf n Zeichen und ist damit sicherer gegen Ueberlauf,
  // garantiert aber NICHT das '\0' -- das setzen wir hier von Hand.
  char klein[6];
  strncpy(klein, "abcdefgh", sizeof(klein) - 1);
  klein[sizeof(klein) - 1] = '\0';  // Abschluss sicherstellen
  printf("strncpy -> %s\n", klein); // abcde

  // --- strcat: haengt an (Ziel braucht Platz fuer beide Teile + '\0') ---
  char gruss[32] = "Hallo, ";
  strcat(gruss, "Welt!");
  printf("strcat  -> %s\n", gruss); // Hallo, Welt!

  // --- strchr: sucht ein Zeichen, liefert Zeiger darauf oder NULL ---
  char *p = strchr(text, 'W');
  if (p != NULL) {
    // Zeiger-Differenz = Position im String (0-basiert): 'W' steht an Index 6
    printf("strchr  -> 'W' an Index %ld\n", (long)(p - text));  // 6
  }
  return 0;
}
