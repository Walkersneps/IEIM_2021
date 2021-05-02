/* Scrivere un programma che:
 *  - sappia gestire un'immagine 512x512:
 *     + immagine a calori, ogni pixel definito da un colore e una tonalità
 *     + colori ammissibili: viola, arancione, verde, blu, rosso, giallo
 *     + 1024 possibili tonalità per ogni colore
 *  - abbia una funzione colori() che:
 *     + prenda in input l'immagine
 *     + restituisca il numero di pixel di ogni gradazione, per ogni colore
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 512
#define NTOL 1024
#define NCOL 6
#define MAX_COL_NAME_LENGTH 10

typedef enum {
    Viola,
    Arancione,
    Verde,
    Blu,
    Rosso,
    Giallo
} Col;

typedef struct {
    Col colore;
    int tonalita;
} Pixel;


char nomi_colori[NCOL][MAX_COL_NAME_LENGTH] = {
    "Viola",
    "Arancione",
    "Verde",
    "Blu",
    "Rosso",
    "Giallo"
};


void popolaImmagine(Pixel immagine[DIM][DIM]);
void initOccorrenze(int m[NCOL][NTOL]);
void contaOccorrenze(Pixel immagine[DIM][DIM], int occorrenze[NCOL][NTOL]);
void colori(Pixel immagine[DIM][DIM], int occorrenze[NCOL][NTOL]);


int main() {
    Pixel immagine[DIM][DIM];
    int occorrenze[NCOL][NTOL];

    popolaImmagine(immagine);
    initOccorrenze(occorrenze);
    colori(immagine, occorrenze);

    return 0;
}


void popolaImmagine(Pixel immagine[DIM][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            immagine[i][j].colore = rand() % NCOL;
            immagine[i][j].tonalita = rand() % NTOL;
        }
    }
}

void initOccorrenze(int m[NCOL][NTOL]) {
    for (int i = 0; i < NCOL; i++) {
        for (int j = 0; j < NTOL; j++) {
            m[i][j] = 0;
        }
    }
}

void contaOccorrenze(Pixel immagine[DIM][DIM], int occorrenze[NCOL][NTOL]) {
    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            occorrenze[immagine[i][j].colore][immagine[i][j].tonalita]++;
        }
    }
}

void printOccorrenze(int occorrenze[NCOL][NTOL]) {
    int col, shade;
    for (col = 0; col < NCOL; col++) {
        printf("\nColore %s:\n", nomi_colori[col]);
        for (shade = 0; shade < NTOL; shade++) {
            if (occorrenze[col][shade] > 0) printf("  Tonalita' %d: %d pixels\n", shade, occorrenze[col][shade]);
        }
    }
}

void colori(Pixel immagine[DIM][DIM], int occorrenze[NCOL][NTOL]) {
    contaOccorrenze(immagine, occorrenze);
    printOccorrenze(occorrenze);
}