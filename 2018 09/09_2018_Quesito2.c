/* Si	 scriva	 una funzione	 in	 C che nella	 lista	 data	sostituisca	 le	 eventuali	 sottosequenze delimitate da	parentesi	tonde	(parentesi	aperta	all’inizio	della	sequenza,	parentesi	chiusa	
alla	fine	della	sequenza)	con	la somma/differenza/prodotto dei	valori in	esse	contenuti. */


/* Funzioni aggiungi_nodo, crea_nodo e stampa_lista create da ChatGPT per il testing della funzione */
#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    char c;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista modifica(Lista testa, char operatore);
void aggiungi_nodo(Lista *lista, char valore);
Nodo *crea_nodo(char valore);
void stampa_lista(Lista lista);

int main() {
    Lista testa = NULL;

    // Creazione della lista con i valori forniti
    char valori[] = {'1', '2', '(', '5', '2', '2', ')', '8', '9', '7', '(', '1', '2', ')'};
    int lunghezza = sizeof(valori) / sizeof(valori[0]);

    for (int i = 0; i < lunghezza; i++) {
        aggiungi_nodo(&testa, valori[i]);
    }

    // Stampa della lista
    printf("Lista creata: ");
    stampa_lista(testa);

    testa = modifica(testa, '+');

    stampa_lista(testa);

    return 0;
}

Lista modifica(Lista testa, char operatore){
    Nodo *scanner, *scanner2;
    int nuovoVal;

    if(testa == NULL){
        return testa;
    }

    scanner = testa;

    while(scanner != NULL){
        if(scanner->c == '('){
            scanner2 = scanner->next;
            switch(operatore){
                case '+':
                    nuovoVal = 0;
                    break;
                case '-':
                    nuovoVal = scanner2->c - '0';
                    scanner->next = scanner2->next;
                    free(scanner2);
                    scanner2 = scanner->next;
                    break;
                case '*':
                    nuovoVal = 1;
                    break;
                default:
                    break;
            }

            while(scanner2->c != ')'){
                switch(operatore){
                    case '+':
                        nuovoVal += scanner2->c - '0';
                        break;
                    case '-':
                        nuovoVal -= scanner2->c - '0';
                        break;
                    case '*':
                        nuovoVal *= scanner2->c - '0';
                        break;
                    default:
                        break;
                }

                scanner2 = scanner2->next;
                free(scanner->next);
                scanner->next = scanner2;
            }
            scanner->c = nuovoVal + '0';
            scanner->next = scanner2->next;
            free(scanner2);
            scanner2 = NULL;
        }
        scanner = scanner->next;
    }
    return testa;
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

void stampa_lista(Lista lista) {
    Nodo *corrente = lista;
    while (corrente != NULL) {
        printf("%c ", corrente->c);
        corrente = corrente->next;
    }
    printf("\n");
}