/* Data una stringa S1, si scriva una funzione in C che,
 * presa S1 restituisce
 *   1 se esiste una sua permutazione palindroma,
 *   0 altrimenti.
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 128

int find(char daCercare, char *stringa, int size);
char ammettePalindromo(char *stringa, int size);
void eliminaLettera(char *stringa, int indiceDaRimuovere, int size);

int main() {
    char s1[MAX_SIZE];
    int size;

    // Chiedo input
    printf("Dammi una stringa: ");
    scanf("%s", s1);

    size = strlen(s1);
    printf("\n La parola '%s' ", s1);
    if (ammettePalindromo(s1, size)) printf("ammette permutazione palindroma.\n\n");
    else printf("NON ammette permutazione palindroma.\n\n");


    return 0;
}


char ammettePalindromo(char stringa[], int size) {
    int found, limit;
    char letteraCheck, dispari;
    char sgarrato = 0;

    if (size % 2 == 0) dispari = 0;
    else dispari = 1;

    do {
        letteraCheck = stringa[0];      // salvo la prima lettera...
        stringa++; size--;              // ...per poi eliminarla dalla stringa

        found = find(letteraCheck, stringa, size); // cerco la gemella della prima lettera

        if (found < 0) { // letteraCheck non ha gemella
            if (sgarrato || !dispari) return 0; // se la parola iniziale era pari, posso concludere subito. Se era dispari ma avevo già trovato una lettera senza gemella, sono fritto
            else sgarrato = 1; // se la parola iniziale era dispari, posso permettermi di avere una lettera spaiata (in realtà ci sarà per forza)
        }
        else { // letteraCheck ha gemella
            eliminaLettera(stringa, found, size); // elimino la gemella di letteraCheck
            size--;
        }
    } while (size > dispari);

    // sono riuscito a svuotare la stringa --> tutte le lettere avevano una gemella (eccetto 1 se dispari)
    return 1;
}

/* Cerca _daCercare_ nella stringa _stringa_ di dimensione _size_
 * Ritorna l'indice che contiene la prima corrispondenza
 * Se non ci sono corrispondenze, ritorna -1
*/
int find(char daCercare, char *stringa, int size) {
    int i;
    for (i = 0; i < size; i++) if (stringa[i] == daCercare) return i;
    return -1;
}

/* Sovrascrive la stringa eliminando la lettera in posizone _indiceDaRimuovere_
*/
void eliminaLettera(char *stringa, int indiceDaRimuovere, int size) {
    for (int i = indiceDaRimuovere; i < size; i++) stringa[i] = stringa [i + 1];
}
