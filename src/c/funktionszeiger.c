// ju -- 17-Jun-26 -- funktionszeiger.c
/* Funktionszeiger und Callbacks */
#include <stdio.h>

int addiere(int a, int b) { return a + b; }
int subtrahiere(int a, int b) { return a - b; }
int multipliziere(int a, int b) { return a * b; }

// nimmt eine Operation (Funktionszeiger) als Parameter -> Callback
int rechne(int a, int b, int (*op)(int, int)) { return op(a, b); }

int main(void) {
  // Variable, die auf eine Funktion zeigt
  int (*operation)(int, int) = addiere;
  printf("3 + 4 = %d\n", operation(3, 4));

  operation = multipliziere;
  printf("3 * 4 = %d\n", operation(3, 4));

  // Tabelle von Funktionszeigern
  int (*ops[])(int, int) = {addiere, subtrahiere, multipliziere};
  const char *namen[] = {"+", "-", "*"};
  for (int i = 0; i < 3; i++) {
    printf("rechne(6, 2) mit '%s' = %d\n", namen[i], rechne(6, 2, ops[i]));
  }
  return 0;
}
