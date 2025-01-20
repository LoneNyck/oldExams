/* Si definisca una funzione ricorsiva int coppie(int n) che restituisce il numero di coppie di cifre
uguali in posizioni adiacenti presenti nel numero n. Nel caso n sia negativo restituisce 0. */

#include <stdio.h>

int coppie(int num);

int main(){

    printf("%d\n", coppie(112233));

    return 0;
}

int coppie(int num){
    if(num < 0){
        return -1;
    }
    if(num > 9){
        if(num % 10 == (num / 10) % 10){
            return 1 + coppie(num / 10);
        }
        return coppie(num / 10);
    }
    return 0;
}