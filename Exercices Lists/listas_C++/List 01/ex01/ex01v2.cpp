#include <iostream>

using namespace std;

int main()
{
    string nome;
    int idade;

    cout << "Digite seu nome: ";
    cin >> nome;

    cout <<"Digite sua idade: " <<endl;
    cin >>idade;

    if(idade < 30) cout << nome << ", voce eh muito jovem! " << endl;

    return 0;
}