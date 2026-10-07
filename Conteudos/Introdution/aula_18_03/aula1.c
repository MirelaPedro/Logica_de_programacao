#include <stdio.h>

int a;

int main()
{
    printf("Digite um número inteiro: ");
    scanf("%i", &a);

    //Soma e atribui a mesma variavel
    //a += 10; //a = a + 10;
    
    //Incremento(++) ou Decremento(--)
    a++; //a += 1;

    printf("O número final foi: %i\n", a);

    return 0;
}

/*
OPERADORES COMPOSTOS 
    ++ -> soma 1
    -- -> diminui 1
    += -> soma algo e           atribui a variavel  
    -= -> diminui algo e        atribui a variavel  
    *= -> multiplica por algo e atribui a variavel  
    /= -> divide por algo e     atribui a variavel  

*/
