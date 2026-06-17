// ju -- https://bw1.eu -- 26-Dez-18  -- array.c 
#include <stdio.h>
//#include "funktionen.h" // eig. Bibliothek
int main(void){
	// Array - Variablenketten
	printf("Array - Variablenketten\n");
	int iArray[3] = {10, 20, 30};
	for(int i=0;i<3;i++){
		printf("%d (Element) - %d (Index) - %d (Inhalt)\n",i+1, i, iArray[i]);
	}
	printf("%p (Adresse)\n", iArray);
	return 0;
}
