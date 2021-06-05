/* Un numero si dice di ROVERI se è
 * positivo, primo, maggiore di 11 e pari,
 * si scriva una funzione che restituisce al chiamante (NON STAMPA A VIDEO)
 * tutti i numeri ROVERI tra 0 e 1512
*/

#define MINTEST 0
#define MAXXTEST 1512

/* Restituisce la dimensione utile (aka il numero di elementi effettivamente inseriti)
 * dell'array _roveri[]_, dopo averlo popolato con
 * tutti i numeri di Roveri compresi tra MINTEST e MAXTEST.
 *      NB: assicurarsi che _roveri[]_ sia di dimensione adeguata.
 *      !!! La specifica include condizioni incompatibili (n.ro pari (non 2) e primo) */
int roveri(int roveri[]) {
    return 0;
}

// Se pure:
char isPrimo(int n);
int cercaRoveri(int roveri[]) {
    int i, count = 0;
    for (i = 12; i <= MAXXTEST; i += 2) { // cond >11  e pari già verificate
        if (!isPrimo(i)) {
            roveri[count] = i;
            count++;
        }
    }
    return count;
}
char isPrimo(int n) {
    for (int j = 2; j < n; j++)
        if (n % j == 0) return 0;
    return 1;
}