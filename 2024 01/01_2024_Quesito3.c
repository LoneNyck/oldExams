/* Si codifichi ricorsivamente in C una funzione char min
ch( char s[] ) che restituisce il minimo carattere di s (nel consueto ordine alfabetico).  */

#include <stdio.h>
#include <string.h>

char min_ch(char *s);

int main(){

    printf("%c\n", min_ch(""));

    return 0;
}

char min_ch(char *s){
    char prossimo;

    if(strlen(s) > 1){
        prossimo = min_ch(s + 1);
        if(*s < prossimo){
            return *s;
        }
        return prossimo;
    }
    return *s;
}