/* Scrivere una funzione che, ricevuta in ingresso una lista L di interi, un intero val ed un intero limit, elimini dalla 
lista tutti gli elementi che hanno val come val intero se e solo se il numero di volte che val compare nella 
lista è strettamente inferiore a limit.
Per l’eliminazione degli elementi realizzare una funzione delete che, data una lista e un val intero,
restituisce la lista modificata con l’eliminazione degli elementi aventi il val dato. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista modifica(Lista testa, int val, int limit);
Lista delete(Lista testa, int val);

// main di ChatGPT per il testing
int main(){
    Nodo* n1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n2 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n3 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n4 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n5 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n6 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n7 = (Nodo*)malloc(sizeof(Nodo));

    Nodo* scanner;

    n1->val = 1;
    n1->next = n2;

    n2->val = 1;
    n2->next = n3;

    n3->val = 1;
    n3->next = n4;

    n4->val = 3;
    n4->next = n5;

    n5->val = 7;
    n5->next = n6;

    n6->val = 1;
    n6->next = n7;

    n7->val = 4;
    n7->next = NULL;

    scanner = n1;

    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");

    n1 = modifica(n1, 1, 10);
    scanner = n1;

    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");

    return 0;
}

Lista modifica(Lista testa, int val, int limit){
    Nodo *scanner;
    int occ;

    if(testa == NULL){
        return NULL;
    }
    scanner = testa;
    occ = 0;

    while(scanner != NULL){
        if(scanner->val == val){
            occ++;
        }
        scanner = scanner->next;
    }
    if(occ < limit){
        testa = delete(testa, val);
    }

    return testa;
}
Lista delete(Lista testa, int val){
    Nodo *scanner, *prec, *temp;
    
    if(testa == NULL){
        return NULL;
    }

    prec = NULL;
    scanner = testa;

    while(scanner != NULL){
        if(scanner->val == val){
            if(prec == NULL){
                temp = testa->next;
                free(testa);
                testa = temp;
                scanner = testa;
                temp = NULL;
            }
            else{
                prec->next = scanner->next;
                free(scanner);
                scanner = prec->next;
            }
        }
        else{
            prec = scanner;
            scanner = scanner->next;
        }
    }

    return testa;
}