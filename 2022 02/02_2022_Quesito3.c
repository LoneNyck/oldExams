/* Sia data una lista dinamica che memorizza una sequenza di numeri interi, L1. I valori in L1 possono
essere ripetuti. A partire da L1 Si vuole costruire una seconda lista, L2, che memorizza i valori di L1 senza
ripetizioni e, per ognuno, la frequenza con cui appare in L1. La nuova lista L2 deve essere ordinata in
ordine crescente in base al valore. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;

typedef struct nd2{
    int val;
    int occ;
    struct nd2 *next;
} Nodo2;

typedef Nodo *Lista;
typedef Nodo *Lista2;

Lista2 costruisciLista(Lista testa){
    Lista2 testa2;
    Nodo *scanner;
    Nodo2 *scanner2, *prec, *nuovo;

    if(testa == NULL){
        return NULL;
    }

    testa2 = NULL;
    scanner = testa;
    while(scanner != NULL){
        nuovo = malloc(sizeof(Nodo2));

        nuovo->val = scanner->val;
        nuovo->occ = 1;

        if(testa2 == NULL){
            nuovo->next = testa2;
            testa2 = nuovo;
        }
        else{
            prec = NULL;
            scanner2 = testa2;
            while(scanner2 != NULL && nuovo->val > scanner2->val){
                prec = scanner2;
                scanner2 = prec->next;
            }
            if(scanner2 != NULL && nuovo->val == scanner2->val){
                (scanner2->occ)++;
                free(nuovo);
            }
            else if(prec == NULL){
                nuovo->next = testa2;
                testa2 = nuovo;
            }
            else{
                nuovo->next = scanner2;
                prec->next = nuovo;
            }
        }
        scanner = scanner->next;
    }
    return testa2;
}