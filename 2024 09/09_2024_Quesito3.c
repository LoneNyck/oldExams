/* Si codifichi in C una funzione Lista filtra(Lista lis) che riceve una lista lis e la modifica in modo
che, per ciascuna coppia formata da un nodo in posizione dispari e dal successivo nodo in posizione pari, la
lista risultante contenga solo il nodo con il val massimo della coppia. I nodi che non hanno val massimo
nella loro coppia devono essere rimossi dalla lista. Se la lista ha un numero dispari di elementi, l’ultimo
elemento viene conservato nella lista modificata. Se una coppia ha i due elementi di ugual val, entrambi
vengono conservati nella lista modificata.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Nodo;
typedef Nodo *Lista;

Lista filtra(Lista testa);

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
    n1->next = n2; //

    n2->val = 2;
    n2->next = n3;

    n3->val = 5;
    n3->next = n4;

    n4->val = 3;
    n4->next = n5; //

    n5->val = 7;
    n5->next = n6;

    n6->val = 7;
    n6->next = n7;

    n7->val = 4;
    n7->next = NULL;

    n1 = filtra(n1);

    scanner = n1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }

    return 0;
}

Lista filtra(Lista testa){
    Nodo *scanner, *prec, *temp;

    if(testa == NULL || testa->next == NULL){
        return testa;
    }

    prec = NULL;
    scanner = testa;

    while(scanner != NULL && scanner->next != NULL){
        if(scanner->val > scanner->next->val){
            temp = scanner->next;
            scanner->next = temp->next;
            free(temp);
            temp = NULL;

            prec = scanner;
            scanner = prec->next;
        }
        else if(scanner->val < scanner->next->val){
            if(prec == NULL){
                temp = testa->next;
                free(testa);
                testa = temp;
                temp = NULL;

                prec = testa;
                scanner = testa->next;
            }
            else{
                prec->next = scanner->next;
                free(scanner);
                scanner = prec->next;

                prec = scanner;
                scanner = prec->next;
            }
        }
        else{
            prec = scanner->next;
            scanner = prec->next;
        }
    }

    return testa;
}