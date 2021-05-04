/* Si realizzi in C una funzione che,
 * date due stringhe,
 * verifica se una è una permutazione dell’altra.
*/

#include <string.h>

int cerca(char c, char inString[]);
void shiftLeft(char s[], int index);

char sonoPermutate(char s1[], char s2[]) {
    /* Le due stringhe sono una la permutazione dell'altra se
     * per ogni char in una corrisponde un char uguale nell'altra.
     * Quindi effettuo questa verifica e se va a buon fine
     * accorcio le due stringhe eliminando i caratteri verificati
     * (come se si annichilissero tra loro).
     * Appena trovo un carattera che non ha omologo,
     * concoludo che le due stringhe non sono permutazioni.
    */
   
   if(strlen(s1) < 1) return 1; //se ho già svuotato s1 senza aver mai ritornato, vuol dire che ogni char aveva omologo in s2
   
   int pos = cerca(s1[0], s2);

   if (pos < 0) return 0;

   s1++;
   shiftLeft(s2, pos);
   return sonoPermutate(s1, s2);
}


/* Ritorna la posizione della prima occorrenza di _c_ in _inString[]_.
 * Se non trovato, ritorna -1.
*/
int cerca(char c, char inString[]) {
    for (int i = 0; i < strlen(inString); i++)
        if (inString[i] == c) return i;
    return -1;
}

/* Esegue uno shift a sinistra degli elementi di _s[]_, a partire dalla posizione _index_.
 * In pratica, sta eliminando il carattere in posizione _index_ da _s[]_
*/
void shiftLeft(char s[], int index) {
    for (int i = index; i < strlen(s); i++) // l'ultima iterazione copierà il terminatore
        s[i] = s[i + 1];
}





// Per verifica
#include <stdio.h>
#define SIZE 100
int main() {
    char s1[SIZE], s2[SIZE], save[SIZE];

    printf("\nInserisci s1: ");
    scanf("%s", s1);
    printf("Inserisci s2: ");
    scanf("%s", s2);
    strcpy(save, s2);

    if(sonoPermutate(s1, s2)) printf("\n\"%s\" e' una permutazione di \"%s\".\n\n", s1, save);
    else printf("\n\"%s\" NON e' una permutazione di \"%s\".\n\n", s1, save);

    return 0;
}