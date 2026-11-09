#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include <iostream>
#include <sstream>

using namespace std;

class Empregado{
    protected: 
    string nome, description;
    float salario;

    void BuildDescription(){
        stingstream stt;

        stt << "Nome: " << this->nome << "\n" << "Salario: " << this->salario;

        this->description = stt.str();

        /* string description = "";

        description += "Nome: ";
        description += this->nome;
        description += "\n";
        description += "Salario: ";
        description += this->salario; */
    }

    public:
    //Getters
    string GetNome(){return this->nome; }
    float GetSalario(){return this->salario;}
    string GetDescription(){return this->description;}

    //Setters
    void SetSalario(float salario){this->salario = salario;}

    // construtores
    Empregado(string nome, float salario){
        this->nome = nome;
        this->salario = salario;

        BuildDescription();
    }
}

class Gerente : public Empregado{
    private: 
        string departamento;

        void BuildDescription(){

            Empregado :: BuildDescription();
            stingstream stt;
            stt << this->description << "\n" << "Departamento: " << this->departamento;

            this->description = stt.str();
        }

    public:
    Gerente(string nome, float salario, string departamento){
        this->nome = nome;
        this->salario = salario;
        this->departamento = departamento;

        BuildDescription();
    }

    string GetDepartamento(){return this->departamento;}
    void SetDepartamento(string departamento){this->departamento = departamento;}
}

class Vendedor : public Empregado{
    private:
    float percentualComissao;

    void BuildDescription(){
        Empregado :: BuildDescription();
        stringstream stt;

        stt << this->description << "\n" << "Percetual de Comissão: " << this->percentualComissao;

        this->description = stt;
    }

    public:

    Vendendor(string nome, float salario, float percentual){
        this-> percentualComissao = percentual;
    }

    float GetComissao(){return this->percentualComissao;}
    void SetComissao(float percentual){this->percentualComissao = percentual;}
}


// string stream

/*
#include <sstream>

stringstream collector; // buffer de string

collector << "Movie name: " << 

string txt = collector.str();
*/


#endif
