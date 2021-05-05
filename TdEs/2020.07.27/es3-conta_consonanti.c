/* Scrivere una funzione C che
 * presa in ingresso una stringa di caratteri minuscoli
 * (si suppone che la stringa sia corretta e coerente con la specifica),
 * restituisce al chiamante il numero delle consonanti presenti nella stringa.
*/

#include <string.h>

int consonanti(char s[]) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == 'u' ) {
                continue;
            } else {
                count++;
            }
    }

    return count;
}


#include <stdio.h>
int main() {
    char stringa[100];
    printf("\nInserisci una stringa minuscola: ");
    scanf("%s", stringa);

    printf("\nLa stringa \"%s\" ha %d consonanti.\n\n", stringa, consonanti(stringa));

    return 0;
}