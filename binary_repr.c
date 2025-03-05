/* binary-repr.c */
#include <stdio.h>

#define print_bin(var) print_binary_representation(sizeof(var), (char*)&var, 1)
void print_binary_representation(size_t size, char *br, int le);

int main( void ) {
  unsigned char x = 129;
  printf("x as unsigned int: %d\n", x);
  printf("x as signed int: %d\n", (signed char)x); // nota: rappr. in complemento a due (per tipi signed)
  printf("x as hex: %x\n", x);
  printf("Binary repr of %d: ", x);
  print_bin(x);
  printf("x as short: ");
  short int x_as_short = x;
  print_bin(x_as_short);
  printf("x as long: ");
  long int x_as_long = x;
  print_bin(x_as_long);

  signed char y = -1;
  printf("Binary repr of -1: ");
  print_bin(y);
  //print_binary_representation(sizeof(y), (char*)&y, 1);

  float f = -2.625;
  printf("Binary repr of -2.625: ");
  print_bin(f);

  double c = 3.14;
  float d = 2.54;	// note: implicit conversion double -> float

  printf("c = %.4f = ", c);
  print_bin(c);

  printf("d = %.4f = ", d);
  print_bin(d);

  printf("\"hello\" = ");
  print_bin("hello"); // cf. extended-ASCII representation

  char false_value = 1 > 5;
  printf("False = %d = ", 1 > 5);
  print_bin(false_value);

  char true_value = 5 > 1; 
  printf("True = %d = ", 5 > 1);
  print_bin(true_value);
}


void print_binary_representation(size_t size, char *br, int le){
  for(int i = le ? size - 1 : 0; le ? i >= 0 : i < size; le ? i-- : i++){
    printf("%u%u%u%u %u%u%u%u ", 
      br[i] & 128 ? 1 : 0, 
      br[i] & 64 ? 1 : 0, 
      br[i] & 32 ? 1 : 0, 
      br[i] & 16 ? 1 : 0,
      br[i] & 8 ? 1 : 0, 
      br[i] & 4 ? 1 : 0, 
      br[i] & 2 ? 1 : 0, 
      br[i] & 1 ? 1 : 0);
  }
  puts("");
}
