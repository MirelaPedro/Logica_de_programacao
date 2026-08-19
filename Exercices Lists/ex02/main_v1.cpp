/*
Criar em C++ um programa que implementa o jogo do Cara ou Coroa. Modifique o
enunciado original abaixo, e faça com que a máquina trapaceie e a moeda vire em coroa
com uma probabilidade de 70% de ocorrer.
*/

#include <iostream>
#include <cstdlib> //rand
#include <ctime> //time 

using namespace std;

int main()
{
    srand(time(0));
    int a, b;

    do{
        cout << "1 para cara, 2 para coroa: ";
        cin >> a;
    } while((a != 1) and (a != 2));

    b = rand() % 100;

    if(b < 70 and a == 2) {
        cout << "Voce ganhou, era coroa!!" << endl;
    } 
    else if(b >= 70 and a == 1){
        cout << "Voce ganhou era cara!!" << endl;
    }
    else if(b < 70){
        cout << "Voce perdeu, era coroa!!" << endl;
    }
    else{
        cout << "Voce perdeu, era cara!!" << endl;
    }
   
    return 0;
}
