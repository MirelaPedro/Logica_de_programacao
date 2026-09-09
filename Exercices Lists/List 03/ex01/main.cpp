#include <iostream>
#include <fstream>
#include <vector>
#define SIZECONT 100

using namespace std;

// prototypes
void insert(vector <int> &lista); //propositalemente passagem por referências (ideal)
void showAll(vector <int> lista); //propositalemente passagem por cópia (não ideal, gera cópia da variável)
void search(vector <int> lista);
void deleteByIndex(vector <int> &lista);
void showByIndex(vector <int> *lista); //propositalemente passagem por ponteiro


int main()
{
    vector <int> contList;
    int op;

    while(true)
    {
        cout << "UFSC Numeric Manager System (int)" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Insert a Value" << endl;
        cout << "2. Remove by Index" << endl;
        cout << "3. Search a Number (show all occurences)" << endl;
        cout << "4. Show All" << endl;
        cout << "5. Show by index" << endl;
        cout << "0. Exit" << endl;
        cout << "Option: " << endl;
        cin >> op;

        if(op == 0) 
        {
            cout << "Fechando programa..." << endl;
            break;
        }

        switch (op)
        {
        case 1:
            insert(contList);
            break;
        case 2:
            deleteByIndex(contList);
            break;
        case 3:
            search(contList);
            break;
        case 4:
            showAll(contList);
            break;
        case 5:
            showByIndex(&contList);
            break;
        default:
            cout << "Opção Inválida!" << endl;
            break;
        }
    }

    return 0;
}

void insert(vector <int> &lista)
{
    int n;
    cin.ignore();
    cout << "Number: " ;
    cin >> n;

    lista.push_back(n);

    cout << "Value inserted into position: " << lista.size()-1 << endl;
}

void showAll(vector <int> lista)
{
    cout << "NUMBERS'S LIST" << endl;
    for(size_t i = 0; i < lista.size(); i++){
        cout << "["<<i<<"] -> "<< lista.at(i) << endl;
        //cout << lista[i] << endl; (menos seguro)
    }
}

void search(vector <int> lista)
{
    int search, numbersFind = 0;

    cin.ignore();
    cout << "Search: " ;
    cin >> search;

    for(size_t i = 0; i < lista.size(); i++){
        if(search == lista[i]){
            cout << "Número no index " << i << ": " << lista.at(i) << endl;
            numbersFind++;
        }
    }

    cout << "QTD: " << numbersFind << endl;
}

void deleteByIndex(vector <int> &lista)
{
    int index;

    do{
        cout << "Pos (begin in 0): " ;
        cin >> index;
    } while(index < 0 || index >= lista.size());

    lista.erase(lista.begin() + index);
}

void showByIndex(vector <int> *lista)
{
    int index = 0;
    do{
        cout << "Pos (begin in 0): " ;
        cin >> index;
    } while(index < 0 || index >= lista->size());

    cout << "Número no index " << index << ": " << lista->at(index) << endl;
}
