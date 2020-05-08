#ifndef EVENTO_H
#define EVENTO_H

#include "Publicacao.h"

using namespace std;

class Perfil;

class Evento : public Publicacao {
    public:
        Evento(Perfil* autor, string texto, string data);
        virtual ~Evento();

        string getData();

    private:
        string data;
};

#endif // EVENTO_H

