/* Si scriva un programma in C che calcoli il minimo comune multiplo tra tre numeri
 * interi positivi arbitrari forniti dall'utente.
*/

#include <stdio.h>

int calc_mcm (int n1, int n2, int n3) {
  int notFound = 1;
  int count = 1;
  int mcm;

  // Determina il massimo tra i parametri
  int maxn = n1;
  if (n2 > maxn) maxn = n2;
  if (n3 > maxn) maxn = n3;

  // Cerca mcm a partire da max
  while (notFound) {
    mcm = maxn*count;

    if (mcm % n1 == 0) {
      if (mcm % n2 == 0) {
        if (mcm % n3 == 0) {
          notFound = 0;
        }
      }
    }

    count++;
  }

  return mcm;
}


int main() {
  int n1, n2, n3;

  printf("Inserisci il primo numero: ");
  scanf("%d", &n1);
  printf("\nInserisci il secondo numero: ");
  scanf("%d", &n2);
  printf("\nInserisci il terzo numero: ");
  scanf("%d", &n3);


  printf("Il minimo comune multiplo calcolato è: %d\n", calc_mcm(n1, n2, n3));

  return 0;
}
