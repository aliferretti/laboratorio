/* Valutazione di espressioni */

#include <stdio.h>

int main(void) {
    unsigned char c = 23; // 0001 0111
    printf("%x\n", c); // note: print hex representation
    printf("%d\n", c & 14);
    printf("%d\n", c | 8);
    printf("%d\n", c ^ 5);
    printf("%d\n", c << 2);
    printf("%d\n", c >> 1);
}
