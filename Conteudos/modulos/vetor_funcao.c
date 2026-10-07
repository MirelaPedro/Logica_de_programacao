#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defifindo constantes
#define T_VETOR 100

//Protótipo das funcoes
void mostrar_vetor(int vetor[T_VETOR]);
int max(int vetor[T_VETOR]);

// FUNÇÃO MAIN
int main()
{
    int vetor[T_VETOR], maior;

    // Define somente a função rand 
    srand(time(NULL));

    // Carrega o vetor com os dados aleatórios
    for(int i = 0; i < T_VETOR; i++){
        vetor[i] = rand() % 10000;
    }

    mostrar_vetor(vetor);

    maior = max(vetor);

    printf("\nO maior valor no vetor é: %i\n", maior);

    return 0;
}

void mostrar_vetor(int vetor[T_VETOR])
{
    for(int i = 0; i < T_VETOR; i++){ // sizeof(vetor)/sizeof(int) :  a funcao sizeof retorna o valor em bytes, logo é necessário dividir pela quantidade de bytes que o tipo de dado int possui
        if (i % 10 == 0) printf("\n");
        printf("%i\t", vetor[i]);
    }
}

int max(int vetor[T_VETOR])
{
    int maior;

    for(int i = 0; i < T_VETOR; i++){

        if(i == 0) maior = vetor[i];
        if(maior < vetor[i]) maior = vetor[i];
    }

    return maior;
}
