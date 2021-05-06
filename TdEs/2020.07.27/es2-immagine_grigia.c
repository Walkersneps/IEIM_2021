/* Si scriva la dichiarazione di un’immagine img,
 * come matrice di 1024x1024 pixel,
 * dove un pixel puo’ essere Bianco, Nero, o una delle 254 gradazioni di grigio.
 * Si scriva quindi in C una funzione ricorsiva colore che
 * ricevuta in ingresso la matrice (decidete voi come “passarla”)
 * restituisce alla funzione chiamante, tramite una sola invocazione della funzione colore,
 * il numero dei pixel con un certo colore.
*/

/* Convenzione:
 *     0 = Bianco
 * 1-254 = Tutti i Grigi
 *   255 = Nero
 * 
 * Elementi di tipo char mi sono sufficienti (giusti giusti).
*/
//char img[1024][1024];


/* Ritorna il numero di pixels in _m[][]_ che sono di _colore_.
 *  NB: prima chimata con _iter_ = 0.
*/
int pixels(char *m, char colore, int iter) {
    if (iter == 1024*1024) {
        if (*m == colore) return 1;
        else return 0;
    }
    
    if (*m == colore)
        return (1 + pixels(m + 1, colore, iter + 1));
    else
        return pixels(m + 1, colore, iter + 1);
}



/* Ritorna il numero di pixels in _m[][]_ che sono di _colore_.
 *  NB: lavora tramite iterazione e non ricorsione
*/
int pixels_non_ric(char m[1024][1024], char colore) {
    int r, c, count = 0;
    for (r = 0; r < 1024; r++)
        for (c = 0; c < 1024; c++)
            if (m[r][c] == colore)
                count++;
    return count;
}




// Verifica
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CERCATO 13
int main() {
    srand(time(NULL));

    char img[1024][1024];

    for (int r = 0; r < 1024; r++)
        for (int c = 0; c < 1024; c++)
            img[r][c] = rand() % 255;

    printf("\nPixels di colore %d (ricorsiva): %d", CERCATO, pixels(img, CERCATO, 0));
    printf("\nPixels di colore %d (non ricorsiva): %d\n\n", CERCATO, pixels_non_ric(img, CERCATO));

    return 0;
}

