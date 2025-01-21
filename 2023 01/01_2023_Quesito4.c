/* Scrivere una funzione che, ricevendo in ingresso una lista dinamica e un intero k > 0, individui il nodo che si trova k posizioni dopo il nodo centrale e ne restituisca il puntatore al chiamante. Se tale nodo non esiste, ad esempio a causa di un insufficiente numero di nodi nella lista, la funzione deve restituire il valore NULL.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    struct nd* next;
} Nodo;

Nodo *trova(Nodo *testa, int pos){
    Nodo* fast, *slow;
    int i;

    fast = testa;
    slow = testa;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    // a seconda di come fast sia giunto alla fine, il nodo sui cui punta slow è differente
    if(fast == NULL){
        i = 1;
    }
    else if(fast->next == NULL){
        i = 0;
    }

    while(slow->next != NULL && i < pos){
        slow = slow->next;
        i++;
    }

    if(pos == i){
        return slow;
    }
    else{
        return NULL;
    }
}