/* Una matrice è BERSANI se è:
 *  - quadrata,
 *  - di un numero di righe dispari,
 *  - tale che gli elementi sulla diagonale sono in ordine crescente
 *      (i.e. a(i,j) < a(i+1,j+1)).
 * 
 * Si scriva una funzione che, recuperata in ingresso una matrice,
 * restituisce 1 se BERSANI, 0 altrimenti.
*/

int bersani(int r, int c, int m[r][c]) {
    int i;
    if (r != c) return 0; // dev'essere quadrata
    if (r % 2 != 1) return 0; // il numero di righe dev'essere dispari

    for (i = 1; i < r; i++)
        if (m[i][i] < m[i-1][i-1])
            return 0;

    return 1;
}





#include <stdio.h>
#define r 3
#define c 3
int main() {
    int mat[r][c] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    
    printf("La funzione bersani ritorna: %d\n", bersani(r, c, mat));

    return 0;
}