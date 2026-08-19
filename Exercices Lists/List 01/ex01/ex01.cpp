#include <iostream>

using namespace std;

int main()
{
    cout <<"Digite sua idade: " <<endl;

    int idade = 0;
    cin >>idade;

    if(idade < 30) cout << "Você eh muito jovem! " << endl;

    return 0;
}