/* i scriva una funzione ricorsiva in C che, ricevuta come parametro la testa della lista, modifichi i valori
nella lista sommando a ogni elemento il valore dell’elemento precedente. Il primo elemento resta
invariato. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista somma(Lista testa){
    if(testa == NULL || testa->next == NULL){
        return testa;
    }
    
    somma(testa->next);
    testa->next->val += testa->val;
    return testa;
}