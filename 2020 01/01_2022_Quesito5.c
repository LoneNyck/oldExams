/* i definisca una funzione che, ricevuto come parametro il puntatore a un file di testo (e qualsiasi altro
parametro ritenuto necessario), determini quale dei 26 caratteri minuscoli dell’alfabeto compare nel file con
maggiore frequenza. Il programma restituisce all’ambiente chiamante il carattere e la sua frequenza. */

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_LET 26

int contaLettere(FILE *f, int let[NUM_OF_LET], char *lettera);

int main(int argc, char *argv[]){
    FILE *f;
    int let[26] = {0};
    int max;
    char c;

    if(argc != 2){
        printf("Parametri insufficienti in chiamata del programma\n");
        return 1;
    }

    f = fopen(argv[1], "r");

    max = contaLettere(f, let, &c);

    printf("La lettere che compare più volte è %c, per un totale di %d volte\n", c, max);

    return 0;
}

int contaLettere(FILE *f, int let[NUM_OF_LET], char *lettera){
    char c;
    int max;
    int i;

    if(f != NULL){
        while(!feof(f)){
            c = fgetc(f);

            if(c >= 'a' && c <= 'z'){
                let[c - 'a']++;
            }
        }
    }

    max = let[0];
    *lettera = 'a';
    for(i = 1; i < NUM_OF_LET; i++){
        if(let[i] > max){
            max = let[i];
            *lettera = 'a' + i;
        }
    }

    return max;
}