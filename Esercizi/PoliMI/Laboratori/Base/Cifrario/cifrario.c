/* Si scriva un programma in C che data una lettera minuscola ed un intero dispari,
 * stampa a video il valore cifrato della lettera.
 * Considerando i caratteri minuscoli come un insieme ordinato “circolare”,
 * dato il carattere in ingresso, il carattere cifrato sarà
 * il carattere inserito più il valore intero
 *      Esempio:
 *        •Input 1: a, 3 - Output 1: d
 *        •Input 2: z, 5 – Output 2: e
*/

#include <stdio.h>
#define NLETTERE 26

// Esegue la cifratura
char cifra(char plaintxt, int key) {
    char cifrato; // conterrà il risultato

    int adjusted_key = key % NLETTERE; // rimuovo parte multipla di NLETTERE (eventuali cicli alfabetici ripetuti)

    int somma = plaintxt + adjusted_key; // applico la cifratura

    // se vado out of bounds, ricomincio dalla 'a'
    if (somma > 'z') {
        cifrato = somma - NLETTERE;
    } else {
        cifrato = somma;
    }

    return cifrato;
}


// Verifica che l'argomento sia una lettera minuscola
int isLowercaseLetter(char check) {
    if ((check >= 'a') && (check <= 'z')) return 1;
    else return 0;
}

// -- MAIN
int main() {
    char plntxt;
    int key, ans;

    // Acquisisco input
    do {
        printf("Inserire carattere alfabetico minuscolo da cifrare: ");
        scanf(" %c", &plntxt);
        printf("Inserire chiave numerica di traslazione: ");
        scanf("%d", &key);
    } while (!isLowercaseLetter(plntxt)); // insisto finchè non ho una lettera minuscola in input


    // Eseguo la cifratura
    ans = cifra(plntxt, key);

    // Rispondo
    printf("\n%c + %d --> %c (ASCII # %d)\n", plntxt, key, ans, ans);


    return 0;
}



// inutilizzato
char cifra_old(char plaintxt, int key) {
    char cifrato;

    int ciclature = key/NLETTERE; // quanti giri extra ho fatto
    int adjusted_key = key - (ciclature*NLETTERE);

    char somma = plaintxt + adjusted_key;
    if (somma > 'z') cifrato = somma - NLETTERE - 1;
    else cifrato = somma;

    return cifrato;
}
