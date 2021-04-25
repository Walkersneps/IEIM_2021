int fattoriale(int n) {
    int res = 1;

    for (int i = n; i > 0; i--) {
        res = res * i;
    }
    
    return res;
}