/* Homework 1 - Esercizio 3
 * Si scriva in C la funzione che, facendo uso della funzione scritta all’esercizio 2,
 * implementi la funzione “elevamento a potenza”.
 * Nel descrivere la funzione si può usare solo, se lo si ritenesse necessario
 * oltre alla  funzione  moltiplicazione, l’operatore di somma.
 * Il prototipo della funzione è:
 *    int elevamento(int base, int potenza);
 * Si supponga quindi di avere un main che riceve due valori val_base e val_potenza e che
 * salva in val_elevamento il valore di val_baseval_potenza.
 * Si assume che val_potenza e val_base siano numeri interi, maggiori o uguali a 0.
*/

#include "hw1_es2_moltiplicazione.h"

// base, potenza sono interi maggiori o uguali a zero
int elevamento(int base, int potenza) {
  int result = 1;
  for (int i = 0; i < potenza; i++) result = do_moltiplicazione(base, result);
  return result;
}
