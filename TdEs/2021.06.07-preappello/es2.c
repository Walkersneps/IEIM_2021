/* Un numero si dice di SANTA se è
 * positivo, primo, maggiore di 11 e dispari,
 * si scriva una funzione che restituisce al chiamante (NON STAMPA A VIDEO)
 * tutti i numeri SANTA tra -1512 e 1512.
*/


#define MINSANTA -1512
#define MAXSANTA 1512
char isPrimo(int n);

/* Riempie _santaTrovati[]_ con i numeri richiesti,
 * Ritorna il numero di elementi inseriti
 *
 * NB: Assicurarsi che _santaTrovati[]_ disponga dello spazio necessario
 *     (un safe limit abbondante può essere MAXSANTA-11)
*/
int trovaSanta(int santaTrovati[]) {
    int i;
    int ntrovati = 0;

    //for (i = MINSANTA; i <= MAXSANTA; i++) { // anzichè un ciclo di questo tipo, e controllare poi tutte le condizioni, mi conviene impostare per efficienza:
    for (i = 13; i < MAXSANTA; i += 2) { // soddisfo già 'positivo', 'maggiore di 11', e 'dispari'
        if (isPrimo(i)) {
            santaTrovati[ntrovati] = i;
            ntrovati++;
        }
    }

    return ntrovati;
}

// Ritorna 1 se _n_ è un numero primo, 0 altrimenti
char isPrimo(int n) {
    // NB: se avessi usato il ciclo "abbondante", avrei dovuto prima positivizzare n 
    int j;
    for (j = 2; j < n; j++)
        if (n % j == 0)
            return 0;
    return 1;
}



#include <stdio.h>
int main() {
    int s[MAXSANTA];
    int size;

    size = trovaSanta(s);

    for (int i = 0; i < size; i++)
        printf(" %d", s[i]);

    printf("\n");
    return 0;
}