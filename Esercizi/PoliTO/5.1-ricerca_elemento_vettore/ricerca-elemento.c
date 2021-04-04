/* Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
 * I numeri sono memorizzati in un vettore.
 * Il valore N è inserito dall’utente, ma il vettore può contenere al massimo 30 numeri.
 * Terminato l’inserimento della sequenza di numeri, l’utente inserisce un valore di riferimento.
 * Il programma deve indicare se tale valore di riferimento è contenuto nel vettore.
*/

#include <stdio.h>
#define MAXN 30

char posizioneRitrovamento(int array[], int size, int ricercato);
void printArray(int array[], int size);

int main() {
    int N, wanted, pos;

    do {
        printf("Quanti valori vuoi inserire? ");
        scanf("%d", &N);
    } while (N <= 0);
    int v[N];
    for (int i = 0; i < N; i++) {
        printf("Inserisci elemento %d-esimo: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("\nHai inserito l'array "); printArray(v, N);
    printf("\nChe elemento vuoi cercare al suo interno? ");
    scanf("%d", &wanted);

    pos = posizioneRitrovamento(v, N, wanted);

    if (pos < 0) {
        printf("L'elemento %d non e' stato trovato.\n", wanted);
        return 1;
    } else {
        printf("L'elemento %d e' stato ritrovato in posizione %d.\n", wanted, pos);
        return 0;
    }
}

// Ritorna l'indice della prima posizione in cui l'elemento _ricercato_ è presente in _array[]_
// Ritorna -1 se non vi sono occorrenze
char posizioneRitrovamento(int array[], int size, int ricercato){
    for (int j = 0; j < size; j++) if (array[j] == ricercato) return j;
    return -1;
}


void printArray(int array[], int size) {
    printf("[ ");
    for (int j = 0; j < size; j++) printf("%d ", array[j]);
    printf("]");
}