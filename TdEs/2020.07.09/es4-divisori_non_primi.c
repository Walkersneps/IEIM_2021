/* Si scriva una funzione in C che,
 * dato un numero N intero positivo,
 * restituisca al chiamante tutti i suoi divisori non primi.
*/


char isPrimo(int n);

/* Inserisce in _divisoriNonP[]_ tutti i divisori non primi di _N_.
 * Ritorna il numero di divisori calcolati.
 *   NB: non è cura della funzione assicurarsi che _divisoriNonP[]_ sia ampia a sufficienza.
*/
int calcolaDivisoriNonPrimi(int N, int divisoriNonPrimi[]) {
    int indx = 0;
    for (int j = 4; j <= N; j++) { // parto da 4 perché 1,2,3 sono primi
        if (N % j == 0) { // j è divisore di N
            if (!isPrimo(j)) {
                divisoriNonPrimi[indx] = j;
                indx++;
            }
        }
    }
    return indx;
}


char isPrimo(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0) // i è divisore di n
            return 0;
    return 1;
}



// Verifico
#include <stdio.h>
int main() {
    int N, ndiv;
    do {
        printf("\nInserisci un numero N = ");
        scanf("%d", &N);
    } while (N < 1);
    int divs[N]; // N avrà al più N divisori

    ndiv = calcolaDivisoriNonPrimi(N, divs);

    printf("\nI divisori non primi di %d sono: ", N);
    for (int k = 0; k < ndiv; k++) printf("%d ", divs[k]);
    printf("\n\n");

    return 0;
}