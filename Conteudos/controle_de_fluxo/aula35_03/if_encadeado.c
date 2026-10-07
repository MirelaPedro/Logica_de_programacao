# include <stdio.h>

/*
Ler uma letra, se vogal, ler um nº inteiro,
caso seja consoante, ler um nº float

1. se o nº inteiro for maior que dez, some 1, caso o contrario, diminua 1.

*/

char letra;

int main(){

    printf("Letra: ");
    scanf("%c", &letra);
    getchar();

    //CONDICIONAL DE VOGAL
    if(letra == 'a' || letra == 'A' || 
        letra == 'e' || letra == 'E' || 
        letra == 'i' || letra == 'I' || 
        letra == 'o' || letra == 'O' || 
        letra == 'u' || letra == 'U')
    {//Como faz para transformar a letra em minúscula?
        int number;
        printf("Digite um número inteiro: ");
        scanf("%i", &number);

        //Contador ou 
        if(number > 10){
            number++;
        } else {
            number--;
        }

        printf("Number: %i", number);
    }
    //CONDICINAL DE CONSOANTE 
    else{
        float number;

        printf("Digite um número real: ");
        scanf("%f", &number);
        
        printf("Number: %.2f", number);
    }

    printf("\n");

    return 0;
}


