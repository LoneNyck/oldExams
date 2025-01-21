/* Si definisca la funzione almeno-k-consec, che restituisce 1 se nella lista sono presenti (almeno) 
k occorrenze consecutive del carattere (e restituisce 0 altrimenti). */


/* funzioni aggiungi_nodo e crea_nodo create da ChatGPT per il testing */
#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    char c;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

int almeno_k_consecutivi(Lista testa, char c, int k);
void aggiungi_nodo(Lista *lista, char valore);
Nodo *crea_nodo(char valore);

// main solo ai fini di testare la funzione
int main(){
    Lista testa = NULL;

    // Creazione della lista con i valori forniti
    char valori[] = {'a', 'b', 'c', 'a', 'a', 'a', 'b', 'c', 'a', 'a', 'a', 'a', 'a', 'k'};
    int lunghezza = sizeof(valori) / sizeof(valori[0]);

    for (int i = 0; i < lunghezza; i++) {
        aggiungi_nodo(&testa, valori[i]);
    }

    printf("%d\n", almeno_k_consecutivi(testa, 'a', 5));

    return 0;
}

int almeno_k_consecutivi(Lista testa, char c, int k){
    Nodo *scanner, *scanner2;
    int tot;

    if(testa == NULL){
        return 0;
    }

    scanner = testa;
    while(scanner->next != NULL){
        tot = 0;
        if(scanner->c == c && scanner->c == scanner->next->c){
            tot = 1;
            scanner2 = scanner->next;
            while(scanner2->c == scanner->c){
                tot++;
                scanner2 = scanner2->next;
            }
        }
        if(tot >= k){
            return 1;
        }
        scanner = scanner->next;
    }

    return 0;
}

Nodo *crea_nodo(char valore) {
    Nodo *nuovo = (Nodo *)malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        perror("Errore di allocazione");
        exit(EXIT_FAILURE);
    }
    nuovo->c = valore;
    nuovo->next = NULL;
    return nuovo;
}

void aggiungi_nodo(Lista *lista, char valore) {
    Nodo *nuovo = crea_nodo(valore);
    if (*lista == NULL) {
        *lista = nuovo;
    } else {
        Nodo *corrente = *lista;
        while (corrente->next != NULL) {
            corrente = corrente->next;
        }
        corrente->next = nuovo;
    }
}