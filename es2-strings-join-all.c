#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Si realizzi una funzione `join_all(strings, N, sep)` che, dati in ingresso:
 *   - un array `strings` di stringhe qualsiasi
 *   - la dimensione `N` di tale array (ovvero numero di stringhe) 
 *   - una stringa di separazione `sep`
 * produca una NUOVA stringa ottenuta concatenando tutte le stringhe dell'array, separate da `sep`. 
 * 
 * Ad esempio, dato l'array s = { "ciao", "mondo", "!" } contenente N=3 stringhe, e sep="...",
 * la funzione f(s,N,sep) deve restituire la stringa "ciao...mondo...!"
 *
 * Suggerimenti e vincoli:
 * - si faccia attenzione ai caratteri di terminazione delle stringhe
 * 
 * - è possibile, se lo si desidera, usare le funzioni di libreria `strlen`, `strcpy`, o `sprintf`:
 * 
 *      char *strcpy( char *dest, const char *src );
 *              Copies the null-terminated byte string pointed to by src, including the null terminator, 
 *              to the character array whose first element is pointed to by dest.
 * 
 *      size_t strlen( const char *str );
 *              Returns the length of the given null-terminated byte string.
 *              (size_t is an implementation-defined unsigned integer type)
 * 
 *      int sprintf( char *str, const char *format, ... );
 *              Writes formatted string to input str. The function returns the number of characters written,
 * 
 * - la propria soluzione va inserita nella porzione del sorgente inclusa tra i commenti single-line
 *   `// STUDENT-SOLUTION-START` e  `// STUDENT-SOLUTION-END`.
 *   Codice scritto al di fuori di tali commenti non sarà considerato durante la valutazione.
 * 
 * - è possibile ed anche consigliato realizzare funzioni ausiliarie, purche comprese tra la coppia di commenti suddetti
 * 
 * - ATTENZIONE: la soluzione verrà confrontata con quella dei colleghi mediante strumenti automatici al fine 
 *   di rilevare potenziali copiature. Il controllo è resistente a rename di variabili, spezzamento di espressioni etc.
 *   Qualora vengano riscontrate similarità importanti, è possibile che la prova possa venire annullata, e che ulteriori
 *   modalità di verifica di competenze (ad es., prove orali) siano attuate. 
 */

// STUDENT-SOLUTION-START
char *join_all(char** strings, int strings_count, char *sep) {
    return strdup("TODO");
}
// STUDENT-SOLUTION-END

int ntests = 0;
int nsuccess = 0;

int test_join_all(char *test_name, char** strings, int strings_count, char *sep, char *expected) {
    printf("\n-----------------\nTEST %d: %s\n-----------------\n", ntests++, test_name);
    printf("Concatenating the following strings:\n");
    for (int i = 0; i < strings_count; i++) {
        printf("\t- '%s'\n", strings[i]);
    }
    printf("Result:\n");
    printf("\texpected: '%s'\n", expected);
    char *actual = join_all(strings, strings_count, sep);
    if (expected == NULL) {
        printf("\t  actual: NULL\n");
    } else {
        printf("\t  actual: '%s'\n", actual);
    }
    if (strcmp(expected, actual) == 0) {
        printf("OK!\n");
        nsuccess++;
        return 0;
    } else {
        printf("ERROR: unexpected result!\n");
        return 1;
    }
}

int main() {
    int status = 0;
    status |= test_join_all("Test 1: empty sep", (char *[]) { "abc", "ABC", "123" }, 3, "", "abcABC123");
    status |= test_join_all("Test 2: single sep", (char *[]) { "abc", "AB", "1" }, 3, ".", "abc.AB.1");
    status |= test_join_all("Test 3: 2-chars sep", (char *[]) { "a", "AB", "123" }, 3, "--", "a--AB--123");
    status |= test_join_all("Test 4: space sep", (char *[]) { "hello", "world", "!" }, 3, " ", "hello world !");
    status |= test_join_all("Test 5: single string", (char *[]) { "just one" }, 1, " ", "just one");
    status |= test_join_all("Test 6: null input", NULL, 0, "", "");
    status |= test_join_all("Test 7: some empty strings", (char *[]) { "", "ciao", "", "mondo", "" }, 5, "", "ciaomondo");

    printf("\n=== SUCCESS %d OUT OF %d TESTS ===\n", nsuccess , ntests);

    return status;
}
