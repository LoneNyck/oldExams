/* Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una 
sequenza di interi. Dopo aver dichiarato in modo opportuno il tipo del nodo e la lista, si scriva una funzione in C
che riceve come parametro la testa della lista e un intero x e modifica la lista eliminando i valori che in essa 
ricorrono un numero di volte maggiore o uguale a x. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int val;
    struct nd *next; 
} Nodo;
typedef Nodo *Lista;

Lista eliminaNodi(Lista testa, int max);

// lista creata da ChatGPT per il testing
int main(){
    Nodo *scanner;

    Nodo *nodo1 = malloc(sizeof(Nodo));
    nodo1->val = 3;

    Nodo *nodo2 = malloc(sizeof(Nodo));
    nodo2->val = 5;
    nodo1->next = nodo2;

    Nodo *nodo3 = malloc(sizeof(Nodo));
    nodo3->val = 8;
    nodo2->next = nodo3;

    Nodo *nodo4 = malloc(sizeof(Nodo));
    nodo4->val = 4;
    nodo3->next = nodo4;

    Nodo *nodo5 = malloc(sizeof(Nodo));
    nodo5->val = 8;
    nodo4->next = nodo5;

    Nodo *nodo6 = malloc(sizeof(Nodo));
    nodo6->val = 5;
    nodo5->next = nodo6;

    Nodo *nodo7 = malloc(sizeof(Nodo));
    nodo7->val = 3;
    nodo6->next = nodo7;

    Nodo *nodo8 = malloc(sizeof(Nodo));
    nodo8->val = 8;
    nodo7->next = nodo8;

    nodo8->next = NULL;

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    printf("\n");

    nodo1 = eliminaNodi(nodo1, 1);

    scanner = nodo1;
    while(scanner != NULL){
        printf("%d->", scanner->val);
        scanner = scanner->next;
    }
    
    return 0;

}


Lista eliminaNodi(Lista testa, int max){
    Nodo *scanner, *prec, *scanner2, *prec2, *temp;
    int num;
    int freq;

    if(testa == NULL || testa->next == NULL){
        return testa;
    }

    prec = NULL;
    scanner = testa;
    while(scanner != NULL){
        num = scanner->val;
        freq = 1;
        
        scanner2 = scanner->next;
        while(scanner2 != NULL){
            if(scanner2->val == num){
                freq++;
            }
            scanner2 = scanner2->next;
        }

        if(freq >= max){
            prec2 = prec;
            scanner2 = scanner;

            while(scanner2 != NULL){
                if(scanner2->val == num){
                    if(prec2 == NULL){
                        temp = testa->next;
                        free(testa);
                        testa = temp;

                        prec = NULL;
                        scanner = testa;
                        prec2 = prec;
                        scanner2 = scanner;
                    }
                    else{
                        prec2->next = scanner2->next;
                        free(scanner2);
                        scanner2 = prec2->next;
                    }
                }
                else{
                    prec2 = scanner2;
                    scanner2 = prec2->next;
                }
            }
        }
        else{
            prec = scanner;
            scanner = prec->next;
        }
    }
    return testa;
}

