#include <stdio.h>

int main()
{
    int a,b, response;

    a = 3;
    b = 12;

    response = a != b && a > 7;

    printf("Relação: %i\n\n", response);
    printf("Relação de diferença: %i\n", a != b);
    
}

/*
OPERADORES RELACIONAIS
    Igualdade       ->  ==
    Diferente de    ->  !=
    Maior que       ->  >
    Menor que       ->  <
    Maior ou igual  ->  >=
    Menor ou igual  ->  <=
*/

/*
OPERADORES LÓGIGOS
    &&  ->  and
    ||  ->  or
    !   ->  not


    TABELAS VERDADES
        And{
            0 - false
            1 - true

            0 && 0 = 0
            0 && 1 = 0
            1 && 0 = 0
            1 && 1 = 1
        }

        Or{
            0 - false
            1 - true

            0 || 0 = 0
            0 || 1 = 1
            1 || 0 = 1
            1 || 1 = 1
        }

        Not{

            0 - false
            1 - true

            !0 = 1
            !1 = 0
        }

*/

//Todo operador relacionar devolve um valor logico (0 or 1);

//C NAO TEM O TIPO PRIMITIVO BOOLEAN (TRUE OR FALSE);

/*
O c tem 5 tipos principais:
    INT - numero inteiro
    FLOAT - numero nao inteiro
    CHAR - caracter
    VOID - tipo nao definido 
    DOUBLE - duas vezes o int

*/
