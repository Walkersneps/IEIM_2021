/* Si consideri un sistema monoprocessore in cui
 * si avviano tre diversi processi (A, B, C)
 * che eseguono il seguente programma:
*/
#include <stdio.h>
int main() {
    int dato, risultato, i;

    while (1) {
        risultato=0;
        printf("\n\nInserire un numero intero positivo da tastiera: ");
        scanf("%d", &dato);

        for (i=2; i<(dato/2)+1; i++)
            if (i*i==dato)
                risultato = i;

        printf("\nDato: %d\nRisultato: %d",dato, risultato);
    }

    return 0;
}
/* Si consideri ciascuna delle situazioni elencate qui sotto e si dica se può verificarsi.
 * Si giustifichi la risposta a ognuna delle 4 situazioni.
 * 
 *  1. A, B, C sono tutti e tre in stato di pronto.
 *  2. A, B, C sono tutti e tre in stato di attesa.
 *  3. A, B, C sono tutti e tre in stato di esecuzione.
 *  4. A è in stato di attesa, B è in stato di esecuzione, C è in stato di pronto.
*/

// #####
/* 1. SI ogni volta che il processore esegue istruzioni legate ad altri processi
 * 2.           not sure, direi di sì
 * 3. NO perchè il sistema considerato è monoprocessore e può quindi eseguire un singolo thread alla volta
 * 4. SI se B sta calcolando la radice (ciclo for), A è alla scanf() e l'utente non ha ancora inserito il dato, C sta aspettando il suo turno
*/