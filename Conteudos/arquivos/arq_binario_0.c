#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    int a = 10, b = 20;

    // Abrir arquivo modo leitura
    fp = fopen("dados.bin", "wb"); // o .bin é apenas para diferenciar // o b define o arquivo binario
    
    fwrite(&a, sizeof(a), 1, fp); // endereco da variavel que tem o dado, quantos bytes tem em a, quantas unidades da variavel eu vou escrever, endereco do arquivo
    fwrite(&b, sizeof(b), 1, fp);

    fclose(fp);

    return 0;
}

/*

*/
