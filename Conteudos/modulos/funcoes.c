#include <stdio.h>
#include <string.h>


//Cabeçalho
void soma_a_b(void); //tipo_de_retorno_da_função nome(parâmetros)
int soma(void);

int main(){
    int soma;

    soma_a_b();
    soma = soma();

    printf("Soma: %i", soma);

    return 0;
}

//Implementação
void soma_a_b(void)
{
    int a = 10, b = 20;

    printf("Soma: %i\n", a + b);
}

int soma(void)
{
    int a = 40, b = 20;

    return a + b;
}
