/* Scrivere un programma in linguaggio C per la rappresentazione del triangolo di Floyd.
 * Il triangolo di Floyd è un triangolo rettangolo che contiene numeri naturali,
 * definito riempiendo le righe del triangolo con numeri consecutivi e
 * partendo da 1 nell’angolo in alto a sinistra.
 *      Si consideri ad esempio il caso N=6.
 *      Il triangolo di Floyd e’ il seguente:
 *      1                       (1)
 *      2  3                    (2)
 *      4  5  6                 (3)
 *      7  8  9  10             (4)
 *      11 12 13 14 15          (5)
 *      16 17 18 19 20 21       (6)
 * Il programma riceve da tastiera un numero intero N e visualizza le prime N righe del triangolo di Floyd.
 *   Suggerimento. Si osserva che il numero di valori in ogni riga corrisponde all’indice della riga:
 *                 1 valore sulla prima riga, 2 sulla seconda, 3 sulla terza
*/

#include <stdio.h>

void printFloyd(int righe);

int main() {
    int N;

    do {
        printf("Quante righe del triangolo di Floyd vuoi stampare? ");
        scanf("%d", &N);
    } while (N <= 0);

    printf("\nLe prime %d righe del triangolo di Floyd sono:\n", N);
    printFloyd(N);
    printf("\n\n");

    return 0;
}

void printFloyd(int N) {
    int num = 1;
    for (int riga = 1; riga <= N; riga++) {
        printf("\n(%d)  ", riga);

        for (int colonna = 1; colonna <= riga; colonna++){
            printf("  %d", num);
            num++;
        }
    }
}