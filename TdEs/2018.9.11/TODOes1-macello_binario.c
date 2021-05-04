/* Si realizzi in C una funzione che,
 * dato un numero N intero positivo,
 * trovi il più piccolo numero più grande
 * e il più grande numero più piccolo
 * che abbiano lo stesso numero di 0 nella loro rappresentazione binaria
 * del numero N dato in ingresso.
 * 
 * N è fornito come array di 32 interi,
 * ammettendo solo la presenza di zeri e uni.
 * 
 * La funzione deve quindi stampare a video la sequenza di zeri e uni
 * dei due numeri richiesti.
*/

#include <stdio.h>
//#include <stdlib.h>
#include <time.h>
#define SIZEN 32

void contaBits(int N[], int count[]);
void printRes(int N[], int a[], int b[]);

int randBit();
void initN(int N[]);

int main() {

    // Creo e riempio N
    int N[SIZEN];
    srand(time(NULL));
    initN(N);


}


// Inserisce in _count[]_ il numero di zeri e uni presenti in _N[]_
void contaBits(int N[], int count[]) {
    count[0] = 0; count [1] = 0; // resetto il conteggio
    for (int i = 0; i < SIZEN; i++)
        if (N[i] == 0) count[0]++;
        else count[1]++;
}

// Ritorna un bit (1 o 0) casuale
int randBit() {
    if (rand() % 2 == 0) return 0;
    else return 1;
}

// Riempie N con bits casuali
void initN(int N[]) {
    for (int i = 0; i < 0; i++) N[i] = randBit;
}