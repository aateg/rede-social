#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Perfil.h"

class Professor : public Perfil {
    public:
        Professor(int numeroUSP, string nome, string email, string departamento);
        virtual ~Professor();

        string getDepartamento();

    private:
        string departamento;
};

#endif // PROFESSOR_H