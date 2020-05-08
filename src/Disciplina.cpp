#include "Disciplina.h"
#include <iostream>

using namespace std;

Disciplina::Disciplina (string sigla, string nome,
    Professor *responsavel) : Perfil(nome) {
        this->sigla = sigla;
        this->responsavel = responsavel;

        // professor responsavel eh um dos seguidores
        this->seguidores[0] = responsavel;
        this->quantidadeDeSeguidores = 1;
}

Disciplina::~Disciplina() {
  cout << "Disciplina destruida!" << endl;
}

string Disciplina::getSigla() {
    return this->sigla;
}

Professor *Disciplina::getResponsavel() {
    return this->responsavel;
}

void Disciplina::imprimir() {
    cout << "sigla: " << sigla << " - nome: " << this->getNome();
    cout << " - Responsavel: " << responsavel->getNome() << endl;
}
