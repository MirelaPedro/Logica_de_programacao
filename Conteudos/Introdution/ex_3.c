//ENTRADA DE DADOS EM C

#include <stdio.h>

int main(){
    int number1, number2, soma;

    //Entrada de dados
    printf("Digite um número inteiro: ");
    scanf("%i", &number1); //se não colocar o & vai dar erro pq nao tem autorização para sobreescrever na variável

    printf("Digite um segundo número inteiro: ");
    scanf("%i", &number2);

    //Escrevendo o comando diretamente no Scanf dá erro, pois o scanf é apenas para ler um dado, ou seja, apenas a entrada e não uma saída
    //scanf("Digite outro número inteiro: %i", &number2);

    //Processamento de dados
    soma = number1 + number2;

    //Saída de dados
    printf("O valor da soma dos números é: %i\n", soma);

    return 0;
}
