#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define T 10

typedef char String[100];

void copy_vetor(int original[T], int copia[T]);
void carregar_vetor(int vetor[T]);
void mostrar_vetor(int vetor[T], String msg);

int main()
{
    int vetor_1[T], vetor_2[T];

    carregar_vetor(vetor_1);
    mostrar_vetor(vetor_1, "Original\0");
    copy_vetor(vetor_1, vetor_2);
    mostrar_vetor(vetor_2, "Copia\0");

    return 0;
}

void copy_vetor(int original[T], int copia[T])
{
    for (int i = 0; i < T; i++){
        copia[i] = original[i];
    }
}

void carregar_vetor(int vetor[T])
{
    srand(time(NULL));

    for(int i = 0; i < T; i ++){
        vetor[i] = rand() % 100;
    }
}

void mostrar_vetor(int vetor[T], String msg)
{
    printf("\n%s\n", msg);
    printf("[");
    for (int i = 0; i < T; i++){
        printf("%i", vetor[i]);
    }
    printf("]\n");
}

/*
    Crie um programa que tenha uma função que copiei os valores de um vetor para outro
    Crie um vetor aleatorio e copiei para outro
    Nao esqueca de mostrar os vetores ao fim do programa
*/

