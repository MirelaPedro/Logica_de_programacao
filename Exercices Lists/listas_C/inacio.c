#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define T_CIDADES 50
#define T_ROTAS 30
#define T_STRING 100
#define FIM 0
#define CONTINUE -1

// ------------------------------------- HEADER
typedef char String[T_STRING];

typedef struct cidade{
    int id;
    String nome;
    String local_rodoviaria;
} Cidade;

typedef struct rota{
    int id;
    int origem;
    int destino;
    float distancia;
} Rota;

//Variaveis Globais
Cidade cidades[T_CIDADES];
Rota rotas[T_ROTAS];
int qtd_rotas = 0, qtd_cidades = 0;

// FUNCOES AUXILIARES - PROTOTIPO
// menus
int menu_principal();
int menu_cidades();
int menu_rotas();
// funcoes

// cadastro
Cidade nova_cidade();
Rota nova_rota();

// listar
void listar_cidades();
void listar_rotas();
void mostrar_dados_rota(Rota rota);
void mostrar_dados_cidade(Cidade cidade);
void cidades_cadastradas();

// Pesquisar / Localizar
void localizar_rotas_por_cidade(String nome_cidade, int op);
int localizar_cidade(String nome_cidade);
int localizar_indice_cidade(int id);
void mostrar_rota_mais_curta();
void mostrar_rota_mais_longa();

// formatacao
void retirar_enter(String str);
void formatar_maiuscula(String str);
void mostrar_msg(char* msg);
void limpar_tela();
void exportar_script_py(String nome_script);

// alterar
void alterar_dado(char *pont);

// ------------------------------------- MAIN
int main()
{
    int option, retorno;
    String nome_cidade;

    do {
        limpar_tela();

        option = menu_principal();

        switch (option)
        {
            // CIDADES
            case 1:
                do {
                    limpar_tela();
                    option = menu_cidades();

                    switch(option)
                    {
                        case 1: 
                            cidades[qtd_cidades] = nova_cidade();
                            mostrar_dados_cidade(cidades[qtd_cidades]); // mostrando a nova cidade cadastrada para o usuário
                            qtd_cidades += 1; // atualizando a quantidade de cidades no sistema
                            break;
                        
                        case 2: 
                            listar_cidades();
                            mostrar_msg("PRESSIONE ENTER PARA VOLTAR AO MENU PRINCIPAL");
                            break;

                    }

                } while (option != FIM);

                option = CONTINUE; // Para não sair do programa, apenas do menu atual (-1)
                break;

            // ROTAS
            case 2:
                do {
                    limpar_tela();
                    option = menu_rotas();

                    switch(option)
                    {
                        case 1: 
                            if(qtd_cidades == 0){
                                printf("AÇÃO INVÁLIDA\n");
                                printf("Não há cidades cadastradas para a criação de uma rota!\n");
                                break;
                            }

                            printf("Utilize o id da cidade na origem e destino\n");
                            rotas[qtd_rotas] = nova_rota();
                            mostrar_dados_rota(rotas[qtd_rotas]);
                            qtd_rotas += 1;
                            break;

                        case 2: 
                            listar_rotas();
                            break;
                        case 3:
                            printf("Nome da cidade a ser pesquisada: ");
                            fgets(nome_cidade, T_STRING, stdin);
                            retirar_enter(nome_cidade);
                            formatar_maiuscula(nome_cidade);

                            printf("Tipo de Consulta: \n");
                            printf("1. Por origem; \n");
                            printf("2. Por destino; \n");
                            printf("3. Por origem e origem; \n");
                            printf(": ");
                            scanf("%i", &retorno);

                            localizar_rotas_por_cidade(nome_cidade, retorno);

                            break;
                        
                        case 4:
                            mostrar_rota_mais_curta();
                            break;
                        case 5:
                            mostrar_rota_mais_longa();
                            break;
                    }

                } while (option != FIM);

                option = CONTINUE; // Para não sair do programa, apenas do menu atual
                break;
        }
    } while(option != FIM);

    return 0;
}

// ------------------------------------- FUNÇÕES
//FUNCOES AUXILIARES - IMPLEMENTACAO

// MENUS
int menu_principal()
{
    int option;

    printf("\n      | VIAÇÃO CIDADE S/A |\n\n");
    printf("1.Cidades\n");
    printf("2.Rotas\n");
    printf("0.Sair\n");
    printf("::: ");
    scanf("%i", &option);
    getchar();

    return option;
}

int menu_cidades()
{
    int option;

    printf("------------------------------\n");
    printf("\n      | MENU CIDADES |\n");
    printf("1.Cadastrar cidade\n");
    printf("2.Mostrar cidades\n");
    printf("3.Localizar cidade\n");
    printf("0.Voltar\n");
    printf("::: ");
    scanf("%i", &option);
    getchar();


    printf("------------------------------\n\n");

    return option;
}

int menu_rotas()
{
    int option;

    printf("------------------------------\n");
    printf("\n      | MENU ROTAS |\n");
    printf("1.Cadastrar rota\n");
    printf("2.Mostrar rotas\n");
    printf("3.Localizar rotas por cidade\n");
    printf("4.Mostrar rota mais curta\n");
    printf("5.Mostrar rota mais longa\n");
    printf("0.Voltar\n");
    printf("::: ");
    scanf("%i", &option);
    getchar();


    printf("------------------------------\n\n");

    return option;
}

// ENTRADA DE DADOS / CADASTROS

Cidade nova_cidade()
{
    printf("        CIDADE\n");
    Cidade city;

    city.id = qtd_cidades + 1;

    // Nome da Cidade
    printf("Cidade %i\n", city.id);
    printf("Nome: ");
    fgets(city.nome, T_STRING, stdin);
    //tirar o enter do final da string

    // formatação do nome da cidade
    retirar_enter(city.nome);
    formatar_maiuscula(city.nome);

    // Local da Rodoviária
    printf("Local da Rodoviária: ");
    fgets(city.local_rodoviaria, T_STRING, stdin);
    retirar_enter(city.local_rodoviaria);
    formatar_maiuscula(city.local_rodoviaria);

    return city;
}

Rota nova_rota()
{
    printf("        ROTA\n");
    Rota rota;
    
    rota.id = qtd_rotas + 1;

    printf("Rota %i\n", rota.id);

    cidades_cadastradas();
    printf("-------- ");

    printf("Origem: ");
    scanf("%i", &rota.origem);
    getchar();

    cidades_cadastradas();
    printf("-------- ");

    printf("Destino: ");
    scanf("%i", &rota.destino);
    getchar();

    cidades_cadastradas();
    printf("-------- ");

    printf("Distância(Km): ");
    scanf("%f", &rota.distancia);
    getchar();

    return rota;
}

// PRINTS / READ / MOSTRAR
void listar_cidades()
{
    limpar_tela();
    printf("------------------------------\n");
    mostrar_msg("RELATÓRIO DAS CIDADES");
    // Caso não haja nada cadastrados
    if(qtd_cidades == 0) printf("NÃO HÁ CIDADES CADASTRADAS \n");

    for (int i = 0; i < qtd_cidades; i++){
        mostrar_dados_cidade(cidades[i]);
    }
}

void listar_rotas()
{
    limpar_tela();
    printf("------------------------------\n");
    mostrar_msg("RELATÓRIO DAS ROTAS");
    // Caso não haja nada cadastrados
    if(qtd_rotas == 0) printf("NÃO HÁ ROTAS CADASTRADAS \n");
    for(int i = 0; i < qtd_rotas; i++){
        mostrar_dados_rota(rotas[i]);
    }
}

void mostrar_dados_rota(Rota rota)
{
    printf("\n---------- ROTA\n");
    printf("Id: %i\n", rota.id);
    printf("Origem: [%i] - %s\n", rota.origem, cidades[rota.origem - 1].nome);
    printf("Destino: [%i] - %s\n", rota.destino, cidades[rota.destino - 1].nome);
    printf("Distância: %.2f Km\n", rota.distancia);
}

void mostrar_dados_cidade(Cidade cidade)
{
    printf("\n---------- CIDADE\n");
    printf("Id: %i\n", cidade.id);
    printf("Nome: %s\n", cidade.nome);
    printf("Local da Rodoviária: %s\n", cidade.local_rodoviaria);
}

void cidades_cadastradas()
{
    printf("----- CIDADES CADASTRADAS \n");
    for (int i = 0; i < qtd_cidades; i++){
        printf("[%i] -----> %s\n", cidades[i].id, cidades[i].nome);
    }
}

// LOCALIZAR
void localizar_rotas_por_cidade(String nome_cidade, int op)
{
    /*
    op = 1 -> listar por origem
    op = 2 -> listar por destino
    op = 3 -> listar por ambos
    */

    int id_cidade;

    id_cidade = localizar_cidade(nome_cidade);
    if(id_cidade == 0) {
        printf("Cidade %s não encontrada\n", nome_cidade);
        return;
    }

    switch(op) {
        case 1: for(int i = 0; i < qtd_rotas; i ++){
            if(rotas[i].origem == id_cidade) mostrar_dados_rota(rotas[i]);
        }
        break;

        case 2: for(int i = 0; i < qtd_rotas; i ++){
            if(rotas[i].destino == id_cidade) mostrar_dados_rota(rotas[i]);
        }
        break;

        case 3: for(int i = 0; i < qtd_rotas; i ++){
            if(rotas[i].origem == id_cidade || rotas[i].destino == id_cidade) mostrar_dados_rota(rotas[i]);
        }
        break;
    }
}

int localizar_cidade(String nome_cidade)
{
    for(int i = 0; i < qtd_cidades; i++){
        if (!strcmp(nome_cidade, cidades[i].nome)) return cidades[i].id;
    }
    return 0;
}

void mostrar_rota_mais_curta()
{
    float distancia = rotas[0].distancia;
    int idx = 0;

    for(int i = 0; i < qtd_rotas; i++){
        if(distancia > rotas[i].distancia){
            distancia = rotas[i].distancia;
            idx = i;
        }
    }

    mostrar_dados_rota(rotas[idx]);
}

void mostrar_rota_mais_longa()
{
    float distancia = rotas[0].distancia;
    int idx = 0;

    for(int i = 0; i < qtd_rotas; i++){
        if(distancia < rotas[i].distancia){
            distancia = rotas[i].distancia;
            idx = i;
        }
    }

    mostrar_dados_rota(rotas[idx]);
}

// FORMATAÇÕES
void retirar_enter(String str)
{
    str[strlen(str)-1] = '\0';
}

// formata todas as letras para maiúscula
void formatar_maiuscula(String str)
{
    for(int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}

int localizar_indice_cidade(int id)
{
    for (int i = 0; i < qtd_cidades; i++){
        if(cidades[i].id == id) return i;
    }

    return -1;
}

void mostrar_msg(char* msg)
{
    printf("\n \033[035m%s\033[0m\n", msg);
    getchar();
}

void limpar_tela()
{
    system("clear");
}

void exportar_script_py(String nome_script)
{
    FILE *arquivo;

    arquivo = fopen(nome_script, "w+");

    // Script python
    fprintf(arquivo, "%s\n", "import pandas as pd\n");

    fprintf(arquivo, "%s\n", "dados{");
    for(int i = 0; i < qtd_rotas; i++){
        fprintf(arquivo, "%s\n", "  %i : \n");
    }
    fprintf(arquivo, "%s\n", "}\n");

    fclose(arquivo);
}

/*
QUANTIDADE DE PARADAS, QUAIS PARADAS

-> retirar espaços no início e no fim
-> não salvar quando a entrada estiver vazia(apenas o enter)
-> repetir até o usuario digitar um valor válido
*/
