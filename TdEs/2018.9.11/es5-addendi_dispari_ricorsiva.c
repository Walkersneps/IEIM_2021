/* Si scriva in C una funzione ricorsiva che,
 * preso in ingresso un numero dispari, stampi a video
 * tutte le coppie di numeri che sommati lo compongono.
 * Potete passare alla funzione tutti i parametri che ritenete essere necessari.
 * 
 * Esempio: Dato 5, Stampa: 1 + 4, 2 + 3, 3 + 2, 4 + 1
*/

#include <stdio.h>

void addendiDispari(int n, int indx) {
    if (indx == n) return;
    
    printf("%d + %d, ", indx, n - indx);
    addendiDispari(n, indx + 1);
}



int main() {
    int N;

    printf("Inserisci numero: ");
    scanf("%d", &N);

    printf("\n%d = ", N);
    addendiDispari(N, 1);
    printf("\n\n");

    return 0;
}