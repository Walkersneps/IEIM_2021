/* Homework 1 - Esercizio 1
 * Si descriva in  pseudocodice, l’algoritmo per il gioco del tris.
 * Si gioca su una griglia quadrata di 3×3 caselle.
 * A turno, i giocatori scelgono una cella vuota e vi disegnano il proprio simbolo
 * (di solito  un  giocatore  ha  come  simbolo  una "X"  e  l'avversario  una "O").
 * Vince il giocatore che riesce a disporre tre dei propri simboli
 * in linea retta orizzontale, verticale o diagonale.
 * Se la griglia viene riempita senza che nessuno dei giocatori
 * sia riuscito a completare una linea retta di tre simboli, 
 * il gioco finisce  in  parità e la partità è detta "patta".
*/

#include <stdio.h>
#define EMPTY 32 // codice ASCII per 'Space'
#define O 79 // codice ASCII per 'O'
#define X 88 // codice ASCII per 'X'
#define BOARD_SIZE 3 // Massimo 127
#define DIAG_1 1 // Diagonale UP_SX-->DW_DX
#define DIAG_2 2 // Diagonale DW_SX-->UP_DX

char isEven(int n);
void inizializzaBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
char isInBounds(int daValidare);
char casellaOccupata(char riga, char colonna, char inBoard[BOARD_SIZE][BOARD_SIZE]);
void richiediMossa(char board[BOARD_SIZE][BOARD_SIZE], char player);
char controllaRiga(int riga, char board[BOARD_SIZE][BOARD_SIZE]);
char controllaColonna(int colonna, char board[BOARD_SIZE][BOARD_SIZE]);
char controllaDiagonale(char quale, char board[BOARD_SIZE][BOARD_SIZE]);
char controllaVincita(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char winner = 0;
    int turno = 0;
    char board[BOARD_SIZE][BOARD_SIZE];
    inizializzaBoard(board);

    printf("Giocate a TRIS!\n");
    printBoard(board);

    do {
        if (isEven(turno)) richiediMossa(board, O);
        else richiediMossa(board, X);
        turno ++;
        printBoard(board);
        winner = controllaVincita(board);
    } while ((!winner) && (turno < BOARD_SIZE*BOARD_SIZE)); // Mi fermo non appena ho un vincitore oppure ho riempito la board

    if (winner) printf("\n\nHa vinto %c!\n\n", winner);
    else printf("\nPATTA!\n\n");
    
    return 0;
}



char isEven(int n) {
    if (n % 2 == 0) return 1;
    return 0;
}

void inizializzaBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(char i = 0; i < BOARD_SIZE; i++){
        for (char j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY;
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n    ");
    for (int i = 0; i < BOARD_SIZE; i++) printf("%d   ", i+1); // stampo intestazione orizzontale
    for(char r = 0; r < BOARD_SIZE; r++){ // per ogni riga r
        printf("\n%d  ", r+1); // stampo elemento dell'intestazione verticale per la riga corrente
        for (char c = 0; c < BOARD_SIZE; c++) printf(" %c |", board[r][c]);
        printf("\n   --------------");
    }
}

char isInBounds(int daValidare){
    if ((daValidare >= 0) && (daValidare < BOARD_SIZE)) return 1;
    return 0;
}

char casellaOccupata(char riga, char colonna, char inBoard[BOARD_SIZE][BOARD_SIZE]) {
    if (inBoard[riga][colonna] == O || inBoard[riga][colonna] == X) return 1;
    return 0;
}

void richiediMossa(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int riga, colonna;
    printf("\nGiocatore %c:\n", player);
    printf("  In che riga vuoi inserire? ");
    scanf("%d", &riga);
    printf("  In che colonna vuoi inserire? ");
    scanf("%d", &colonna);

    riga--; colonna--;
    //DEBUG   printf("riga: %d, colonna: %d\n", riga, colonna);

    if (isInBounds(riga) && isInBounds(colonna)) { // verifico che sia stata inserita una cella esistente
        if (!casellaOccupata(riga, colonna, board)) { // verifico che la casella non sia già occupata
            board[riga][colonna] = player; // salvo la mossa
            return;
        } else {
            printf("Errore! La casella scelta e' gia' occupata");
            richiediMossa(board, player);
        }
    } else {
        printf("Errore! riga e colonna devono essere minori o uguali a %d.\n", BOARD_SIZE);
        richiediMossa(board, player);
    }
}



/* Tutte le funzioni seguenti ritornano:
 * --> 0 nessun tris
 * --> 1 ha fatto punto O
 * --> 2 ha fatto punto X
*/
char controllaRiga(int riga, char board[BOARD_SIZE][BOARD_SIZE]) {
    char possibleWinner;
    possibleWinner = board[riga][0];
    if (possibleWinner == EMPTY) return 0;

    for (int i = 1; i < BOARD_SIZE; i++) {
        if (board[riga][i] != possibleWinner) return 0;
    }
    
    return possibleWinner;
}

char controllaColonna(int colonna, char board[BOARD_SIZE][BOARD_SIZE]) {
    char possibleWinner;
    possibleWinner = board[0][colonna];
    if (possibleWinner == EMPTY) return 0;

    for (int i = 1; i < BOARD_SIZE; i++) {
        if (board[i][colonna] != possibleWinner) return 0;
    }
    
    return possibleWinner;
}

char controllaDiagonale(char quale, char board[BOARD_SIZE][BOARD_SIZE]) {
    char possibleWinner;

    if (quale == DIAG_1) {
        possibleWinner = board[0][0];
        if (possibleWinner == EMPTY) return 0;
        for (int i = 1; i < BOARD_SIZE; i++) {
            if (board[i][i] != possibleWinner) return 0;
        }
    } else {
        possibleWinner = board[0][BOARD_SIZE-1];
        if (possibleWinner == EMPTY) return 0;
        for (int i = 1; i < BOARD_SIZE; i++) {
            if (board[i][BOARD_SIZE-i-1] != possibleWinner) return 0;
        }
    }

    return possibleWinner;
}


char controllaVincita(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i;
    char winner;

    // Controllo tutte le righe
    for (i = 0; i < BOARD_SIZE; i++) {
        winner = controllaRiga(i, board);
        if (winner) return winner;
    }

    // Controllo tutte le colonne
    for (i = 0; i < BOARD_SIZE; i++) {
        winner = controllaColonna(i, board);
        if (winner) return winner;
    }

    // Controllo le due diagonali
    winner = controllaDiagonale(DIAG_1, board);
    if (winner) return winner;
    winner = controllaDiagonale(DIAG_2, board);
    return winner;
}