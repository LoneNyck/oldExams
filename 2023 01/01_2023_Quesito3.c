/* Si vuole definire un programma in C che aiuti la mamma a capire se una ricetta può essere preparata con gli
ingredienti disponibili in cucina. Il programma fa uso di due file: */

#include <stdio.h>
#include <string.h>

#define SIZE 20
#define N 32

typedef struct{
    char nome[SIZE];
    int quantita;
} Prodotto;

int controllaRicetta(FILE *fileDispensa, FILE *fileRicetta);

int main(int argc, char *argv[]){
    FILE *fDisp, *fRic;
    int prep;

    if(argc != 3){
        printf("Argomenti insufficienti durante la chiamata di funzione\n");
        return -1;
    }

    fDisp = fopen(argv[1], "r");
    fRic = fopen(argv[2], "r");

    if (fDisp == NULL || fRic == NULL){
        printf("Errore nell'apertura dei file\n");
        return -1;
    }

    prep = controllaRicetta(fDisp, fRic);

    if(prep){
        printf("La ricetta può essere preparata\n");
    }
    else{
        printf("La ricetta non può essere preparata\n");
    }
    
    fclose(fRic);
    fclose(fDisp);    

    return 0;
}


int controllaRicetta(FILE *fileDispensa, FILE *fileRicetta){
    Prodotto ingredientiDisponibili[N], ingredientiRicetta[N];
    int prodottiDispensa, prodottiRicetta;
    int trovato, prep;
    int i, j;

    prodottiDispensa = 0;
    prodottiRicetta = 0;

    while(!feof(fileDispensa)){
        fscanf(fileDispensa, "%s %d", ingredientiDisponibili[prodottiDispensa].nome, &ingredientiDisponibili[prodottiDispensa].quantita);
        prodottiDispensa++;
    }

    while(!feof(fileRicetta)){
        fscanf(fileRicetta, "%s %d", ingredientiRicetta[prodottiRicetta].nome, &ingredientiRicetta[prodottiRicetta].quantita);
        prodottiRicetta++;
    }

    prep = 1;

    for(i = 0; i < prodottiRicetta; i++){
        j = 0;
        trovato = 0;
        while(j < prodottiDispensa && !trovato){
            if(!strcmp(ingredientiRicetta[i].nome, ingredientiDisponibili[j].nome)){
                trovato = 1;
            }
            else{
                j++;
            }
        } 
        printf("%s: ", ingredientiRicetta[i].nome);
        if(trovato && ingredientiDisponibili[j].quantita >= ingredientiRicetta[i].quantita){
            printf("Ok\n");
        }
        else if(trovato && ingredientiDisponibili[j].quantita < ingredientiRicetta[i].quantita){
            printf("mancanti %d\n", ingredientiRicetta[i].quantita - ingredientiDisponibili[j].quantita);
            prep = 0;
        }
        else{
            printf("mancanti %d\n)", ingredientiRicetta[i].quantita);
            prep = 0;
        }
    }
    if(prep){
        return 1;
    }
    return 0;
}  