/* Siano dati due vettori di interi inseriti da tastiera.
 * La lunghezza dei due vettori è inserita dall’utente da tastiera.
 * I due vettori possono avere lunghezze diverse, ma possono contenere al massimo 30 numeri.
 * 
 * Si scriva un programma in linguaggio C per generare un terzo vettore che contiene l’intersezione
 * tra due vettori.
 * Tale vettore deve contenere i numeri presenti in entrambi i vettori dati.
 *      Ad esempio, si assuma che siano stati inseriti i due vettori:
 *          1 6 15 20 25 // 5 elementi
 *          2 20 18 6    // 4 elementi
 *      Il programma deve visualizzare la sequenza 6 20.
*/

#include <stdio.h>
#define MAXN 30

void printArray(int *array, int size, int startIndex);
int calcolaIntersezione(int *v1, int size1, int *v2, int size2, int *intersezione);
char appartiene(int elemento, int *inArray, int size);

int main() {
    int size1, size2, minSize, sizeIntersezione;
    
    // Acquisisco input
    do {
        printf("Dimensione vettore 1: ");
        scanf("%d", &size1);
        printf("Dimensione vettore 2: ");
        scanf("%d", &size2);
    } while (size1 < 0 || size1 > MAXN || size2 < 0 || size2 > MAXN);

    int v1[size1], v2[size2];

    // Il vettore intersezione sarà grande al massimo quanto il più corto dei due input
    if (size1 > size2) minSize = size2;
    else minSize = size1;
    int intersez[minSize];

    for (int i = 0; i < size1; i++) {
        printf("Inserisci %d-esimo numero di v1: ", i+1);
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < size2; i++) {
        printf("Inserisci %d-esimo numero di v2: ", i+1);
        scanf("%d", &v2[i]);
    }

    printf("\nv1 = "); printArray(v1, size1, 0);
    printf("\nv2 = "); printArray(v2, size2, 0);

    printf("La loro intersezione e': ");
    sizeIntersezione = calcolaIntersezione(v1, size1, v2, size2, intersez);
    printArray(intersez, sizeIntersezione, 0);
    printf("\n\n");

    return 0;
}


void printArray(int *array, int size, int startIndex) {
    printf("[ ");
    for (int j = startIndex; j < size; j++) printf("%d ", array[j]);
    printf("]");
}

// Ritorna la dimensione di intersezione[]
int calcolaIntersezione(int *v1, int size1, int *v2, int size2, int *intersezione){
    int comuni = 0;

    for (int j = 0; j < size1; j++) { // per ogni elemento di v1
        if (!appartiene(v1[j], intersezione, comuni)) {
            for (int k = 0; k < size2; k++) {
                if (v1[j] == v2[k]) {
                    intersezione[comuni] = v1[j];
                    comuni ++;
                    break;
                }
            }
        }
    }

    return comuni;
}


char appartiene(int elemento, int *inArray, int size) {
    for (int j = 0; j < size; j++) {
        if (inArray[j] == elemento) return 1;
    }

    return 0;
}