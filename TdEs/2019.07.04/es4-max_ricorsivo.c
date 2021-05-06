/* Si scriva una funzione ricorsiva in C che
 * data una sequenza di interi tutti diversi,
 * restituisce il valore del più grande numero trovato.
 * Il prototipo della funzione è:
 *      int foo (int *vettore, int posix)
*/

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

// Alla prima chiamata, _posix_ = ((dimensione dell'array) - 1) [aka massimo indice indirizzabile]
int foo(int *vettore, int posix) {
    if (posix == 0)
        return *vettore;
    else
        return max(*vettore, foo(vettore + 1, posix - 1));
}

// Alternativa
int bar(int *vettore, int posix) {
    if (posix == 0)
        return vettore[0];
    else
        return max(vettore[posix], bar(vettore, posix - 1));
}



// Verifica
#include <stdio.h>
#define N 7
int main() {
    int a[N] = {2345, 5, 876, 13, 876, 12, 1};

    printf("\nIl massimo (foo) e' %d.\n\n", foo(a, N-1));
    printf("\nIl massimo (bar) e' %d.\n\n", bar(a, N-1));
    
    return 0;
}