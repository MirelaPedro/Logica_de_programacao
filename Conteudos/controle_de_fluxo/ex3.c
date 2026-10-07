//Tendo como entrada de dados a altura e o sexo de uma pessoa, construa um algoritimo que calcule seu peso ideal, utilizando as seguintes fórmulas
//Para homens: (72.7 * h) - 58
//Para mulheres: (62.1 *h) - 44.7

#include <stdio.h>

int main(){
    char sexo;
    float h, peso;

    printf("Sexo: \nM - masculino \nF - feminino \n:");
    scanf("%c", &sexo);
    getchar();

    printf("Altura: ");
    scanf("%f", &h);

    if(sexo == 'M'){
        peso = (72.7 * h) - 58;
    } else{
        peso = (62.1 * h) - 44.7;
    }

    printf("Seu peso ideal é: %.2f\n", peso);

    return 0;
}

