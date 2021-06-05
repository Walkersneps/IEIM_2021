/* Si scriva in C una funzione che, dati due numeri N1 ed N2,
 * interi e maggiori di zero (si deve verificare che siano maggiori di zero),
 * restituisca al chiamante la lista di tutti i loro divisori primi comuni tra loro.
 *  Esempio:
 *      Input: A = 15, B = 12
 *      Restituito al chiamante: 3
*/

char isPrimo(int n);

/* Riempie _divisori[]_ con tutti i divisori primi comuni ad N1 e N2, e ne
 * ritorna il numero.
 *
 * !! Assicurarsi che _divisori[]_ sia grande abbastanza (safe limit: min(N1, N2)-1)
*/
int divisoriPrimiComuni(int N1, int N2, int divisori[]) {
    int min, i;
    int ndiv = 0;

    if (N1 < N2) min = N1;
    else min = N2;

    // in base all'esempio, ignoro 1, che è sempre divisore primo comune a qualunque coppia di numeri
    for (i = 2; i <= min; i++) {
        if (isPrimo(i) && (N1 % i == 0) && (N2 % i == 0)) {
            divisori[ndiv] = i;
            ndiv++;
        }
    }

    return ndiv;
}


char isPrimo(int n) {
    if (n <= 2) return 1;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}





// Verifico
#include <stdio.h>
int main() {
    int n1, n2, min, amount, i;

    printf("Inserisci N1 ed N2: ");
    scanf("%d", &n1); scanf("%d", &n2);

    if (n1 < n2) min = n1;
    else min = n2;
    int divisori[min];

    amount = divisoriPrimiComuni(n1, n2, divisori);

    printf("I divisori primi comuni a %d e %d sono: ", n1, n2);
    for (i = 0; i < amount; i++) printf(" %d", divisori[i]);
    printf(".\n\n");

    return 0;
}
