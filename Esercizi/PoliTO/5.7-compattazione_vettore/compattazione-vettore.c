/* Scrivere un programma in linguaggio C che legge N numeri interi da tastiera
 * e li memorizza in un vettore. Il numero N viene inserito dall’utente ed è minore di 20.
 * Il programma deve generare un secondo vettore che compatta i numeri contenuti nel primo vettore.
 * In particolare:
 *   • ogni numero che compare ripetuto nel primo vettore, deve comparire una sola volta nel secondo
 *      vettore
 *   • ogni numero uguale a zero presente nel primo vettore non deve comparire nel secondo vettore
 * 
 * Il programma deve visualizzare il contenuto del secondo vettore.
 * 
 * Ad esempio, si supponga N=8 e si consideri la sequenza di numeri 1 18 3 0 24 3 6 0
 * inseriti da tastiera. Il programma deve visualizzare 1 18 3 24 6
 * 
*/


// TODO: allocare solo lo spazio necessario per il vettore compattato

#include <stdio.h>
#define NMAX 20

void printArray(int *array, int size, int startIndex); // stampa _array[]_ di dimensione _size_ in modo carino, leggendolo a partire dalla posizione _startIndex_
void compatta(int *esteso, int size, int *compattato);

int main() {
    int N;

    // Acquisisco input utente
    do {
        printf("Inserire dimensione del vettore (massimo %d): ", NMAX);
        scanf("%d", &N);
    } while (!(N > 0 && N < NMAX));

    int v[N], compattato[N + 1];

    for (int i = 0; i < N; i++) {
        printf("Inserire elemento %d-esimo: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Mostro dati inseriti
    printf("E' stato inserito l'array ");
    printArray(v, N, 0);

    // Eseguo la compattazione e mostro il risultato
    //          printf("\nDEBUG compattato[] pre operazioni="); printArray(compattato, N+1, 0);
    compatta(v, N, compattato);
    printf("\nCompattato, si ha: ");
    printArray(compattato, compattato[0] + 1, 1);
    //          printf("\nDEBUG: compattato[] completo = "); printArray(compattato, N+1, 0);
    printf("\n\n");


    return 0;
}


void printArray(int *array, int size, int startIndex) {
    printf("[ ");
    for (int j = startIndex; j < size; j++) printf("%d ", array[j]);
    printf("]");
}

// Scrive in compattato[] la contrazione di esteso[], secondo le richieste dell'esercizio. Il primo elemento (posizione 0) indica il numero di elementi compattati
void compatta(int *esteso, int size, int *compattato) {
    char gia_ce = 0;
   
    compattato[0] = 0; // inizializzo dimensione del vettore

    for (int j = 0; j < size; j++) {
        if (esteso[j] == 0) continue; // se ho uno zero, passo subito al prossimo elemento di array[]
        for (int k = 1; k <= compattato[0]; k++) {
            if (compattato[k] == esteso[j]) { // abbiamo già registrato questo elemento
                gia_ce = 1;
                break;
            } else {
                gia_ce = 0;
            }
        }

        if (!gia_ce) { // non ho trovato corrispondenze
            compattato[compattato[0] + 1] = esteso[j]; // aggiungo l'elemento all'array compatto
            compattato[0]++; // registro l'aumento degli elementi di compattato[]
        } // implicito: se ho trovato corrispondenze, non faccio nulla e passo al prossimo elemento di array[]
    }
}