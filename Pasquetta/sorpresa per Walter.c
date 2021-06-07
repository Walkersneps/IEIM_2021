#include<stdio.h>
#include<string.h>
#define DIM 100

void giorgesangiorg();

int main(){
    printf("\nCONOSC A GIORG?");
    printf("\nPer favore Walter scrivi la risposta in maiuscolo e senza spazi con il punto interrogativo alla fine grazie senno' non funziona baci");
    giorgesangiorg();
    printf("\n");
return 0;
}

void giorgesangiorg(){
    char s1[DIM] = {};
    char s2[] = "CHIGIORG?";
    printf("\nRISPOSTA CORRETTA: ");
    scanf("%s", &s1);
    if (!(strcmp(s1, s2)))
        printf("\nGIORG E SAN GIORG");

    else{
        printf("\nRISPOSTA SBAGLIATA!");
        giorgesangiorg();
    }
}
