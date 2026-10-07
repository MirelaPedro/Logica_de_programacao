#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    int *vetor = NULL, tamanho, max;

    // ./v_din 100 1000
    if(argc < 3) {
        printf("Erro. Uso %s tamanho max_numero\n", argv[0]);
        exit(0);
    }

    tamanho = atoi(argv[1]); // alpha numerico to integer
    max_numero = atoi(argv[2]);

    return 0;
}
