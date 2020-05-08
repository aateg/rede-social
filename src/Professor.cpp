#include "Professor.h"
#include <iostream>

using namespace std;
/*
Professor::Professor (string nome) : Perfil(nome) {
    this->departamento = "POLI";
}
*/

Professor::Professor (int numeroUSP, string nome, string email,
    string departamento) : Perfil(numeroUSP, nome, email) {
    this->departamento = departamento;
}

Professor::~Professor() {
  cout << "Professor destruido!" << endl;
}

string Professor::getDepartamento(){
    return this->departamento;
}
/*
void Professor::imprimir(){
    cout << "Departamento: " << this->getDepartamento();
    Perfil::imprimir();
}
*/