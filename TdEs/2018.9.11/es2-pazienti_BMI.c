/* Dato un insieme di pazienti, ognuno identificato da
 * peso (in Kg) e altezza (in metri),
 * si definisca la struttura dati per memorizzare i singoli pazienti.
 * 
 * Si scriva quindi una funzione in C che,
 * dato un array di K pazienti ed un numero N (con N<K),
 * scelga gli N migliori pazienti dall’insieme
 * ottimizzando il loro BMI (BMI = peso/(altezza^2)), aka gli N pazienti a più basso BMI.
 * La funzione dovrà quindi restituire al chiamante l’array degli N pazienti individuati.
*/

#define K 120 // quanti pazienti ho
#define N 5 // quanti ne voglio selezionare

struct paziente {
    float peso;
    float altezza;
};
typedef struct paziente Paziente;

// Calcola il BMI del paziente _paz_
float bmi(Paziente paz) {
    paz.peso / (paz.altezza * paz.altezza);
}

// da _arr[]_ seleziona gli N valori minimi e ne inserisce gli indici in _ans[]_
void selectMins(float BMIs[], int minPazs[]) {
    int p, mp;
    float minBMIs[N];
    for (mp = 0; mp < N; mp++) minBMIs[mp] = __FLT_MAX__; // inizializzo il podio ai massimi possibili
    
    for (p = 0; p < K; p++) { // per ogni paziente
        for (mp = 0; mp < N; mp++) { // per ogni spazio in classifica
            if(BMIs[p] < minBMIs[mp]) { // ho trovato qualcuno che è più secco
                minPazs[mp] = p; // salvo il suo indice sul podio
                minBMIs[mp] = BMIs[p]; // salvo il suo BMI sul podio
            }
        }
    }
}

// Inserisce in _pazientiConLowestBMIs[]_ i K pazienti di _lista[]_ con BMI minimi
void scegliPazienti(Paziente lista[], Paziente pazientiConLowestBMIs[]) {
    int i;
    float BMIs[K];
    int ipiusecchidelvillaggio[N];

    // Calcolo il BMI di ogni paziente
    for (i = 0; i < K; i++) BMIs[i] = bmi(lista[i]);

    // Trovo i pazienti a BMI più basso...
    selectMins(BMIs, ipiusecchidelvillaggio);

    // ...e li inserisco nell'output
    for (i = 0; i < K; i++) pazientiConLowestBMIs[i] = lista[ipiusecchidelvillaggio[i]];
}