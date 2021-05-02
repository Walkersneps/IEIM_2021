/* Si scriva un programma che, ricevuti e salvati in un array
 * N numeri interi positivi, compresi tr a0 e 10:
 *  - Calcoli le occorrenze di ciascuna delle cifre
 *  - Stampi a video il valore delle occorrenze,
 *    solo per i numeri presenti almeno una volta
*/

#include <stdio.h>
#define MAXN 30
#define MINITEM 0
#define MAXITEM 10

void printArray(int array[], int size);
void initArray(int array[], int size);
void calcolaOccorrenze(int inArray[], int inSize, int toArray[]);
void printOccorrenze(int occorrenze[], int size);

int main() {
    int size;
    int occorrenze[MAXITEM-MINITEM+1]; initArray(occorrenze, MAXITEM-MINITEM+1);

    do {
        printf("\nQuanti numeri vuoi inserire (max %d)? ", MAXN);
        scanf("%d", &size);
    } while (size < 0 || size > MAXN);

    int a[size];

    for (int i = 0; i < size; i++) {
        do {
            printf("Inserisci numero %d-esimo: ", i);
            scanf("%d", &a[i]);
        } while (a[i] < MINITEM || a[i] > MAXITEM);
    }

    printf("\nHai inserito: a[] = "); printArray(a, size); printf("\n");

    calcolaOccorrenze(a, size, occorrenze);
    printOccorrenze(occorrenze, MAXITEM-MINITEM+1);

    return 0;
}

// Stampa carino _array[]_ di dimensione _size_
void printArray(int array[], int size) {
    int j;
    printf("{ ");
    for (j = 0; j < size-1; j++) printf("%d, ", array[j]);
    printf("%d", array[j]);
    printf(" }");
}

void initArray(int array[], int size) {
    for (int j = 0; j < size; j++) array[j] = 0;
}

void calcolaOccorrenze(int inArray[], int inSize, int toArray[]) {
    for (int j = 0; j < inSize; j++) toArray[inArray[j]]++;
}

void printOccorrenze(int occorrenze[], int size) {
    for (int j = 0; j < size; j++)
        if (occorrenze[j]) printf("\nIl numero %d occorre %d volte.", j, occorrenze[j]);
}