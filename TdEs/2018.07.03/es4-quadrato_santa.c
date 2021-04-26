/* Un "quadrato santa" è una scacchiera quadrata di lato n
 * con un simbolo su ogni casella, in modo che
 * ognuno di essi compaia una e una sola volta in ogni riga e in ogni colonna.
 * Si scriva una funzione in C che data una matrice di 9x9 caratteri tutti minuscoli,
 * restituisca al chiamante se tale matrice sia un quadrato latino o meno.
*/

// sto testo non l'ho tanto capito...

#include <stdio.h>
#define SIZE 3
#define AS_CHARS 1
#define AS_NUMS 0

char esisteUnivocoSuRiga(char elemento, char riga, char inMatrice[SIZE][SIZE]);
char esisteUnivocoSuColonna(char elemento, char colonna, char inMatrice[SIZE][SIZE]);
char isCarattereLatinoMinuscolo(char x);
char isQuadratoSantaLatino(char matrice[SIZE][SIZE]);
void stampaMatriceAsChars(char matrice[SIZE][SIZE]);
void stampaMatriceAsNums(char matrice[SIZE][SIZE]);
void stampaMatrice(char matrice[SIZE][SIZE], char display);

int main() {
    char qs[SIZE][SIZE];
    char opt;

    printf("Costruisci il tuo quadrato:");
    for (int i = 0; i < SIZE; i++) {
        printf("\nRiga %d:\n", i+1);
        for (int j = 0; j < SIZE; j++) {
            printf("  R%d - C%d: ", i+1, j+1);
            scanf(" %c", &qs[i][j]);
        }
    }

    do {
        printf("Te la stampo per (c)aratteri o per (n)umeri? ");
        scanf(" %c", &opt);
    } while (opt != 'c' && opt !='n');

    if (opt == 'c') stampaMatrice(qs, AS_CHARS);
    else stampaMatrice(qs, AS_NUMS);

    if (isQuadratoSantaLatino(qs)) printf("\nLa matrice inserita e' un 'quadrato santa' composto da soli caratteri latini minuscoli.\n\n");
    else printf("\nLa matrice inserita non e' un 'quadrato santa' oppure contiene caratteri non latini minuscoli.\n\n");
    
    return 0;
}


/* Restituisce:
 * 1 se la _riga_ di _inMatrice_ contiene al una e una sola volta _elemento_
 * 0 altrimenti (_elemento_ non trovato o contenuto più di 1 volta)
*/
char esisteUnivocoSuRiga(char elemento, char riga, char inMatrice[SIZE][SIZE]) {
    char trovato = 0;
    for (int i = 0; i < SIZE; i++) {
        if (inMatrice[riga][i] == elemento) {
            if (trovato) return 0; // non univoco
            else trovato = 1;
        }
    }

    if (trovato) return 1;
    else return 0; // mai trovato
}

/* Restituisce:
 * 1 se la _colonna_ di _inMatrice_ contiene al una e una sola volta _elemento_
 * 0 altrimenti (_elemento_ non trovato o contenuto più di 1 volta)
*/
char esisteUnivocoSuColonna(char elemento, char colonna, char inMatrice[SIZE][SIZE]) {
    char trovato = 0;
    for (int i = 0; i < SIZE; i++) {
        if (inMatrice[i][colonna] == elemento) {
            if (trovato) return 0; // non univoco
            else trovato = 1;
        }
    }

    if (trovato) return 1;
    else return 0; // mai trovato
}

/* Restituisce:
 * 1 se _x_ è un carattere alfabetico latino minuscolo
 * 0 altrimenti
*/
char isCarattereLatinoMinuscolo(char x) {
    if ((x >= 'a') && (x <= 'z')) return 1;
    else return 0;
}

/* Restituisce:
 * 1 se la matrice è un quadrato santa di soli caratteri latini
 * 0 altrimenti
*/
char isQuadratoSantaLatino(char matrice[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if(!isCarattereLatinoMinuscolo(matrice[0][i])) return 0;
        for (int j = 0; j < SIZE; j++) {
            if(!esisteUnivocoSuColonna(matrice[0][i], j, matrice)) return 0;
            if(!esisteUnivocoSuRiga(matrice[0][i], j, matrice)) return 0;
        }
    }
    return 1;
}

/* Stampa a video _matrice_.
 * L'argomento _display_ permette di scegliere se stamparne gli elementi come caratteri o come numeri
*/ 
void stampaMatrice(char matrice[SIZE][SIZE], char display) {
    if (display == AS_CHARS) stampaMatriceAsChars(matrice);
    else stampaMatriceAsNums(matrice);
}

void stampaMatriceAsChars(char matrice[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j = 0; j < SIZE; j++) printf("  %c", matrice[i][j]);
    }
}

void stampaMatriceAsNums(char matrice[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j = 0; j < SIZE; j++) printf("  %d", matrice[i][j]);
    }
}