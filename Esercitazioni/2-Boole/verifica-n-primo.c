/* Si scriva un programma in C che verifichi se il numero intero
 * inserito dall'utente è un numero primo.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int input;

    do {
        printf("Inserisci un intero positivo: ");
        scanf("%d", &input);
    } while (input <= 0);

    for (int i = 2; i < sqrt(input); i++) {
        if (input % i == 0) {
            printf("%d NON e' un numero primo.\n", input);
            return 0;
        }   
    }
    
    printf("%d e' un numero primo.\n", input);
    return 0;
}