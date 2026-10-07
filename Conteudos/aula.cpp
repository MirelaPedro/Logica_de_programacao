#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // include para pair
#include <tuple> // include para tupla

using namespace std

int main()
{
    pair <float, string> p1;  // pair < ? , ? > p1
    p1.first = 20;
    p1.second = "chuya";
    pair < float, string > p2 (22, "vinho");


    vector < pair < float, size_t >> ice;
    ice.push_back(make_pair(50, 50000));

    cout << "Graus: " << ice.at(0).first << "  Vendas: " << ice.at(0).second << endl;

    // --------- TUPLAS ----------
    tuple <int, string, string, float> livro;
    get<0>(livro) = 1;
    get<1>(livro) = "Declínio de um homem";
    get<2>(livro) = "Osamo Dazai";
    get<3>(livro) = 60.89;

    typedef tuple <int, string, string, float> livro;

    vector<pair<string,livro>> vendas;

    vendas.push_back(make_pair("13/06/2025", make_tuple(13452, "Declínio de um homem", "Osamo Dazai", 54.90)));


    cout << "Dia da venda: " << vendas.at(0).first << " Livro vendido: " << get<1>(vendas.at(0).second) << " Valor da vendas: " << get<3>(vendas.at(0).second) << endl;


    return 0;
}