/* riceve come parametro una lista e, a partire dall’inizio, la modifica nel seguente modo: per ciascuna tripletta (tre
nodi consecutivi) modifica il valore del primo nodo, sostituendolo con la somma dei tre valori della tripletta, e rimuove
i due nodi successivi. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nd{
    int valore;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista sommaTriplette(Lista testa);

// main unicamente per il testing
// cambiare il limite nel for per vedere tutti i casi possibili
int main(){
    Lista testa;
    Nodo *nuovoNodo, *scanner;
    srand(time(NULL));

    testa = NULL;

    for(int i = 0; i < 5; i++){
        nuovoNodo = malloc(sizeof(Nodo));
        nuovoNodo->valore = rand() % 10;
        nuovoNodo->next = testa;
        testa = nuovoNodo;
    }

    scanner = testa;
    while(scanner != NULL){
        printf("%d->", scanner->valore);
        scanner = scanner->next;
    }
    printf("\n");

    testa = sommaTriplette(testa);

    scanner = testa;
    while(scanner != NULL){
        printf("%d->", scanner->valore);
        scanner = scanner->next;
    }

    return 0;
}

Lista sommaTriplette(Lista testa){
    Nodo *scanner, *temp1, *temp2;
    int i;

    if(testa == NULL || testa->next == NULL || testa->next->next == NULL){
        return testa;
    }

    scanner = testa;
    while(scanner != NULL && scanner->next != NULL && scanner->next->next != NULL){
        scanner->valore += (scanner->next->valore + scanner->next->next->valore);
        temp1 = scanner->next;
        temp2 = scanner->next->next;

        scanner->next = temp2->next;
        free(temp1);
        free(temp2);
        scanner = scanner->next;
    }

    return testa;
}