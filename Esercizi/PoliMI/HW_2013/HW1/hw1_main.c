#include <stdio.h>
#include "hw1_es2_moltiplicazione.h"
#include "hw1_es3_elevamento.h"


int main() {

  // ##### TESTA MOLTIPLICAZIONE #####
  /*
  int val1, val2;

  printf("Inserisci primo valore: ");
  scanf("%d", &val1);
  printf("Inserisci secondo valore: ");
  scanf("%d", &val2);

  printf("Usando metodo 1: %d\n", moltiplicazione(val1, val2));
  printf("Usando Metodo 2: %d\n\n", moltiplicazione_alt(val1, val2));
  */


  // ##### TESTA ELEVAMENTO #####
  int base, potenza;

  printf("Inserisci la base (numero da elevare): ");
  scanf("%d", &base);
  printf("Inserisci la potenza a cui elevare la base: ");
  scanf("%d", &potenza);

  printf("%d^%d = %d\n\n", base, potenza, elevamento(base, potenza));


  return 0;
}
