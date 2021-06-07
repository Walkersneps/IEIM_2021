int consonante(char carattere) {
    if (carattere == 'a' ||
        carattere == 'e' ||
        carattere == 'i' ||
        carattere == 'o' ||
        carattere == 'u')
        return 0;
    else return 1;
}

int contaVocali(char stringa[]) {
  if (stringa[0] == '\0') return 0;
  if (consonante(stringa[0])) return contaVocali(stringa + 1);
  else return (1 + contaVocali(stringa + 1));
}


#include <stdio.h>
int main() {
    char s[50];

    printf("Inserisci stringa: ");
    scanf("%s", &s);

    printf("\nLa stringa \"%s\" contiene %d vocali.\n", s, contaVocali(s));

    return 0;
}