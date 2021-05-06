/* Data una immagine di 512x512 pixel, in cui
 * ciascun pixel è codificato su una scala di 1024 grigi,
 * si scriva una funzione in C che,
 * preso un video (una sequenza di 128 immagini) in ingresso,
 * restituisce al chiamante (aka NON stampa a video)
 * le occorrenze di grigi per ciascuna immagine.
*/

#define RES 1024
#define DIM 512
#define FRAMES 128

typedef struct {
    int pixels[DIM][DIM];
} Immagine;

typedef struct {
    Immagine frames[FRAMES];
} Video;


/* Riempie la matrice _occorrenze[][]_ in modo che l'elemento _occorrenze[i][j]_ rappresenti
 * il numero di pixel accesi alla j-esima sfumatura di grigio nell'i-esimo frame del video _v_.
*/
void calcola_occorrenze(Video v, int occorrenze[FRAMES][RES]) {
    for (int frame = 0; frame < FRAMES; frame++)
        for (int riga = 0; riga < DIM; riga++)
            for (int col = 0; col < DIM; col++)
                occorrenze[frame][v.frames[frame].pixels[riga][col]]++;
}