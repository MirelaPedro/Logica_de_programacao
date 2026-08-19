/*
Desenvolva um programa em C++ que realize a leitura de 10 valores em ponto
flutuante. Fornecer ao fim em tela, o valor mínimo, máximo, e a média. Desenvolver com
arrays.
*/

#include <iostream>
#define SIZE_A 10

using namespace std;

int main()
{
    float a[SIZE_A];

    for(int i = 0; i < 10; i ++){
        cout << "Digite um ponto flutuante: ";
        cin >> a[i];
    }

    return 0;
}

// std:: numerical_limits()
// o minimo e o maximo pode ser calculado com numerical limits
