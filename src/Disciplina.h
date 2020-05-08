#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Professor.h"

class Disciplina : public Perfil {
    public:
        Disciplina(string sigla, string nome, Professor *responsavel);
        virtual ~Disciplina();

        string getSigla();
        Professor *getResponsavel();
        //void imprimir();

    protected:
        bool adicionarSeguidor(Perfil *seguidor);

    private:
        string sigla;
        Professor *responsavel;
};

#endif // Disciplina_H
