/* Dopo aver opportunamente definito i tipi di dati atti a rappresentare una lista dinamica di valori interi, si
scriva una funzione Lista MaggioriDiTuttiISuccessori(Lista pL) che, ricevendo la testa
di una lista dinamica di interi, la modifica eliminando da essa ciascun elemento E che sia minore di almeno
uno degli elementi successivi a E. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista maggioreDiTuttiISuccessivi(Lista testa);


// main di ChatGPT per il testing del programma
int main(){
    Nodo *scanner;

    Nodo *nodo1 = malloc(sizeof(Nodo));
    nodo1->val = 1;

    Nodo *nodo2 = malloc(sizeof(Nodo));
    nodo2->val = 10;
    nodo1->next = nodo2;

    Nodo *nodo3 = malloc(sizeof(Nodo));
    nodo3->val = 8;
    nodo2->next = nodo3;

    Nodo *nodo4 = malloc(sizeof(Nodo));
    nodo4->val = 6;
    nodo3->next = nodo4;

    Nodo *nodo5 = malloc(sizeof(Nodo));
    nodo5->val = 7;
    nodo4->next = nodo5;

    Nodo *nodo6 = malloc(sizeof(Nodo));
    nodo6->val = 3;
    nodo5->next = nodo6;

    Nodo *nodo7 = malloc(sizeof(Nodo));
    nodo7->val = 2;
    nodo6->next = nodo7;

    Nodo *nodo8 = malloc(sizeof(Nodo));
    nodo8->val = 4;
    nodo7->next = nodo8;

    nodo8->next = NULL;

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");

    nodo1 = maggioreDiTuttiISuccessivi(nodo1);

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    
    return 0;

}

Lista maggioreDiTuttiISuccessivi(Lista testa){
    Nodo *scanner, *scanner2, *prec;
    int trovato;

    prec = NULL;
    scanner = testa;

    while(scanner != NULL){
        scanner2 = scanner->next;
        trovato = 0;

        while(scanner2 != NULL && !trovato){
            if(scanner2->val > scanner->val){
                trovato = 1;
            }
            scanner2 = scanner2->next;
        }

        if(trovato){
            if(prec == NULL){
                scanner = testa->next;
                free(testa);
                testa = scanner;
            }
            else{
                prec->next = scanner->next;
                free(scanner);
                scanner = prec->next;
            }
        }
        else{
            prec = scanner;
            scanner = prec->next;
        }
    }

    return testa;
}
