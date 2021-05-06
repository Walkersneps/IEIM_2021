/* Domanda 5.1 (60%): Si scriva una funzione in C che,
 *                    preso un vettore non ordinato di interi
 *                    e un numero X,
 *                    dice se il numero è presente o meno dell’array.
 *                    La funzione deve effettuare la ricerca nella seguente maniera:
 *                      a. confronta il numero con l’elemento a “metà” del vettore
 *                      b. richiama se stessa (si tratta quindi di una funzione ricorsiva)
 *                         sulla metà superiore ed inferiore del vettore
 * 
 * Domanda 5.2 (40%): Una volta descritta la funzione della parte 5.1,
 *                    si scriva una seconda funzione che, partendo dalla prima,
 *                    conta le occorrenze del numero X nel vettore in ingresso.
 *                    Cosa cambia rispetto alla prima funzione?
*/

// ####### 5.1 #######
// Verifica se _X_ è presente nell'array _inArray[]_ di dimensione _size_
int isThere(int X, int inArray[], int ofSize) {
    if (ofSize == 0) return 0; // Caso banale: array vuoto
    if (inArray[ofSize / 2] == X) // Caso semplice: l'ho trovato
        return 1;
    else
        return (isThere(X, inArray, ofSize / 2) || // metà inferiore
                isThere(X, inArray + (ofSize / 2) + 1, (ofSize / 2) - !(ofSize % 2))); // metà superiore
}



// ####### 5.2 #######
// Ritorna il numero di volte con cui _X_ compare  nell'array _inArray[]_ di dimensione _size_
int occorrenze(int X, int inArray[], int ofSize) {
    if (ofSize == 0) return 0; // Caso banale: array vuoto
    if (inArray[ofSize / 2] == X) // Caso semplice: l'ho trovato
        return (1 +
                occorrenze(X, inArray, ofSize / 2) + // metà inferiore
                occorrenze(X, inArray + (ofSize / 2) + 1, (ofSize / 2) - !(ofSize % 2))); // metà superiore
    else
        return (occorrenze(X, inArray, ofSize / 2) + 
                occorrenze(X, inArray + (ofSize / 2) + 1, (ofSize / 2) - !(ofSize % 2)));
}



// Verifica
#include <stdio.h>
#define MAXDIM 100
int main() {
    int dim, i, x;
    do {
        printf("\nInserisci dimensione dell'array: ");
        scanf("%d", &dim);
    } while (dim < 0 || dim > MAXDIM);
    int a[dim];

    for (i = 0; i < dim; i++) {
        printf("Inserisci elemento [%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nHai inserito: [ ");
    for (i = 0; i < dim; i++) printf("%d ", a[i]);
    printf("].\n");

    for (;;) {
        printf("Che numero vuoi cercare? ");
        scanf("%d", &x);
        if (isThere(x, a, dim))
            printf("Trovato! ");
        else
            printf("Non trovato! ");
        printf("(%d volte)\n", occorrenze(x, a, dim));
    }

    return 0;
}