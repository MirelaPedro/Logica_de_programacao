#include <iostream>
#include <fstream>
#include <vector>
#define SIZECONT 100

using namespace std;

// data types
struct contato
{
    string nome, telefone;
};

// prototypes
int menu();
contato criarContato();
void imprimirListaContatos(vector <contato> lista);
void searchNome(vector <contato> lista);
void deleteByIndex(vector <contato> lista);

bool saveFile(string filepath, vector <contato> lista);
bool loadFile(string filepath, vector <contato> lista);

int main()
{
    contato newCont;
    vector <contato> contList;
    int op;

    while(true)
    {
        cout << "Agenda de Contatos da UFxC" << endl;
        cout << "1. Inserir Registro" << endl;
        cout << "2. Remover Registro por Indice" << endl;
        cout << "3. Pesquisar Nomes por Substring" << endl;
        cout << "4. Listar Todos os Registros" << endl;
        cout << "5. Salvar dados em arquivo txt" << endl;
        cout << "6. Trazer dados de arquivo txt" << endl;
        cout << "0. Sair do Sistema" << endl;
        cout << "Digite uma das opcoes acima: " << endl;
        cin >> op;

        if(op == 0) 
        {
            cout << "Fechando programa..." << endl;
            break;
        }

        switch (op)
        {
        case 1:
            newCont = criarContato();
            contList.push_back(newCont);
           
            break;
        case 2:
            deleteByIndex(contList);
            break;
        case 3:
            searchNome(contList);
            break;
        case 4:
            imprimirListaContatos(contList);
            break;
        case 5:
            saveFile("database.txt", contList);
            break;
        case 6:
            loadFile("database.txt", contList);
            break;
        default:
            cout << "Opção Inválida!" << endl;
            break;
        }
    }

    return 0;
}

contato criarContato()
{
    string nome, telefone;
    contato novo;

    cin.ignore();
    cout << "Nome: " ;
    getline(cin, nome);
    
    cout << "Telefone: ";
    getline(cin, telefone);

    novo.nome = nome;
    novo.telefone = telefone;
    return novo;
}

void imprimirListaContatos(vector <contato> lista)
{
    cout << "LISTA DE CONTATOS" << endl;
    for(size_t i = 0; i < lista.size(); i++){
        cout << lista[i].nome << ": " << lista[i].telefone << endl;
    }
}

void searchNome(vector <contato> lista)
{
    string search;
    size_t pos;

    cin.ignore();
    cout << "Pesquisar por nome: " ;
    getline(cin,search);

    for(size_t i = 0; i < lista.size(); i++){
        pos = lista[i].nome.find(search);

        if(pos < lista[i].nome.size()){
            cout << lista[i].nome << ": " << lista[i].telefone<< endl;
        }
    }
}

void deleteByIndex(vector <contato> lista)
{
    int index;

    cout << "Posição que deseja deletar (inicia em 0): " ;
    cin >> index;

    for(size_t i = 0; i < lista.size(); i++){
        if(i == index);
    }
}

bool saveFile(string filepath, vector <contato> lista)
{
    ofstream fp;
    fp.open(filepath);

    //Verificando se o arquivo está aberto
    if(fp.is_open() == false) {
        cout << "Erro, o arquivo não abriu." << endl;
        return false;
    }

    for(size_t i=0; i < lista.size(); i++){
        fp << lista[i].nome << endl;
        fp << lista[i].telefone << endl;
    }

    fp.close();

    return true;
}

bool loadFile(string filepath, vector <contato> lista)
{
    ifstream fp;
    fp.open(filepath);

    if(fp.is_open() == false){
        cout << "Error, database file don't found!" << endl;
        return false;
    }

    for(size_t i = 0; i < lista.size(); i++){
        getline(fp, lista[i].nome);
        getline(fp, lista[i].telefone);
    }

    fp.close();
    return true;
}
