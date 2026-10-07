#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    struct point *next;
};

void print_data_points(struct point *p);
struct point *new_point(int x, int y);
struct point *last(struct point *list);
void add_point(struct point *list, struct point *new);
void add_item(struct point *list);
struct point *create_list();

int main()
{
    struct point *list = create_list();

    // adicionando mais um
    add_item(list);
    add_item(list);

    print_data_points(list);
    return 0;
}

void print_data_points(struct point *p)
{
    while(p){ // p só não é valido quando aponta para null
        printf("Valor de X..: %i\n", p->x);
        printf("Valor de Y..: %i\n", p->y);
        printf("Endereço....: %p\n\n", p);
        p = p->next;
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

struct point *last(struct point *list)
{
    while (list->next){
        list = list->next;
    }
    return list;
}

void add_point(struct point *list, struct point *new)
{
    struct point *last_point = last(list);
    last_point ->next = new;
}

void add_item(struct point *list)
{
    struct point *new = NULL;
    int x, y;

    printf("X do ponto...: ");
    scanf("%i", &x);
    printf("Y do ponto...: ");
    scanf("%i", &y);

    // adicionando mais um
    new = new_point(x, y);
    add_point(list, new);
}

struct point *create_list()
{
    struct point *list = NULL, *new = NULL;

    // criando a lista
    new = new_point(1, 2);
    list = new;

    return list;
}

/*void update_values(struct point* p)
{
    printf("X do novo ponto..: ");
    scanf("%i", &p->x);
    getchar();

    printf("Y do novo ponto..: ");
    scanf("%i", &p->y);
    getchar();
}*/
