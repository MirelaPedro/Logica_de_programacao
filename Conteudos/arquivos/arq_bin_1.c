#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    int a, b;

    fp = fopen("dados.bin", "rb");
    
    fread(&a, sizeof(a), 1, fp);
    fread(&b, sizeof(b), 1, fp);

    fprintf(stdout, "a: %i\n", a);
    fprintf(stdout, "b: %i\n", b);

    fclose(fp);

    return 0;
}

