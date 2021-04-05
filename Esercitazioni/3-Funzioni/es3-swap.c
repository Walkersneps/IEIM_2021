// INPUT: due numeri interi, uno positivo e l'altro negativo
// OUTPUT: i due numeri come inseriti
//         i due numeri swappati

#include <stdio.h>

void scambia(int *n1, int *n2);

int main() {
    int pos, neg;

    do {
        printf("Inserire un numero POSITIVO: ");
        scanf("%d", &pos);
        printf("Inserire un numero NEGATIVO: ");
        scanf("%d", &neg);
    } while ((pos < 0) && (neg > 0));

    printf("Hai inserito:\n  a = %d\n  b = %d\n", pos, neg);

    scambia(&pos, &neg);

    printf("Scambiando, si ottiene:\n  a = %d\n  b = %d\n", pos, neg);

    return 0;
}


void scambia(int *n1, int *n2) {
    int memoria = *n1;
    *n1 = *n2;
    *n2 = memoria;

    return;
}