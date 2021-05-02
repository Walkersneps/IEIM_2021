/* Scrivere un programma che acquisisca da tastiera
 * una matrice quadrata di float A di dimensioni scelte dall'utente.
 *   • Si calcoli la media per ogni riga della matrice A.
 *   • Ed infine si crei una nuova matrice B dove
 *       ogni elemento B[i][j] contenga lo stesso numero in valore assoluto di A[i][j]:
 *           - salvato con segno positivo se A[i][j] e'maggiore della media della riga i,
 *           - con segno negativo altrimenti.
*/

#include <stdio.h>
#define MAXSIZE 10

int askSize();
void askMatr(int size, float m[size][size]);
float media(float a[], int size);
float modulo(float n);
void medieXRighe(int size, float m[size][size], float toArr[]);
void popolaB(int size, float a[size][size], float b[size][size], float medie[size]);
void printWithMedia(int size, float m[size][size], float medie[size]);
void printB(int size, float b[size][size]);

int main() {
    int s = askSize();
    float medie[s];
    float a[s][s], b[s][s]; askMatr(s, a);

    medieXRighe(s, a, medie);
    printWithMedia(s, a, medie);
    popolaB(s, a, b, medie);
    printB(s, b);

    return 0;
}


int askSize() {
    int size;
    do {
        printf("Inserisci la dimensione della matrice (max %d): ", MAXSIZE);
        scanf("%d", &size);
    } while (size < 0 || size > MAXSIZE);
    return size;
}

void askMatr(int size, float m[size][size]) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("Inserisci R_%d - C_%d: ", r+1, c+1);
            scanf("%f", &m[r][c]);
        }
    }
}

float media(float a[], int size) {
    float sum = 0;
    for (int j = 0; j < size; j++) sum += a[j];
    return (sum/size);
}

float modulo(float n) {
    if (n < 0) return (-n);
    else return n;
}

void medieXRighe(int size, float m[size][size], float toArr[]) {
    for (int riga = 0; riga < size; riga++) toArr[riga] = media(&m[riga][0], size);
}

void popolaB(int size, float a[size][size], float b[size][size], float medie[size]) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (a[r][c] > medie[r]) b[r][c] = modulo(a[r][c]);
            else b[r][c] = -modulo(a[r][c]);
        }
    }
}

void printWithMedia(int size, float m[size][size], float medie[]) {
    printf("A = ___\n    |\n");
    for (int r = 0; r < size; r++) {
        printf("    | ");
        for (int c = 0; c < size; c++)
            printf("%f ", m[r][c]);
        printf("|   %f\n", medie[r]);
    }
    printf("    |\n    ---\n");
}

void printB(int size, float b[size][size]) {
    printf("B = ___\n    |\n");
    for (int r = 0; r < size; r++) {
        printf("    | ");
        for (int c = 0; c < size; c++)
            printf("%f ", b[r][c]);
        printf("|\n");
    }
    printf("    |\n    ---\n");
}
