/* Un’azienda ha dotato i propri dipendenti di un sensore che emette un codice numerico ogni volta che un
regDipendente attraversa la porta d’ingresso/uscita dell’azienda. L’azienda ha meno di 100 dipendenti. A ogni
attraversamento, il sensore registra ora e minuti del passaggio, insieme al codice del regDipendente (un
codice alfanumerico di max 4 caratteri). 
Si scrivano due funzioni. La prima calcola i minuti lavorati da un singolo dipendente.
La seconda stampa tutte le registrazioni
Le registrazioni son salvate su un file.
Si scriva quindi un main che riceve come parametro il file ed eventualmente il codice del dipendente:
nel primo caso stampa tutte le registrazioni, nel secondo i minuti lavorati dal dipendente con il codice inserito */

#include <stdio.h>
#include <string.h>

#define MAX_LUNG_COD 5

typedef struct{
    int ora;
    int min;
} Orario; 

int minutiLavorati(FILE *f, char *codice);
void stampaDati(FILE *f);

int main(int argc, char *argv[]){
    FILE *f;

    if(argc != 2 && argc != 3){
        printf("I parametri passati sono errati\n");
        return -1;
    }

    f = fopen(argv[1], "r");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    if(argc == 3){
        printf("%d\n", minutiLavorati(f, argv[2]));
    }
    else if(argc == 2){
        stampaDati(f);
    }

    fclose(f);

    return 0;
}

int minutiLavorati(FILE *f, char *codice){
    Orario reg, regDipendente[2];
    char codiceLetto[MAX_LUNG_COD];
    int minLavorati;
    int i;

    i = 0;
    for(i = 0; i < 2; i++){
        regDipendente[i].min = 0;
        regDipendente[i].ora = 0;
    }

    i = 0;
    while(!feof(f) && i < 2){
        fscanf(f, "%d %d %s", &reg.ora, &reg.min, codiceLetto);

        if(!strcmp(codiceLetto, codice)){
            regDipendente[i].ora = reg.ora;
            regDipendente[i].min = reg.min;
            i++;
        }
    }

    minLavorati = 0;
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

void stampaDati(FILE *f){
    Orario reg;
    char codice[MAX_LUNG_COD];

    while(!feof(f)){
        fscanf(f, "%d %d %s", &reg.ora, &reg.min, codice); 
        printf("%2d %2d %4s\n", reg.ora, reg.min, codice);
    }
}