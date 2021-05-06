/* I cifrari a scorrimento sono metodi di cifratura che
 * agiscono su un testo in cui ogni lettera del testo in chiaro viene sostituita,
 * nel testo cifrato, con la lettera che si trova un certo numero di posizioni dopo nell’alfabeto.
 * La sostituzione avviene lettera per lettera scorrendo il testo dall’inizio alla fine.
 * Un famoso cifrario è il Santa[V,C], un cifrario che spacca l'alfabeto in vocali e consonanti
 * e quindi fa scorrere una vocale di V vocali (solo sull'insieme delle vocali, ordinate alfabeticamente)
 * e una consonante di C consonanti (solo sull'insieme delle consonanti, ordinate alfabeticamente).
 *      Stringa: ciao
 *      Cifrata Santa[2,1]: duie
 * 
 * Si scriva una funzione che,
 * ricevuta in ingresso una stringa di testo (consideriamo solo caratteri minuscoli)
 * ed  i  valori  V  e  C,
 * restituisce la stringa cifrata usando Santa[V,C].
*/

#include <string.h>
#define NLETTERE 26
#define NVOCALI 5
#define NCONSONANTI 21 // NLETTERE - NVOCALI

char isVocale(char c);
int find(char x, const char inArray[], int s);
char aumenta_vocale(char x, int V);
char aumenta_consonante(char x, int C);
const char vocali[10] = {'a', 'e', 'i', 'o', 'u', 'a', 'e', 'i', 'o', 'u'};

/* Popola _dest[]_ con la cifrata Santa[_V_, _C_] di _orig[]_
 *  NB: _dest[]_ dev'essere una stringa lunga tanto quanto _orig[]_
*/
void cifraSanta(char orig[], char dest[], int V, int C) {
    for (int l = 0; l < strlen(orig); l++) {
        if (isVocale(orig[l]))
            dest[l] = aumenta_vocale(orig[l], V);
        else
            dest[l] = aumenta_consonante(orig[l], C);
    }
}


// Ritorna _x_ incrementata di _V_ elementi, sul solo insieme delle vocali, e assumendo che _x_ sia una vocale.
char aumenta_vocale(char x, int V) {
    int norm = V % 5; // normalizzo V a un solo ciclo
    int xindex = find(x, vocali, 5); // posizione della vocale x

    return vocali[xindex + norm];
}

// Ritorna _x_ incrementata di _C_ elementi, sul solo insieme delle consonanti, e assumendo che _x_ sia una consonante.
char aumenta_consonante(char x, int C) {
    for (int i = 0; i < (C % NCONSONANTI); i++) { // Normalizzo C a massimo un tour completo di consonanti
        if (x == 'z') { // se devo incrementare oltre la 'z', torno da capo
            x = 'b'; // skippo la 'a' perché è una vocale
            continue; // ho gia incrementato quello che dovevo per questa iterazione
        }

        if (isVocale(x+1))
            x += 2; // due vocali nell'alfabeto non sono mai adiacenti
        else
            x += 1;
    }

    return x;
}

char isVocale(char c) {
    if (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u')
        return 1;
    else return 0;
}

/* Ritorna: l'indice della prima occorrenza di _x_ in _inArray[]_, assumendolo di dimensione _s_
 *         -1 se non trovato.
*/
int find(char x, const char inArray[], int s) {
    for (int i = 0; i < s; i++)
        if (inArray[i] == x)
            return i;
    return -1;
}



#include <stdio.h>
#define SIZE 100
int main() {
    char chiaro[SIZE], crypt[SIZE];
    int V, C;
    printf("\nInserisci una parola da cifrare: ");
    scanf("%s", chiaro);
    strcpy(crypt, chiaro);
    printf("Inserisci i parametri [V C]: ");
    scanf("%d %d", &V, &C);

    cifraSanta(chiaro, crypt, V, C);

    printf("\nSanta[V%d,C%d](%s) = %s\n\n", V, C, chiaro, crypt);

    return 0;
}