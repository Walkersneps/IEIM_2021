/* Data una matrice M1 di NxN interi,
 * si scriva una funzione in C che,
 * dopo aver fatto inserire gli NxN numeri,
 * ne calcola la trasposta, salvandola sempre su M1.
*/

#include <stdio.h>
#define N 3

void inserimento(int m[N][N]);
void printMatr(int m[N][N], int trsp); // non richiesto
void matrcpy(int orig[N][N], int dest[N][N]);

void trasposta(int M1[N][N]) {
    int tmp[N][N];
    int r, c;
    inserimento(M1);
    //printMatr(M1, 0); // non richiesto
    matrcpy(M1, tmp);

    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            M1[r][c] = tmp[c][r];
    
    //printMatr(M1, 1); // non richiesto
}

void inserimento(int m[N][N]) {
    int r, c;
    printf("\nPopoliamo la matrice M1: ");
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            printf("Inserisci R%d - C%d: ", r, c);
            scanf("%d", &m[r][c]);
        }
    }
}

void printMatr(int m[N][N], int trsp) {
    int r, c;
    printf("\n");
    if (trsp) printf("M1 = \n");
    else printf("M1_T = \n");
    for (r = 0; r < N; r++) {
        printf("      ");
        for (c = 0; r < N; c++) {
            printf("%d ", m[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrcpy(int orig[N][N], int dest[N][N]) {
    int r, c;
    for (r = 0; r < N; r++)
        for (c = 0; c < N; c++)
            dest[r][c] = orig[r][c];
}




int main() {
    int M1[N][N];
    trasposta(M1);

    return 0;
}
