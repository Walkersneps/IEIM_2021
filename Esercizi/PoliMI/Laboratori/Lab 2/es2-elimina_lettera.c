/* Scrivere un programma che acquisica in ingresso una stringa ed un carattere.
 *  • Il programma deve poi creare una nuova stringa
 *     ottenuta rimuovendo dalla stringa originale il carattere inserito.
*/

#include <stdio.h>
#include <string.h>
#define MAXLENGHT 40

int rimuovi(char daStringa[], int diLunghezza, char lettera);
int find(char lettera, char inStringa[], int diLunghezza);
void shiftLeft(char str[], int size, int index);
void tronca(char stringa[], int dopo);

int main() {
    char toDel;
    char str[MAXLENGHT];

    printf("\nInserisci una parola: ");
    scanf("%s", &str);
    printf("Quale lettera vuoi rimuoverle?: ");
    scanf(" %c", &toDel);

    printf("\nRimuovendo tutte le '%c' da '%s', si ottiene: ", toDel, str);
    tronca(str, rimuovi(str, strlen(str), toDel)-1);
    printf("%s", str);

    return 0;
}

/* Esegue uno shift a sinistra degli elementi di _str[]_ a partire dalla posizione _index_
 *
 * NB: _str[index]_ è il primo elemento che sarà *sovrascritto*
 * NB: tenere presente che l'operazione decrementerà di 1 la lunghezza effettiva di _str[]_
*/
void shiftLeft(char str[], int size, int index) {
    for (int i = index; i < size-1; i++) str[i] = str[i+1];
}

/* Ritorna l'indice della prima occorrenza di _lettera_ nella stringa _inStringa_
 * Ritorna -1 se non trovato
*/
int find(char lettera, char inStringa[], int diLunghezza) {
    for (int i = 0; i < diLunghezza; i++) if (inStringa[i] == lettera) return i;
    return -1;
}

/* Rimuove dalla stringa tutte le occorrenze di _lettera_.
 * Ritorna la nuova lunghezza della stringa
*/
int rimuovi(char daStringa[], int diLunghezza, char lettera) {
    int t = find(lettera, daStringa, diLunghezza);
    if (t < 0) { // lettera non trovata
        return diLunghezza;
    } else { // lettera trovata
        shiftLeft(daStringa, diLunghezza, t);
        rimuovi(daStringa, diLunghezza - 1, lettera);
    }
}

// Inserisce il terminatore della stringa dopo l'indice _dopo_
void tronca(char stringa[], int dopo) {
    stringa[dopo+1] = '\0';
}