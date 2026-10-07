#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VETOR_TAMANHO 100

struct number_v{
    int num;
    struct number_v *prox;
};

int gerar_aleatorio(int inicio, int fim, char tipo);
void preencher_vetor(int inicio, int fim, int *vetor, char tipo);
void mostrar_vetor(int *vetor);
void mostrar_lista(struct number_v *lista);
void intercalar_vetores(int *vetor_par, int *vetor_impar, struct number_v *vetor_final);
int menu();
void preenchendo_vetor(int *par, int *impar);
void mostrando_vetores(int *par, int *impar, struct number_v* vetor_final);
struct number_v* adicionar_elemento(int *valor);

int main()
{
    srand(time(NULL));
    int pares[VETOR_TAMANHO];
    int impares[VETOR_TAMANHO];
    struct number_v *vetor_final = NULL;
    int op;

    do{
        op = menu();

        switch(op){
            case 0: break;

            // Preencher um vetor
            case 1:
                preenchendo_vetor(pares, impares);
                break;

            // Mostrar um vetor
            case 2:
                mostrando_vetores(pares, impares, vetor_final);
                break;

            // Intercalar os vetores
            case 3:
                intercalar_vetores(pares, impares, vetor_final);
                break;
        }
    } while( op != 0);


    return 0;
}

int gerar_aleatorio(int inicio, int fim, char tipo)
{
    int num, resto;

    if(tipo == 'p'){
        resto = 0;
    } else {
        resto = 1;
    }

    do{
        num = (rand() % fim) + inicio;
    } while (num % 2 != resto);    

    return num;
}

void preencher_vetor(int inicio, int fim, int *vetor, char tipo)
{
    for (int i = 0; i < VETOR_TAMANHO; i++){
        *(vetor + i) = gerar_aleatorio(inicio, fim, tipo);
    }
}

void mostrar_vetor(int *vetor)
{
    printf("|   VETOR   |\n");

    for(int i = 0; i < VETOR_TAMANHO; i++){
        printf("%i \t", *(vetor + i));
    }
    printf("\n");
}

void mostrar_lista(struct number_v *lista)
{
    printf("|   LISTA   |\n");

    while (lista != NULL){
        printf("%i\t", lista->num);
        lista = lista->prox;
    }
    printf("\n");
}

void intercalar_vetores(int *vetor_par, int *vetor_impar, struct number_v *vetor_final)
{
    vetor_final = calloc(sizeof(int), 1);

    for(int i = 0; i < (VETOR_TAMANHO * 2); i++){
        if(i % 2 == 0){
            vetor_final = adicionar_elemento(vetor_par + (i/2));
        } else{
            vetor_final = adicionar_elemento(vetor_impar + (i/2));
        }
    }
}

int menu()
{
    int op;
    
    do {
        printf("---------------------\n");
        printf("|       MENU        |\n");
        printf("---------------------\n\n");

        printf("1. Preencher um vetor\n");
        printf("2. Mostrar um vetor\n");
        printf("3. Intercalar vetores\n");
        printf("0. Sair do programa\n");
        printf(": ");
        scanf("%i", &op);
    } while(op < 0 || op > 3);
    
    return op;
}

void preenchendo_vetor(int *par, int *impar)
{
    int op, inicio, fim;
    printf("-------------------------\n");
    printf("|   PREENCHER VETOR     |\n");
    printf("-------------------------\n\n");

    do {
        printf("ESCOLHA UM VETOR PARA PREENCHER\n");
        printf("1. Par\n");
        printf("2. Ímpar\n");
        scanf("%i", &op);
    } while(op < 0 || op > 2);

    printf("\n");

    do {
        printf("ESCOLHA O INTERVALO DE PREENCHIMENTO\n");
        printf("Início: ");
        scanf("%i", &inicio);
        printf("Fim: ");
        scanf("%i", &fim);
    } while(inicio == fim);

    if(op == 1){
        preencher_vetor(inicio, fim, par, 'p');
    } else{
        preencher_vetor(inicio, fim, impar, 'i');
    }
}

void mostrando_vetores(int *par, int *impar, struct number_v* vetor_final)
{
    int op;
    printf("---------------------\n");
    printf("|   MOSTRAR VETOR   |\n");
    printf("---------------------\n\n");

    do{
        printf("1. Vetor par; \n");
        printf("2. Vetor ímpar; \n");
        printf("3. Vetor final; \n");
        scanf("%i", &op);
    } while( op < 1 || op > 3);
    
    switch(op)
    {
        case 1:
            mostrar_vetor(par);
            break;
        case 2:
            mostrar_vetor(impar);
            break;
        case 3:
            mostrar_lista(vetor_final);
    }

}

struct number_v* adicionar_elemento(int *valor)
{
    struct number_v *vetor = (struct number_v*)calloc(sizeof(struct number_v), 1);

    vetor->num = *(valor);
    vetor->prox = NULL;

    return vetor;
}
