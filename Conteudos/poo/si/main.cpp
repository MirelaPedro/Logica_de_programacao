#include <iostream>
#include "uso.cpp"

using namespace std;

int main()
{
    int op = 0;
    Funcionario novoFuncionario;

    do{
        mostrarMenu();
        cin >> op;

        if(op < 1 || op > 5){
            cout << "Opção inválida. Opções válidas de 1 - 5." << endl;
            continue;
        }

        switch (op)
        {
            case 1:
                novoFuncionario = cadastrarFuncionario();
                break;

            case 3:
                mostrarFuncionario(novoFuncionario);
                break;

        }
    } while(op != 5);

    return 0;
}