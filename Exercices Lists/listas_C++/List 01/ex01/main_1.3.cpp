// Esta versão faz o uso do getline para capturar string com espaços

#include <iostream>

using namespace std;

int main()
{
    string nome;
    int idade;

    cout << "Digite seu nome: ";
    getline(cin, nome);

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << nome;
    if(idade < 30){
        cout << ", voce eh muito jovem." << endl;
    } else {
        cout << ", voce eh muito velho!" << endl;
    }

    return 0;
}