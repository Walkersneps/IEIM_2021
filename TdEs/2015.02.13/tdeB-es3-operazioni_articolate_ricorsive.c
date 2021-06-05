/* Si realizzi una funzione in C che, preso come argomento un vettore di numeri v=[v1,..., vn],
 * calcola la seguente operazione complessa:
 *      ∏[v_i] * ∑(v_i) * ∏ (1/(v_i))
 *      [tutte le produttorie e sommatorie ciclano sull'indice i=1..n]
 * Le produttorie/sommatorie DEVONO essere calcolate tramite DUE funzioni RICORSIVE,
 * una che calcola la produttoria e una che calcola la sommatoria.
*/

// ### !!! ### !!! ###
// Trabocchetto di Santa: verificato che tutti i v_i siano nonnulli, l'operazione si semplifica in realtà alla sola sommatoria centrale!
float es3(float v[], int size) {
    return sommatoria(v, size);
}




// #### Risoluzione estesa:

void reciproci(float sorg[], float dest[], int size);
float sommatoria(float v[], int n);
float produttoria(float v[], int n);

/* Ritorna il risultato dell'operazione richiesta,
 * eseguendola sugli elementi del vettore _v[]_ composto da _size_ elementi
 * 
 * !!! Assicurarsi che tutti gli elementi di _v[]_ siano nonnulli
*/
float operazioneComplessa(float v[], int size) {
    float rec[size];
    reciproci(v, rec, size);

    return (produttoria(v, size) * sommatoria(v, size) * produttoria(rec, size));
}


// Ritorna la somma dei primi _n_ elementi di _v[]_
float sommatoria(float v[], int n) {
    if (n == 1) return v[0];
    else return (v[n-1] + sommatoria(v, n-1));
}

// Ritorna il prodotto dei primi _n_ elementi di _v[]_
float produttoria(float v[], int n) {
    if (n == 1) return v[0];
    else return (v[n-1] * sommatoria(v, n-1));
}

/* Riempie _dest[]_ con i valori reciproci dei rispettivi primi _size_ elementi di _sorg[]_.
 *
 * !!! Assicurarsi che tutti gli elementi di _v[]_ siano nonnulli
*/
void reciproci(float sorg[], float dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = (1 / sorg[i]);
}