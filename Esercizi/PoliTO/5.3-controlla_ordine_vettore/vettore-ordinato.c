/* Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
 * I numeri sono memorizzati in un vettore.
 * Il valore N è inserito dall’utente,  ma il vettore può contenere al massimo 30 numeri.
 * Terminato l’inserimento della sequenza di  numeri,  il  programma  deve  verificare
 * se  il  vettore  contiene  una  sequenza  di  numeri ordinata in modo strettamente crescente.
*/

#include <stdio.h>
#define MAXN 30

char sonoOrdinati(int *numeri, int size);

int main() {
    int N, ncurr;

    // Acquisisco N
    do {
        printf("Quanti numeri vuoi inserire? (massimo %d) ", MAXN);
        scanf("%d", &N);
    } while (!((N > 0) && (N < MAXN)));

    // Genero l'array
    int numeri[N];

    // Acquisisco i altri numeri
    for (int i = 0; i < N; i++) {
        printf("Inserire il %d-numero: ", i+1);
        scanf("%d", &numeri[i]);
    }

    // Verifico Ordinamento
    if (sonoOrdinati(numeri, N)) printf("\nI numeri forniti sono in ordine strettamente crescente.\n\n");
    else printf("\nI numeri forniti NON sono ordine strettamente crescente.\n\n");
    

    return 0;
}


// Ritorna 1 se l'array fornito (di dimensione size) contiene numeri in ordine strettamente crescente
// Diversamente, ritorna 0.
char sonoOrdinati(int *numeri, int size) {
    // Inutile controllare il primo elemento
    int precedente = numeri[0];

    for (int i = 1; i < size; i++) {
        // Appena trovo un numero <= del precedente, invalido il controllo ed esco
        if (numeri[i] <= precedente) return 0;
        precedente = numeri[i];
    }

    // Se sono ancora vivo, vuol dire che è tutto in ordine
    return 1;
}