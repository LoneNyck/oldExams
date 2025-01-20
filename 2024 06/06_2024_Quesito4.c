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

void sommaTriplette(Nodo *testa);

// main unicamente per il testing
int main(){
    Nodo *testa, *nuovoNodo, *scanner;
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

    sommaTriplette(testa);

    scanner = testa;
    while(scanner != NULL){
        printf("%d->", scanner->valore);
        scanner = scanner->next;
    }

    return 0;
}


void sommaTriplette(Nodo *testa){
    Nodo *scanner, *temp;
    int len = 0;
    int i;

    scanner = testa;
    while(scanner != NULL){
        len++;
        scanner = scanner->next;
    }

    if(len > 2){
        scanner = testa; 
        for(i = 0; i < (len / 3); i++){
            temp = scanner->next; 
            scanner->valore += (temp->valore + temp->next->valore);

            scanner->next = temp->next; 
            free(temp); 
            temp = scanner->next; 
            scanner->next = temp->next; 
            free(temp); 
            
            scanner = scanner->next;
        }
    }
}
