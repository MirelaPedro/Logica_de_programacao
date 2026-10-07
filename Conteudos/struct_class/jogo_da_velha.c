#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct jogo{
    float x, o;
}jogo_t;

int main(){
    char jogo_atual[3][3], celula;
    int jogos = 1, fim = 0, linha, coluna;

    printf("BEM-VINDO AO JOGO DA VELHA\n\n");

    //Mostrando o jogo/zerando qualquer lixo de memória da matriz
    printf("\t1\t2\t3\n");
    for(int i = 0; i < 3; i++){
        printf("%i \t", i + 1);

        for(int j = 0; j < 3; j++){
            jogo_atual[i][j] = ' ';
            printf(" %c\t", jogo_atual[i][j]);
        }

        printf("\n");
    }

    while(fim != 1){
        // ---------- JOGADAS
        //limpando o rand
        srand(time(NULL));

        //Pedindo as coordenadas da jogada
        printf("Digite a linha: ");
        scanf("%i", &linha);
        printf("Digite a coluna: ");
        scanf("%i", &coluna);

        jogo_atual[linha - 1][coluna - 1] = 'X';

        //Fazendo a jogada do computador
        for(;;){ // um for para nao cair no mesmo lugar de outra jogada
            linha  = rand() % 3;
            coluna = rand() % 3;

            if(jogo_atual[linha][coluna] != 'X'){
                jogo_atual[linha][coluna] = 'O';
                break;
            }
        }        

        // -------- IMPRIMINDO JOGO
        //Mostrando o jogo para o jogador se orientar
        printf("JOGO %i\n\n", jogos);

        printf("\t1\t2\t3\n");
        for(int i = 0; i < 3; i++){
            printf("%i \t", i + 1);

            for(int j = 0; j < 3; j++){
                printf(" %c\t", jogo_atual[i][j]);
            }

            printf("\n");
        }

        // --------- VERIFICANDO SE ALGUÉM VENCEU

        //Verificando por linha
        for(int i = 0; i < 3; i++){
            celula = jogo_atual[i][0];

            if((celula == jogo_atual[i][1]) && (celula == jogo_atual[i][2])){
                if(celula = 'X'){
                    printf("X - ganhou!");
                    fim = 1;
                }

                if(celula = 'O'){
                    printf("O - ganhou!");
                    fim = 1;
                }
            }
        }

        //Verificando colunas
        for(int j = 0; j < 3; j++){
            celula = jogo_atual[0][j];

            if((celula == jogo_atual[1][j]) && (celula == jogo_atual[2][j])){
                if(celula = 'X'){
                    printf("X - ganhou!");
                    fim = 1;
                }

                if(celula = 'O'){
                    printf("O - ganhou!");
                    fim = 1;
                }
            }
        }
    }

    /*do{

        printf("\t1\t2\t3\n");
        for(int i = 0; i < 3; i++){
            printf("%i \t", i);

            for(int j = 0; j < 3; j++){
                printf(" \t");
                printf("/");
            }

            printf("\n");
        }
    }*/

    return 0;
}




/*
JOGO DA VELHA

Melhor de 3
Contra o computador
Mostra o resultado de quem ganhou (o jogador ou o computador)


dois jogadores ou contra o computador
*/
