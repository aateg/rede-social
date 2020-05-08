#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"

#include <string>
using namespace std;

class RedeSocial {
    public:
        RedeSocial (); // construtor
        ~RedeSocial(); // destrutor
        
        Perfil **getPerfis();
        int getQuantidadeDePerfis();
        bool adicionar (Perfil *perfil);
        void imprimir ();

        void imprimirEstatisticas();
    private:
        Perfil **perfis;
        const int capacidade = 100;
        int quantidadeDePerfis;
};

#endif //REDESOCIAL_H