#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include "Perfil.h"

#include <string>
using namespace std;

class Perfil;

class Publicacao {
    public:
        // construtor e destrutor
        Publicacao(Perfil *autor, string texto);
        virtual ~Publicacao();

        // Getters
        Perfil* getAutor();
        string getTexto();

        virtual void curtir(Perfil* quemCurtiu);
        virtual int getCurtidas();

        virtual void imprimir();

    private:
        string texto;
        Perfil* autor;
        int quantidadeDeCurtidas;
};

#endif // PUBLICACAO_H
