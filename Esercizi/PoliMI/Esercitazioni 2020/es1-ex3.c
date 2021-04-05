// Eseguire la funzione 
// f(a,b,x) = x * (a+b)
// senza usare l'operatore di moltiplicazione

#include <stdio.h>


int main() {
    int a, b, x;
    int prodotto;

    printf("Inserire a: ");
    scanf("%d", &a);
    printf("Inserire b: ");
    scanf("%d", &b);
    printf("Inserire x: ");
    scanf("%d", &x);


    // Metto in ordine i due input (a+b) e (x)
    int min = a + b;
    int max = x;
    if (a+b > x) {
        min = x;
        max = a + b;
    }

    // Eseguo la moltiplicazione tramite somma iterativa
    for (int i = 0; i < min; i++) {
        prodotto = prodotto + max;
    }

    printf("\nf(a, b, x) = x * (a + b) = %d\n\n", prodotto);

    return 0;
}