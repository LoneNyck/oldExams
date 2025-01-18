/* Si codifichi in C una funzione Lista filtra(Lista lis) che riceve una lista lis e la modifica in modo
che, per ciascuna coppia formata da un nodo in posizione dispari e dal successivo nodo in posizione pari, la
lista risultante contenga solo il nodo con il valore massimo della coppia. I nodi che non hanno valore massimo
nella loro coppia devono essere rimossi dalla lista. Se la lista ha un numero dispari di elementi, l’ultimo
elemento viene conservato nella lista modificata. Se una coppia ha i due elementi di ugual valore, entrambi
vengono conservati nella lista modificata.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valore;
    struct node *next;
} Nodo;

Nodo * filtra(Nodo *testa);

int main(){
    Nodo* n1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n2 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n3 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n4 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n5 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n6 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n7 = (Nodo*)malloc(sizeof(Nodo));

    Nodo* scanner;

    n1->valore = 1;
    n1->next = n2;

    n2->valore = 2;
    n2->next = n3;

    n3->valore = 5;
    n3->next = n4;

    n4->valore = 3;
    n4->next = n5;

    n5->valore = 7;
    n5->next = n6;

    n6->valore = 7;
    n6->next = n7;

    n7->valore = 4;
    n7->next = NULL;

    n1 = filtra(n1);
    scanner = n1;

    while(scanner != NULL){
        printf("%d->", scanner->valore);
        scanner = scanner->next;
    }
    return 0;
}


Nodo * filtra(Nodo *testa){
    Nodo *scanner, *prec, *temp;
    int len = 0;

    scanner = testa;
    while(scanner != NULL){
        len++;
        scanner = scanner->next;
    }
    scanner = NULL;

    // nel caso in cui la lista abbia un elemento o la lista sia vuota, la ritorno direttamente
    if(len == 1 || len == 0){
        return testa;
    }
    // * INIZIO DEL CODICE EFFETTIVO
    if(testa->valore < testa->next->valore){
        temp = testa->next;
        free(testa);
        testa = temp; 
        prec = testa; 
    }
    else if(testa->valore > testa->next->valore){
        temp = testa->next->next;
        free(testa->next);
        testa->next = temp;
        prec = testa; 
    }
    else{
        prec = testa->next;
    }
    scanner = prec->next;

    // scanner punta sempre al terzo elemento della lista originaria

    while(scanner != NULL && scanner->next != NULL){ 
        if(scanner->valore > scanner->next->valore){
            temp = scanner->next->next; 
            free(scanner->next);
            scanner->next = temp; 

            prec = scanner;
        }
        else if(scanner->valore < scanner->next->valore){
            prec->next = scanner->next;
            free(scanner);

            prec = prec->next;
        }
        else{
            prec = scanner->next;
        }
        scanner = prec->next;
    }
    return testa;
}