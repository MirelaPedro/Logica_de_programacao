/*
Na versão dois o usuário passa a probabilidade de dar COROA como argumento de chamado do programa
*/

#include <iostream>
#include <cstdlib> //rand
#include <ctime> //time 

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2){
        cout << "Error, o uso do programa deve ser <excutavel probabilidade_coroa>" << endl;
        return 2;
    }

    srand(time(0));
    int a, b, probability = (int) argv[1];

    do{
        cout << "1 para cara, 2 para coroa: ";
        cin >> a;
    } while((a != 1) and (a != 2));

    b = rand() % 100;

    if(b < probability and a == 2) {
        cout << "Voce ganhou, era coroa!!" << endl;
    } 
    else if(b >= probability and a == 1){
        cout << "Voce ganhou era cara!!" << endl;
    }
    else if(b < probability){
        cout << "Voce perdeu, era coroa!!" << endl;
    }
    else{
        cout << "Voce perdeu, era cara!!" << endl;
    }
   
    return 0;
}
