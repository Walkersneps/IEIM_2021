/* Data la seguente struttura dati,
 * che si considera anche opportunamente già popolata:
*/
typedef struct {
    char nome[15];
    float altezza;
    float latitudine;
    float longitudine;
} monti;
monti vettore[50], ordinato[50]; 
/* Si scriva una funzione in C che,
 * recuperato vettore[] (e non solo),
 * salva in ordinato[] i suoi elementi in ordine di altezza crescente.
*/


int findSpot(monti monte, monti inArray[], int ofSize);
void shiftRight(int firstIndex, int lastIndex, monti v[]);

/* Dispone gli elementi di _vettore[_dim_]_ in _ordinato[_dim_]_,
 * come descritto dalla specifica.
 *      In questo caso, si passerebbe dim=50
*/
void ordinaMonti(int dim, monti vettore[], monti ordinato[]) {
    int m, spot;
    ordinato[0] = vettore[0];
    if (vettore[1].altezza >= ordinato[0].altezza)
        ordinato[1] = vettore[1];
    else
        ordinato[1] = vettore[0];
        ordinato[0] = vettore[1];
    for (m = 2; m < dim; m++) { // m = size di ordinato[] all'avvio dell'iterazione corrente
        spot = findSpot(vettore[m], ordinato, m);
        if (spot < m) {
            shiftRight(spot, m - 1, ordinato);
            ordinato[spot] = vettore[m];
        } else {
            ordinato[spot] = vettore[m];
        }
    }

}

/* Esegue uno shift a destra dei primi _lastIndex_ elementi di _v[]_, "liberando" l'indice _firstIndex_
 * e sovrascrivendo l'elemento in _lastIndex_+1 */
void shiftRight(int firstIndex, int lastIndex, monti v[]) {
    int j;
    for (j = lastIndex + 1; j > firstIndex; j--)
        v[j] = v[j - 1];
}

/* Ritorna l'indice in cui posizionare _monte_ in modo che _inArray[]_
 * rimanga ordinato per altezza crescente. */
int findSpot(monti monte, monti inArray[], int ofSize) {
    int j;
    if (monte.altezza < inArray[0].altezza)
        return 0;
    for (j = 1; j < ofSize; j++)
        if (monte.altezza <= inArray[j].altezza && monte.altezza >= inArray[j - 1].altezza)
            return j;
    return ofSize;
}



// crescente --> altezze minori a sx