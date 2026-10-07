#include <stdio.h>

int main()
{
    int valor = 1, x = 2, y = 3, *p = &y;

    *p = 100; // muda o valor no endereço no qual ele aponta

    printf("Endereço de valor......: %p\n", &valor);
    printf("Endereço de x..........: %p\n", &x);
    printf("Endereço de y..........: %p\n", &y);
    printf("Endereço de p..........: %p\n\n", &p);
    printf("Conteúdo de valor......: %i\n", valor);
    printf("Conteúdo de x..........: %i\n", x);
    printf("Conteúdo de y..........: %i\n", y);
    printf("Conteúdo de p..........: %p\n", p);

    return 0;
}