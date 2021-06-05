int mcm(int a, int b);

// Ritorna il mcm dei primi _size_ elementi di _a[]_
int mcm_ricorsivo(int a[], int size) {
    if (size > 2) {
        return mcm(a[0], mcm_ricorsivo(a+1, size-1));
    } else if (size == 2) {
        return mcm(a[0], a[1]);
    } else {
        return a[0];
    }
}


int mcm(int a, int b) {
    int i, candidato;
    int min = b;
    int max = a;
    if (a < b) {
        min = a;
        max = b;
    }

    for (i = 1; i < min; i++) {
        candidato = max*i;
        if (candidato % min == 0)
            return candidato;
    }

    return max*min;
}






// VERIFICA
#include <stdio.h>
#define N 5
int main() {
    int arr[N] = {1, 3, 2, 7, 5};

    printf("\nL'mcm e' %d.\n\n", mcm_ricorsivo(arr, N));

    return 0;
}