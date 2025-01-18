/* Si vuole scrivere un programma in grado di analizzare un testo per determinare alcune statistiche sulla
frequenza delle parole in esso contenute */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nd{
    char *par;
    int freq;
    struct nd *next;
} Nodo;

Nodo *frequenza(FILE *f, Nodo *testa);
int statistiche(Nodo *testa, Nodo **min, Nodo **max);

int main(int argc, char *argv[]){
    FILE *f;
    Nodo *testa;
    Nodo *max, *min;
    int totParole;

    if(argc != 2){
        printf("Parametri insufficienti in chiamata\n");
        return -1;
    }

    f = fopen(argv[1], "r");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    testa = NULL;

    testa = frequenza(f, testa);

    totParole = statistiche(testa, &min, &max);

    printf("Nel file compaiono %d parole\n", totParole);
    printf("La parola con minore frequenza è %s, con una freq di %d\n", min->par, min->freq);
    printf("La parola con maggiore frequenza è %s, con una freq di %d\n", max->par, max->freq);

    return 0;
}

Nodo *frequenza(FILE *f, Nodo *testa){
    char parola[128];
    int len;
    Nodo *nuovo, *prec, *scanner;

    while(!feof(f)){
        fscanf(f, "%s", parola);
        len = strlen(parola);

        if(len > 1){
        nuovo = malloc(sizeof(Nodo));
        nuovo->par = malloc(sizeof(char) * (len + 1));

        strcpy(nuovo->par, parola);
        nuovo->freq = 1;

        prec = NULL;
        scanner = testa;

        while(scanner != NULL && strcmp(scanner->par, nuovo->par) < 0){
            prec = scanner;
            scanner = prec->next;
        }

        if(scanner != NULL && strcmp(scanner->par, nuovo->par) == 0){
            scanner->freq += nuovo->freq;
            free(nuovo);
        }
        else{
            if(prec == NULL){
            nuovo->next = testa;
            testa = nuovo;
            }
            else{
            nuovo->next = scanner;
            prec->next = nuovo;
            }
        }
        }
    }
    return testa;
}

int statistiche(Nodo *testa, Nodo **min, Nodo **max){
    Nodo *scanner;
    int totPar = 0;

    scanner = testa;
    *min = testa;
    *max = testa;

    while(scanner != NULL){
        if(scanner->freq < (*min)->freq){
            *min = scanner;
        }
        if(scanner->freq > (*max)->freq){
            *max = scanner;
        }
        totPar += scanner->freq;
        scanner = scanner->next;
    }

    return totPar;
}
