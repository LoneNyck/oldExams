/* Un’azienda ha dotato i propri dipendenti di un sensore che emette un codice numerico ogni volta che un
dipendente attraversa la porta d’ingresso/uscita dell’azienda. L’azienda ha meno di 100 dipendenti. A ogni
attraversamento, il sensore registra ora e minuti del passaggio, insieme al codice del dipendente (un
codice alfanumerico di max 4 caratteri). */

#include <stdio.h>
#include <string.h>

#define MAX_LUNG_COD 10

typedef struct{
    int ora;
    int min;
} Orario; 

int minutiLavorati(FILE *f, char *codice);
int stampaDati(FILE *f);

int main(int argc, char *argv[]){
    FILE *f;

    if(argc != 2 && argc != 3){
        printf("Errore\n");
        return -1;
    }

    f = fopen(argv[1], "r");

    if(argc == 3){
        printf("%d\n", minutiLavorati(f, argv[2]));
    }
    else if(argc == 2){
        stampaDati(f);
    }

    fclose(f);
}

int minutiLavorati(FILE *f, char *codice){
    Orario registrazione, regDipendente[2];
    char codiceVisualizzato[MAX_LUNG_COD];
    int minLavorati = 0;
    int i = 0;

    if(f == NULL){
        printf("Errore: non è stato possibile aprire il file\n");
        return -1;
    }

    for(i = 0; i < 2; i++){
        regDipendente[i].min = 0;
        regDipendente[i].ora = 0;
    }

    i = 0;
    while(!feof(f)){
        fscanf(f, "%d %d %s", &registrazione.ora, &registrazione.min, codiceVisualizzato);

        if(!strcmp(codiceVisualizzato, codice)){
            regDipendente[i].ora = registrazione.ora;
            regDipendente[i].min = registrazione.min;
            i++;
        }
    }

    if(regDipendente[0].ora == regDipendente[1].ora){
        minLavorati = regDipendente[1].min - regDipendente[0].min;
    }
    else{
        minLavorati += (60 - regDipendente[0].min);
        for(i = regDipendente[0].ora + 1; i < regDipendente[1].ora; i++){
            minLavorati += 60;
        }
        minLavorati += regDipendente[1].min;
    }

    return minLavorati;
}

int stampaDati(FILE *f){
    Orario registrazione;
    char codice[MAX_LUNG_COD];

    if(f == NULL){
        printf("Errore: non è stato possibile aprire il file\n");
        return -1;
    } 

    while(!feof(f)){
        fscanf(f, "%d %d %s", &registrazione.ora, &registrazione.min, codice); 
        printf("%2d %2d %4s\n", registrazione.ora, registrazione.min, codice);
    }

    return 0;
}