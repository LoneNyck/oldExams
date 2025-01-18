/* Sia data una lista che memorizza una sequenza di interi. La lista contiene almeno due nodi.
Dopo aver opportunamente definito il tipo dei nodi della lista, si scriva una funzione che riceve come parametro
la testa della lista e ne modifica i valori sommando a ogni elemento il valore dell'elemento precedente. Il primo
nodo rimane invariato. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;

void sommaPrec(Nodo *testa){
    if(testa->next->next != NULL){
        sommaPrec(testa->next);
    }

    testa->next->val += testa->val;
}