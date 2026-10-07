#include <stdio.h>

// Parâmetro por valor -> passa apenas o valor que está dentro da variável para uma cópia
int soma(int valor);
// Parâmetro por referência -> passa o endereço da memória em que está a variável
void soma_2(int *valor); // agora não é mais um escalar e sim um ponteiro

int main()
{
    int numero = 10;

    numero = soma(numero);
    soma_2(&numero); //agora é necessário passar o endereço, no caso o ponteiro

    printf("[main]-> Conteúdo de número...: %i\n", numero);
    
    printf("[main]-> Endereço de número: %p\n", &numero);

    return 0;
}

int soma(int valor)
{
    return ++valor;
}

void soma_2(int *valor)
{
    *valor = *valor + 1; //precisa isolar a variavel pq senão ele vai incrementar no endereço
    printf("[soma_2]-> Conteúdo de Valor: %i\n", *valor);//Para pegar o conteúdo da variável é necessário o *, que indica que está pegando o conteúdo da variável na qual foi indicada o endereço
    printf("[soma_2]-> Endereço de valor: %p\n", &valor); // Valor ainda é uma variável, ent tem endereco próprio
    printf("[soma_2]-> Endereço para qual o ponteiro aponta: %p\n", valor); //mas seu valor é o endereço da outra variável
}
