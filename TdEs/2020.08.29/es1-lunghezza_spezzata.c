/* Si definiscano in C due strutture dati che permettano:
 *   - una di rappresentare un punto in un piano cartesiano
 *   - l’altra una linea spezzata formata da N punti.
 * 
 * Si scriva quindi in C una funzione che,
 * ricevuta in ingresso una linea spezzata,
 * ne calcoli la lunghezza.
 * 
 * Si ricorda che la distanza tra due punti si misura lungo la retta passante per i due punti;
 * se si è su un piano cartesiano con coordinate dei due punti P0 (x0, y0) e P1 (x1, y1)
 * basta applicare il teorema di Pitagora:
 *      d = sqrt[(x0-x1)^2 + (y0-y1)^2]
*/

#include <math.h>
#define N 4

typedef struct punto {
    int x;
    int y;
} Punto;

typedef struct spezzata {
    Punto punti[N];
} Spezzata;


// Ritorna la distanza euclidea ab (Th di Pitagora).
int distanza(Punto a, Punto b) {
    return sqrt(((a.x - b.x)^2) + ((a.y - b.y)^2));
}

// Ritorna la lunghezza della spezzata _s_, costituita da _npunti_ punti.
int lunghezza(Spezzata s, int npunti) {
    int l = 0;
    for (int i = 1; i < npunti; i++)
        l += distanza(s.punti[i - 1], s.punti[i]);
    return l;
}

