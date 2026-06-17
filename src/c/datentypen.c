// ju -- https://bw1.eu -- 26-Dez-18  -- datentypen.c 
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "funktionen.h" // eig. Bibliothek
int main(void){
   // Datentypen
   printf("Datentypen\n");
   // char
   printf("         char = %11d bit\n", CHAR_BIT);
   printf("     char_min = %11d\n", CHAR_MIN);
   printf("     char_max = %11d\n", CHAR_MAX);
   printf("unsigned char = %11d\n", UCHAR_MAX);
   // int
   printf("      int_min = %11d\n", INT_MIN);
   printf("      int_max = %11d\n", INT_MAX);
   printf(" unsigned int = %11u\n", UINT_MAX);
   // long
   printf("     long_min = %11ld\n", LONG_MIN);
   printf("     long_max = %11ld\n", LONG_MAX);
   printf("unsigned long = %11lu\n", ULONG_MAX);

   // bits & bytes
   printf("\nbits & bytes\n");
   double byte1 = pow(2, 8);// basis, exponent
   double byte2 = pow(2, 16);// basis, exponent
   double byte3 = pow(2, 32);// basis, exponent
   double byte4 = pow(2, 64);// basis, exponent
   printf(" 8 Bit = %12g = %20.0lf = 1 Byte\n", byte1, byte1);
   printf("16 Bit = %12g = %20.0lf = 2 Bytes\n", byte2, byte2);
   printf("32 Bit = %12g = %20.0lf = 4 Bytes\n", byte3, byte3);
   printf("64 Bit = %12g = %20.0lf = 8 Bytes\n", byte4, byte4);
   return(0);
}