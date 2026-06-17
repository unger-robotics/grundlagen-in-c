// ju -- https://bw1.eu -- 6-Jan-19  -- struct-led.c 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include "funktionen.h" // eig. Bibliothek
struct ledTyp{// neuer Datentyp
	// Eigenschaften: Name, Farbe, Zustand
	char name[20];
	int color;
	bool state;
};
#define GREEN 1;
#define RED   2;
int main(void){
	// structs - Strukturen
	printf("structs - Strukturen\n");

  struct ledTyp led1, led2;// variablen anlegen
	// Zugriff led1
	strcpy(led1.name, "led1");
	led1.color = GREEN;
	led1.state = 1; // ON
	// Zugriff led2
	strcpy(led2.name, "led2");
	led2.color = RED;
	led2.state = 0; // ON
	// Ausgabe 
	printf("%s %d %d\n", led1.name, led1.color, led1.state);
  printf("%s %d %d\n", led2.name, led2.color, led2.state);

	return 0;
}
