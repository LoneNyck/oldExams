/* Si definisca una funzione ricorsiva che, ricevuti come parametri un array di interi, a, due valori interi, x e y, e
qualsiasi altro parametro ritenuto necessario, restituisca:
- il numero di volte in cui x è seguito da y, oppure
- il valore -1 nel caso in cui l’array non contenga alcuna occorrenza di x.
Per esempio, dato l’larray a[8]= {5,3,2,5,3,5,3,3},
- se x = 5 e y = 3 la funzione restituirà 3
- se x = 5 e y = 4 la funzione restituirà 0
- se x = 4, e quindi x non è presente nell’array, la funzione restituirà il valore -1 */

#include <stdio.h>
#include <stdlib.h>

int contiene(int *array, int x, int y, int len, int *trovato);

int main(){
    int array[8] = {5,3,2,5,3,5,3,3};
    int trovato = 0;

    printf("%d\n", contiene(array, 3,3, 8, &trovato));

    return 0;
}

int contiene(int *array, int x, int y, int len, int *trovato){
    if(len == 1 && *trovato){
        return 0;
    }
    else if(len == 1 && !*trovato){
        return -1;
    }

    if(!*trovato && *array == x){
        *trovato = 1;
    }
    if(*array == x && *(array + 1) == y){
        return 1 + contiene(array + 1, x, y, len - 1, trovato);
    }
    return contiene(array + 1, x, y, len - 1, trovato);
}