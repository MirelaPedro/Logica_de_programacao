#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_STR 100

typedef char String[T_STR];

struct time_futebol{
    String nome;
    int ano_fundacao;
    float divida;
};

typedef struct time_futebol time_futebol_t;

struct times{
    time_futebol_t *v_times;
    int qtd_times;
};

int menu();
void retirar_enter(String str);
void cadastrar_novo_time(struct times *t);
void listar_times(struct times t);
void mostrar_time(time_futebol_t *time);

time_futebol_t* localizar_time_por_nome(struct times *t, String nome);
time_futebol_t* localizar_time_maior_divida(struct times *t);



int main()
{
    // inicializando os dados
    struct times dados_times;
    dados_times.v_times = NULL;
    dados_times.qtd_times = 0;
    int op;

    while(1){
        op = menu();

        if(op == 0) break;

        switch(op){
            case 1: 
                cadastrar_novo_time(&dados_times);
                break;
            case 2: 
                listar_times(dados_times);
                break;
        }
    }

    return 0;
}

int menu()
{
    int op;

    printf("\n-------------\n");
    printf("|   MENU    |");
    printf("\n-------------\n");
    printf("1. Cadastrar novo time\n");
    printf("2. Listar times cadastrados\n");
    printf("0. \n");
    printf(": ");

    scanf("%i", &op);
    getchar();

    return op;
}

void retirar_enter(String str)
{
    if(str[strlen(str) - 1] == '\n') str[strlen(str) - 1] == '\0'; 
}

void cadastrar_novo_time(struct times *t)
{
    // alocando e realocando o vetor
    if(t->qtd_times == 0) {t->v_times = (time_futebol_t*)calloc(sizeof(time_futebol_t), 1);}
    else{t->v_times = (time_futebol_t*)realloc(t->v_times, sizeof(time_futebol_t) * (t->qtd_times + 1));}

    printf("\n-----------------\n");
    printf("|   CADASTRO    |");
    printf("\n-----------------\n");

    // solicitando dados
    printf("Nome do time...............: ");
    fgets((t->v_times + t->qtd_times)->nome, T_STR, stdin);
    retirar_enter((t->v_times + t->qtd_times)->nome);
    printf("Ano de fundação do time....: ");
    scanf("%i", &((t->v_times + t->qtd_times)->ano_fundacao));
    printf("Valor da dívida do time....: ");
    scanf("%f", &((t->v_times + t->qtd_times)->divida));
    getchar();

    t->qtd_times++;
}

void listar_times(struct times t)
{
    printf("\n--------------\n");
    printf("|   TIMES    |");
    printf("\n--------------\n");

    for (int i = 0; i < t.qtd_times; i++){
        mostrar_time((t.v_times + i));
    }
}

void mostrar_time(time_futebol_t *time)
{
    printf("\nNome do time................: %s\n", time->nome);
    printf("Ano de fundação.............: %i\n", time->ano_fundacao);
    printf("Valor da dívida.............: %.2f\n", time->divida);
}

time_futebol_t* localizar_time_por_nome(struct times *t, String nome)
{
    for(int i = 0; i < t->qtd_times; i++){
        if(!strcmp(nome, *((t->v_times + i)->nome))) return(t->v_times + i);
    }
}

time_futebol_t* localizar_time_maior_divida(struct times *t)
{

}


// ////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////
// --------------------------------------------------------------------------------------------------------------------
// *************************************************************************************

