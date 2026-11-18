#ifndef __CONTA__
#define __CONTA__

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Cliente{
    private:
        int id;
        string nome;
        string endereco;
        string profissao;
        float salario;

    public:
        Cliente( int id, string nome, string endereco, string profissao, float salario){
            this->nome = nome;
            this->endereco = endereco;
            this->profissao = profissao;
            this->salario = salario;
        }

        string GetProfissao() const {return this->profissao;}
        int GetId() const {return this->id;}

        string toString(){
            stringstream stt;

            stt <<"---------------" << endl;
            stt <<"Nome: " << this->nome << "\nEndereço: " << this->endereco << "\nProfissão: " << this->profissao << "\nSalário: " << this->salario << endl;
            stt <<"---------------" << endl;
            return stt.str();
        }
};


class Conta{
    protected:
        int id;
        Cliente idCliente;
        float saldo;

    public:
        Conta(){
            this->cliente = 0;
            this->saldo = 0;
        }
        Conta(float saldo, int id, int idCliente){
            this->saldo = saldo;
            this->idCliente = idCliente;
        }

        int GetId() const {return this->id;}
        int GetIdCliente() const {return this->idCliente;}

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
        float limiteAtual, limite;
    public:
        ContaEspecial(float saldo, float limite, int id, int idCliente) : Conta(saldo, idCliente){
            this->limite = limite;
            this->limiteAtual = limite;
        }

        bool sacar(float valor){
            if(valor > (this->saldo)){
                if((valor - this->saldo) > this->limiteAtual) return false;

                this->saldo = 0;
                this->limiteAtual -= valor - this->saldo;
                return true;
            }
            this->saldo -= valor;
            return true;
        }

        bool transferir(Conta conta){
            cout << "Valor que deseja transferir: ";
            float valor;
            cin >> valor;
            if(!sacar(valor)) return false;

            conta.depositar(valor);
            return true;
        }

        bool restaurarLimite(){this->limiteAtual = this->limite;}
};


#endif
