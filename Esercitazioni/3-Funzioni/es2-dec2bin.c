// INPUT: numero intero positivo
// OUTPUT: stampare a video la codifica binaria dell'input

#include <stdio.h>

void printBin (int numero);

int main() {
    int in;

    do {
     printf("Inserire un intero positivo: ");
     scanf("%d", &in);
    } while (in < 0);

    printBin(in);

    return 0;    
}

// NB: la codifica viene stampata in ordine inverso
void printBin(int numero) {
    do {
        printf("%d", numero % 2);
        numero = numero / 2;
    } while (numero > 0);
}