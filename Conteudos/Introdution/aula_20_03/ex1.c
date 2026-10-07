#include <stdio.h>

int main()
{
    float salario;
    const float MINIMO = 1621; //é padrao escrever constantes em maiusculo

    printf("Salário: ");
    scanf("%f", &salario);

    int comp = salario > MINIMO;

    /*
    Seleção simples

    //A forma como foi feita inicialmente na aula

    if(salario > MINIMO){
        printf("Este salário é maior que o mínimo de R$%2.f\nSendo R$%2.f\n", MINIMO, salario);
    }


    if(salario <= MINIMO){
        printf("Este salário é menor ou igual ao mínimo de R$%2.f\nSendo R$%2.f\n", MINIMO, salario);
    }
    */

    if(comp){
        printf("Este salário é maior que o mínimo de R$%2.f\nSendo R$%2.f\n", MINIMO, salario); //este é o comando que esta sendo condicionado
    } else {
        printf("Este salário é menor ou igual ao mínimo de R$%2.f\nSendo R$%2.f\n", MINIMO, salario);
    }

    return 0;
}


/*
DESVIOS CONDICIONAIS

if(expressao_condiocional) {
    cmds...
    cmds...
}
*/
