/* Testo: https://www.codingcreativo.it/esercizio-sulle-struct-in-c/
 * Definire la struttura automobili che descrive un’automobile in base
 * alla marca, cilindrata, anno di immatricolazione e acquirente con nome e cognome.
 * Scriviamo quindi un programma in C, che dichiara una tabella autosalone
 * di tipo automobili con 5 elementi.
 * Il programma deve consentire di inserire i dati delle auto vendute
 * e di visualizzare le marche delle auto, secondo una ricerca.
 * Inoltre deve visualizzare il cognome dei proprietari con auto che hanno una cilindrata
 * superiore a 1800 cc.
 * Infine occorre visualizzare il numero di auto immatricolate in un determinato anno.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE_MARCA 20
#define SIZE_NOMI 20
#define SIZE_CATALOGO 5
#define LIMIT_SUPERBOLLO 1800
#define FILENAME "autosalone.save"

// Abilito la funzione clscr()
//#ifdef _WIN64
//#include <conio.h>
//#else
#define clrscr() printf("\e[1;1H\e[2J")
//#endif


struct acquirente_struct {
    char nome[SIZE_NOMI];
    char cognome[SIZE_NOMI];
};
typedef struct acquirente_struct Acquirente;


struct automobile_struct {
    char marca[SIZE_MARCA];
    int cilindrata;
    unsigned int anno;
    Acquirente acquirente;
};
typedef struct automobile_struct Automobile;

struct autosalone_struct {
    int size;
    Automobile *inventario;
};
typedef struct autosalone_struct Autosalone;


char mainMenu();
int venditeDurante(unsigned int anno, Autosalone as);
void inserimento(Autosalone *as);
int salva(Autosalone as);
int importa(Autosalone *as);
void funcVenditeAnnue(Autosalone as);
void funcInserimento(Autosalone *as);
void funcSalva(Autosalone *as);
void funcImporta(Autosalone *as);
void mainMenuRouter(char selezione, Autosalone *as);
void router(char context, char selezione, Autosalone *as);


int main() {
    Automobile catalogo[SIZE_CATALOGO];
    Autosalone autosalone = { .size = 0,
                              .inventario = catalogo };

    for (int i = 0; i < 300; i++) {
        //router('m', mainMenu(), &autosalone);
        char selez = mainMenu();
        mainMenuRouter(selez, &autosalone);
    }
    

    return -1;
}

/* Mostra il menu principale
 * Ritorna un char indicante la voce scelta dall'utente
*/
char mainMenu() {
    char selezione;

    //clrscr();
    printf("\n-- Autosalone --\n");
    printf("    - Menu -\n");
    printf("  a) vendite annue\n");
    printf("  i) inserisci vendita\n");
    printf("  m) marche\n");
    printf("  s) superbollo\n\n");
    printf("  w) salva dati su file\n");
    printf("  l) leggi da file\n\n");
    printf("  e) esci dal programma\n\n");

    do {
        printf("Selezione: ");
        scanf(" %c", &selezione);
    } while (selezione != 'a' && selezione != 'e' && selezione != 'i'  && selezione != 'l' && selezione != 'm' && selezione != 's' && selezione != 'w');
    
    return selezione;
}

// Ritorna il numero di auto catalogate in _inventario[]_ vendute durante _anno_
int venditeDurante(unsigned int anno, Autosalone as) {
    if (as.size == 0) return 0;

    Autosalone smaller = { .inventario = as.inventario + 1,
                           .size = as.size - 1 };
    if (as.inventario[0].anno == anno) return (1 + venditeDurante(anno, smaller));
    else return venditeDurante(anno, smaller);
}

// Richiede all'utente i dati per una nuova vettura
void inserimento(Autosalone *as) {
    printf("  --- Inserimento Veicolo ---\n");
    printf("      Marca <- ");
    scanf("%s", &as->inventario[as->size].marca);
    printf("      Cilindrata <- ");
    scanf("%d", &(as->inventario[as->size].cilindrata));
    printf("      Anno prima immatricolazione <- ");
    scanf("%d", &as->inventario[as->size].anno);
    printf("      Acquirente <- ");
    scanf("%s %s", &as->inventario[as->size].acquirente.nome, &as->inventario[as->size].acquirente.nome);

    as->size++;
}

/* Scrive un'immagine di _as_ su un file locale.
 * Ritorna: 1 se l'operazione è andata a buon fine
 *          0 altrimenti
*/
int salva(Autosalone as) {
    FILE *file = fopen(FILENAME, "wb");
    if (file != NULL) {
        fwrite(&as, sizeof(struct autosalone_struct), 1, file);
        fclose(file);
        return 1;
    } else return 0;
}

/* Sovrascrive _as_ con i dati salvati su un file locale.
 * Ritorna: 1 se l'operazione è andata a buon fine
 *          0 altrimenti
*/
int importa(Autosalone *as) {
    FILE *file = fopen(FILENAME, "rb");
    if (file != NULL) {
        fread(as, sizeof(struct autosalone_struct), 1, file);
        fclose(file);
        return 1;
    } else return 0;
}

// Interfaccia per la ricerca per anno
void funcVenditeAnnue(Autosalone as) {
    unsigned int annoIn;

    clrscr();
    printf("  ---  Ricerca per Anno ----\n");
    printf("       Anno cercato -> ");
    scanf("%d", &annoIn);

    printf("\nNel %d sono state immatricolate %d auto.\n", annoIn, venditeDurante(annoIn, as));
}

// Interfaccia per l'inseriimento di nuove vetture
void funcInserimento(Autosalone *as) {
    if (as->size <= SIZE_CATALOGO) {
        clrscr();
        inserimento(as);
        printf("\nInserimento eseguito correttamente");
    } else {
        printf("Errore: Il catalogo ha raggiunto la dimensione massima di %d vetture.\n", SIZE_CATALOGO);
        printf("\n  ...Premi INVIO per continuare...");
        scanf(" %*c");
    }
}

// Interfaccia per il salvataggio dell'autosalone
void funcSalva(Autosalone *as) {
    if (salva(*as)) {
        printf("Salvataggio avvenuto correttamente.\n");
        printf("\n  ...Premi INVIO per continuare...");
        scanf(" %*c");
    } else {
        printf("Salvataggio fallito!\n(forse il file non esiste)\n");
        printf("\n  ...Premi INVIO per continuare...");
        scanf(" %*c");
    }
}

// Interfaccia per il caricamento dell'autosalone
void funcImporta(Autosalone *as) {
    if (importa(as)) {
        printf("Caricamento dell'autosalone avvenuto correttamente.\n");
        printf("\n  ...Premi INVIO per continuare...");
        scanf("%*c");
    } else {
        printf("Importazione fallita!\n(forse il file non esiste)\n");
        printf("\n  ...Premi INVIO per continuare...");
        scanf("%*c");
    }

}

/*    printf("\n-- Autosalone --\n");
    printf("    - Menu -\n");
    printf("  m) marche\n");
    printf("  s) superbollo\n\n");
*/

// Esegue l'azione scelta dall'utente nel menu principale
void mainMenuRouter(char selezione, Autosalone *as) {
    switch (selezione) {
    case 'a':
        funcVenditeAnnue(*as);
        break;
    case 'e':
        exit(0);
        break;
    case 'i':
        funcInserimento(as);
        break;
    case 'l':
        funcImporta(as);
        break;
    case 'w':
        funcSalva(as);
        break;
    default:
        printf("\n\nERRORE: invalid menu entry\n");
        exit(1);
        break;
    }
}

// Esegue l'azione scelta dall'utente
void router(char context, char selezione, Autosalone *as) {
    switch (context) {
        case 'm':
            mainMenuRouter(selezione, as);
            break;
        default:
            printf("\n\nERRORE: invalid context\n");
            exit(1);
            break;
    }
    router(context, mainMenu(), as);
}
