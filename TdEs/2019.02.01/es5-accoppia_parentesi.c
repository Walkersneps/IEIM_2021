/* Si scriva in C una funzione che,
 * data una stringa contenente solo parentesi tonde aperte o chiuse,
 * dice se la stringa rappresenta una sequenza ben formata.
 * Ben formata implica che ad ogni parentesi aperta, ne corrisponde una chiusa,
 * e non esistono parentesi chiuse prima di averle aperte 
 * e/o non rimangono parentesi aperte.
 *  
 *  Esempio 1:
 *      S: ()(()))())(
 *          - Risposta: La stringa NON è ben formata
 *  Esempio 2:
 *      S: ((()()(())))
 *          - Risposta: La stringa è ben formata
 * 
*/
#include <string.h>
#include <stdio.h>

/* Esegue _amount_ shifts a sinistra dei caratteri di _str[]_,
 * a partire dalla posizione _indx_.
 * In pratica, elide _amount_ caratteri da _str[]_ a partire da _indx_.
 *   Es: shiftLeft("giovanni", 3, 2) --> "gionni"
*/
void shiftLeft(char str[], int indx, int amount) {
    for (int i = indx; i <= (strlen(str) - amount); i++)
        str[i] = str[i + amount];
}

void accoppia_parentesi(char str[]) {
    if ( (str[0] == ')') || ((strlen(str) == 2) && (str[1] != ')')) ) {
        printf("\nLa stringa NON e' ben formata.\n\n");
        return;
    }

    if (strlen(str) > 2) {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i+1] == ')' && str[i] == '(') {
                shiftLeft(str, i, 2);
                return accoppia_parentesi(str);
            }
        }
    }

    printf("\nLa stringa e' ben formata.\n\n");
}







int main() {
    char s[100];
    printf("Inserisci la stringa di parentesi: ");
    scanf("%s", s);
    accoppia_parentesi(s);

    return 0;
}
