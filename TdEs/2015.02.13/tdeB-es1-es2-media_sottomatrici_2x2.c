// Esercizio 1: radice quadrata --> vd. TdE 2018.07.03 es1

/* Esercizio 2
 * Scrivere un programma in linguaggio C che esegua le seguenti operazioni:
 *  • Acquisisca da tastiera due valori interi nRighe e nCol.
 *    I due valori devono essere:
 *      - pari,
 *      - maggiori di 0,
 *      - minori di N, dove N è una costante opportunamente definita con valore 100.
 *  • Acquisisca da tastiera nRighe x nCol valori interi,
 *    e li memorizzi in una matrice m, di dimensioni massime NxN,
 *    organizzandoli su un numero di righe pari a nRighe e un numero di colonne pari a nCol.
 *  • Considerando la matrice m come suddivisa in sottomatrici 2x2,
 *    calcoli e stampi a video il numero di sottomatrici 2x2
 *    con  media  maggiore  di  10.
*/

#include <stdio.h>
#define N 100
#define LIMITE 10

int main() {
    int nRighe, nCol;
    int buone = 0;
    int r, c, submatr, sr, sc;

    // ### Punto 1 ###
    do {
        printf("Inserisci nRighe (max %d): ", N);
        scanf("%d", &nRighe);
    } while (nRighe % 2 != 0 || nRighe < 0 || nRighe > N);
    do {
        printf("Inserisci nCol (max %d): ", N);
        scanf("%d", &nCol);
    } while (nCol % 2 != 0 || nCol < 0 || nCol > N);


    // ### Punto 2 ###
    int m[nRighe][nCol];
    for (r = 0; r < nRighe; r++) {
        for (c = 0; c < nCol; c++) {
            printf("Inserisci m[%d][%d]: ", r, c);
            scanf("%d", &m[r][c]);
        }
    }


    // ### Punto 3 ###
    for (submatr = 0; submatr < ((nRighe*nCol)/4); submatr ++) {
        sr = 2 * (submatr / nCol); // riga del primo elemento della sottomatrice corrente
        sc = 2 * (submatr % nCol); // colonna del primo elemento della sottomatrice corrente
        if (((m[sr][sc] + m[sr+1][sc] + m[sr][sc+1] + m[sr+1][sc+1]) / 4) > 10)
            buone++;
    }
    printf("\n%d sottomatrici hanno media maggiore di %d.\n", buone, LIMITE);

    return 0;
}