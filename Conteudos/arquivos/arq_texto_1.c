/*
Programa para gerar n numeros inteiros
Os numeros serao gerados aleatoriamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    FILE *fp = NULL;
    int qtd_numeros, numero;

    if(argc < 3) {
        fprintf(stdout, "Erro: %s   qtd. números   nome do arquivo\n", argv[0]);
        exit(0);
    }

    srand(time(NULL));

    // quantos números
    qtd_numeros = atoi(argv[1]);
    fp = fopen(argv[2], "a");

    for(int i = 0; i <qtd_numeros; i++){
        numero = rand() % 10000;
        fprintf(fp, "%i\n", numero);
    }
    
    fclose(fp);

    return 0;
}
