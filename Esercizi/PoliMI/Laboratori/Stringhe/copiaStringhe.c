/* Si scriva un programma in C che, data una stringa, la copi in una seconda,
 * senza usare la funzione strcpy
*/

#include <stdio.h>
#define DIM 128

int main() {
    // Alloco memoria
    char str1[DIM], str2[DIM];
    int i = 0;
    int length = 0;

    printf("Inserisci una stringa di massimo %d caratteri: ", DIM-1);
    scanf("%s", str1);

    // Determino la lunghezza di str1
    while ((str1[length] != '\0') && (length <= DIM)) length++;

    // Copio carattere per carattere str1 --> str2
    for (i = 0; i < length; i++) str2[i] = str1[i];

    // Mostro risultato
    printf("\nHai fornito \"%s\" in str1\n", str1);
    printf("Ho copiato str1 --> str2 = \"%s\"\n", str2);

    return 0;
}