#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>
#include <iostream>

using namespace std;

class Ticket{
    private:
        string movie, session, seat, description;
        float value; //cost

        void BuildDescription(){
            description = "";
            description += "The movie name is: ";
            description += movie;
            description += " and your session is: ";
            description += session;
            description += " with ";
            description += seat;
            description += " seat and you have paied $";
            description += value;
        }

    public:
        // em geral não é necessário implemnetar o construtor default, apenas no caso do compilador reclamar
        Ticket(string movie, string session, string seat, float value){
            this->movie = movie;
            this->session = session;
            this->seat = seat;
            this->value = value;

            BuildDescription();
        }

        // getters
        float GetValue() {return this->value;}
        Ticket GetDescription() {return this->descrition}

        void SetValue(float value){this->value = value;}
        void SetMovie(string movie){this->movie = movie;}
        void SetSession(string session){this->session = session;}
        void SetSeat(string seat){this->seat = seat;}

};

#endif

// #pragma_once -. para guarda de inclusão
