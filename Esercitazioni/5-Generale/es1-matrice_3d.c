/* Scrivere un programma che:
 *   - legga un 'cubo' di char
 *   - conti il numero di occorrenze della lettera a
 *   - conti il numero di caratteri maiuscoli inseriti
 *   - dica quale carattere ha il maggior numero di occorrenze
*/

#include <stdio.h>
#define SIZE 3
#define LOOKOUT 'a'
#define NCHARS 257

void acquisisciCubo(char cubo[SIZE][SIZE][SIZE]);
char moda(char cubo[SIZE][SIZE][SIZE]);
int contaOccorrenze(char cubo[SIZE][SIZE][SIZE], char ricercato);



int main() {
    char cubo[SIZE][SIZE][SIZE];

    printf("\nRiempiamo il cubo: \n");
    acquisisciCubo(cubo);

    


    return 0;
}


// Riempie _cubo[][][]_ con input utente
void acquisisciCubo(char cubo[SIZE][SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                printf("  A%c B%c C%c: ", i, j, k);
                scanf(" %c", &cubo[i][j][k]);
            }
        }
    }
}

// Conta il numero di occorrenze in _cubo[][][]_ di _ricercato_
int contaOccorrenze(char cubo[SIZE][SIZE][SIZE], char ricercato) {
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (cubo[i][j][k] = ricercato) count++;
            }
        }
    }

    return count;
}

// Ritorna il carattere con più occorrenze nel _cubo[][][]_
char moda(char cubo[SIZE][SIZE][SIZE]) {
    int occorrenze[NCHARS];
    int max = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                occorrenze[cubo[i][j][k]]++;
            }
        }
    }

    for (int p = 0; p < 256; p++) if (occorrenze[p] > max) max = p;

    return max;
}