/* Si scriva un programma che visualizzi gli istogrammi verticalmente */

#include <stdio.h>
#define MAXCOL 12
#define MAXHEIGHT 20
#define TRATTO '*'
#define EMPTY ' '

int askAscisse();
void askDati(int altezze[], int size);
int max(int array[], int size);
void initMatr(int righe, int colonne, char hist[righe][colonne]);
void generaHist(int maxHeight, int ncolonne, char hist[maxHeight][ncolonne], int altezze[]);
void printHist (int maxHeight, int ncolonne, char hist[maxHeight][ncolonne], int altezze[]);

int main() {
    int ndati, altzz;

    ndati = askAscisse();
    int altezze[ndati];

    askDati(altezze, ndati);
    altzz = max(altezze, ndati);
    char isto[altzz][ndati];
    initMatr(altzz, ndati, isto);
    generaHist(altzz, ndati, isto, altezze);

    printf("\nL'istogramma inserito e':\n\n");
    printHist(altzz, ndati, isto, altezze);
    printf("\n\n");
}


// Chiede all'utente quanti dati voglia visualizzare
int askAscisse() {
    int n;
    do {
        printf("\nQuante colonne vuoi rappresentare (max %d)? ", MAXCOL);
        scanf("%d", &n);
    } while ((n < 0) || (n > MAXCOL));
    return n;
}

/* Chiede all'utente di inserire le altezze delle _size_ colonne dell'istogramma,
 * e salva i dati nell'array _altezze[]_
*/
void askDati(int altezze[], int size) {
    printf("Inserire le altezze delle colonne (max %d):\n", MAXHEIGHT);
    for (int j = 0; j < size; j++) {
        do {
            printf("  Colonna %d: ", j);
            scanf("%d", &altezze[j]);
        } while ((altezze[j] < 0) || (altezze[j] > MAXHEIGHT));
    }
    printf("\n");
}

// Ritorna il massimo elemento contenuto in un _array[]_ di interi di misura _size_
int max(int array[], int size) {
    int currmax = 0;
    for (int j = 0; j < size; j++) if (array[j] > currmax) currmax = array[j];
    return currmax;
}

// Inizializza la matrice _m[][]_ riempiendola di EMPTY
void initMatr(int righe, int colonne, char m[righe][colonne]) {
    for (int r = 0; r < righe; r++) {
        for (int c = 0; c < colonne; c++) m[r][c] = EMPTY;
    }
}

/* Popola la matrice _hist[][]_ con la rappresentazione grafica
 * dell'istogramma descritto in _altezze[]_, conoscendone
 * le due dimensioni _maxHeight_ e _ncolonne_
*/
void generaHist(int maxHeight, int ncolonne, char hist[maxHeight][ncolonne], int altezze[]) {
    // disegno per colonne, da sinistra verso destra, e dal basso verso l'alto
    for (int col = 0; col < ncolonne; col++) {
        for (int rig = maxHeight - 1; rig > maxHeight - altezze[col] - 1; rig--) {
            hist[rig][col] = TRATTO;
        }
    }
}

// Disegna l'istogramma
void printHist (int maxHeight, int ncolonne, char hist[maxHeight][ncolonne], int altezze[]) {
    int rig, col;
    for (rig = 0; rig < maxHeight; rig++) {
        for (col = 0; col < ncolonne; col++) {
            if (altezze[col] > 9) printf(" %c  ", hist[rig][col]); // per allineamento, se l'altezza è un numero a due cifre, aggiungo uno spazio preposto --> la barra è sempre in linea con la cifra più a destra
            else printf("%c  ", hist[rig][col]);
        }
        printf("\n");
    }
    
    // piè di pagina
    for (col = 0; col < ncolonne; col++) printf("%d  ", altezze[col]);
    printf("\n");
    for (col = 0; col < ncolonne; col++) {
        if (altezze[col] > 9) printf(" %d  ", col);
        else printf("%d  ", col);
    }
}



/*
*               0  1  2  .   ncol
0               -  -  -  .    -
1               -  -  -  .    -
2               -  -  -  .    -
.               .  .  .  .    .
(maxHeight-1)   .  -  -  .    -



*/