/* Si scriva una funzione in C che,
 * dato una matrice di 10x10 interi,
 * ne calcola il determinante.
*/

#define SIZE 3

int det2x2(int m[2][2]);
int sgn(int r, int c);
void creaMinore(int s, int m[s][s], int minore[s-1][s-1], int delRow, int delCol);

// Calcola il determinante di _m[][]_, matrice quadrata di dimensione _s_.
int det(int s, int m[s][s]) {
    if (s == 2) return det2x2(m);

    int minore[s-1][s-1];
    int c, determinante = 0;

    for (c = 0; c < s; c++) {
        creaMinore(s, m, minore, 0, c);
        determinante += (sgn(0, c) * det(s - 1, minore));
    }
    
    return determinante;
}



#include <stdio.h>
int main() {
    /*int matr[SIZE][SIZE] = { {1, 2, 3, 4},
                             {6, 7, 8, 9},
                             {11, 12, 13, 14},
                             {15, 16, 17, 18} };*/
                        
    /*int matr[SIZE][SIZE] = { {1, 2},
                             {3, 4} };*/

    int matr[SIZE][SIZE] = { {1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9} };
    
    printf("\nDeterminante = %d.\n\n", det(SIZE, matr));

    return 0;
}




// Calcola il determinante della matrice 2x2 _m[][]_.
int det2x2(int m[2][2]) {
    return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

/* Popola _minore[][]_ in modo che rappresenti il minore di _m[][]_
 * ottenuto eliminandogli la riga _delRow_ e la colonna _delCol_.
*/
void creaMinore(int s, int m[s][s], int minore[s-1][s-1], int delRow, int delCol) {
    int r = 0, c = 0;

    while (r < delRow) {
        while (c < delCol) {
            minore[r][c] = m[r][c];
            c++;
        }
        c++; // skippo la delCol
        while (c < s) {
            minore[r][c-1] = m[r][c];
            c++;
        }

        r++;
        c = 0;
    }
    r++; // skippo la delRow
    while(r < s) {
        while (c < delCol) {
            minore[r][c] = m[r][c];
            c++;
        }
        c++; // skippo la delCol
        while (c < s) {
            minore[r][c-1] = m[r][c];
            c++;
        }

        r++;
        c = 0;
    }
}

// Ritorna il segno del complemento algebrico dell'elemento in posizione (_r_;_c_).
int sgn(int r, int c) {
    if (((r + c) % 2) == 0) return 1;
    else return (-1);
}