/* area_triangolo.c: calcola l'area di un triangolo */

#include <stdio.h>

int main(void) {
    float base = 5.0;
    float altezza = 12.0;
    float area;
    area = base * altezza / 2;
    printf("%f\n", area);
    return 0;
}
