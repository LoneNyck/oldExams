/* Data una lista dinamica, una sua rotazione a destra fa in modo che l’ultimo valore a destra venga spostato in
testa.
Dopo aver definito un tipo di dato opportuno per rappresentare gli elementi di una lista di interi, si definisca una
funzione che, ricevuta in ingresso una lista con nodi del tipo definito e un valore intero k >= 0, effettui k rotazioni
a destra, per effetto delle quali gli ultimi k elementi della lista sono spostati in testa. */

/* main e funzione creaNodo generate da ChatGPT per controllare il funzionamento*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Nodo *creaNodo(int val);
Lista ruota(Lista testa, int k);

int main() {
    Lista lista, scanner;
    Nodo *n1 = creaNodo(6);
    Nodo *n2 = creaNodo(8);
    Nodo *n3 = creaNodo(3);
    Nodo *n4 = creaNodo(1);
    Nodo *n5 = creaNodo(10);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    lista = n1;
    printf("Lista originale: ");
    scanner = lista;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }

    lista = ruota(lista, 1);
    printf("\nLista dopo 2 rotazioni: ");

    scanner = lista;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }

    return 0;
}

Nodo *creaNodo(int val) {
    Nodo *nuovoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuovoNodo->val = val;
    nuovoNodo->next = NULL;
    return nuovoNodo;
}

Lista ruota(Lista testa, int k){
    Lista scanner, ultimo, primo;
    int i;

    if(testa == NULL || testa->next == NULL || k == 0){
        return testa;
    }

    scanner = testa;
    ultimo = NULL;
    primo = NULL;

    i = 0;

    while(scanner->next != NULL){
        scanner = scanner->next;
        i++;

        if(i == k){
            ultimo = testa;
        }
        if(i > k){
            ultimo = ultimo->next;
        }
    }

    if(ultimo == NULL){
        return testa;
    }

    primo = ultimo->next;
    ultimo->next = NULL;
    scanner->next = testa;

    return primo;
}