#include "Aluno.h"
#include <iostream>

using namespace std;

Aluno::Aluno (string nome) : Perfil(nome){}

Aluno::~Aluno() {
  cout << "Aluno destruido!" << endl;
}