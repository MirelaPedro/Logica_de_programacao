#include <stdio.h>
#include <stdlib.h>

#define FIM 0

struct point {
    int x;
    int y;
    struct point *next;
};

// menus
int menu_principal();

// pontos
void print_data_points(struct point *p);
struct point *new_point(int x, int y);
struct point *add_point(struct point *list, struct point *new);
struct point *add_item(struct point *list);
struct point *create_list();

int main()
{
    struct point *list = create_list();
    int op;

    do{
        op = menu_principal();

        switch (op){
            case 0: break;

            case 1:
                add_item(list);
            case 2:
                print_data_points(list);
        }
    } while(op != FIM);

    return 0;
}

// ............................ MENUs
int menu_principal()
{
    int op;

    do{
        printf("-----------------------------\n");
        printf("|       MENU PRINCIPAL      |\n");
        printf("-----------------------------\n\n");

        printf("1. Adicionar um ponto\n");
        printf("2. Mostrar lista\n");
        printf("0. Sair do Programa\n");
        printf(": ");
        scanf("%i", &op);
    } while (op < 0 || op > 2);

    return op;
}

void print_data_points(struct point *p)
{
    while(p){ // p só não é valido quando aponta para null
        printf("Valor de X..: %i\n", p->x);
        printf("Valor de Y..: %i\n", p->y);
        printf("Endereço....: %p\n\n", p);
        p = p->next; // desse jeito da errado
    }
}

struct point *new_point(int x, int y)
{
    struct point *new = (struct point*)calloc(sizeof(struct point), 1);

    new->x = x;
    new->y = y;
    new->next = NULL;

    return new;
}

struct point *add_point(struct point *list, struct point *new)
{
    new->next = list;
    return new;
}

struct point *add_item(struct point *list)
{
    struct point *new = NULL;
    int x, y;

    printf("X do ponto...: ");
    scanf("%i", &x);
    printf("Y do ponto...: ");
    scanf("%i", &y);

    // adicionando mais um
    new = new_point(x, y);
    list = add_point(list, new);
}

struct point *create_list()
{
    struct point *list = NULL, *new = NULL;
    // criando a lista
    list = add_item(list);
    return list;
}

