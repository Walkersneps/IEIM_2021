/* Ogni numero pari maggiore di 2 può essere scritto come somma di due numeri primi
 * (che possono essere anche uguali).
 * Si scriva una funzione in C che,
 * dato un numero pari,
 * stampa a video i due numeri primi che sommati lo compongono.
 *  Esempio:
 *      4 = 2 + 2
 *      10 = 3 + 7 = 5 + 5
 *      14 = 3 + 11 = 7 + 7
*/

#include <stdio.h>

char isPrimo(int n);


void addendi_primi(int n) {
    printf("\n%d ", n);
    for (int j = n; j >= (n/2); j--)
        if (isPrimo(j))
            printf("= %d + %d ", j, n - j);

    printf("\n\n");
}


char isPrimo(int n) {
    for (int i = 2; i < n; i++)
        if (n%i == 0)
            return 0;
    return 1;
}


int main() {
    int N;
    printf("\nInserisci un numero: ");
    scanf("%d", &N);
    addendi_primi(N);
    return 0;
}