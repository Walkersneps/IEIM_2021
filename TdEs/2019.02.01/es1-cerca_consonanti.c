/* Si scriva in C una funzione ricorsiva che,
 * data in ingresso una stringa, restituisce al chiamante
 * il numero delle consonanti presenti nella stringa.
 * La funzione può usare la funzione vocale che,
 * dato un carattere, restituisce:
 *      - 1 se il carattere è una vocale,
 *      - 0 altrimenti.
 * Il prototipo della funzione vocale è il seguente:
 *       int vocale(char carattere);
*/


int vocale(char carattere);

int contaConsonanti(char str[], int count) {
    if (str[0] == '\0') return count; // stringa esaurita
    
    if (!vocale(str[0])) count++;

    str++;
    return contaConsonanti(str, count); 
}





#include <stdio.h>
#define STRSZ 50
int main() {
    char s[STRSZ];
    printf("Inserisci una stringa: ");
    scanf(" %s", s);

    printf("\nLa stringa \"%s\" contiene %d consonanti.\n\n", s, contaConsonanti(s, 0));
    return 0;
}

int vocale(char carattere) {
    switch (carattere) {
        case 'a': return 1; break;
        case 'e': return 1; break;
        case 'i': return 1; break;
        case 'o': return 1; break;
        case 'u': return 1; break;
        default: return 0; break;
    }
}


