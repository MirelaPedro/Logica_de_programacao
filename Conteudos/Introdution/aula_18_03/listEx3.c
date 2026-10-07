#include <stdio.h>

//Declarando as variáveis e constantes
float salario;
const float aumento = 1.1;

int main()
{
    printf("Digite o salario: ");
    scanf("%f", &salario);

    salario *= aumento;

    printf("O salário Final é: R$%.2f \n\n", salario);

    return 0;
}
