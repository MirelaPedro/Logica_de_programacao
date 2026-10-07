#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_STRING 100

typedef char string [T_STRING];

typedef struct raca_cao {
    string nome;
    float peso_medio;
    int longevidade;
    struct raca_cao *prox;
} raca_t;

int menu();
raca_t *nova_raca();
void listar_racas(raca_t *lista);
void inserir_raca_inicio(raca_t **lista, raca_t *novo);
void inserir_raca_fim(raca_t **lista, raca_t *novo);
void exportar_binario(raca_t *lista, char* nome_arq);
void exportar_html(raca_t *lista, char* nome_arq);
void exportar_csv(raca_t *lista, char* nome_arq);
void mostrar_dados_raca(raca_t *r);
void ler_dados_arq_bin(raca_t **lista, char *nome_arq);
void retirar_enter(char *str);

int main()
{
    raca_t *lista = NULL, *novo = NULL;
    int op;

    do{
        op = menu();

        switch(op)
        {
            case 0: break;
            case 1:
                printf("Cadastrar\n");
                novo = nova_raca();
                inserir_raca_inicio(&lista, novo);
                break;
            case 2:
                printf("Listar\n");
                listar_racas(lista);
                break;
            case 3:
                printf("Salvando dados\n");
                exportar_binario(lista, "base_dados.bin");
                break;
            case 4:
                printf("Exportando CSV\n");
                exportar_csv(lista, "base_dados.csv");
                break;
            case 5:
                printf("Exportando HTML\n");
                exportar_html(lista, "base_dados.html");
                break;
            case 6:
                printf("Importando dados binrios\n");
                ler_dados_arq_bin(&lista, "base_dados.bin");
                break;
        }
    } while (op != 0);
    
    return 0;
}

int menu()
{
    int op;

    do{
        printf("1. Cadastrar nova raça\n");
        printf("2. Listar raças cadastradas\n");
        printf("3. Salvar dados (arq.bin)\n");
        printf("4. Exportar .csv\n");
        printf("5. Exportar .html\n");
        printf("6. Importar arquivo binário\n");
        printf("0. Sair\n");
        printf("::: ");
        scanf("%i", &op);
    } while(op < 0 || op > 6);

    return op;
}

raca_t *nova_raca()
{
    raca_t *novo = NULL;

    novo = (raca_t*)malloc(sizeof(raca_t));

    novo->prox = NULL;

    printf("Nome da raça........: ");
    fgets(novo->nome, T_STRING, stdin);
    retirar_enter(novo->nome);
    printf("Peso médio..........: ");
    fscanf(stdin, "%f", &novo->peso_medio);
    printf("Longevidade.........: ");
    fscanf(stdin, "%i", &novo->longevidade);

    return novo;
}

void listar_racas(raca_t *lista)
{
    while (lista){
        mostrar_dados_raca(lista);
        lista = lista->prox;
    }
}

void inserir_raca_inicio(raca_t **lista, raca_t *novo)
{
    novo->prox = *lista;
    *lista = novo;
}

void inserir_raca_fim(raca_t **lista, raca_t *novo)
{

}

void exportar_binario(raca_t *lista, char* nome_arq)
{
    FILE *fp = NULL;
    fp = fopen(nome_arq, "wb");

    while(lista){
        fwrite(lista, sizeof(raca_t), 1, fp);
        lista = lista->prox;
    }

    fclose(fp);
}

void exportar_html(raca_t *lista, char* nome_arq)
{
    FILE *fp = NULL;
    fp = fopen(nome_arq, "w");

    fprintf(fp, "<html><body>\n");
    fprintf(fp, "<table><thead>\n");
    fprintf(fp, "<tr><th>Raca</th><th>Peso Medio</th><th>Longevidade</th></tr>\n");
    fprintf(fp, "</thead>\n");

    fprintf(fp, "<tbody>\n");
    while(lista){
        fprintf(fp, "<tr>\n");
        fprintf(fp, "<td>%s</td>", lista->nome);
        fprintf(fp, "<td>%.2f</td>", lista->peso_medio);
        fprintf(fp, "<td>%i</td>\n", lista->longevidade);
        fprintf(fp, "</tr>\n");
        lista = lista->prox;
    }
    fprintf(fp, "</tbody></table>\n");
    fprintf(fp, "</html></body>\n");

    fclose(fp);

}

void exportar_csv(raca_t *lista, char* nome_arq)
{
    FILE *fp = NULL;
    fp = fopen(nome_arq, "w");

    while(lista){
        fprintf(fp, "%s;", lista->nome);
        fprintf(fp, "%.2f;", lista->peso_medio);
        fprintf(fp, "%i;\n", lista->longevidade);
        lista = lista->prox;
    }

    fclose(fp);
}

void mostrar_dados_raca(raca_t *r)
{
    printf("Nome da raca...........: %s\n", r->nome);
    printf("Peso medio da raca.....: %.2f\n", r->peso_medio);
    printf("Longevidade da raca....: %i\n\n", r->longevidade);
}

void ler_dados_arq_bin(raca_t **lista, char *nome_arq)
{
    FILE *fp = NULL;
    raca_t *novo = NULL;
    fp = fopen(nome_arq, "rb");

    while(!feof(fp)){
        novo = (raca_t*)malloc(sizeof(raca_t));

        fread(novo, sizeof(raca_t), 1, fp);
        novo->prox = NULL;
        if(!feof(fp)){
            inserir_raca_inicio(lista, novo);
        } else {
            free(novo);
        }
        
    }

    fclose(fp);

}

void retirar_enter(char *str)
{
    if(*(str+strlen(str) -1) == '\n') *(str+strlen(str) -1) = '\0';
}
