/* Si scriva una funzione ricorsiva che, ricevuto come parametro un array di interi e ogni parametro
ritenuto necessario, individui e restituisca al chiamante il valore massimo dell’array. */

#include <stdio.h>

int massimo(int *array, int len);

int massimo(int *array, int len){
    int max;

    if(len == 1){
        return *array;
    }
    max = massimo(array + 1, len - 1);

    if(*array > max){
        return *array;
    }
    return max;
}