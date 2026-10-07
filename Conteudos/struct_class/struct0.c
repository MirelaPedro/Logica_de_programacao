#include <stdio.h>

//Tipo 'novo' de dado
struct produto{
    int codigo;
    float valor;

};

//Essa forma é só usada para estruturas que vão ser usadas apenas em momentes específicos
//é a única situação no c que precisa do ; depois de {}
//porque assim pode ser declarado as variaveis logo após // } p0, p1;

typedef struct produto produto_t; //definindo um novo tipo do tipo struct produto 
//colocar o _t no final é uma boa prática para indicar que é um tipo de dado

/* typedef struct{
    int codigo;
    float valor;
} produto_t; */

/* typedef struct produto{
    int codigo;
    float valor;
} produto_t; */

int main(){
    //Declarando uma variável do tipo struct produto
    produto_t p0, p1;

    printf("Código do produto: ");
    scanf("%i", &p0.codigo);

    printf("Código lido.........: %i\n", p0.codigo);

    printf("Valor do produto: ");
    scanf("%f", &p0.valor);

    printf("Valor lido..........: %.2f\n", p0.valor);

    p1 = p0; //o c aceita isso

    printf("p1 código: %i\n", p1.codigo);
    printf("p1 valor: %.2f\n", p1.valor);

    return 0;
}

/*
Variáveis compostas heterogênias: um tipo de dado que possui varios tipos primitivos sem misturar
TAD - Tipo abstrato de dado -> struct
*/