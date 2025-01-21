/* Una sequenza di caratteri è rappresentata da una lista dinamica. Scrivere una funzione che,
ricevendo in ingresso una lista dinamica che rappresenta una sequenza di soli caratteri alfabetici, la comprime
sostituendo ad ogni sottosequenza di almeno due caratteri alfabetici consecutivi uguali (ad esempio ..bbbb..),
una coppia di caratteri (nell’esempio ..b4..) costituita dal carattere alfabetico che viene ripetuto e dalla cifra (un
carattere compreso tra ‘2’ e ‘9’) che indica la lunghezza della sottosequenza. */

/* funzione crea lista di ChatGPT */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nd{
    char c;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista accorcia(Lista testa);
Lista creaLista();

// main per il testing
int main(){
    Lista testa;
    Nodo *scanner;

    testa = NULL;
    testa = creaLista();

    testa = accorcia(testa);

    scanner = testa;
    while(scanner != NULL){
        printf("%c", scanner->c);
        scanner = scanner->next;
    }
    printf("\n");

    return 0;
}

Lista creaLista(){
    Nodo *testa, *ultimo;
    char sequenza[100] = "ciao";
    int i;

    testa =  NULL;
    ultimo = NULL;
    for (i = 0; i < strlen(sequenza); i++) {
        Nodo *nuovo = malloc(sizeof(Nodo));
        nuovo->c = sequenza[i];
        nuovo->next = NULL;
        
        if (testa == NULL) {
            testa = nuovo;
            ultimo = testa;
        } else {
            ultimo->next = nuovo;
            ultimo = nuovo;
        }
    }
    return testa;
}

Lista accorcia(Lista testa){
    Nodo *scanner, *uguali, *temp;
    int cont;
    int i;

    scanner = testa;
    uguali = scanner;

    while(scanner != NULL){
        cont = 1;
        while(uguali != NULL && uguali->next != NULL && uguali->next->c == uguali->c){
            cont++;
            uguali = uguali->next;
        }

        if(cont > 1){
            for(i = 0; i < cont - 2; i++){
                temp = scanner->next;
                scanner->next = temp->next;
                free(temp);
            }

            uguali->c = '0' + cont; 
        }

        scanner = scanner->next;
        uguali = scanner;
    }

    return testa;
}