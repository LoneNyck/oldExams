/* Si codifichi in C una funzione void sdoppia( Lista lis, Lista * pPos, Lista * pNeg) che riceve
una lista lis e, modificando solo i collegamenti tra i nodi (senza allocare né deallocare memoria), costruisce e
rende disponibili al chiamante due liste così definite: una (puntata da pPos) che contiene tutti gli elementi con
valore positivo e una (puntata da pNeg) che contiene tutti gli elementi con valore negativo, preservandone
l’ordine originale */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

void sdoppia(Lista testa, Lista *pos, Lista *neg);

int main(){
    Lista pos, neg;
    Nodo *scanner;

    Nodo *nodo1 = malloc(sizeof(Nodo));
    nodo1->val = 1;

    Nodo *nodo2 = malloc(sizeof(Nodo));
    nodo2->val = -2;
    nodo1->next = nodo2;

    Nodo *nodo3 = malloc(sizeof(Nodo));
    nodo3->val = 3;
    nodo2->next = nodo3;

    Nodo *nodo4 = malloc(sizeof(Nodo));
    nodo4->val = -6;
    nodo3->next = nodo4;

    Nodo *nodo5 = malloc(sizeof(Nodo));
    nodo5->val = 9;
    nodo4->next = nodo5;

    Nodo *nodo6 = malloc(sizeof(Nodo));
    nodo6->val = -1;
    nodo5->next = nodo6;

    Nodo *nodo7 = malloc(sizeof(Nodo));
    nodo7->val = 5;
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

    sdoppia(nodo1, &pos, &neg);

    scanner = pos;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");
    scanner = neg;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    
    return 0;
}

void sdoppia(Lista testa, Lista *pos, Lista *neg){
    Nodo *scanner, *ultimoPos, *ultimoNeg;

    *pos = NULL;
    *neg = NULL;

    ultimoPos = NULL;
    ultimoNeg = NULL;

    scanner = testa;

    while(scanner != NULL){
        if(scanner->val < 0){
            if(ultimoNeg == NULL){
                *neg = scanner;
                ultimoNeg = *neg;
                scanner = scanner->next;
                ultimoNeg->next = NULL;
            }
            else{
                ultimoNeg->next = scanner;
                ultimoNeg = ultimoNeg->next;
                scanner = scanner->next;
                ultimoNeg->next = NULL;
            }
        }
        else{
            if(ultimoPos == NULL){
                *pos = scanner;
                ultimoPos = *pos;
                scanner = scanner->next;
                ultimoPos->next = NULL;
            }
            else{
                ultimoPos->next = scanner;
                ultimoPos = ultimoPos->next;
                scanner = scanner->next;
                ultimoPos->next = NULL;
            }
        }
    }
}