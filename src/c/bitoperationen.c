// ju -- https://bw1.eu -- 17-Jun-26 -- bitoperationen.c
/* Bitweise Operatoren: & | ^ ~ << >> sowie Bitmasken/Flags */
#include <stdio.h>

// Bitmuster einer 8-Bit-Zahl ausgeben (hoechstes Bit zuerst)
void zeigeBits(unsigned char z) {
  for (int i = 7; i >= 0; i--) {
    putchar((z >> i) & 1 ? '1' : '0');
  }
}

// Einzelne Rechte als Flags (jeweils eine Zweierpotenz)
#define LESEN     (1u << 0)   // 0001
#define SCHREIBEN (1u << 1)   // 0010
#define LOESCHEN  (1u << 2)   // 0100

int main(void) {
  unsigned char a = 0x35;   // 0011 0101 = 53
  unsigned char b = 0x0F;   // 0000 1111 = 15

  printf("a      = "); zeigeBits(a);                    printf(" (%d)\n", a);
  printf("b      = "); zeigeBits(b);                    printf(" (%d)\n", b);
  printf("a & b  = "); zeigeBits(a & b);                printf("\n");
  printf("a | b  = "); zeigeBits(a | b);                printf("\n");
  printf("a ^ b  = "); zeigeBits(a ^ b);                printf("\n");
  printf("~a     = "); zeigeBits((unsigned char)~a);    printf("\n");
  printf("a << 1 = "); zeigeBits((unsigned char)(a << 1)); printf("\n");
  printf("a >> 1 = "); zeigeBits(a >> 1);               printf("\n");

  // Flags setzen und einzeln abfragen
  unsigned int rechte = 0;
  rechte |= LESEN;        // Recht hinzufuegen
  rechte |= SCHREIBEN;
  printf("\nRechte: lesen=%d schreiben=%d loeschen=%d\n",
         (rechte & LESEN)     != 0,
         (rechte & SCHREIBEN) != 0,
         (rechte & LOESCHEN)  != 0);
  return 0;
}
