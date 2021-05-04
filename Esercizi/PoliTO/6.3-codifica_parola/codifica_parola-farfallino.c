/* Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera.
 * La frase è terminata dall’introduzione del carattere di invio.
 * La frase contiene sia caratteri maiuscoli che caratteri minuscoli,
 * e complessivamente al più 100 caratteri.
 * Il programma deve svolgere le seguenti operazioni:
 *   • visualizzare la frase inserita;
 *   • costruire una nuova frase tale che ogni lettera vocale
 *     presente nella frase di partenza sia seguita
 *     dalla lettera ’f’ (se la vocale è minuscola)
 *     o dalla lettera ’F’ (se la vocale è maiuscola)
 *     nella nuova frase.
 *     Il programma deve memorizzare la nuova frase in una opportuna variabile.
 *   • visualizzare la nuova frase.
 * 
 * Ad esempio, la frase "VacAnze di NaTAle" diviene "VafcAFnzef dif NafTAFlef".
*/

#include <stdio.h>
#include <string.h>
#define MAX_CARATTERI 100

char isVocale(char c);
char isUppercase(char c);
void ins(char c, char inString[], char index);
void farfallino(char s[]);

int main() {
    char inserimento[MAX_CARATTERI];
    char ans[2*MAX_CARATTERI];

    printf("Inserisci una frase di massimo %d caratteri: ", MAX_CARATTERI);
    gets(inserimento);
    strcpy(ans, inserimento);

    farfallino(ans);

    printf("\nIl farfallino di \"%s\" e' \"%s\".\n\n", inserimento, ans);

    return 0;
}

// NB: assicurarsi che s abbia abbastanza spazio
void farfallino(char s[]) {
    for (int p = 0; p < strlen(s); p++) {
        if (isVocale(s[p])) {
            if (isUppercase(s[p])) ins('F', s, p+1);
            else ins('f', s, p+1);

            p++; // skippo la 'f' o 'F' appena inserita, che sicuramente non è una vocale lol
        }
    }
}

/* Inserisce _c_ in _inString[]_ alla posizone _index_.
 * Dopo l'inserimento, sarà vera inString[index]==c.
*/
void ins(char c, char inString[], char index) {
    // Eseguo uno shift a destra di tutti i caratteri da _index_ in poi, per far spazio a _c_
    for (int i = strlen(inString) + 1; i > index; i--) // +1 perchè voglio portarmi appresso anche il terminatore
        inString[i] = inString[i - 1];
    
    // Inserisco il carattere
    inString[index] = c;
}

char isVocale(char c) {
    if (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' ||
        c == 'U') return 1;
    else return 0;
}

char isUppercase(char c) {
    if ( (c >= 'A') && (c <= 'Z') ) return 1;
    else return 0;
}