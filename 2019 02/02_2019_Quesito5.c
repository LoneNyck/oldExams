/* Si vuole realizzare un correttore automatico in grado di individuare e correggere alcuni errori 
di battitura presenti in un testo. Il correttore sostituisce le vocali seguite dall’apostrofo con le corrispondenti 
vocali accentate. Quindi, parole come puo’, perche’, piu’, gia’, sono sostituite con può, benché, più, 
già (il verso degli accenti non è rilevante).
Si scriva un programma in C, opportunamente organizzato in funzioni, che legga un testo da un file, una parola 
alla volta, corregga nelle parole lette le eventuali vocali apostrofate, e salvi tutte le parole (corrette o non) in un 
nuovo file.
I nomi dei due file, quello da cui leggere il testo iniziale e quello in cui scrivere il testo corretto, devono essere 
specificati come argomenti della linea di comando (parametro del main). 
N.B.: Non si conosce la lunghezza massima delle parole memorizzate nel testo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void correggi(FILE *fIN, FILE *fOut);

int main(int argc, char *argv[]){
    FILE *fIn, *fOut;

    if(argc != 3){
        printf("Parametri insufficienti in chiamata\n");
        return -1;
    }

    fIn = fopen(argv[1], "r");
    fOut = fopen(argv[2], "w");

    if(fIn == NULL || fOut == NULL){
        printf("Errore nell'apertura dei file\n");
        return -1;
    }

    correggi(fIn, fOut);

    fclose(fIn);
    fclose(fOut);

    return 0;
}

void correggi(FILE *fIn, FILE *fOut){
    char *s;
    char c;
    int cont;

    cont = 0;
    s = malloc(sizeof(char) * (cont + 1));

    while(!feof(fIn)){
        c = fgetc(fIn);

        // parola finita
        if(c == ' ' || c == EOF){
            //controllare l'accento
            if(s[cont - 1] == '\''){
                c = s[cont - 2];
                switch(c){
                    case 'a':
                        strcpy(&s[cont - 2], "à");
                        break;
                    case 'e':
                        strcpy(&s[cont - 2], "è");
                        break;
                    case 'i':
                        strcpy(&s[cont - 2], "ì");
                        break;
                    case 'o':
                        strcpy(&s[cont - 2], "ò");
                        break;
                    case 'u':
                        strcpy(&s[cont - 2], "ù");
                        break;
                    default:
                        break;
                }
            }

            fprintf(fOut, "%s ", s);
            free(s);

            cont = 0;
            s = malloc(sizeof(char) * (cont + 1));
        }
        else{
            cont++;
            s = realloc(s, sizeof(char) * (cont +1));
            s[cont - 1] = c;
        }
    }
}