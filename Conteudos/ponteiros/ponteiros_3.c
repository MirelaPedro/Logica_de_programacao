#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define T_STRING 100
typedef char String[T_STRING];

void formatar_str_maiusculo(String str);

int main()
{
    String msg;

    printf("Digite uma string: ");
    fgets(msg, T_STRING, stdin);

    printf("Pos.0 do vetor msg: %c\n", *msg);

    formatar_str_maiusculo(msg);

    printf("Msg: %s", msg);
    return 0;
}

void formatar_str_maiusculo(String str)
{
    for(int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}

// Todo vetor é um ponteiro que aponta pra uma posição 0
// E a matriz é um ponteiro de ponteiro (vetor) 
