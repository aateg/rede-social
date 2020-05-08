#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor (string nome) : Perfil(nome) {
    this->departamento = "POLI";
}

Professor::Professor (string nome, string departamento) : Perfil(nome) {
    this->departamento = departamento;
}

Professor::~Professor() {
  cout << "Professor destruido!" << endl;
}

string Professor::getDepartamento(){
    return this->departamento;
}

void Professor::imprimir(){
    cout << "Departamento: " << this->getDepartamento();
    Perfil::imprimir();
}