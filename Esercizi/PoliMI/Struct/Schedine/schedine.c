/* Il programma, partendo da un array di dimensione prefissata
 * che contiene in ogni cella:
 *   - data della giocata
 *   - colonna con i tredici segni
 * • Copia in un altro vettore solo le giocate dell’anno 2010
 * • Quindi, visualizza queste giocate.
*/

#include <stdio.h>
#define NSCHEDINE 3
#define SIZE_SCHEDINA 13
#define ANNO_CERCATO 2010

struct data_struct {
    char giorno;
    char mese;
    unsigned int anno;
};
typedef struct data_struct Data;

struct schedina_struct {
    Data data;
    char giocata[SIZE_SCHEDINA];
};
typedef struct schedina_struct Schedina;


void printSchedina(Schedina s);
char checkColonna (char colonna[]);
void getData(Data* data);
void getColonna(char colonna[]);
void getInput(Schedina schedine[]);
int conta_anniBuoni(Schedina schedine[], unsigned int annoCercato);
void copiaSchedine(Schedina origine[], Schedina destinazione[], unsigned int annoCercato);


int main() {
    Schedina schedine[NSCHEDINE];
    int quanteSchedineBuone;

    // Leggo schedine
    getInput(schedine);

    quanteSchedineBuone = conta_anniBuoni(schedine, ANNO_CERCATO);
    if (quanteSchedineBuone) {
        Schedina schedineBuone[quanteSchedineBuone];
        copiaSchedine(schedine, schedineBuone, ANNO_CERCATO);
        printf("\nHo trovato %d schedine risalenti all'anno %d:\n", quanteSchedineBuone, ANNO_CERCATO);
        for (int i = 0; i < quanteSchedineBuone; i++) printSchedina(schedineBuone[i]);
        return 0;
    } else {
        printf("\nNessuna delle schedine inserite risale al %d.\n\n", ANNO_CERCATO);
        return 0;
    }
    return -1;
}

// Popola l'array di schedine
void getInput(Schedina schedine[]) {
    for (int i = 0; i < NSCHEDINE; i++) {
        printf("\nSchedina %d:\n", i+1);
        getData(&schedine[i].data);
        getColonna(schedine[i].giocata);
        printf("\n");
    }
}

// Chiede all'utente e salva una data
void getData(Data* data) {
    do {
        printf("  Giorno: ");
        scanf("%d", &data->giorno);
    } while ((data->giorno < 0) || (data->giorno > 31));
    do {
        printf("  Mese: ");
        scanf("%d", &data->mese);
    } while ((data->mese < 0) || (data->mese > 12));
    do {
        printf("  Anno: ");
        scanf("%d", &data->anno);
    } while (data->anno < 0);
}

// Stampa a video il resoconto della schedina _s_
void printSchedina(Schedina s) {
    printf("  Schedina del %d/%d/%d:\n", s.data.giorno, s.data.mese, s.data.anno);
    printf("    Giocata: ");
    for (int j = 0; j < SIZE_SCHEDINA; j++) printf("%c", s.giocata[j]);
    printf("\n");
}

// Chiede all'utente di inserire la giocata e popola l'array corrispondente
void getColonna(char colonna[]) {
    printf("  Giocata di %d simboli: ", SIZE_SCHEDINA);
    do {
        scanf("%s", colonna);
    } while (!checkColonna(colonna));
}

/* Verifica che _colonna[]_ sia valida. Ritorna:
 * 1 se contiene solo simboli validi
 * 0 altrimenti
*/
char checkColonna (char colonna[]) {
    for (int j = 0; j < SIZE_SCHEDINA; j++) {
        if (colonna[j] == '1' || colonna[j] == 'x' || colonna[j] == '2') continue;
        else return 0;
    }
    return 1;
}

// Restituisce il numero di schedine che hanno data risalente ad _annoCercato_
int conta_anniBuoni(Schedina schedine[], unsigned int annoCercato) {
    int count = 0;
    for (int j = 0; j < NSCHEDINE; j++) if (schedine[j].data.anno == annoCercato) count ++;
    return count;
}

// Copia le schedine risalenti ad _annoCercato_ contenute in _origine[]_ dentro a _destinazione[]_
void copiaSchedine(Schedina origine[], Schedina destinazione[], unsigned int annoCercato) {
    int cbuone = 0;
    for (int j = 0; j < NSCHEDINE; j++) {
        if (origine[j].data.anno == annoCercato) {
            destinazione[cbuone] = origine[j];
            cbuone ++;
        }
    }
}