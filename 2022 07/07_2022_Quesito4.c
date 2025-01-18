/* Si definisca una funzione, ordine, che riceve in ingresso il puntatore al file in cui sono
memorizzati i nomi (e ogni altro parametro ritenuto necessario) e costruisce e restituisce al chiamante
una lista dinamica che memorizza i nomi contenuti nel file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nd{
    char *nome;
    char *cognome;
    struct nd *next;
} Nodo;

typedef Nodo *Lista;

Lista ordina(FILE *f);
int statistiche(Lista testa, char **cognome);

int main(){
    Lista testa;
    Nodo *scanner;
    char *cognome;
    int i;

    FILE *f = fopen("nomi.txt", "r");

    testa = ordina(f);

    scanner = testa;
    while(scanner != NULL){
        printf("%s %s->", scanner->cognome, scanner->nome);
        scanner = scanner->next;
    }
    printf("\n");

    fclose(f);

    i = statistiche(testa, &cognome);

    printf("%d\n", i);
    printf("%s\n", cognome);

    return 0;
}

Lista ordina(FILE *f){
    Nodo *testa, *nuovo;
    Nodo *scanner, *prec;
    char s[128];

    testa = NULL;

    while(!feof(f)){
        nuovo = malloc(sizeof(Nodo));

        fscanf(f, "%s", s);
        nuovo->nome = malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(nuovo->nome, s);

        fscanf(f, "%s", s);
        nuovo->cognome = malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(nuovo->cognome, s);

        if(testa == NULL){
            nuovo->next = testa;
            testa = nuovo;
        }
        else{
            prec = NULL;
            scanner = testa;

            while(scanner != NULL && strcmp(nuovo->cognome, scanner->cognome) > 0){
                prec = scanner;
                scanner = prec->next;
            }

            while(scanner != NULL && strcmp(nuovo->cognome, scanner->cognome) == 0 && strcmp(nuovo->nome, scanner->nome) > 0){
                prec = scanner;
                scanner = prec->next;
            }

            if(prec == NULL){
                nuovo->next = testa;
                testa = nuovo;
            }
            else{
                prec->next = nuovo;
                nuovo->next = scanner;
            }
        }
    }

    return testa;
}

int statistiche(Lista testa, char **cognome){
    Nodo *scanner, *prec;
    char *s;
    int max, occ;

    if(testa == NULL){
        s = malloc(sizeof(char));
        strcpy(s, "\0");
        *cognome = s;
        return 0;
    }

    scanner = testa;
    prec = NULL;
    max = 1;
    s = malloc(sizeof(char) * (strlen(testa->cognome) + 1));
    strcpy(s, testa->cognome);

    while(scanner->next != NULL){
        occ = 1;
        if(strcmp(scanner->cognome, scanner->next->cognome) != 0){
            prec = scanner;
            scanner = prec->next;
        }
        else{
            while(scanner->next != NULL && strcmp(scanner->cognome, scanner->next->cognome) == 0){
                prec = scanner;
                scanner = prec->next;
                occ++;
            }
        }
        
        if(occ > max){
            max = occ;
            s = realloc(s, sizeof(char) * strlen(prec->cognome) + 1);
            strcpy(s, prec->cognome);
        }
    }

    *cognome = s;
    return max;
}