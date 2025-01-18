/* Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una sequenza di interi. Si 
scriva una funzione ricorsiva in C che riceve come parametro la testa della lista, modifica la lista sommando a
ogni elemento il valore di tutti gli elementi a esso successivi (l’ultimo elemento resta invariato), e restituisca la 
somma di tutti i valori nella lista. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next; 
} Nodo;
typedef Nodo *Lista;

Lista aggiungiSuccessivi(Lista testa);

// lista creata da ChatGPT per il testing
int main(){ 
    Nodo *scanner;
    
    Nodo *nodo1 = malloc(sizeof(Nodo));
    nodo1->val = 2;

    Nodo *nodo2 = malloc(sizeof(Nodo));
    nodo2->val = 0;
    nodo1->next = nodo2;

    Nodo *nodo3 = malloc(sizeof(Nodo));
    nodo3->val = 3;
    nodo2->next = nodo3;

    Nodo *nodo4 = malloc(sizeof(Nodo));
    nodo4->val = 2;
    nodo3->next = nodo4;

    Nodo *nodo5 = malloc(sizeof(Nodo));
    nodo5->val = 0;
    nodo4->next = nodo5;

    Nodo *nodo6 = malloc(sizeof(Nodo));
    nodo6->val = 3;
    nodo5->next = nodo6;

    Nodo *nodo7 = malloc(sizeof(Nodo));
    nodo7->val = 121;
    nodo6->next = nodo7;

    Nodo *nodo8 = malloc(sizeof(Nodo));
    nodo8->val = 18;
    nodo7->next = nodo8;

    Nodo *nodo9 = malloc(sizeof(Nodo));
    nodo9->val = 0;
    nodo8->next = nodo9;

    nodo9->next = NULL;

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");

    nodo1 = aggiungiSuccessivi(nodo1);

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }

    return 0;
}

Lista aggiungiSuccessivi(Lista testa){
    if(testa == NULL || testa->next == NULL){
        return testa;
    }
    aggiungiSuccessivi(testa->next);
    testa->val += testa->next->val;
    return testa;
}