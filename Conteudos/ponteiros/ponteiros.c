#include <stdio.h>

struct ponto {
    int x;
    int y;
};

int main()
{
    struct ponto d1, *ptr_d;

    d1.x = 3;
    d1.y = 7;

    ptr_d = &d1;

    printf("Endereço de d1..........: %p\n", &d1);
    printf("Valor de x de d1........: %i\n", d1.x);
    printf("Valor de y de d1........: %i\n\n", d1.y);

    printf("Endereço de ptr.........: %p\n", &ptr_d);
    printf("Valor de x (d1) (ptr)...: %i\n", ptr_d->x);
    printf("Valor de y (d1) (ptr)...: %i\n\n", ptr_d->y);

    return 0;
}
