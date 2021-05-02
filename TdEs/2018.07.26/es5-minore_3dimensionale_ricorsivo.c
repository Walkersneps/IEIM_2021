/* Si scriva in C una funzione ricorsiva che,
 * dato un array n-dimensionale di RxCxZ interi,
 * restituisca la posizione, nelle sue coordinate r, c, z
 * (con r<R, c<C, z<Z),
 * dell’elemento minore presente nell’array.
 * 
 * NOTA: l’array è stato popolato in modo da non avere
 *       alcuna ripetizione nei valori al suo interno
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 3
#define C 4
#define Z 5


void calcolaIndici(int, int*);
void minIndex(int*, int, int, int*); // è la funzione richiesta
int rndsgn();


int main() {
    //int coordinateMinimo[3];
    int datiMin[4];
    int arr[R][C][Z];
    srand(time(NULL));

    // Popolo l'array
    for (int i = 0; i < R; i++)
        for (int j =  0; j < C; j++)
            for (int k = 0; k < Z; k++)
                arr[i][j][k] = (rndsgn() * rand());

    // Avvio la ricorsione
    //cercaMinimo(arr, coordinateMinimo, 0, RAND_MAX);
    minIndex(arr, 0, RAND_MAX, datiMin);

    // Mostro risultato
    //printf("\nIl Minimo e' %d\nIn posizione r = %d, c = %d, z = %d\n\n", arr[coordinateMinimo[0]][coordinateMinimo[1]][coordinateMinimo[2]], coordinateMinimo[0], coordinateMinimo[1], coordinateMinimo[2]);
    printf("\nIl Minimo e' %d\nIn posizione r = %d, c = %d, z = %d\n\n", datiMin[3], datiMin[0], datiMin[1], datiMin[2]);

    return 0;
}


// Calcola gli indici r, c, z corrispondenti al sequenziale e li inserisce in _indexes[]_
void calcolaIndici(int sequenziale, int indexes[3]) {
    indexes[0] = (sequenziale / (C*Z));     // r
    indexes[1] = (sequenziale % (C*Z)) / Z; // c
    indexes[2] = (sequenziale % (C*Z)) % Z; // z
}

void minIndex(int *a, int iter, int lastMin, int ans[]) {
    if (iter == R*C*Z) return;

    if (*a < lastMin) {
        calcolaIndici(iter, ans);
        ans[3] = *a;

        minIndex(a + 1, iter + 1, *a, ans);
    } else
        minIndex(a + 1, iter + 1, lastMin, ans);
}

// Genera un segno random
int rndsgn() {
    if (rand() % 2) return 1;
    else return -1;
}

/*
/* Salva in _coords[]_ le coordinate che contengono
 * l'elemento minimo di _a[][][]_
/
void cercaMinimo(int a[R][C][Z], int coords[], int startIndex, int lastMin) {
    // Se ho già letto tutto l'array, esco dalla funzione
    if (startIndex == R*C*Z)
        return;
    
    // Sbobino indici posizionali
    int r, c, z;
    r = startIndex / (C*Z);
    c = (startIndex % (C*Z)) / Z;
    z = (startIndex % (C*Z)) % Z;

    if (a[r][c][z] < lastMin) { // Nuovo minimo trovato
        // Salvo le coordinate del nuovo minimo
        coords[0] = r;
        coords[1] = c;
        coords[3] = z;

        // Chiamo ricorsivamente la funzione, con l'elemento corrente come nuovo minimo
        cercaMinimo(a, coords, startIndex + 1, a[r][c][z]);
    } else {
        cercaMinimo(a, coords, startIndex + 1, lastMin);
    }
}
*/




