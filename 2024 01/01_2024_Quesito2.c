/* Si codifichi in C una funzione void ripulisci(FILE * fin, FILE * fout) che riceve
dal chiamante due file testuali (già aperti) (fin in modalità lettura e contenente l’elenco dei prodotti
potenzialmente duplicati, fout in modalità scrittura e inizialmente vuoto), individua e unifica i prodotti
duplicati, e salva in fout l'elenco compattato. */

#include <stdio.h>
#include <string.h>

#define MAX_PROD 100

typedef struct{
    char nome[20];
    int quantita;
} Prodotto;

void ripulisci(FILE * fin, FILE * fout);

int main(int argc, char *argv[]){
    FILE *fin, *fout;

    if(argc != 3){
        printf("Errore: argomenti insufficienti in chiamata\n");
        return -1;
    }

    fin = fopen(argv[1], "r");
    if(fin == NULL){
        printf("Errore: impossibile aprire file di input");
        return -1;
    }
    fout = fopen(argv[2], "w");
    if(fout == NULL){
        printf("Errore: impossibile aprire file di output");
        return -1;
    }

    ripulisci(fin, fout);
    printf("Operazione completata con successo!\n");

    fclose(fin);
    fclose(fout);

    return 0;
}

void ripulisci(FILE * fin, FILE * fout){
    Prodotto lista[MAX_PROD];
    int numeroProdotti, quantitaProdotto, presente;
    char nomeProdotto[20];
    int i;

    numeroProdotti = 0;
    while(!feof(fin)){
        presente = 0;
        quantitaProdotto = 0;
        fscanf(fin, "%s %d", nomeProdotto, &quantitaProdotto);
        
        i = 0;
        for(i = 0; i < numeroProdotti; i++){
            if(!strcmp(lista[i].nome, nomeProdotto)){
                lista[i].quantita += quantitaProdotto;
                presente = 1;
            }
        }
        if(!presente){
            stpcpy(lista[numeroProdotti].nome, nomeProdotto);
            lista[numeroProdotti].quantita = quantitaProdotto;
            numeroProdotti++;
        }
    }

    for(i = 0; i < numeroProdotti; i++){
        fprintf(fout, "%s %d\n", lista[i].nome, lista[i].quantita);
    }
}
