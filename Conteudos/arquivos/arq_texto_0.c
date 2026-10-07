#include <stdio.h>

int main()
{
    FILE *fp = NULL; // o tipo FILE é uma struct. o ponteiro pro arquivo é chamado de descritor de arquivo

    fp = fopen("abacaxi.txt", "w"); // parametros -> nome, modo de abertura

    fprintf(fp, "To com fome!\n"); // escrevendo para um arquivo, passa qual arquivo e depois é igual ao printf

    fclose(fp); // fechando o arquivo

    return 0;
}

/*
Módulo de arbetura de arquivo do tipo texto:
r - somente leitura
w - escrita
rw - leitura e escrita
a - (append) adiciona dados a um arquivo existente
*/

