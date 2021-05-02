/* Si scriva in C una funzione che,
 * presa una matrice di RxC interi, già popolata con tutti 0,
 * permetta l’inserimento degli RxC numeri interi positivi (verificando che siano positivi).
 * 
 * Verifichi quali di questi numeri sono primi e ne riporti,
 * salvandoli  in  un array “visibile al chiamante”,
 * le posizioni nella matrice.
*/

#include <stdio.h>
#define MAXSIZE 5

typedef struct {
    int riga;
    int colonna;
} Coordinata;

char isPrimo(int n);
void inserimento(int R, int C, int m[R][C]);
void inizializza(int R, int C, int m[R][C]);
int es2(int R, int C, int m[R][C], Coordinata posizioni[]);

// Per verificare funzionamento
int main() {
    int R, C, nprimi;

    // Leggo da tastiera R e C
    do {
        printf("\nQuante righe R (max %d)? ", MAXSIZE);
        scanf("%d", &R);
    } while ((R < 1) || (R > MAXSIZE));
    do {
        printf("\nQuante colonne C (max %d)? ", MAXSIZE);
        scanf("%d", &C);
    } while ((C < 1) || (C > MAXSIZE));

    int m[R][C];
    inizializza(R, C, m);

    Coordinata posizioniPrimi[R*C];
    nprimi = es2(R, C, m, posizioniPrimi);

    printf("\nHo trovato %d numeri primi nelle posizioni:\n", nprimi);
    for (int i = 0; i < nprimi; i++)
        printf("  R%d - C%d\n", posizioniPrimi[i].riga+1, posizioniPrimi[i].colonna+1);
    
    return 0;
}

/* Ritorna:
 * 1 se _n_ è un numero primo
 * 0 altrimenti
*/
char isPrimo(int n) {
    for (int i = 2; i < n; i++) if (n % i == 0) return 0;
    return 1;
}

// Chiede all'utente di riempire _m[][]_
void inserimento(int R, int C, int m[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            do {
                printf("Inserisci elemento %d.%d: ", i+1, j+1);
                scanf("%d", &m[i][j]);
            } while (m[i][j] < 0);
        }
    }
}

// Popola tutta la matrice riempiendola di zeri
void inizializza(int R, int C, int m[R][C]) {
    for (int rig = 0; rig < R; rig++)
        for (int col = 0; col < C; col++)
            m[rig][col] = 0;
}

// Esegue quanto richiesto e ritorna la quantità di numeri primi trovati
int es2(int R, int C, int m[R][C], Coordinata posizioni[]) {
    int quantiPrimi = 0;

    inserimento(R, C, m);

    for (int rig = 0; rig < R; rig++) {
        for (int col = 0; col < C; col++) {
            if (isPrimo(m[rig][col])) {
                posizioni[quantiPrimi].colonna = col;
                posizioni[quantiPrimi].riga = rig;
                quantiPrimi++;
            }
        }
    }

    return quantiPrimi;
}