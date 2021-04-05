/* Si scriva un programma in C che permetta di effettuare
 * la conversione tra diverse unità di misura.
 * L'utente sceglie cosa convertire, e fornisce una misura.
 * Il programma ne riporta il valore convertito.
*/

#include <stdio.h>

int main() {
    char scelta;
    float in, out;

    printf("Cosa vuoi convertire?\n    * l: Piedi --> Metri\n    * p: Libbre --> Kilogrammi\n    * t: Celsius --> Fahrenheit\n      Scelta: ");
    scanf("%c", &scelta);

    if (scelta == 'l') {
        printf("Inserisci la misura in ft: ");
        scanf("%f", &in);
        out =  in*0.3048;
        printf("\n%.3f ft = %.3f m.\n", in, out);
    } else if (scelta == 'p') {
        printf("Inserisci la misura in lb: ");
        scanf("%f", &in);
        out = in*0.453592;
        printf("\n%.3f lb = %.3f kg.\n", in, out);
    } else if (scelta == 't') {
        printf("Inserisci la misura da convertire: ");
        scanf("%f", &in);
        out = (in * 9.0 / 5.0) + 32.0;
        printf("\n%.3f C = %.3f F.\n", in, out);
    } else {
        printf("Errore: scelta non valida!");
        return 1;
    }
    
}

