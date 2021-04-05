#include "utils.h"

int binomiale(int n, int k) {
    return (fattoriale(n)) / (fattoriale(k)*fattoriale(n-k));
}