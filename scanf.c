#include <stdio.h>

/*
 * 1) Return value of scanf(): Number of receiving arguments successfully assigned (which may be zero in case a matching failure
 * occurred before the first receiving argument was assigned), or EOF if input failure 
 * occurs before the first receiving argument was assigned.
 * 
 * 2) How does scanf() behave in case of input failure? When scanf() sees a character that does not match the format,
 * it returns and leaves such a character on the input stream, which is not consumed. So, further calls of scanf()
 * would start consuming from that input.
 * You can test this behaviour by running:
 * ```
 *   $ ./a.out
 *   7
 *   Number of correctly assigned variables: 0
 *   User entered 21880 and 0.000000
 *   New d: whatever
 *   Number of correctly assigned variables: 1
 *   User overwrite d to 7
 *  ```
 */

int main(){
    int d;
    float f;
    // Cosa succede se si usano stringhe di formattazione di input non limitate al dato da leggere?
    int n = scanf("Numero: %d\n\n%f", &d, &f);
    // User must type: "Numero: 5 7.7" (without quotes)
    // Any whitespace, \n, or \t in format string matches 0+ whitespace-like characters
    printf("Number of correctly assigned variables: %d\n", n);
    printf("User entered %d and %f\n", d, f);
    printf("New d: ");
    n = scanf("%d\n", &d);
    // Note: a trailing \n in the scanf format string matches an arbitrary number of whitespace until a non-whitespace char appears
    // https://stackoverflow.com/questions/23033265/how-scanf-works-if-i-add-a-new-line-n-at-the-end
    printf("Number of correctly assigned variables: %d\n", n);
    printf("User overwrote d to %d\n", d);    
    return 0;
}