/* Si scriva la dichiarazione di un’immagine img,
 * come matrice di 800x600 colori.
 * I colori ammissibili sono Rosso, Giallo, Verde, Blu, Bianco e Nero.
 * 
 * Si scriva quindi in C una funzione colori che
 * ricevuto in ingresso img (e basta?),
 * restituisce alla funzione chiamante,
 * tramite una sola invocazione della funzione colori,
 * per ciascun colore,
 * il numero dei pixel che hanno quello specifico colore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGZZ 800
#define ALTZZ 600
#define NCOLORI 6
#define MAX_LUNGH_NOME_COL 7

typedef enum {
    Rosso,
    Giallo,
    Verde,
    Blu,
    Bianco,
    Nero
} Colore;

const char nomiColori[NCOLORI][MAX_LUNGH_NOME_COL] = {
    "Rosso",
    "Giallo",
    "Verde",
    "Blu",
    "Bianco",
    "Nero"
};


void initArray(int a[], int size);
void randomPicture(int altezza, int larghezza, int img[altezza][larghezza]);
void printColori(int occorrenze[]);
void colori(int altezza, int larghezza, int img[altezza][larghezza], int occorrenze[NCOLORI]);


int main() {
    int img[LARGZZ][ALTZZ];
    int npixels[NCOLORI];

    randomPicture(ALTZZ, LARGZZ, img);

    colori(ALTZZ, LARGZZ, img, npixels);

    printColori(npixels);

    return 0;
}

// Inizializza un array _a[]_ di lunghezza _size_ popolandolo con 0
void initArray(int a[], int size) {
    for (int j = 0; j < size; j++) a[j] = 0;
}

// Popola _img[][]_ con colori estratti pseudo-random
void randomPicture(int altezza, int larghezza, int img[altezza][larghezza]) {
    for (int r = 0; r < altezza; r++)
        for (int c = 0; c < larghezza; c++)
            img[r][c] = (rand() % NCOLORI);
}

// Stampa per ogni colore il numero di pixel accesi
void printColori(int occorrenze[]) {
    for (int colore = Rosso; colore <= Nero; colore++)
        printf("\n%s: %d", nomiColori[colore], occorrenze[colore]);
}

/* Inserisce il numero di occorrenze di ogni colore nell'immagine
 * nell'array _occorrenze[]_
*/
void colori(int altezza, int larghezza, int img[altezza][larghezza], int occorrenze[NCOLORI]) {
    initArray(occorrenze, NCOLORI);
    for (int rig = 0; rig < altezza; rig++)
        for (int col = 0; col < larghezza; col++)
            occorrenze[img[rig][col]]++;
}