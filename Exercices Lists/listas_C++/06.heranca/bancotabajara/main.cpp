#include <iostream>
#include <vector>
#include "conta.hpp"

using namespace std;

void mostrarMenu();
void cadastrarCliente(vector <Cliente> listaClientes);
void abrirConta(vector <Conta> listaContas, Cliente *cliente);
void removerCliente(vector <Cliente> listaClientes, Cliente cliente);
void mostrarClientes();
void listarContas();
void transferirConta();


int main(){
    int opcaoMenu;
    vector <Cliente> listaClientes;
    vector <Conta> listaContas;

    while(true){
        mostrarMenu();
        cin >> opcaoMenu;
        cin.ignore();

        switch(opcaoMenu){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;

            case 5:

                break;

            case 6:

                break;
        }

    }

    return 0;
}

void mostrarMenu(){
    cout << "----------MENU----------" << endl;
    cout << "1. Cadastrar Cliente" << endl;
    cout << "2. Remover Cliente" << endl;
    cout << "3. Mostrar Clientes" << endl;
    cout << "4. Abrir conta" << endl;
    cout << "5. Listar Contas" << endl;
    cout << "6. Transferir Conta" << endl;
    cout << "0. Sair do Programa" << endl;
    cout << ": ";
}

