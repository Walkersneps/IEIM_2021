/* Scrivere in C la funzione ricorsiva che, preso in ingresso
 * un vettore P di K elementi interi
 * e un numero h (con K > h),
 * restituisca al chiamante il vettore “ruotato a destra” di h posizioni.
 *      Esempio:
 *          Input: P=[1, 2, 3, 4, 5, 6],  h=2
 *          Restituisce: P=[5, 6, 1, 2, 3, 4]
 * 
 * Si scriva quindi una seconda funzione che risolve lo stesso problema in maniera iterativa.
 * 
 * Quali delle due soluzioni risulta essere “migliore”, perché?
*/

void shiftRightCiclico_ricorsivo(int P[], int K, int h) {
    if (h == 0) return;

    int save = P[K-1];
    for (int j = K-1; j > 0; j--) 
        P[j] = P[j-1];
    P[0] = save;

    shiftRightCiclico_ricorsivo(P, K, h-1);
}

void shiftRightCiclico_iterativo_v1(int P[], int K, int h) {
    int i;
    int save[h];
    
    // salvo gli ultimi h elementi
    for (i = 0; i < h; i++)
        save[i] = P[K-h+i];

    // slitto di h posizioni
    for (i = K-1; i > h-1; i--)
        P[i] = P[i-h];

    // ripristino gli elementi salvati prima
    for (i = 0; i < h; i++)
        P[i] = save[i];
}

void shiftRightCiclico_iterativo_v2(int P[], int K, int h) {
    int i, j, save;

    // per h volte:
    for (i = 0; i < h; i++) {
        save = P[K-1]; // salvo l'ultimo elemento
        for (j = K-1; j > 0; j--) // faccio slittare gli altri
            P[j] = P[j-1];
        P[0] = save; // ripristino l'elemento salvato prima
    }
}

// v1 è più efficiente di v2 per K grandi



// La soluzione iterativa è più efficiente perchè tiene allocata meno memoria.