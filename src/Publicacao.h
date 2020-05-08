#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include "Perfil.h"

#include <string>
using namespace std;

class Perfil;

class Publicacao {
    public:
        // construtor
        Publicacao(Perfil *autor, string texto);
        // destrutor
        ~Publicacao();
        // Getters
        string getTexto();
        Perfil* getAutor();
        // Setters
        void setTexto(string nome);
        void setAutor(Perfil* autor);

        void imprimir();
        
    private:
        string texto;
        Perfil* autor;
};

#endif // PUBLICACAO_H