/* Sobre o exercício apresentado nos slides a01-03, slide 08 e 09. Reimplementar o
mesmo utilizando somente uma única estrutura de dados multidimensional. O vetor
times deve ser eliminado, e o nome do time deve ser armazenado sempre na posição 0 de
cada subvetor, e depois da posição 1 em diante devem ser mostrados os nomes dos
jogadores que compõem o elenco. */
// e se fizer um vetor dentro da struct de time com o jogador que pertence a ele?

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct time{
    int id;
    string name;
    int fundationYear;
    string mascote;
    int len_players;
} time;

typedef struct player{
    int id;
    string name;
    int age;
    int id_time;
    string position;
    int camisa;
} player;

// prototypes
// -- general
void showMenu();
void showAll(vector <time> listTimes, vector <player> listPlayers);

// -- times
void playerTime(vector <time> &listTimes);  // filiação do jogador a um time // TAMBÉM É UMA FUNÇÃO DE JOGADOR
void insertTime(vector <time> &listTimes); 
void removeTime(vector <time> listTimes);
void searchTime(const vector <time> &listTimes, const vector <player> &listPlayers);
void showAllTimes(const vector <time> &listTimes, const vector <player> &listPlayers); 

// -- players
void insertPlayer(vector <player> &listPlayers); 
void removePlayer(vector <player> listPlayers);
void searchPlayer(vector <player> listPlayers); 
void showAllPlayers(vector <player> listPlayers);
vector <player> searchPlayersOnTime(vector <player> listPlayers, int id_time);


int main()
{
    vector <time> times;
    vector <player> players;

    while(true)
    {
        int op;
        showMenu();
        cin >> op;

        if(op == 0) break;

        switch (op)
        {
        // insert time
        case 1:
            insertTime(times);
            break;
        // remove time
        case 2:
            break;
        // search time
        case 3:
            break;
        // insert player
        case 4:
            break;
        // remove player
        case 5:
            break;
        // search player
        case 6:
            break;
        // show all
        case 7:
            break;
        // show times
        case 8:
            showAllTimes(times, players);
            break;
        // show players
        case 9:
            break;
        // fili
        case 10:
            break;

        default:
            cout << "Opção inválida! Tente novamente. Opções válidas: 0 - 10" << endl;
            break;
        }

    }

    return 0;
}


// -- general
void showMenu()
{
    cout << " --------- MENU DE OPÇÕES --------- " << endl;
    cout << "1. Cadastrar novo time" << endl; 
    cout << "2. Remover time" << endl; 
    cout << "3. Pesquisar time" << endl; 
    cout << "4. Cadastrar jogador" << endl; 
    cout << "5. Remover jogador" << endl; 
    cout << "6. Pesquisar jogador" << endl; 
    cout << "7. Mostrar tudo" << endl; 
    cout << "8. Mostrar times" << endl; 
    cout << "9. Mostrar jogadores" << endl; 
    cout << "10. Filiação de jogadores" << endl;
    cout << "0. Sair do programa" << endl;
    cout << "Opção de escolha: "; 
}

void showAll(vector <time> listTimes, vector <player> listPlayers);

// -- times
void playerTime(vector <time> &listTimes);  // filiação do jogador a um time // TAMBÉM É UMA FUNÇÃO DE JOGADOR

void insertTime(vector <time> &listTimes)
{
    time newTime;

    cin.ignore();
    cout << "Nome do Time: ";
    getline(cin, newTime.name);
    cout << "ID - NÃO PODE HAVER IDs IGUAIS: ";
    cin >> newTime.id;
    cin.ignore();
    cout << "Ano de fundação do time: ";
    cin >> newTime.fundationYear;
    cin.ignore();
    cout << "Mascote do time: ";
    getline(cin, newTime.mascote);
    cout << "Quantidade de jogadores automaticamente configurada como zero" << endl;

    listTimes.push_back(newTime);
}

void removeTime(vector <time> listTimes);
void searchTime(const vector <time> listTimes, const vector <player> listPlayers);
void showAllTimes(const vector <time> listTimes, const vector <player> listPlayers)
{
    vector <player> playersOnTime;
    for(size_t i = 0; i < listTimes.size(); i++){
        playersOnTime = searchPlayersOnTime(listPlayers, listTimes[i].id);

        cout << listTimes[i].name  << "["<<listTimes[i].id<<"]" << endl;
        cout << "Ano de fundação: " << listTimes[i].fundationYear << endl;
        cout << "Mascote do Time: " << listTimes[i].mascote << endl;
        cout << "Quantidade de jogadores no time: " << playersOnTime.size() << endl;

        if(playersOnTime.size() > 0){
            cout << " ----- JOGADORES FILIADOS ---- " << endl;
            for(size_t j = 0; j < playersOnTime.size(); j ++){
                cout << "Id do Jogador: " << playersOnTime[i].id << endl;
                cout << "Jogador: " << playersOnTime[j].name << endl;
                cout << "Idade: " << playersOnTime[i].age << endl;
                cout << "Posição: " << playersOnTime[i].position << endl;
                cout << "Camisa: " << playersOnTime[i].camisa << endl;
            }
        }
    }
}

// -- players
void insertPlayer(vector <player> &listPlayers); 
void removePlayer(vector <player> listPlayers);
void searchPlayer(vector <player> listPlayers); 
void showAllPlayers(vector <player> listPlayers);
vector <player> searchPlayersOnTime(vector <player> listPlayers, int id_time)
{
    vector <player> playersOnTime;

    for(size_t i = 0; i < listPlayers.size(); i++){
        if(listPlayers[i].id_time == id_time) playersOnTime.push_back(listPlayers[i]);
    }

    return playersOnTime;
}
