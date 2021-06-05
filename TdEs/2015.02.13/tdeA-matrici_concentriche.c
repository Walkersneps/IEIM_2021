/* Esercizio 1
 * Si scriva in C una funzione valoriDiCorniceUguali che
 * data una matrice quadrata M,
 * restituisce 1 se tutti i valori disposti sulla sua cornice più esterna
 * (costituita dalla prima e dall’ultima riga e dalla prima e dall’ultima colonna)
 * sono uguali tra loro, 0 altrimenti.
*/
char valoriDiCorniceUguali(int size, int M[size][size]) {
    for (int c = 0; c < size; c++)
        if (M[0][c] != M[0][0] ||
            M[size-1][c] != M[0][0] ||
            M[c][0] != M[0][0] ||
            M[c][size-1] != M[0][0])
            return 0;
    return 1;
}
 
/* Esercizio 2
 * Si sviluppi in C una funzione ricorsiva corniciConcentriche che,
 * data una matrice quadrata M,
 * restituisca 1 se la matrice è costituita da cornici concentriche,
 * 0 altrimenti. 
*/
char corniciConcentriche(int size, int M[size][size]) {
    if (size < 2) return 1;
    if (valoriDiCorniceUguali(size, M)) {
        if (size == 2) return 1;
        // restringo la matrice e richiamo
        int smaller[size-2][size-2];
        for (int r = 0; r < size-2; r++)
            for (int c = 0; c < size-2; c++)
                smaller[r][c] = M[r+1][c+1];
        return corniciConcentriche(size-2, smaller);
    } else
        return 0;
}


/* Esercizio 3
 * Si scriva in C una funzione che,
 * data una matrice quadrata M,
 * verificato che M è costituita da matrici concentriche,
 * restituisce la trasposta di M
 * (andando a sovrascrivere M – non è possibile usare “matrici di appoggio”).
*/
#include <stdio.h>
void trasposta_inPlace(int size, int M[size][size]) {
    if (!corniciConcentriche(size, M))
        printf("\nLa matrice non e' concentrica. Non verra' eseguita la trasposizione.\n");
    // Nel caso favorevole, la trasposta sarà sempre identica ad M stessa --> non faccio nulla
}





#define s 5
void print_matrix(int dim, int matrix[dim][dim]);
int main() {
    int m[s][s] = { {2, 2, 2, 2, 2},
                    {2, 5, 5, 5, 2},
                    {2, 5, 1, 5, 2},
                    {2, 5, 5, 2, 2},
                    {2, 2, 2, 2, 2}
                };
    int n[s+1][s+1] = { {2, 2, 2, 2, 2, 2},
                        {2, 5, 5, 5, 5, 2},
                        {2, 5, 1, 1, 5, 2},
                        {2, 5, 1, 1, 5, 2},
                        {2, 5, 5, 5, 5, 2},
                        {2, 2, 2, 2, 2, 2}
                };

    printf("\nEs1 dispari ritorna: %d", valoriDiCorniceUguali(s, m));
    printf("\nEs2 dispari ritorna: %d", corniciConcentriche(s, m));
    printf("\n\nEs1 pari ritorna: %d", valoriDiCorniceUguali(s+1, n));
    printf("\nEs2 pari ritorna: %d", corniciConcentriche(s+1, n));

    printf("\nEs3 dispari: \n"); print_matrix(s, m); trasposta_inPlace(s, m);
    printf("\nEs3 dispari: \n"); print_matrix(s+1, n); trasposta_inPlace(s+1, n);


    return 0;
}

void print_matrix(int dim, int matrix[dim][dim]){
    int i,j;
        for(i=0;i<dim;i++){
          for(j=0;j<dim;j++){
            printf(" %d ",matrix[i][j]);
          }
            printf("\n");
    }
}