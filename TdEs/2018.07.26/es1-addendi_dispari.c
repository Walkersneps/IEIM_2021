/* Si scriva in C un programma che,
 * preso in ingresso un numero pari,
 * stampi a video, se esistono, tutte le coppie di numeri dispari che sommati lo compongono.
 * 
 * NOTA: i due numeri dispari possono essere anche uguali.
 *   Esempi:
 *     8 = 3 + 5
 *     10 = 3 + 7, 5 + 5
 *     12 = 5 + 7
 *     14 = 3 + 11, 7 + 7
*/

#include <stdio.h>


char isPari(int n);


int main() {
    int in;

    do {
        printf("\nInserisci un numero pari: ");
        scanf("%d", &in);
    } while (!isPari(in));

    for (int i = 1; i <= in / 2; i = i + 2) {
        printf("\n%d = %d + %d", in, i, in - i);
    }

    return 0;
}


/* Ritorna:
 * 1 se _n_ è pari
 * 0 se _n_ è dispari
*/
char isPari(int n) {
    if (n % 2 == 0) return 1;
    else return 0;
}