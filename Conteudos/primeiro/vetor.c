#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>

void mostrar_dados_vetor(struct ponto *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++){
        fprintf(stdout, "Ponto (%i) - [%i - %i]\n", i, (p + i)->x, (p + i)->y);
    }
}

void preencher_vetor(struct ponto *p, int tamanho)
{
    for(int i = 0; i < tamanho; i++){
        (p + i)->x = rand() % 100;
        (p + i)->y = rand() % 100;
    }

}
