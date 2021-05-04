/* Si scriva in C una funzione che,
 * dati due array di interi V1 e V2 (con V2<V1),
 * verifica se V2 è presente in V1, e se questa cosa è vera,
 * restituisce l’indice della prima occorrenza di V2 in V1.
 * 
 *  Esempio: Dati V1: 111212121 e V2: 121, restituisce 2
*/

char isSovrapponibile(int V2[], int s2, int V1[]);

/* Ritorna:
 * -1 se _V2[]_ non è presente in _V1[]_
 * l'indice di prima occorrenza altrimenti
 * 
 * _s1_ e _s2_ sono le dimensioni di V1 e V2, rispettivamente.
 * 
 * Alla prima chiamata, passare _index_ = 0
*/
int sovrapposizione(int V1[], int s1, int V2[], int s2, int index) {
    if (index > s1 - s2) return -1; // la parte rimanente di V1 è meno lunga di s2
    if (isSovrapponibile(V2, s2, V1)) return index;
    sovrapposizione(V1 + 1, s1, V2, s2, index + 1);
}

/* Verifica se _V2[]_ (di lunghezza _s2_) è contenuta in _V1[]_.
 * NB: suppone s2 <= s1
*/
char isSovrapponibile(int V2[], int s2, int V1[]) {
    for (int i = 0; i < s2; i++) if (V1[i] != V2[i]) return 0;
    return 1;
}

#include <stdio.h>
#define S1 9
#define S2 3
#define _V1 {1, 1, 1, 2, 1, 2, 1, 2, 1}
#define _V2 {1, 2, 1}
int main() {
    //  V1: 111212121 e V2: 121, restituisce 2
    int V1[S1] = _V1;
    int V2[S2] = _V2;

    printf("\n%d\n\n", sovrapposizione(V1, S1, V2, S2, 0));

    return 0;
}