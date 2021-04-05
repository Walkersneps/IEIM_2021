/* Homework 1 - Esercizio 2
 * Si descriva in C la funzione per il calcolo della moltiplicazione,
 * implementandola in maniera iterativa.
 * La funzione ha il seguente prototipo: 
 *    int moltplicazione(int valore1, int valore2);
 * Nel descrivere la funzione si può usare solo l’operatore di somma
 * (è vietato usare la moltiplicazione).
 * Si assume che valore1 e valore2 siano numeri interi, maggiori o uguali a 0.
*/

int do_moltiplicazione (int valmin, int valmax) {
  int result = 0;
  for (int i = 0; i < valmin; i++) result = result + valmax;
  return result;
}

int moltiplicazione(int valore1, int valore2) {
  if (valore1 > valore2) return do_moltiplicazione(valore2, valore1);
  else return do_moltiplicazione(valore1, valore2);
}


// funzione alternativa
int moltiplicazione_alt(int valore1, int valore2) {
  int min = valore1;
  int max = valore2;
  if (valore2 < valore1) {
    min = valore2;
    max = valore1;
  }

  int result = 0;
  for (int i = 0; i < min; i++) result = result + max;

  return result;
}




/*int main() {
  int val1, val2;

  printf("Inserisci primo valore: ");
  scanf("%d", &val1);
  printf("Inserisci secondo valore: ");
  scanf("%d", &val2);

  printf("Usando metodo 1: %d\n", moltiplicazione(val1, val2));
  printf("Usando Metodo 2: %d\n\n", moltiplicazione_alt(val1, val2));
  return 0;
}*/
