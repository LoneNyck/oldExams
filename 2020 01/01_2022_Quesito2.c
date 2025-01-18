/* Si scriva una funzione ricorsiva che, ricevuti come parametri un array di interi, a, un intero
Quesito 2 (5 punti). positivo, val, e altri parametri eventualmente ritenuti necessari, restituisce 1 se il numero di valori negativi in a
è maggiore di val, 0 altrimenti. */

#include <stdio.h>

int tantiNegativi(int *a, int len, int val, int *neg);

int tantiNegativi(int *a, int len, int val, int *neg){
    if(len == 0){
        return 0;
    }

    if(*a < 0){
        (*neg)++;
    }

    if(*neg > val){
        return 1;
    }
    if(len == 1){
        return 0;
    }

    return tantiNegativi(a + 1, len - 1, val, neg);
}