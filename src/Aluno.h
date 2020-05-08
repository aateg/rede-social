#ifndef ALUNO_H
#define ALUNO_H

#include "Perfil.h"

class Aluno : public Perfil {
    public:
        Aluno(string nome);
        ~Aluno();
};

#endif // ALUNO_H