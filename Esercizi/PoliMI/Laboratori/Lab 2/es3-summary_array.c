/* Si scriva un programma in C che, dato un vettore di 10 numeri interi,
 * calcoli valore massimo, minimo e la media.
*/

#include <stdio.h>
#define N 10

void printArray(int array[], int size);
float media(int array[], int size);
int max(int array[], int size);
int min(int array[], int size);

int main() {
    int a[N];

    for (int i = 0; i < N; i++) {
        printf("Inserisci elemento %d-esimo: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("\nHai inserito: "); printArray(a, N); printf("\n");

    printf("\nLa media dei valori e': %f", media(a, N));
    printf("\nIl valore massimo e': %d", max(a, N));
    printf("\nIl valore minimo e': %d\n\n", min(a, N));

    return 0;
}


void printArray(int array[], int size) {
    int j;
    printf("{ ");
    for (j = 0; j < size-1; j++) printf("%d, ", array[j]);
    printf("%d", array[j]);
    printf(" }");
}

float media(int array[], int size) {
    float sum = 0;
    for (int j = 0; j < size; j++) sum += array[j];
    return (sum/size);
}

int max(int array[], int size) {
    int m = -__INT8_MAX__;
    for (int j = 0; j < size; j++) if (array[j] > m) m = array[j];
    return m;
}

int min(int array[], int size) {
    int m = __INT8_MAX__;
    for (int j = 0; j < size; j++) if (array[j] < m) m = array[j];
    return m;
}