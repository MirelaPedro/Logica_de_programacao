#ifndef __CONTA__
#define __CONTA__

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Cliente{
    private:
        string nome;
        string endereco;
        string profissao;
        float salario;

    public:
        Cliente(string nome, string endereco, string profissao, float salario){
            this->nome = nome;
            this->endereco = endereco;
            this->profissao = profissao;
            this->salario = salario;
        }

        string GetProfissao() const {return this->nome;}

        string toString(){
            stringstream stt;

            stt <<"Nome: " << this->nome << "\nEndereço: " << this->endereco << "\nProfissão: " << this->profissao << "\nSalário: " << this->salario << endl;
            return stt.str();
        }
};


class Conta{
    protected:
        Cliente *cliente;
        float saldo;

    public:
        Conta(){
            this->cliente = NULL;
            this->saldo = 0;
        }
        Conta(float saldo, Cliente *cliente){
            this->saldo = saldo;
            this->cliente = cliente;
        }

        void depositar(float valor){
            this->saldo += valor;
        }

        bool sacar(float valor){
            if(valor > saldo){
                return false;
            }
            this->saldo -= valor;
            return true;
        }

        string toString(){
            string st;
            st = 'Saldo: ';
            st += this->saldo;
            return st;
        }

        bool transferir(Conta conta){
            cout << "Valor que deseja transferir: ";
            float valor;
            cin >> valor;
            if(this->saldo < valor) return false;
            conta.saldo += valor;
            return true;
        }

        
};

class ContaEspecial : public Conta{
    private:
        float limite;
    public:
        ContaEspecial(float saldo, float limite){
            this->saldo = saldo;
            this->limite = limite;
        }
};


#endif