/* Si scriva un sottoprogramma ricorsivo void(...) che riceve due array ordinati e le loro dimensioni, e copia i loro
elementi in un terzo array, che dovrà risultare anch'esso ordinato. Anche il terzo array dovrà esser passato come
parametro al sottoprogramma. */

#include <stdio.h>

void creaArray(int *array1, int *array2, int len1, int len2, int *array3){
    if(len1 != 0 && len2 != 0){
        if(*array1 < *array2){
            *array3 = *array1;
            creaArray(array1 + 1, array2, len1 - 1, len2, array3 + 1);
        }
        else{
            *array3 = *array2;
            creaArray(array1, array2 + 1, len1, len2 - 1, array3 + 1);
        }
    }
    else{
        if(len2 == 0){
            *array3 = *array1;
            creaArray(array1 + 1, array2, len1 - 1, len2, array3 + 1);
        }
        else if(len1 == 0){
            *array3 = *array2;
            creaArray(array1, array2 + 1, len1  - 1, len2, array3 + 1);
        }
    }
}

int main(){
    int array1[4] = {1,4,6,10};
    int array2[4] = {2,3,6,9};
    int array3[8] = {0};

    creaArray(array1, array2, 4, 4, array3);

    for(int i = 0; i < 8; i++){
        printf("%d ", array3[i]);
    }

    return 0;
}