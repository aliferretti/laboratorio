#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int sizea, int sizeb);
void print_array(int *a, int size);
int matrix_equals(int **a, int **b, int a_rows, int a_cols, int b_rows, int b_cols); // controlla l'uguaglianza di due matrici
void free_matrix(int **a, int a_rows); // libera la memoria associata a una matrice
void print_matrix(int **a, int a_rows, int a_cols); // stampa in stdout una matrice
int **make_matrix(int rows, int cols, int elem); // costruisce una matrice di `rows` righe e `cols` colonne, con ogni cella inizializzata a `elem`
int **build_matrix(int rows, int cols, int *elems); // costruisce una matrice di `rows` righe e `cols` colonne, con contenuto fornito sequenzialmente dall'array `elems`
int check(char* name, int** input, int N, int M,  int** exp); // funzione di test

/*
Implementare una funzione f(matrix, N, M) che 

- accetta in ingresso una matrice N x M di interi  e
- modifica sul posto la matrice in modo che le colonne siano ordinate sulla base del totale della somma dei loro elementi

In altre parole, un'invocazione f(matrix, 4, 3) con 
             | 0, 1, 0 |
    matrix = | 3, 7, 8 |
             | 0, 5, 0 |
             | 1, 1, 1 |
deve modificare sul posto la matrice affinché
             | 0, 8, 1 |    
    matrix = | 3, 0, 7 |    
             | 0, 1, 5 |    
             | 1, 0, 1 |
               ^  ^  ^___________ questa colonna ha somma 14
               ^  ^__________ questa colonna ha somma 9
               ^___________ questa colonna ha somma 4


Osservazioni e consigli:

* SUGGERIMENTO: Si faccia riferimento alle funzioni di test/verifica per esempi di funzionamento
* SUGGERIMENTO: si suggerisce di compilare con opzione -Wall per ottenere tutti i warning del compilatore: gcc -Wall source.c

NOTE GENERALI:

*) ATTENZIONE: la propria soluzione va inserita nella porzione del sorgente inclusa tra i commenti single-line
`// STUDENT-SOLUTION-START` e  `// STUDENT-SOLUTION-END`.
Codice scritto al di fuori di tali commenti non sarà considerato durante la valutazione.
*) E' possibile definire più funzioni ausiliarie qualora lo si ritenga opportuno. 
Ma lo si faccia all'interno dei commenti, come indicato nel punto precedente.
*) ATTENZIONE: la soluzione verrà confrontata con quella dei colleghi mediante strumenti automatici al fine
di rilevare potenziali copiature. Il controllo è resistente a rename di variabili, spezzamento di espressioni etc.
Qualora vengano riscontrate similarità importanti, è possibile che la prova possa venire annullata, e che ulteriori
modalità di verifica di competenze (ad es., prove orali) siano attuate.
*/
// STUDENT-SOLUTION-START
int matrix_col_sum(int **matrix, int col, int colsize) {
    int sum = 0;
    for(int i=0; i<colsize; i++) {
        sum += matrix[i][col];
    }
    return sum;
}

void matrix_column_copy(int **matrix, int col, int *dest, int colsize) {
    for(int i=0; i<colsize; i++) {
        dest[i] = matrix[i][col];
    }
}

void matrix_column_swap(int **matrix, int N, int M, int col1, int col2) {
    int temp_col[N];
    matrix_column_copy(matrix, col1, temp_col, N);
    int to_be_moved[N];
    matrix_column_copy(matrix, col2, to_be_moved, N);
    for(int r=0; r<N; r++) {
        matrix[r][col1] = to_be_moved[r];
        matrix[r][col2] = temp_col[r];
    }
}

void f(int **matrix, int N, int M) {
    int sums[M];
    for(int i = 0; i<M; i++) sums[i] = matrix_col_sum(matrix, i, N);
    int sorted_cols_indices[M];
    for(int i=0; i<M; i++) {
        sorted_cols_indices[i] = i;
    }
    for(int i=0; i<M; i++) {
        int min_col = i;
        for(int j=i; j<M; j++) {
            if(sums[sorted_cols_indices[j]] < sums[sorted_cols_indices[min_col]]) min_col = j;
        }
        int temp = sorted_cols_indices[i];
        sorted_cols_indices[i] = sorted_cols_indices[min_col];
        sorted_cols_indices[min_col] = temp;
    }
    // crea la matrice ordinata
    int sorted_matrix[N][M]; // = make_matrix(N, M, 0);
    for(int c=0; c<M; c++) {
        int col_idx = sorted_cols_indices[c];
        for(int r=0; r<N; r++) {
            sorted_matrix[r][c] = matrix[r][col_idx];
        }
    }
    // copia nella matrice in input
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++) {
            matrix[r][c] = sorted_matrix[r][c];
        }
    }
    // libera la memoria della matrice 
    // free_matrix(sorted_matrix, N);
}

// STUDENT-SOLUTION-END

void test() {
    // Caso 0: esempio base (già presente)
    int** m0 = build_matrix(4, 3, (int[]) {
        0, 1, 0,
        3, 7, 8,
        0, 5, 0,
        1, 1, 1
    });
    int** exp0 = build_matrix(4, 3, (int[]) {
        0, 0, 1,
        3, 8, 7,
        0, 0, 5,
        1, 1, 1
    });
    check("Example from instructions", m0, 4, 3, exp0);

    // Caso 1: righe con somma uguale
    int** m1 = build_matrix(3, 4, (int[]) {
        1, 1, 1, 1,
        2, 2, 0, 0,
        0, 0, 2, 2
    });
    int** exp1 = build_matrix(3, 4, (int[]) {
        1, 1, 1, 1,
        2, 2, 0, 0,
        0, 0, 2, 2
    });
    check("Equal column sums", m1, 3, 4, exp1);;

    // Caso 2: matrice 1xN
    int** m3 = build_matrix(1, 5, (int[]) {
        4, 3, 2, 1, 0
    });
    int** exp3 = build_matrix(1, 5, (int[]) {
        0, 1, 2, 3, 4
    });
    check("Single row matrix with reverse column order", m3, 1, 5, exp3);

    // Caso 3: matrice vuota
    int** m4 = build_matrix(0, 0, NULL);
    int** exp4 = build_matrix(0, 0, NULL);
    check("Empty matrix (0x0)", m4, 0, 0, exp4);

    // Caso 4: un altro esempio
    int** m5 = build_matrix(3, 2, (int[]) {
        9, 0,
        5, 1,
        0, 0
    });
    int** exp5 = build_matrix(3, 2, (int[]) {
        0, 9,
        1, 5,
        0, 0
    });
    check("Another simple example with 2 cols", m5, 3, 2, exp5);

    // Caso 6: colonna singola
    int** m6 = build_matrix(3, 1, (int[]) {
        0, 
        1,
        5
    });
    int** exp6 = build_matrix(3, 1, (int[]) {
        0,
        1,
        5
    });
    check("Single column", m6, 3, 1, exp6);
}


int n_tests = 0, n_succ_tests = 0;

int main(){
    test();
    printf("=== SUCCESS %d OUT OF %d TESTS ===\n", n_succ_tests , n_tests);
    return 0;
}


int check(char* name, int** input, int N, int M, int** exp) {
    printf("\n-----------------\nTEST %d: %s\n-----------------\n", n_tests++, name);
    printf("Input:\n");
    print_matrix(input, N, M);
    puts("");
    f(input, N, M);
    int success = matrix_equals(input, exp, N, M, N, M);
    printf("Output:\n");
    print_matrix(input, N, M);
    puts("");
    if(!success){
        printf("Result: FAIL\n");
        printf("Actual:\n");
        print_matrix(input, N, M);
        printf("\nExpected:\n");
        print_matrix(exp, N, M);
    } else {
        n_succ_tests++;
        printf("Result: OK\n");
    }
    printf("\n");
    free_matrix(input, N);
    free_matrix(exp, N);
    return success;
}

int **make_matrix(int rows, int cols, int elem) {
    int** m = (int **) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        m[i] = (int *) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            m[i][j] = elem;
        }
    }
    return m;
}

int **build_matrix(int rows, int cols, int *elems) {
    int** m = (int **) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        m[i] = (int *) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            m[i][j] = elems[i * cols + j];
        }
    }
    return m;
}

int matrix_equals(int **a, int **b, int a_rows, int a_cols, int b_rows, int b_cols) {
    if(a_rows != b_rows || a_cols != b_cols) return FALSE;
    if(a == NULL || b == NULL) return a==b;
    for (int i=0; i<a_rows && i<b_rows; i++) {
        for(int j=0; j<a_cols && j<b_cols; j++) {
            if(a[i][j] != b[i][j]) return FALSE;
        }
    }
    return TRUE;
}


void free_matrix(int **a, int a_rows) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        free(a[i]);
    }
    free(a);
}

void print_matrix(int **a, int a_rows, int a_cols) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        printf("| ");
        for(int j=0; j<a_cols; j++) {
            printf("%2d ", a[i][j]);
        }
        printf(" |\n");
    }
}

int array_equals(int a[], int b[], int sizea, int sizeb){
    if(a == b) return FALSE;  // shouldn't pass the same array
    if(a == NULL || b == NULL) return FALSE;
    if(sizea != sizeb) return FALSE;
    for (; sizea--;)
        if (a[sizea] != b[sizea])
            return FALSE;
    return TRUE;
}

void print_array(int *a, int size){
    if(a == NULL) {
        printf("NULL");
        return;
    }
    int i;
    printf("[");
    for (i=0; i<size; i++) printf("%d%s", a[i], i<size-1 ? "," : "");
    printf("]");
} 
