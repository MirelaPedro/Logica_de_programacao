#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' ,'z'};

int num_aleatorio(int inicio, int fim);
void preencher_vetor(char *l, int t);
void mostrar_vetor(char *l, int t);

int main()
{
    srand(time(NULL));

    int tamanho = num_aleatorio(5, 20);
    char *v_letras = NULL; // fechando com NULL para não deixar aberto

    // alocação dinâmica do v_letras
    //v_letras = (char*)malloc(sizeof(char)* tamanho);
    v_letras = (char*)calloc(sizeof(char), tamanho);

    mostrar_vetor(v_letras, tamanho);
    preencher_vetor(v_letras, tamanho);
    mostrar_vetor(v_letras, tamanho);

    

    return 0;
}

int num_aleatorio(int inicio, int fim)
{
    return inicio + rand() % fim;
}

void preencher_vetor(char *l, int t)
{
    for(int i = 0; i < t; i++){
        *(l + i) = letras[num_aleatorio(0, 26)];
    }
}

void mostrar_vetor(char *l, int t)
{
    for(int i = 0; i < t; i++){
        printf("%c ", *(l + i));
    }

    printf("\n");
}

