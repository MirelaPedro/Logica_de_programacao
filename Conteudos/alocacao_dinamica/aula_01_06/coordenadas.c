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
    coord_t *lista_coordenadas = NULL;
    int qtd_coordenadas = 0, opcao;

    do {
        opcao = menu();

        switch (opcao) {
            case 1: if (qtd_coordenadas == 0) {
                        lista_coordenadas = (coord_t*)calloc(sizeof(coord_t), 1);
                        *(lista_coordenadas+qtd_coordenadas) = nova_coordenada();
                        qtd_coordenadas++;
                    }
                    else {
                        lista_coordenadas = (coord_t*)realloc(lista_coordenadas, sizeof(coord_t) * qtd_coordenadas + 1); // sintaxe realloc(ponteiro, sizeof(tipo) * qtd_anterior + 1)
                        *(lista_coordenadas+qtd_coordenadas) = nova_coordenada(); // adicionando o valor no novo espaço
                        qtd_coordenadas++;
                    }
                    break;
            case 2: listar_coordenadas(lista_coordenadas, qtd_coordenadas);
                    break;
        }

    } while (opcao != 0);

    return 0;
}

int menu()
{
    int opc;

    printf("1.Incluir nova coordenada\n");
    printf("2.Listar coordenadas\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%i", &opc);

    return opc;
}

coord_t nova_coordenada()
{
    coord_t coordenada;

    printf("Qual o valor de x? ");
    scanf("%i", &coordenada.x);
    printf("Qual o valor de y? ");
    scanf("%i", &coordenada.y);

    return coordenada;
}

void listar_coordenadas(coord_t *coordenadas, int qtd_coordenadas)
{
    for (int i = 0; i < qtd_coordenadas; i++) {
        printf("Valor de x: %i\n", coordenadas[i].x);
        printf("Valor de y: %i\n\n", coordenadas[i].y);
    }

}
