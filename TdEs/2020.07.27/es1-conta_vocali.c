/* Si scriva in C una funzione che
 * ricevuta in ingresso una stringa di caratteri minuscoli
 * (si suppone che la stringa sia corretta e coerente con la specifica),
 * restituisce al chiamante, attraverso una sola invocazione della funzione,
 * le occorrenze delle vocali presenti nella stringa.
*/

#include <string.h>

/* Popola _occorrenze[]_ con le occorrenze delle rispettive vocali.
 * Per convenzione, occorrenze[0] = #occorrenze di 'a', le altre vocali a seguire in ordine
 *   NB: si assume che _occorrenze[]_ sia un vettore di 0.
*/
void occorrenze_vocali(char s[], int occorrenze[5]) {
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'a':
                occorrenze[0]++;
                break;
            case 'e':
                occorrenze[1]++;
                break;
            case 'i':
                occorrenze[2]++;
                break;
            case 'o':
                occorrenze[3]++;
                break;
            case 'u':
                occorrenze[4]++;
                break;
            default:
                break;
        }
    }
}

void occorrenze_vocali_ricorsiva(char s[], int occorrenze[5]) {
    if (strlen(s) < 1) return;

    switch (s[0]) {
        case 'a':
            occorrenze[0]++;
            break;
        case 'e':
            occorrenze[1]++;
            break;
        case 'i':
            occorrenze[2]++;
            break;
        case 'o':
            occorrenze[3]++;
            break;
        case 'u':
            occorrenze[4]++;
            break;
        default:
            break;
    }
    
    return occorrenze_vocali_ricorsiva(s + 1, occorrenze);
}




#include <stdio.h>
int main() {
    char stringa[100];
    int occ[5] = {0};
    printf("\nInserisci una stringa minuscola: ");
    scanf("%s", stringa);

    occorrenze_vocali(stringa, occ);
    printf("\nLa stringa %s ha vocali (metodo iterativo): ", stringa);
    printf("  a compare %d volte\n", occ[0]);
    printf("  e compare %d volte\n", occ[1]);
    printf("  i compare %d volte\n", occ[2]);
    printf("  o compare %d volte\n", occ[3]);
    printf("  u compare %d volte\n", occ[4]);
    
    occ[0] = 0;
    occ[1] = 0;
    occ[2] = 0;
    occ[3] = 0;
    occ[4] = 0;

    occorrenze_vocali_ricorsiva(stringa, occ);
    printf("\nLa stringa %s ha vocali (metodo ricorsivo): ", stringa);
    printf("  a compare %d volte\n", occ[0]);
    printf("  e compare %d volte\n", occ[1]);
    printf("  i compare %d volte\n", occ[2]);
    printf("  o compare %d volte\n", occ[3]);
    printf("  u compare %d volte\n", occ[4]);

    printf("\n\n");
    return 0;
}



