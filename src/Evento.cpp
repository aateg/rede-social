#include "Evento.h"
#include <iostream>

using namespace std;

Evento::Evento (Perfil* autor, string texto,
    string data) : Publicacao(autor, texto){
    this->data = data;
}

Evento::~Evento() {
  cout << "Evento destruido!" << endl;
}

string Evento::getData(){
    return this->data;
}
