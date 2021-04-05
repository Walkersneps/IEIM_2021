/* Si scriva un programma in C che calcoli il minimo comune multiplo tra tre numeri
 * interi positivi arbitrari forniti dall'utente.
*/

#include <stdio.h>

// Calcola  il mcm di tre numeri, assumendo che il terzo parametro sia il maggiore
int calc_mcm_quick (int n1, int n2, int n_max) {
  int notFound = 1;
  int count = 1;
  int mcm;

  // Cerca mcm a partire da max
  while (notFound) {
    mcm = n_max*count;

    if (mcm % n1 == 0) { // mcm è multiplo di n1
      if (mcm % n2 == 0) { // mcm è multiplo di n2
        notFound = 0; // mcm è sicuramente anche multiplo di n_max perchè da lui prodotto
      }
    }

    count++;
  }

  return mcm;
}

// Calcola il mcm tra tre numeri
int calc_mcm (int n1, int n2, int n3) {

  // Determina quale dei tre parametri sia il maggiore e invoca calc_mcm_quick() correttamente (si spera)

  if (n2 >= n3) {
    if (n2 >= n1) { // n2(=n3)(=n1) è il max
      return calc_mcm_quick(n1, n3, n2);
    }
  }

  // se sono rimast0 qui --> n3>n2 oppure (n2>=n3 & n1>n2)
  if (n3 >= n1) { // n3(=n1) è il max
    return calc_mcm_quick(n1, n2, n3);
  }

  // se sono rimasto qui --> n3>n2 & n1>n3 --> n1 è max
  return calc_mcm_quick(n2, n3, n1);
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
