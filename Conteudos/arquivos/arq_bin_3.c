#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int copia[10], k = 0;
    FILE *fp = NULL;

    fp = fopen("morango.idiota", "wb");

    if(!fp){
        fprintf(stdout, "Error: file doesn't open\n");
        exit(0);
    }

    fwrite(vetor, sizeof(int), sizeof(vetor)/sizeof(int), fp);

    fclose(fp);

    fp = fopen("morango.idiota", "rb");

    fread(copia, sizeof(int), sizeof(vetor)/sizeof(int), fp);

    fclose(fp);

    for(int k = 0; k < sizeof(copia)/sizeof(int); k++){
        fprintf(stdout, "%i \t", *(copia + k));
    }
    fprintf(stdout, "\n");

    return 0;
}

