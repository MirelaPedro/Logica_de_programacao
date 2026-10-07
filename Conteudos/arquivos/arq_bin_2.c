#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int copia[10], k = 0;
    FILE *fp = NULL;

    fp = fopen("morango.id", "wb");

    if(!fp){
        fprintf(stdout, "Error: file doesn't open\n");
        exit(0);
    }

    for(int i = 0; i < (sizeof(vetor)/sizeof(int)); i++){
        fwrite((vetor + i), sizeof(int), 1, fp);
    }

    //fwrite(vetor, sizeof(int), sizeof(vetor)/sizeof(int), fp);

    fclose(fp);

    fp = fopen("morango.id", "rb");

    while(!feof(fp)){ // o feof procura o  fim do arquivo, retornando 0 para não fim dee arquivvo e 1 para fim de arquivoo
        fread((copia + k), sizeof(int), 1, fp);
        k++;
    }

    fclose(fp);

    for(int k = 0; k < sizeof(copia)/sizeof(int); k++){
        fprintf(stdout, "%i \t", *(copia + k));
    }
    fprintf(stdout, "\n");

    return 0;
}

