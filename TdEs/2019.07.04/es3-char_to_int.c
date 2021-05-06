/* Dato un array di caratteri in cui
 * i caratteri ammissibili sono solo quelli che rappresentano i numeri da 0 a 9.
 * 
 * Domanda 3.1 (60%): Si scriva una funzione in C che,
 *                    preso in ingresso uno di questi array,
 *                    restituisce il valore numerico equivalente.
 *                      Esempio:
 *                          • Dato ‘3’ ‘5’ ‘4’, restituisce l’intero 354
 *                          • Dato ‘6' ‘5’ ‘0’ ‘2’ ‘1’ restituisce l’intero 65021
 * 
 * Domanda 3.2 (40%): I numeri restituiti dalla funzione richiesta possono essere negativi?
 *                    Giustificare la risposta.
*/


// ####### 3.1 #######
#include <math.h>

int char_to_int(char c);

/* Dato l'array _in[]_ (conforme alla specifica del problema) di dimensione _size_,
 * ritorna il valore numerico equivalente.
*/
int charArr_to_int(char in[], int size) {
    int i, out = 0;

    for (i = 0; i < size; i++)
        out += (pow(10, size - i - 1) * char_to_int(in[i]));

    return out;
}

// Restituisce l'int corrispondente a _c_, assumendo che l'operazione sia possibile (undefined behaviour se _c_ non è un char compreso tra '1' e '0')
int char_to_int(char c) {
    return (c - '0');
}



// ####### 3.2 #######
/* Sì, potrei avere restituito un numero negativo,
 * perchè se inserisco un numero che manda in overflow la variabile di tipo int,
 * posso invertire il bit di segno.
 * 
 * Soluzione: posso definire la funzione come unsigned int
 *
 * es: prova con 9876543212345678987654321
 * 
 * (basta un numero maggiore di 2147483647)
*/



// Verifico
#include <stdio.h>
#define MAX 398
int main() {
    int cifre, j;
    do {
        printf("\nQuante cifre vuoi inserire (max %d)? ", MAX);
        scanf("%d", &cifre);
    } while (cifre < 0 || cifre > MAX);

    char digits[cifre];

    printf("Inserisci le cifre, tutte di seguito: ");
    for (j = 0; j < cifre; j++) scanf(" %c", &digits[j]);

    printf("\nHo prodotto il numero %d.\n", charArr_to_int(digits, cifre));

    return 0;
}
