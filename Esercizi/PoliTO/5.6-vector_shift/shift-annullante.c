/* Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
 * Il  valore  N  è  inserito  dall’utente.   I  numeri  sono  memorizzati  in  un  vettore.
 * Il programma esegue le seguenti operazioni:
 * 1.  visualizza il vettore
 * 2.  esegue uno spostamento (shift) a sinistra di una posizione del contenuto del vettore.
 * 
 *   * Pertanto ogni elemento del vettore deve assumere il valore dell’elemento immediatamente
 *   * successivo all’interno del vettore. 
 *   * L’elemento di indice N-1 deve assumere il valore zero.
 *      * Ad esempio dato il vettore: 1 10 15 18, il programma deve generare il vettore: 10 15 18 0
 * 
 * Il programma visualizza il vettore ottenuto.
 * 
 * 3.  esegue uno spostamento (shift) a destra di una posizione del contenuto del vettore ottenuto
 *     nel passo precedente.
 * 
 *   * Pertanto ogni elemento del vettore deve assumere il valore dell’elemento immediatamente precedente all’interno del vettore.
 *   * L’elemento di indice 0 deve assumere il valore zero.
 * 
 * Il programma visualizza il vettore ottenuto.
 * 
 * Nota: Nella definizione di “destra” e “sinistra” si immagini il vettore stampato orizzontalmente,
 * a partire dalla cella di indice 0.
*/

#include <stdio.h>

void shiftRight(int *array, int size); // Esegue uno shift ad anello in senso orario
void shiftLeft(int *array, int size); // Esegue uno shift ad anello in senso antiorario
void printArray(int *array, int size); // Stampa il contenuto di un array nel formato [ array[0] array[1] ... array[size-1] ]
void duplicaArray(int *daCopiare, int size, int *destinazione); // Copia il contenuto di un array in un altro

int _main() {
    int N, i;

    // Acquisisco numero elementi
    do {
        printf("Quanti numeri vuoi inserire nel vettore? ");
        scanf("%d", &N);
    } while (N <= 0);

    // Alloco lo spazio per gli array
    int arr[N], duplicato[N];

    // Acquisisco i valori
    for (i = 0; i < N; i++) {
        printf("Inserire il numero %d-esimo: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nL'array inserito e': ");
    printArray(arr, N);
    
    // Duplico l'array inserito
    duplicaArray(arr, N, duplicato);

    // Eseguo shift a destra su arr[]
    shiftRight(arr, N);
    printf("\nEseguendo uno shift a destra ottengo: ");
    printArray(arr, N);

    // Eseguo shift a sinistra su duplicato[] per ottenere uno shift a sx rispetto all'array inserito
    shiftLeft(duplicato, N);
    printf("\nEseguendo uno shift a sinistra ottengo: ");
    printArray(duplicato, N);
    
    printf("\n");
    return 0;
}


// SOLUZIONE PIU' ECONOMICA:
/* salvo (primo e) ultimo elemento
 * shift dx
 * shift sx
 * ripristino ultimo elemento
 * shift sx
 * 
 * PROFIT: soltanto due int anzichè una copia completa dell'array
*/
int main() {
    int N, i, primo, ultimo;

    // Acquisisco numero elementi
    do {
        printf("Quanti numeri vuoi inserire nel vettore? ");
        scanf("%d", &N);
    } while (N <= 0);

    // Alloco lo spazio per  l'array
    int arr[N];

    // Acquisisco i valori
    for (i = 0; i < N; i++) {
        printf("Inserire il numero %d-esimo: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nL'array inserito e': ");
    printArray(arr, N);
    
    // Salvo i valori a rischio
    //primo = arr[0];
    ultimo = arr[N - 1];

    // Eseguo shift a destra
    shiftRight(arr, N);
    printf("\nEseguendo uno shift a destra ottengo: ");
    printArray(arr, N);

    // Eseguo doppio shift a sinistra per ottenere uno shift a sx rispetto all'array inserito inizialmente
    shiftLeft(arr, N);
    arr[N - 1] = ultimo; // Ripristino l'ultimo valore --> adesso arr[] coincide con quello di partenza
    shiftLeft(arr, N);
    printf("\nEseguendo uno shift a sinistra ottengo: ");
    printArray(arr, N);
    
    printf("\n");
    return 0;
}


void printArray(int *array, int size) {
    printf("[ ");
    for (int j = 0; j < size; j++) printf("%d ", array[j]);
    printf("]");
}

void shiftRight(int *array, int size) {
    for (int j = size - 1; j > 0; j--) array[j] = array[j - 1]; // Eseguo gli shift
    array[0] = 0;
}

void shiftLeft(int *array, int size){
    for (int j = 0; j < size - 1; j++) array[j] = array[j + 1]; // Eseguo gli shift
    array[size - 1] = 0;
}

void duplicaArray(int *daCopiare, int size, int *destinazione) {
    for (int j = 0; j < size; j++) destinazione[j] = daCopiare[j];
}