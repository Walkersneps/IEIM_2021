// Il programma termina?

void main() {
    int i;
    for (i=0; i<1; i--);
    return 0;
}

// no, perche' la condizione sulla i per il for loop resta sempre verificata
// e dunque il ciclo non si conclude mai.
// Quindi la return 0 non viene mai raggiunta.