// INPUT: numero intero positivo
// OUTPUT: stampare a video la codifica binaria dell'input

#include <stdio.h>
#include <math.h>

int bitNecessari(int numero);
void toBase2_inverso(int base10, int *destinazione);
void printBin(int *codificaInversa, int size);

int main() {
    int base10;

    do {
        printf("Inserire un numero positivo in base 10: ");
        scanf("%d", &base10);
    } while (base10 <= 0);

    // Converto
    int base2[bitNecessari(base10)];
    toBase2_inverso(base10, base2);

    printf("\n%d |10 = ", base10);
    printBin(base2, bitNecessari(base10));
    printf(" |2\n\n");

    return 0;
}

int bitNecessari(int numero) {
    return log2(numero) + 1;
    //return (log(numero) / log(2)) + 1;
}

void toBase2_inverso(int base10, int *destinazione) {
    int i = 0;
    do {
        destinazione[i] = base10 % 2;
        base10 = base10 / 2;
        i++;
    } while (base10 > 0);
}

void printBin(int *codificaInversa, int size) {
    for (int j = size - 1; j >= 0; j--) {
        printf("%d", codificaInversa[j]);
    }
}
