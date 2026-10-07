#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar(int *v, int t);
void preencher(int *v, int t, int inicio);

int main()
{
    srand(time(NULL));
    int n, n2,*v = NULL;

    printf("Qual é o valor de 'n'? ");
    scanf("%i", &n);

    v = (int*)calloc(sizeof(int), n); 
    printf("E: %p\n", v);

    preencher(v, n, 0);
    mostrar(v, n);

    printf("Quanto quer adicionar? ");
    scanf("%i", &n2);

    v = (int*)realloc(*v, sizeof(int) * n2);
    
    preencher(v, n2, n - 1);
    mostrar(v, n);

    return 0;
}

void mostrar(int *v, int t)
{
    for(int i = 0; i < t; i ++){
        printf("%i ", *(v + i));
    }
    printf("\n");
}

void preencher(int *v, int t, int inicio)
{
    for(int i = inicio; i < t; i++){
        *(v + i) = rand() % 100;
    }
}

