/* 
O trabalho final da disciplina, constado no plano de ensino como T2, será procedido da seguinte forma:

** Postagem (SOMENTE) até dia 10/12/2026. Pede-se: Apresentação em vídeo de no máximo 8 minutos, contendo: (i) breve descrição do problema a ser resolvido (slides é opcional), (ii) demonstração de partes importantes do código, (iii) execução do programa desenvolvido.

** O trabalho é de ementa aberta, ou seja, o aluno pode escolher o que implementar. Os requisitos mínimos abaixo são colocados:

- Implementar em Linguagem C++ e Orientação à Objetos;

- O sistema deve implementar persistência de dados, ou seja, salvar em arquivo de texto (ou opcionalmente, em banco de dados -- tutorial adicional). A persistência deve ler os dados do arquivo ao carregar, e salvar em momentos oportunos (à definição do aluno).

- Elaborar a interface (gráfica ou em console) do seu sistema. A interface deve conter no mínimo 3 janelas/menus com opções variadas, que podem ser chamadas em momentos distintos;

- Enviar em arquivo padrão ZIP (obrigatório) do projeto completo, de modo que o mesmo possa ser totalmente compilado da forma padrão (g++ *.cpp -o executavel).
*/

// -------------- AICIONAR IDs PARA OS OBJETOS PARA REALIZAR PERSISTENCIA DE DADOS RELACINAL -------------------


#include <iostream>
#include <vector>
#include "conta.hpp"

using namespace std;

void mostrarMenu();
bool cadastrarCliente(vector <Cliente> listaClientes);
void abrirConta(vector <Conta> listaContas, Cliente *cliente);
bool removerCliente(vector <Cliente> listaClientes);
void mostrarClientes(vector <Cliente> &listaClientes);
void listarContas(vector <Conta> &listaContas);
bool transferir(vector <Conta> listaContas);
bool salvarDados();
bool restaurarDados();
int selecionarCliente(vector <Cliente> listaClientes);
int selecionarConta(vector <Conta> listaContas);


int main(){
    float auxFloat;
    bool auxBool;
    int opcaoMenu;
    vector <Cliente> listaClientes;
    vector <Conta> listaContas;

    while(true){
        mostrarMenu();
        cin >> opcaoMenu;
        cin.ignore();

        if(opcaoMenu == 0) {
            salvarDados();
            break;
        }

        switch(opcaoMenu){
            case 1:
                auxBool = cadastrarCliente(listaClientes);
                if(auxBool) {cout << "Cadastro realizado com sucesso!" << endl;}
                else{cout << "Falha no cadastro!" << endl;}
                break;
            case 2:
                // precisa fazer a verificacao das contas tb
                removerCliente(listaClientes);
                break;
            case 3:
                mostrarClientes(listaClientes);
                break;
            case 4:
                abrirConta();
                break;
            case 5:
                listarContas(listaContas);
                break;
            case 6:
                cout << "Valor que deseja depositar: ";
                cin >> auxFloat;
                cin.ignore();

                auxBool = listaContas.at(selecionarConta(listaContas)).depositar(auxFloat);
                if(auxBool) {cout << "Valor depositado com sucesso!" << endl;}
                else{cout << "Falha ao depositar!" << endl;}

                break;
            case 7:
                cout << "Valor que deseja sacar: ";
                cin >> auxFloat;
                cin.ignore();

                auxBool = listaContas.at(selecionarConta(listaContas)).sacar(auxFloat);
                if(auxBool) {cout << "Valor sacado com sucesso!" << endl;}
                else{cout << "Falha ao sacar!" << endl;}

                break;
            case 8:
                auxBool = transferir(listaContas);
                if(auxBool) {cout << "Transferência realizada com sucesso!" << endl;}
                else{cout << "Falha na transferência!" << endl;}

                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

    }

    return 0;
}

void mostrarMenu(){
    cout << "----------MENU----------" << endl;
    cout << "1. Cadastrar Cliente" << endl;
    cout << "2. Remover Cliente (Index)" << endl;
    cout << "3. Mostrar Clientes" << endl;
    cout << "4. Abrir conta" << endl; // cc ou ce
    cout << "5. Listar Contas" << endl;
    cout << "6. Depositar" << endl;
    cout << "7. Sacar" << endl;
    cout << "8. Transferência" << endl;
    cout << "9. Salvar Dados" << endl;
    cout << "10. Restaurar Dados" << endl;
    cout << "0. Sair do Programa" << endl;
    cout << ": ";
}

bool cadastrarCliente(vector <Cliente> listaClientes){
    string nome;
    string endereco;
    string profissao;
    float salario;
    int id;

    cout << "ID.....: ";
    cin >> id;
    cin.ignore();

    if(verificarExistenciaDeCliente(listaClientes, id)) {
        cout << "Id de cliente já cadastrado!" << endl;
        return false;
    }

    cout << "NOME........: ";
    getline(nome, cin);

    cout << "ENDEREÇO....: ";
    getline(endereco, cin);

    cout << "PROFISSÃO...: ";
    getline(profissao, cin);

    cout << "SALÁRIO.....: ";
    cin >> salario;
    cin.ignore();

    listaClientes.push_back(Cliente(nome, endereco, profissao, salario));

    return true;
}

void abrirConta(vector <Conta> listaContas, Cliente *cliente){
    
}

bool removerCliente(vector <Cliente> listaClientes){
    int index = selecionarCliente(listaClientes);
    listaClientes.erase(listaClientes.begin() + index);
}

void mostrarClientes(vector <Cliente> &listaClientes){
    cout << "=========================\nLISTA DE CLIENTES\n========================="<<endl;
    for(size_t i = 0; i < listaClientes.size(); i++){
        cout << "Index do Cliente: " << i << "\n" << listaClientes.at(i).toString();
    }
}

void listarContas(vector <Conta> &listaContas){
    cout << "=========================\nLISTA DE CONTAS\n========================="<<endl;
    for(size_t i = 0; i < listaContas; i++){
        cout << "Index da Conta: " << i << "\n" << listaContas.at(i).toString();
    }
}

bool transferir(vector <Conta> listaContas){
    int contaDetino, contaOrigem;

    cout << "SELECIONE A CONTA DE ORIGEM \n pressione enter para continuar ";
    cin.ignore();
    contaOrigem = selecionarConta(listaContas);

    cout << "SELECIONE A CONTA DE DESTNO \n pressione enter para continuar ";
    cin.ignore();
    contaOrigem = selecionarConta(listaContas);

    if(contaOrigem == contaDetino){
        cout << "Erro. A conta de origem e a conta de destino não podem ser iguais!!" << endl;
        return false;
    }

    return listaContas.at(contaOrigem).transferir(listaContas.at(contaDetino));
}

int selecionarCliente(vector <Cliente> listaClientes) {
    mostrarClientes(listaClientes);
    cout << "Digite o index do cliente: ";
    int index;
    cin >> index;
    cin.ignore();
    return index;
}

int selecionarConta(vector <Conta> listaContas) {
    listarContas(listaContas);
    cout << "Digite o index do conta: ";
    int index;
    cin >> index;
    cin.ignore();
    return index;
}

int verificarExistenciaDeContaCliente(vector <Conta> listarContas, int idCliente){
    for(size_t i = 0; i < listarContas.size(); i ++){
        if(listarContas.at(i).GetIdCliente() == idCliente) return true;
    }
    return false;
}

int verificarExistenciaDeConta(vector <Conta> listarContas, int idConta){
    for(size_t i = 0; i < listarContas.size(); i ++){
        if(listarContas.at(i).GetId() == idConta) return true;
    }
    return false;
}

int verificarExistenciaDeCliente(vector <Cliete> listarClietes, int idCliente){
    for(size_t i = 0; i < listarClietes.size(); i ++){
        if(listarClietes.at(i).GetId() == idCliente) return true;
    }
    return false;
}
