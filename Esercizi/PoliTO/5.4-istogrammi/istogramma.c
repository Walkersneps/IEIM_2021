/* Scrivere un programma in linguaggio C che
 * riceve in ingresso una sequenza di N numeri interi.
 * Il valore N è inserito dall’utente.
 * I numeri sono memorizzati in un vettore.
 * Terminato l’inserimento della sequenza di numeri, il programma deve visualizzare una riga di 
 * asterischi per ogni numero inserito.
 * Il numero di asterischi nella riga è pari al valore del numero inserito.
 *      Ad esempio, dato il vettore [ 9 4 6 ] il programma deve visualizzare:
 *      Elemento 1: 9 *********
 *      Elemento 2: 4 ****
 *      Elemento 3: 6 ******
*/

#include <stdio.h>

void printHist(int valori[], int nRighe);
void printArray(int array[], int size);

int main() {
    int N;

    // Acquisisco input utente
    do {
        printf("Quante righe vuoi nell'istogramma? ");
        scanf("%d", &N);
    } while (!(N > 0));
    int righeHist[N];
    for (int i = 0; i < N; i++) {
        printf("Inserire la lunghezza della colonna %d: ", i+1);
        scanf("%d", &righeHist[i]);
    }

    printf("\n\nIl vettore "); printArray(righeHist, N); printf(" genera l'istogramma:\n");
    printHist(righeHist, N);
    printf("\n");

    return 0;
}


void printHist(int valori[], int nRighe) {
    for (int riga = 0; riga < nRighe; riga++) {
        printf("\nElemento %d:  %d  ", riga+1, valori[riga]);
        for (int i = 0; i < valori[riga]; i++) printf("*");
    }
}

void printArray(int array[], int size) {
    printf("[ ");
    for (int j = 0; j < size; j++) printf("%d ", array[j]);
    printf("]");
}