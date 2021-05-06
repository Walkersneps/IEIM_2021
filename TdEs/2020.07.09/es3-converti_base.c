/* Scrivere una funzione C che
 * prenda in ingresso un numero decimale X positivo e
 * un numero decimale K (tra 2 e 9, estremi compresi)
 * e stampi a video la rappresentazione di X in base K,
 * sapendo che il risultato potrà essere rappresentato su 4 cifre in base K.
 * 
 * Si scriva anche un main che permetta di testare la funzione.
 * 
 *      NOTA: X e K devono essere “testati/validati” nel main,
 *            PRIMA dell’invocazione della funzione.
*/

#include <stdio.h>
#define CFR 4 // Numero di cifre in base K da mantenere

/* Calcola la rappresentazione in base _K_ di _X_ (assunto espresso in base 10),
 * e ne inserisce le prime *CFR* cifre in _kdigits[]_.
*/
void decToBaseK(int X, int K) {
    int i = 1;
    int kdigits[CFR] = {0};

    printf("\n%d|10 = ", X);

    while ((X > 0) && (i <= CFR)) {
        kdigits[CFR - i] = X % K;
        X = X / K;
        i++;
    }

    for (i = 0; i < CFR; i++) printf("%d", kdigits[i]);
    printf("|%d\n\n", K);
}


#include <math.h>
int main() {
    int X, K;
    do {
        printf("\nIn che base vuoi convertire [2-9]? ");
        scanf("%d", &K);
    } while (K < 2 || K > 9);
    do {
        printf("\nInserisci un numero in base 10: ");
        scanf("%d", &X);
    } while (X < 0);

    if (X > pow(K, CFR)) printf("Attenzione: disponendo di sole %d cifre, la rappresentazione sara' incompleta.\n", CFR);

    decToBaseK(X, K);

    return 0;
}