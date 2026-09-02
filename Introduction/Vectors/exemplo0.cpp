#include <iostream>
#include <vector>

// vector <tipo_de_dado> nome;
// diferente de c pode ser acessado por indexação
//vecA.erase(vectA.begin()+1);
using namespace std;

int main()
{
    vector <int> vecA;

    vecA.push_back(10);

    cout << vecA.at(0);

    return 0;
}

