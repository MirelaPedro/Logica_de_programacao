/* 
Uma máquina conta moedas e calcula o montante total disponível de dinheiro. Fazer
um programa em C++ que lê a quantidade de moedas de 1, 10, 25 e 50 centavos, e
calcula o montante.
*/

#include <iostream>

using namespace std;

int main()
{
    int m1, m10, m25, m50, total;

    cout << "Quantas moedas de 1 centavo tem? " << endl;
    cin >> m1;

    cout << "Quantas moedas de 10 centavo tem? " << endl;
    cin >> m10;

    cout << "Quantas moedas de 25 centavo tem? " << endl;
    cin >> m25;

    cout << "Quantas moedas de 50 centavo tem? " << endl;
    cin >> m50; 

    total = m50 * 0.5 + m25 * 0.25 + m10 * 0.1 + m1 * 0.01;

    cout << "Total: R$" << total << endl;

    return 0;
}
