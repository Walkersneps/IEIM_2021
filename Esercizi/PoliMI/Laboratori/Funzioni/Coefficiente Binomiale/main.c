/* Si scriva un programma che, dati due interi positivi _n_ e _k_ in input,
 * Calcoli il coefficiente binomiale n su k
 *
 * NB: gcc -o exe fattoriale.c binomiale.c main.c
*/

#include <stdio.h>
#include "utils.h"

// ##### Verifica Coefficiente binomiale #####
int main() {
    int n, k;

    do {
    printf("\nInserisci numero posti n: ");
    scanf("%d", &n);
    printf("Inserisci numero elementi k: ");
    scanf("%d", &k);
    } while ((k>n) || (n<0));

    printf("Ho calcolato ( %d | %d ) = %d\n\n", n, k, binomiale(n, k));

    return 0;
}


// ##### Verifica fattoriale ######
int _main() {
    int input;

    printf("\nInserisci un numero: ");
    scanf("%d", &input);

    printf("Ho calcolato %d! = %d\n\n", input, fattoriale(input));

    return 0;
}