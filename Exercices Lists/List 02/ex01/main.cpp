/*
Criar um sistema de agenda onde seja possível inserir o nome, e o telefone de pessoas.
Criar duas estruturas de dados na forma de array de strings para acomodar cada uma das
informações ou uma struct contendo os arrays de string internamente.
O seguinte menu e suas operações deve ser implementado:
 cout << "Agenda de Contatos da UFxC" << endl;
 cout << "1. Inserir Registro" << endl;
 cout << "2. Remover Registro por Indice" << endl;
 cout << "3. Pesquisar Nomes por Substring" << endl;
 cout << "4. Listar Todos os Registros" << endl;
 cout << "5. Sair do Sistema" << endl;
 cout << "Digite uma das opcoes acima: " << endl;
Opção 1, insere um registro no sistema, solicitando o nome da pessoa com espaço até o
enter ser pressionado (ver getline com string). O telefone da mesma maneira.
Opção 2. remover um registro de determinado valor inteiro, correspondente à posição.
Opção 3. Pesquisar um nome utilizando substrings. Usar o método find() da string.
Opção 4. Listar todos os registros.
Opção 5. Sair do sistema.
*/
#include <iostream>
#include <fstream>
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
void imprimirListaContatos(contato *lista, size_t size);
void searchNome(contato *lista, size_t size);
void deleteByIndex(contato *lista, size_t size);

bool saveFile(string filepath, contato* lista, size_t registers);
bool loadFile(string filepath, contato* lista, size_t* registers);

int main()
{
    contato contList[SIZECONT], newCont;
    int op;
    size_t registers = 0; // size_t é um tipo unsigned long long int -> sendo um apelido para esse tipo de dado

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
            contList[registers] = newCont;
            registers++;
           
            break;
        case 2:
            deleteByIndex(contList, registers);
            break;
        case 3:
            searchNome(contList, registers);
            break;
        case 4:
            imprimirListaContatos(contList, registers);
            break;
        case 5:
            saveFile("database.txt", contList, registers);
            break;
        case 6:
            loadFile("database.txt", contList, &registers);
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

void imprimirListaContatos(contato *lista, size_t size)
{
    cout << "LISTA DE CONTATOS" << endl;
    for(size_t i = 0; i < size; i++){
        cout << (lista + i)->nome << ": " << (lista + i)->telefone << endl;
    }
}

void searchNome(contato *lista, size_t size)
{
    string search;
    size_t pos;

    cin.ignore();
    cout << "Pesquisar por nome: " ;
    getline(cin,search);

    for(size_t i = 0; i < size; i++){
        pos = (lista + i)->nome.find(search);

        if(pos < (lista + i)->nome.size()){
            cout << (lista+i)->nome << ": " << (lista+i)->telefone<< endl;
        }
    }
}

void deleteByIndex(contato *lista, size_t size)
{
    int index;

    cout << "Posição que deseja deletar (inicia em 0): " ;
    cin >> index;

    for(size_t i = 0; i < size; i++){
        if(i == index);
    }
}

bool saveFile(string filepath, contato* lista, size_t registers)
{
    ofstream fp;
    fp.open(filepath);

    //Verificando se o arquivo está aberto
    if(fp.is_open() == false) {
        cout << "Erro, o arquivo não abriu." << endl;
        return false;
    }

    fp << registers << endl;

    for(size_t i=0; i < registers; i++){
        fp << lista[i].nome << endl;
        fp << lista[i].telefone << endl;
    }

    fp.close();

    return true;
}

bool loadFile(string filepath, contato* lista, size_t* registers)
{
    ifstream fp;
    fp.open(filepath);

    if(fp.is_open() == false){
        cout << "Error, database file don't found!" << endl;
        return false;
    }

    fp >> *registers;
    fp.ignore();

    for(size_t i = 0; i < *registers; i++){
        getline(fp, (lista + i)->nome);
        getline(fp, (lista + i)->telefone);
    }

    fp.close();
    return true;
}
