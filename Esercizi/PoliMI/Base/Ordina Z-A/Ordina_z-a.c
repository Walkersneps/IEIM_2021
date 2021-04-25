/* Dati due caratteri in input,
 * verificare che siano alfabetici
 * e restituirli disposti in ordine alfabetico inverso.
*/

#include <stdio.h>

char toUppercase (char c) {
    if (c > 'Z') { // ho una minuscola
        return c - 32;
    } else { // ho già una maiuscola
        return c;
    }   
}


int isLetter (char c) {
    if ( ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ) {
        return 1;
    } else {
        return 0;
    }
}

// ##### MAIN vero #####
int main() {
    char c1, c2;

    // Acquisisco i caratteri input utente
    do {
        printf("\nInserisci il primo carattere alfabetico: ");
        scanf(" %c", &c1); //TODO: prova con lo spazio
        printf("Inserisci il secondo carattere alfabetico: ");
        scanf(" %c", &c2);
    } while (!isLetter(c1) || !isLetter(c2)); // Insisto finchè non ho due lettere

    // Maiuscolizzo tutto
    c1 = toUppercase(c1);
    c2 = toUppercase(c2);

    if (c1 > c2) {
        printf("\nDisposti in ordine alfabetico inverso --> %c %c\n\n", c1, c2);
    } else if (c1 < c2) {
        printf("\nDisposti in ordine alfabetico inverso --> %c %c\n\n", c2, c1);
    } else {
        printf("\n%c e %c sono lo stesso carattere.\n\n", c1, c2);
    }

    return 0;
}



// ##### TEST di isLetter() #####
int _main() {
    char c1, c2;

    printf("\nInserisci il primo carattere alfabetico: ");
    scanf("%c", &c1); //TODO: prova con lo spazio
    printf("Inserisci il secondo carattere alfabetico: ");
    scanf(" %c", &c2);

    printf("\nHo letto %c _ %c\n", c1, c2);
    printf("isLetter(c1) --> %d\n", isLetter(c1));
    printf("isLetter(c2) --> %d\n", isLetter(c2));

}