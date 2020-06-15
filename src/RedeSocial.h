#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"

#include <string>
using namespace std;

class RedeSocial {
    public:
        RedeSocial (int numeroMaximoDePerfis); // construtor
        virtual ~RedeSocial(); // destrutor

        Perfil **getPerfis();
        int getQuantidadeDePerfis();

        bool adicionar(Perfil *perfil);
        virtual void imprimir();

        //void imprimirEstatisticas();
    private:
        Perfil **perfis;
        int numeroMaximoDePerfis;
        int quantidadeDePerfis;
};

#endif //REDESOCIAL_H
