#include <stdio.h>
#include <string.h>

// quando é chamado com # significa que é uma instrução do pré compilador e não do compilador
#define T_STRING 100
#define T_ALUNOS 50 

typedef char string[T_STRING];

struct aluno{
    int matricula;
    string nome;
    string curso;
    int ano_ingresso;
    float iaa;
};

typedef struct aluno aluno_t;

int main(){
    aluno_t alunos[T_ALUNOS];
    int option, index = 0, aux;
    string str;

    for (;;){
        printf("--------- MENU --------- \n");
        printf("1 - Incluir aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Localizar aluno\n");
        printf("4 - Listar alunos por curso \n");
        printf("0 - Sair \n");
        printf("opção: ");

        scanf("%i", &option);
        getchar();

        if(!option) break; //if

        //if (option == 0){break;}

        printf("\n");

        switch (option){
            //Cadastrando novo aluno
            case 1:
                printf("Cadastrando aluno...\n\n");

                if(index < 50){
                    printf("Matrícula: ");
                    scanf("%i", &alunos[index].matricula);
                    getchar();

                    printf("Nome: ");
                    fgets(alunos[index].nome, T_STRING, stdin);
                    //retirando o \n da string
                    alunos[index].nome[strlen(alunos[index].nome) - 1] = '\0';
                    //alunos[index].nome[strcspn(alunos[index].nome, "\n")] = '\0';

                    printf("Curso: ");
                    fgets(alunos[index].curso, T_STRING, stdin);
                    alunos[index].curso[strlen(alunos[index].curso) - 1] = '\0';

                    printf("Ano de ingresso: ");
                    scanf("%i", &alunos[index].ano_ingresso);

                    printf("IAA: ");
                    scanf("%f", &alunos[index].iaa);
                    getchar();

                    index++; 
                } else {
                    printf("Número máximo de alunos já cadastrados!\n");
                }
                

                break;

            // LISTANDO ALUNOS
            case 2: 
                printf("Listando todos os alunos...\n");

                for(int i = 0; i < index; i++){
                    printf("---------- ALUNO %i\n", i + 1);
                    printf("Matrícula: %i\n", alunos[i].matricula);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Curso: %s\n", alunos[i].curso);
                    printf("Ano de ingresso: %i\n", alunos[i].ano_ingresso);
                    printf("IAA: %.2f\n\n", alunos[i].iaa);
                }                

                break;

            //LOCALIZANDO ALUNO
            case 3: 
                printf("Localizando aluno por nome...\n");
                
                printf("Digite o nome do aluno que deseja encontrar: ");
                fgets(str, T_STRING, stdin);
                str[strlen(str) - 1] = '\0';

                for (int i = 0; i < index; i++){
                    if(strcmp(alunos[i].nome, str) == 0){
                        printf("---------- ALUNO %i\n", i + 1);
                        printf("Matrícula: %i\n", alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Curso: %s\n", alunos[i].curso);
                        printf("Ano de ingresso: %i\n", alunos[i].ano_ingresso);
                        printf("IAA: %.2f\n", alunos[i].iaa);
                    }    

                    if(i == index - 1) printf("ALUNO NÃO ENCONTRADO!\n");
                }

                break;

            //LISTANDO POR CURSO
            case 4:
                printf("Listando alunos por curso...\n");

                printf("Digite o curso que deseja filtrar: ");
                fgets(str, T_STRING, stdin);
                str[strlen(str) - 1] = '\0';

                aux = 0;

                for (int i = 0; i < index; i++){
                    if(strcmp(alunos[i].curso, str) == 0){
                        printf("--------- ALUNO %i\n", i +1);
                        printf("Matrícula: %i\n", alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Curso: %s\n", alunos[i].curso);
                        printf("Ano de ingresso: %i\n", alunos[i].ano_ingresso);
                        printf("IAA: %.2f\n\n", alunos[i].iaa);

                        aux++;
                    }
                }

                if(aux == 0) printf("NEHUM ALUNO NESTE CURSO!\n");

                break;

            //DEFAULT
            default: 
                printf("Opção inválida! Tente novamente! \n");
        }
    }
    

    return 0;
}

/*
    -> verificar se há um aluno com a mesma matricula
    -> criar um struct de curso com número máximo de alunos
    -> verificar se o número de alunos no curso já está no máximo
    -> talvez de pra fazer com turmas que tenham números máximos ao invés de cursos
*/

//toupper()
//tolower()

