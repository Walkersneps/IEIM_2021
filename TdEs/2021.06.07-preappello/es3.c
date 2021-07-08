/* Si scriva una funzione ricorsiva in C che
 * dato una sequenza di interi tutti diversi,
 * restituisce la posizione (indice nell’array) del più grande numero trovato.
 * Il prototipo della funzione è: int foo (int *vettore, int posix)
*/


/* Ritorna l'indice dell'elemento massimo contenuto in _vettore[]_, considerandolo di dimensione _posix_+1
 * ovvero posix è il maggior indice da considerare (cioè per un vettore di dimensione N, chiamerò la funzione passando posix = N-1)
*/
int foo(int *vettore, int posix) {
    if (posix == 0) return posix;
    if (vettore[posix] > vettore[foo(vettore, posix-1)]) return posix;
    else return foo(vettore, posix-1);
}





#include <stdio.h>
#define qwerty 5
int main() {
    int numeri[qwerty] = {267, 6, -2, 234, 255};
    int pos = foo(numeri, qwerty-1);

    printf("ciao");
    printf("\n posizione %d, elemento %d \n", pos, numeri[pos]);

    return 0;
}
