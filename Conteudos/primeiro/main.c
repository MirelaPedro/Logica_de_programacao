#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tipos.h"
#include "vetor.h"

int main()
{
    srand(time(NULL));

    struct ponto morango[10];

    preencher_vetor(morango, 10);
    mostrar_dados_vetor(morango, 10);

    return 0;
}