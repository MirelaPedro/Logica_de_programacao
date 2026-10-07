/*
Este programa irá ler os dados de um arquivo que será passado como argumento na abertura do programa

Programa para ler números de um arquivo texto e armazená-los em um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int qtd_numeros = 0, numero, *v_numeros, i = 0;

    // verificando se passou todos os paramentros
    if(argc != 2){
        fprintf(stdout, "Error: %s  nome_do_arquivo\n", argv[0]);
        exit(0);
    }

    FILE *fp = fopen(*(argv + 1), "r");

    // verificando se o arquivo existe
    if(fp == NULL){
        fprintf(stdout, "Arquivo inexistente!\n");
        exit(0);
    }

    // encontrando a quantidade de numeros
    while (!feof(fp)) {
        fscanf(fp, "%*i");
        qtd_numeros++;
    }

    // alocacao dinamica
    v_numeros = (int*)malloc(sizeof(int) * qtd_numeros);

    // rebobinar o ponteiro
    rewind(fp); // existe a função fsic -> so que precisa da posicao inicial

    while(!feof(fp)) {
        fscanf(fp, "%i", (v_numeros + i));
        i++;
    }

    /*
    for(fp; !feof(op);){
        fscanf(fp, "%i", (v_numeros + i));
        i++;
    }
    */

    fclose(fp);

    for(int k = 0; k < qtd_numeros; k++){
        fprintf(stdout, "%i\n", *(v_numeros + k));
    }

    free(v_numeros);

    return 0;
}