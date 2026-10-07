#include <stdio.h>
#include <string.h>

//Declarando constantes
#define T_STRING 100

//Declarando outros tipos de dados
typedef char String[T_STRING];

// structs
typedef struct date{
    int day;
    int month;
    int year;
} Date;

typedef struct user{
    int id;
    String user;
    String password;
    int CPF;
    Date birthday;
} User;

//Definindo variáveis globais
String adm_password, adm_user;
User users[100]; // qual é o número máximo de usuários que o sistema comporta?

//Prototipo das funcoes
int option_menu(void);
//CRUD
void creat(void);
void update(int verify);
void read(void);
void delete(int verify);
void search(int index);
// ADM
int autentication(void);
void define_adm(void);


//MAIN
int main()
{
    int option;
    do{
        option = option_menu();

        printf("Opção: %i\n", option);
    } while(option != 0);
    
    return 0;
}

//Implementacao das funcoes

int option_menu(void)
{
    int option;

    printf("\n-------- MENU ----------\n\n");
    printf("1.Criar novo usuário\n");
    printf("2.Trocar senha de usuário\n");
    printf("3.Deletar usuário\n");
    printf("4.Pesquisar usuário\n");
    printf("4.Visualizar informações de um usuário em específico\n");
    printf("5.Visualizar todos os usuários e suas respectivas informações\n");
    printf("6.Mostrar quantos usuários há cadastrados\n");
    printf("7.Mostrar aniversariantes do dia (pedir o dia/data)\n");
    printf("8.Alterar informações de usuário\n");
    printf("9.Reiniciar programa\n");
    printf("0.Fechar programa (os dados não serão salvos!)\n");
    printf(": ");
    scanf("%i", &option);

    return option;
}

//FUNCOES DO MENU
void update(int verify)
{

}

//FUNÇÕES DE ADMINISTRADOR
int autentication(void)
{
    String password;
    int verify = 0;

    printf("Senha do Administrador: ");
    fgets(password, T_STRING, stdin);

    return verify;
}
void define_adm(void)
{
    printf("\n--------- CONFIGURAÇÕES DE USUÁRIO DE ADMINISTRADOR ---------\n");
    printf("Usuário de Administrador: ");
    fgets(adm_user, T_STRING, stdin);

    printf("Senha de Administrador: ");
    fgets(adm_password, T_STRING, stdin);

    //Retirando o enter
    for(int i = 0; i < strlen(adm_user); i++){
        if(adm_user[i] == '\n') adm_user[i] = '\0';
    }

    for(int i = 0; i < strlen(adm_password); i++){
        if(adm_password[i] == '\n') adm_password = '\0';
    }
}


/*
CHECK LIST DE TAREFAS
- Quantidade máxima de usuários comportados no sistema
- Loops para Administrador e menus
- Criar menus
- Tipos de dados
- Funções do MENU do administrador:
    1.Criar novo usuário
    2.Trocar senha de usuário
    3.Deletar usuário
    4.Visualizar informações de um usuário em específico
        4.1.Por dígitos do CPF
        4.2.Pela data de nascimento
        4.3.Pelo usuário
    5.Visualizar todos os usuários e suas respectivas informações
    6.Mostrar quantos usuários há cadastrados
    7.Mostrar aniversariantes do dia (pedir o dia/data)
    8.Alterar informações de usuário
        8.1.CPF
        8.2.Data de nascimento
    9.Reiniciar programa
        9.1.Sem reiniciar o administrador
        9.2.Sem reiniciar administrador e quantidade de usuário
        9.3.Reiniciar tudo
    10.Fechar programa (os dados não serão salvos!)
- Funções para definir administrador
*/

