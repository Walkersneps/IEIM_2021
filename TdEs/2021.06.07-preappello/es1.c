/* Dato un array di caratteri in cui i caratteri ammissibili sono
 * solo quelli che rappresentano i numeri da 0 a 9.
 * Data (non si deve scrivere) una funzione in C che,
 * preso in ingresso un array di questi caratteri,
 * restituisce il valore intero equivalente,
 *      ad esempio, dato ‘5’ ‘0’ ‘1’ restituisce l’intero 501.
 * Si dica se i numeri restituiti dalla funzione possono essere negativi.
 * Giustificare opportunamente la risposta.
*/


/* La funzione potrebbe restituire numeri negativi qualora la loro codifica binaria
 * necessiti più di n-1 bit, dove n è il numero di bit disponibili per l'int.
 * In questo caso infatti, verrebbe posto ad 1 il bit più significativo, che,
 * per la codifica in Complemento a 2 (CP2), corrisponde a un numero negativo.
*/