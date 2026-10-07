#include <stdio.h>

struct ponto{
    int x;
    int y;
};

void ler_coord(struct ponto *ptr);
void mostrar_coord(struct ponto p);

int main()
{
    struct ponto p;

    ler_coord(&p);
    mostrar_coord(p);

    return 0;
}

void ler_coord(struct ponto *ptr)
{
    printf("Digite a coordenada de X: ");
    scanf("%i", &ptr->x); 

    printf("Digite a coordenada de Y: ");
    scanf("%i", &ptr->y); 
}

void mostrar_coord(struct ponto p)
{
    printf("Coordenada X: %i\n", p.x);
    printf("Coordenada Y: %i\n", p.y);
}

