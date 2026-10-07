#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas {
    int x;
    int y;
} coord_t;

int menu();
coord_t nova_coordenada();
void listar_coordenadas(coord_t *coordenadas, int qtd_coordenadas);


int main()
{
    coord_t *coordenadas = NULL;
    int qtd_coordenadas = 0, opc;

    coordenadas = (*coord_t)calloc(sizeof(coord_t), 10);
    do{
        opc = menu();

        switch(opc)
        {
            case 1:
                *(coordenadas + qtd_coordenadas) = nova_coordenada();
                qtd_coordenadas += 1;

                break;
            case 2: 
                listar_coordenadas(coordenadas, qtd_coordenadas);

                break;
        }
    } while (opc != 0);

    return 0;
}

int menu()
{
    int opc;

    printf("1.Cadastrar nova coordenada; \n");
    printf("2.Listar coordenadas; \n");
    printf("0.Sair do programa; \n");
    scanf("%i", &opc);

    return opc;
}

coord_t nova_coordenada()
{
    coord_t coordenada;

    printf("Valor de X: ");
    scanf("%i", &coordenada.x);
    printf("Valor de y: ");
    scanf("%i", &coordenada.y);

    return coordenada;
}

void listar_coordenadas(coord_t *coordenadas, int qtd_coordenadas)
{
    for (int i = 0; i < qtd_coordenadas; i++){
        printf("Coordenada %i\n", i);
        printf("X: %i\n", (coordenadas + 1)->x);
        printf("Y: %i\n", (coordenadas + 1)->y);
        printf("\n");
    }
}

