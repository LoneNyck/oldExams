/* Si definisca una funzione che, ricevuti come parametri di ingresso un array a di n numeri
interi positivi, {x1, x2, ..., xn}, un intero y, (y>= xi, ∀ i = 1, ..., n), e qualsiasi altro parametro ritenuto necessario,
individui le partizioni dell’array costituite da elementi adiacenti con somma minore o uguale a y.
Per esempio, sia a = {2, 8, 0, 3, 9, 6, 1, 3} e sia y = 10. Allora:
{2, 8, 0} {3} {9} {6, 1, 3} sono le possibili partizioni individuabili in base al criterio sopra definito.
La funzione dovrà costruire e restituire al chiamante una lista dinamica i cui elementi memorizzano, per ogni
partizione individuata, gli indici nell’array del primo e dell’ultimo elemento della partizione. */

#include <stdio.h>
#include <stdlib.h>

#define N 128

typedef struct nd{
    int iniz;
    int fin;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista partizioni(int *array, int len, int max);

int main(int argc, char *argv[]){
    FILE *f;
    Lista testa;
    Nodo *scanner;
    int array[N] = {0};
    int max;
    int i;

    if(argc != 2){
        printf("Argomenti insufficienti o errati in chiamata\n");
    }
    else{
        f = fopen(argv[1], "r");
        if(f == NULL){
            printf("Errore nell'apertura del file\n");
        }
        else{
            i = 0;
            while(!feof(f)){
                fscanf(f, "%d", &array[i]);
                i++;
            }

            printf("Inserire valore max: ");
            scanf("%d", &max);

            testa = partizioni(array, i, max);

            scanner = testa;
            while(scanner != NULL){
                printf("<%d,%d> -> ", scanner->iniz, scanner->fin);
                scanner = scanner->next;
            }

            scanner = testa;
            while(scanner != NULL){
                printf("{ ");
                for(i = scanner->iniz; i <= scanner->fin; i++){
                    printf("%d ", array[i]);
                }
                printf("} -> ");
                scanner = scanner->next;
            }
        }
        fclose(f);
    }

    return 0;
}

Lista partizioni(int *array, int len, int max){
    Lista testa;
    Nodo *nuovo, *ultimo;
    int somma;
    int iniz, fin;
    int i;

    somma = 0;
    testa = NULL;
    ultimo = NULL;
    iniz = 0;

    i = 0;
    while(i < len){
        if(somma + array[i] > max || i == len - 1){
            if(i == len - 1){
                fin = len - 1;
            }
            else{
                fin = i - 1;
            }

            nuovo = malloc(sizeof(Nodo));
            if(nuovo == NULL){
                printf("Errore nell'allocazione di memoria\n");
                return NULL;
            }
            nuovo->iniz = iniz;
            nuovo->fin = fin;
            
            if(ultimo == NULL){
                nuovo->next = testa;
                testa = nuovo;
                ultimo = testa;
            }
            else{
                nuovo->next = NULL;
                ultimo->next = nuovo;

                ultimo = ultimo->next;
            }

            if(i != len - 1){
                iniz = i;
                somma = 0;
            }
            else{
                i++;
            }
        }
        else{
            somma += array[i];
            i++;
        }
    }

    return testa;
}
