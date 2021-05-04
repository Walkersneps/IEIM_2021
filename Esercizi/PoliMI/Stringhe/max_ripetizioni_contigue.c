#include <string.h>
#include <stdio.h>

void max_rip(char s[]) {
    int best = 0, counter = 0;
    char best_char = 'a', current = 'a';
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == current) { // sono sulla stessa wave
            counter++;
        } else { // s[i] interrompe la streak
            if (counter > best) { // la streak appena interrotta ha fatto record
                best = counter;
                best_char = current;
            }

            // mi preparo per la nuova wave
            current = s[i];
            counter = 1;
        }
    }

    if (counter > best) { // verifico se l'ultima streak prima della fine della stringa abbia fatto record
        best = counter;
        best_char = current;
    }

    printf("\nLa '%c' compare con un record di %d apparizioni consecutive.\n\n", best_char, best);
}


void max_rip_ricorsiva(char s[], int best, char bchar, int curr, char lastChar) {
    if (strlen(s) < 1) printf("\nLa '%c' compare con un record di %d apparizioni consecutive.\n\n", bchar, best); // caso banale (stringa esaurita)
    else {
        if (s[0] == lastChar) {
            curr++;
            if (curr > best) return max_rip_ricorsiva(s+1, curr, lastChar, curr, lastChar);
            else return max_rip_ricorsiva(s+1, best, bchar, curr, lastChar);
        } else { // streak interrotta
            if (curr > best) return max_rip_ricorsiva(s+1, curr, s[0], 0, s[0]);
            else return max_rip_ricorsiva(s+1, best, bchar, 0, s[0]);
        }
    }
}




int main() {
    char s[100];
    printf("\nInserisci una stringa: ");
    scanf("%s", s);

    //max_rip(s);
    max_rip_ricorsiva(s, 0, 'a', 0, 'a');

    return 0;
}