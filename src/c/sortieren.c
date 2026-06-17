// ju -- 17-Jun-26 -- sortieren.c
/* Sortieralgorithmen: Bubble-Sort und Selection-Sort */
#include <stdio.h>

void ausgabe(const int *feld, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", feld[i]);
  printf("\n");
}

void tausche(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// Bubble-Sort: benachbarte Elemente vergleichen und ggf. tauschen
void bubbleSort(int *feld, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (feld[j] > feld[j + 1])
        tausche(&feld[j], &feld[j + 1]);
    }
  }
}

// Selection-Sort: kleinstes Element suchen und nach vorne tauschen
void selectionSort(int *feld, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (feld[j] < feld[min])
        min = j;
    }
    tausche(&feld[i], &feld[min]);
  }
}

int main(void) {
  int a[] = {5, 2, 9, 1, 7, 3};
  int b[] = {5, 2, 9, 1, 7, 3};
  int n = (int)(sizeof(a) / sizeof(a[0]));

  printf("Unsortiert:     ");
  ausgabe(a, n);
  bubbleSort(a, n);
  printf("Bubble-Sort:    ");
  ausgabe(a, n);
  selectionSort(b, n);
  printf("Selection-Sort: ");
  ausgabe(b, n);
  return 0;
}
