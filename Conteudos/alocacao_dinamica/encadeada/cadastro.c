#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FIM 0
#define CONTINUE -1
#define T_STRING 100

typedef char string[T_STRING];

typedef struct dados_pais{
    string nome;
    string continente;
    int titulos;
    float valor;
    struct dados_pais *next;
} dados_pais_t;


// ------------------------ PROTÓTIPO DAS FUNCOES
// menus
int menu_principal();

// pontos
void listar_selecoes(dados_pais_t *lista);
void mostrar_selecao(dados_pais_t *selecao);
dados_pais_t *nova_selecao();
dados_pais_t *pesquisar_selecao_por_nome(dados_pais_t *lista, string nome);

// formatacao
void retirar_enter(string str);
void formatar_string(string str);
void mostrar_aviso(char* aviso);
void deletar_selecao(dados_pais_t *selecao, dados_pais_t *lista);
// purpurina
void limpar_tela();
void pular_linha();

int main()
{
    dados_pais_t *lista_selecoes = NULL, *pais;
    int op;

    do{
        op = menu_principal();

        switch (op){
            case 0: break;
            // CADASTRO
            case 1:
                printf("-------------------------------\n");
                printf("|     CADASTRO DE SELEÇÃO     |\n");
                printf("-------------------------------\n\n");

                pais = nova_selecao(lista_selecoes);
                pais->next = lista_selecoes;
                lista_selecoes = pais;

                limpar_tela();
                break;

            // LISTAGEM
            case 2:
                printf("-------------------------------\n");
                printf("|     LISTAGEM DE SELEÇÕES    |\n");
                printf("-------------------------------\n\n");
                listar_selecoes(lista_selecoes);
                mostrar_aviso("pressione enter para continuar ");

                break;

            // PESQUISA
            case 3:
                printf("-------------------------------\n");
                printf("|     PESQUISA DE SELEÇÃO     |\n");
                printf("-------------------------------\n\n");
                string nome;
                printf("Nome da seleção: ");
                fgets(nome, T_STRING, stdin);
                retirar_enter(nome);
                formatar_string(nome);

                pais = pesquisar_selecao_por_nome(lista_selecoes, nome);
                mostrar_selecao(pais);
                mostrar_aviso("pressione enter para continuar ");
                limpar_tela();
                break;
            
            // DELETE
            case 4: 
                break;
        }
    } while(op != FIM);

    return 0;    
}

// ---------------------------- IMPLEMENTACAO DAS FUNCOES
// .................... MENUs
int menu_principal()
{
    int op;

    do{
        printf("-----------------------------\n");
        printf("|       MENU PRINCIPAL      |\n");
        printf("-----------------------------\n\n");

        printf("1. Cadastrar Seleção\n");
        printf("2. Mostrar Seleções\n");
        printf("3. Pesquisar Seleção por nome\n");
        printf("4. Excluir País\n");
        printf("0. Sair do Programa\n");
        printf(": ");
        scanf("%i", &op);
        getchar();

        if(op < 0 || op > 4) mostrar_aviso("OPÇÃO INVÁLIDA!");
        pular_linha();
    } while (op < 0 || op > 4);

    limpar_tela();
    return op;
}

// .................... LISTAGEM
void listar_selecoes(dados_pais_t *lista)
{
    printf("|   SELEÇÕES    |\n\n");
    for(lista; lista != NULL; lista = lista->next){ // de onde parte, qual é o fim, qual é a mudança de um para o outro
        mostrar_selecao(lista);
    }
}

void mostrar_selecao(dados_pais_t *selecao)
{
    printf("Nome.........: %s\n", selecao->nome);
    printf("Continente...: %s\n", selecao->continente);
    printf("Títulos......: %i\n", selecao->titulos);
    printf("Valor........: %.2f\n\n", selecao->valor);
}

// .................... CADASTRO
dados_pais_t *nova_selecao()
{
    dados_pais_t *pais = (dados_pais_t*)calloc(sizeof(dados_pais_t), 1);

    if(pais == NULL){
        printf("Não há espaço na memória para uma nova seleção, favor excluir uma e tentar novamente!\n\n");
        getchar();
    } else{
        // strings
        printf("Nome.........: ");
        fgets(pais->nome, T_STRING, stdin);
        retirar_enter(pais->nome);
        formatar_string(pais->nome);
        printf("Continente...: ");
        fgets(pais->continente, T_STRING, stdin);
        retirar_enter(pais->continente);
        formatar_string(pais->continente);
        
        // primitivos
        printf("Títulos......: ");
        scanf("%i", &pais->titulos);
        getchar();
        printf("Valor........: ");
        scanf("%f", &pais->valor);
        getchar();
        pais->next = NULL;
    }

    return pais;
}

// PESQUISA
dados_pais_t *pesquisar_selecao_por_nome(dados_pais_t *lista, string nome)
{
    while(lista != NULL){
        if(!strcmp(nome, lista->nome)) return lista;
        lista = lista->next;
    }
    return NULL;
}

// DELETAR
void deletar_selecao(dados_pais_t *selecao, dados_pais_t *lista)
{
    for(lista; lista != NULL; lista = lista->next){
        if(lista->next == selecao) lista->next = lista->next->next;
        free(selecao);
    }
}

// ----- FORMATACOES
void retirar_enter(string str)
{
    int tamanho = strlen(str);
    if(*(str + tamanho - 1) == '\n') *(str + tamanho - 1) = '\0' ;
}

void formatar_string(string str)
{
    for(str; *(str) != '\0'; str +=1){
        *(str) = toupper(*(str));
    }
}

void mostrar_aviso(char* aviso) { 
    printf("\n\033[035m%s\033[0m", aviso);
    getchar();
    limpar_tela();
}

// purpurina
void limpar_tela() { system("clear");}
void pular_linha() { printf("\n"); }

// o mais importante de um tipo/ variavel é o tamanho dela, o quanto vai ocupar na memoria

// naop esta retirando o enter

