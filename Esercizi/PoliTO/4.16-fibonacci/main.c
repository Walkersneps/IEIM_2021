#include <stdio.h>

int main() {
    int amount, curr;
    int md = 0;
    int mu = 1;

    printf("Quanti numeri vuoi stampare? ");
    scanf("%d", &amount);

    // Controllo input
    if (amount < 1) {
        printf("Inserire un numero positivo maggiore di 0.\n\n");
        return 1;
    }

    printf("\n1 --> 0");
    if (amount == 1) return 0;

    printf("\n2 --> 1");
    if (amount == 2) return 0;

    for (int i = 3; i <= amount; i++) {
        curr = md + mu; // prossimo numero della serie
        printf("\n%d --> %d", i, curr);
        md = mu;
        mu = curr;
    }
    
    return 0;
}