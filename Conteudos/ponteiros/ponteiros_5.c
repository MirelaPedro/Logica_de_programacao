#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carregar_vetor(int *v);
void mostrar_vetor(int *v);

int main()
{
    int numeros[10];
    srand(time(NULL));

    carregar_vetor(numeros);
    mostrar_vetor(numeros);

    return 0;
}

void carregar_vetor(int *v)
{
    for(int i = 0; i < 10; i++){
        v[i] = rand() % 100;
    }
}

void mostrar_vetor(int *v)
{
    for (int i = 0; i < 10; i++){
        printf("v[%i]: %i\n", i, *(v+i));
    }
}
