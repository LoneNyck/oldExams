/* Si vuole definire una funzione che, ricevuto in ingresso un array contenente n valori interi, e qualsiasi
altro parametro ritenuto strettamente necessario, verifichi se è possibile dividere l’array in due
partizioni aventi somma degli elementi uguale. */

#include <stdio.h>
#include <stdlib.h>

int *partizione(int *array, int len){
    int *part;
    int somma;
    int trovato = 0;
    int i, j;

    i = 0;
    while (i <= len - 1 && !trovato){
        somma = 0;
        for (j = 0; j < i; j++){
            somma += *(array + j);
        }
        for (j = i; j < len; j++){
            somma -= *(array + j);
        }
        if (somma == 0){
            trovato = 1;
        }
        else{
            i++;
        }
    }

    if (!trovato){
        return NULL;
    }
    part = malloc(sizeof(int) * (len - i));
    for (j = i; j < len; j++){
        *(part + j - i) = *(array + j);
    }
    return part;
}
