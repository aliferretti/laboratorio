/* Dimensione in byte dei principali tipi di dato */

#include <stdio.h>

int main(void) {
    printf("Size of char is %lu\n",          sizeof(char));
    printf("Size of short int is %lu\n",     sizeof(short int));
    printf("Size of int is %lu\n",           sizeof(int));
    printf("Size of long int is %lu\n",      sizeof(long int));
    printf("Size of float is %lu\n",         sizeof(float));
    printf("Size of double is %lu\n",        sizeof(double));
    return 0;
}
