/* Valutazione di espressioni */

#include <stdio.h>

int main(void) {
    1 && printf("A1") && printf("A2");
    5 || printf("B1") || printf("B2");
    0 && printf("C1") && printf("C2");
    0 || printf("D1") || printf("D2");
    printf("\n");
}
