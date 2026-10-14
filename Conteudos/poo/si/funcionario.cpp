#include <iostream>

using namespace std;

class Funcionario
{
    private:
        string nome;
        float salario;
        string cargo;

    public:
        string GetNome(){return this->nome;}
        void SetNome(string novo){this->nome = novo;}
        float GetSalario(){return this->salario;}
        void SetSalario(float novo){this->salario = novo;}
        string GetCargo(){return this->cargo;}
        void SetCargo(string novo){this->cargo = novo;}
};
