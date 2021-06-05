int distanza(int a, int b) {
    int dist = a - b;
    if (dist < 0) return (-1 * dist);
    else return dist;
}

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int foo(int vettore[], int posix) {
    if (posix == 2)
        return distanza(vettore[0], vettore[1]);
    else
        return min(distanza(vettore[posix-1], vettore[posix-2]), foo(vettore, posix-1));
}


#include <stdio.h>
#define s 5
int main() {
    int v[s] = {17,1,8,7,6};
    printf("\nDistanza minima e': %d\n", foo(v, s));
}

