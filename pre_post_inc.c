/* pre_post_inc.c : uso degli operatori ++ e -- */

#include <stdio.h>

int main(void) {
    int a = 0;
    int b = a++;
    int c = --b;
    int d = (++c) + 5;

    printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
    
    return 0;
}
