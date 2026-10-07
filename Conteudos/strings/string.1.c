#include <stdio.h>
#include <stdlib.h>

#define T_STRING 100

int main(){
    int tamanho = 0;
    char string[T_STRING];

    gets(string);

    for(int i = 0; i < T_STRING; i++){
        if(string[i] != '\0'){
            tamanho++;
        } else{
            break;
        }
    }

    printf("Tamanho da string %s é: %i\n", string, tamanho);

    return 0;
}