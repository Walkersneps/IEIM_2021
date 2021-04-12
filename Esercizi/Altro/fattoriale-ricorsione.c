#include <stdio.h>

int fattoriale (int n);

int main () {
    int n;

    printf("Dammi n: ");
    scanf("%d", &n);

    printf("\n%d! = %d\n", n, fattoriale(n));

    return 0;
}


int fattoriale (int n) {
    if (n == 0) return 1;
    else return n*fattoriale(n-1);
}