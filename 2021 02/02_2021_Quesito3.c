/* Sia data una lista dinamica, L, che memorizza una sequenza di numeri interi.
Dato un valore intero val, si vogliono individuare e stampare tutte le sotto-sequenze di L tali che la somma dei
loro elementi sia minore o uguale a val. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;

typedef Nodo *Lista;

void sottoSequenze(Lista testa, int val);

//main di ChatGPT per il testing
int main() {
    // Creazione della lista: 4 -> 3 -> 1 -> 3 -> 7 -> 6 -> 7 -> 4 -> NULL
    Nodo *n1 = malloc(sizeof(Nodo));
    Nodo *n2 = malloc(sizeof(Nodo));
    Nodo *n3 = malloc(sizeof(Nodo));
    Nodo *n4 = malloc(sizeof(Nodo));
    Nodo *n5 = malloc(sizeof(Nodo));
    Nodo *n6 = malloc(sizeof(Nodo));
    Nodo *n7 = malloc(sizeof(Nodo));
    Nodo *n8 = malloc(sizeof(Nodo));

    n1->val = 4; n1->next = n2;
    n2->val = 3; n2->next = n3;
    n3->val = 1; n3->next = n4;
    n4->val = 3; n4->next = n5;
    n5->val = 7; n5->next = n6;
    n6->val = 6; n6->next = n7;
    n7->val = 2; n7->next = n8;
    n8->val = 4; n8->next = NULL;

    sottoSequenze(n1, 6);

    return 0;
}

void sottoSequenze(Lista testa, int val){
    Nodo *scanner;
    int somma;

    if(testa == NULL){
        printf("La lista è vuota\n");
        return;
    }

    scanner = testa;
    somma = 0;

    while(scanner != NULL){
        somma += scanner->val;

        if(val < scanner->val){
            printf("\nIl valore di val presenta un problema...\n");
            return;
        }

        if(somma <= val){
            printf("%d->", scanner->val);
            scanner = scanner->next;
        }
        else{
            printf("\n");
            somma = 0;
        }
    }
}