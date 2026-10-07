#include <stdio.h>

int main(){

    char letra;

    printf("Digite uma letra: ");
    scanf("%c", &letra);


    //SEM UMA VARIÁVEL AUXILIAR

    /*
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        printf("A letra é uma vogal!\n\n");
    } 
    if(letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u'){
        printf("A letra não é uma vogal!\n\n");
    } 
    */

    /*if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        printf("A letra é uma vogal!\n\n");
    } else {
        printf("A letra não é uma vogal!\n\n");
    }*/

    //COM UMA VARIÁVEL AUXILIAR

    int comp = letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u';

    
    if(comp){
        printf("A letra é uma vogal!\n\n");
    } 
    if(!comp) {
        printf("A letra não é uma vogal!\n\n");
    }
    

    /*if(comp){
        printf("A letra é uma vogal!\n\n");
    } else {
        printf("A letra não é uma vogal!\n\n");
    }*/

    return 0;
}