/* Data una immagine di 500x250 pixel, in cui
 * ciascun pixel è codificato su una scala di 256 grigi,
 * si scriva una funzione in C che,
 * preso un video (una sequenza di 5 immagini) in ingresso,
 * restituisce al chiamante (aka NON stampa a video)
 * le occorrenze di grigi per ciascuna immagine.
*/

#define WIDTH 250
#define HEIGHT 500
#define NFRAMES 5
#define DETAIL 256

typedef struct immagine {
    char pixels[HEIGHT][WIDTH];
    // NB: se DETAIL > 258, bisogna dichiarare _pixels[][]_ come int[][]
} Immagine;

typedef struct video {
    Immagine frames[NFRAMES];
} Video;

/* Popola la tabella _occorrenze[][]_ con il numero di occorrenze
 * di ogni sfumatura di grigio per ogni frame contenuto in _v_,
 * assumendo che _v_ sia composto da NFRAMES fotogrammi e
 * considerando una risoluzione di DETAIL sfumature di grigi
*/
void countShades(Video v, char occorrenze[NFRAMES][DETAIL]) {
    for (int f = 0; f < NFRAMES; f++) { // per ogni frame in _v_
        for (int r = 0; r < HEIGHT; r++) {
            for (int c = 0; c < WIDTH; c++) {
                occorrenze[f][v.frames[f].pixels[r][c]]++;
            }
        }
    }
}