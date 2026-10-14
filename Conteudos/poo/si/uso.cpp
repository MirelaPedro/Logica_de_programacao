#include <iostream>
#include "funcionario.cpp"

// --------- PROTOTYPES

void mostrarMenu();
Funcionario cadastrarFuncionario();
void mostrarFuncionario(Funcionario objeto);
void pesquisarSubstring(string substring);

using namespace std;

// --------- IPLEMENTACA
void mostrarMenu()
{
    cout << "-------- MENU DE OPÇÕES ---------" << endl;
    cout << "1. Cadastrar novo funcionário" << endl;
    cout << "2. Remover funcionário" << endl;
    cout << "3. Imprimir relatório de funcionários" << endl;
    cout << "4. Pesquisar Substring" << endl;
    cout << "5. Sair" << endl;
}

Funcionario cadastrarFuncionario()
{
    Funcionario f1;
    string auxiliar;
    float auxiliarf;
    cin.ignore();

    cout << "Nome do funcionário: ";
    getline(cin, auxiliar);
    f1.SetNome(auxiliar);

    cout << "Salário do funcionário: ";
    cin >> auxiliarf;
    f1.SetSalario(auxiliarf);

    cout << "Cargo do funcionário: ";
    getline(cin, auxiliar);
    f1.SetCargo(auxiliar);

    return f1;
}

void mostrarFuncionario(Funcionario objeto)
{
    cout << "Nome do funcionário: " << objeto.GetNome() << endl;
    cout << "Salário do funcionário: " << objeto.GetSalario() << endl;
    cout << "Cargo do funcionário: " << objeto.GetCargo() << endl;
}
void pesquisarSubstring(string substring){};
