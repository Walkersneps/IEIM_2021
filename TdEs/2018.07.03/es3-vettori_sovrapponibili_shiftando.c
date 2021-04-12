/* Dati due array di interi A e B di lunghezza N
 * (si assumono dati e popolati, quindi forniti in ingresso alla funzione di nostro interesse).
 * Si scriva una funzione ricorsiva in C che verifichi se
 * esiste un intero k >= 0 tale per cui
 * B sia identico ad A ruotato verso destra di k elementi.
 *  Esempio
 *      A: [3, 6, 15, 9, 12]
 *      B: [9, 12, 3, 6, 15]
 *      --> B concide con A se k = 3
*/

#include <stdio.h>

char sonoSovrapponibili(int a[], int b[], int N);
void ruotaDx(int vett[], int size);
char sonoSovrapponibiliRuotando(int a[], int b[], int N, int k);
void printArray(int *array, int size);

int main() {
    int i;

    int N = 5;
    int a[] = {12, 3, 6, 15, 9};
    int b[] = {9, 12, 3, 6, 15};

    // Confermo inserimento
    printf("\n\nHai inserito:");
    printf("\n  A = "); printArray(a, N);
    printf("\n  B = "); printArray(b, N);

    // Finalmente, eseguo la verifica
    if(sonoSovrapponibiliRuotando(a, b, N, 0)) printf("\n\nI vettori sono sovrapponibili.\n\n");
    else printf("\n\nI vettori NON sono sovrapponibili.\n\n");

    return 0;
}

int main_interattivo() {
    int N, i;

    // Acquisisco dimensione e poi inizializzo gli array
    do {
        printf("\n Inserisci dimensione dei vettori: ");
        scanf("%d", &N);
    } while (N <= 0);
    int a[N], b[N];

    // Popolo i vettori
    printf("\nInserisci i valori di A:\n");
    for(i = 0; i < N; i++) {
        printf("  %d-esimo valore di A: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\nInserisci i valori di B:\n");
    for(i = 0; i < N; i++) {
        printf("  %d-esimo valore di B: ", i+1);
        scanf("%d", &b[i]);
    }

    // Confermo inserimento
    printf("\n\nHai inserito:");
    printf("\n  A = "); printArray(a, N);
    printf("\n  B = "); printArray(b, N);

    // Finalmente, eseguo la verifica
    if(sonoSovrapponibiliRuotando(a, b, N, 0)) printf("\n\nI vettori sono sovrapponibili.\n\n");
    else printf("\n\nI vettori NON sono sovrapponibili.\n\n");

    return 0;
}


/* Verifica se i due vettori sono immediatamente sovrapponibili
 * (in pratica, se sono uguali)
*/
char sonoSovrapponibili(int a[], int b[], int N) {
    for (int i = 0; i < N; i++) if (a[i] != b[i]) return 0;
    return 1;
}

/* Esegue uno shift ciclico a destra su _vett[]_
*/
void ruotaDx(int vett[], int size) {
    int ultimoElemento = vett[size - 1];

    for (int i = size - 1; i > 0; i--) vett[i] = vett[i - 1];

    vett[0] = ultimoElemento;
}

char sonoSovrapponibiliRuotando(int a[], int b[], int N, int k) {
    if (k < N) {
        if (sonoSovrapponibili(a, b, N)) return 1;
        else {
            ruotaDx(b, N);
            return sonoSovrapponibiliRuotando(a, b, N, k + 1);
        }
    } else return 0;
}

void printArray(int *array, int size) {
    printf("[ ");
    for (int j = 0; j < size; j++) printf("%d ", array[j]);
    printf("]");
}