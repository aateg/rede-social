#include "RedeSocial.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include <iostream>
using namespace std;

RedeSocial::RedeSocial(int numeroMaximoDePerfis){
  this->perfis = new Perfil*[numeroMaximoDePerfis];
  this->quantidadeDePerfis = 0;
  this->numeroMaximoDePerfis = numeroMaximoDePerfis;
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  for (int i = 0; i < this->quantidadeDePerfis; i++){
    delete perfis[i];
  }
  cout << "RedeSocial deletada " << endl;
}

Perfil **RedeSocial::getPerfis(){
  return this->perfis;
}

int RedeSocial::getQuantidadeDePerfis(){
  return this->quantidadeDePerfis;
}

bool RedeSocial::adicionar(Perfil *perfil){
  if(this->quantidadeDePerfis < this->numeroMaximoDePerfis){
    this->perfis[this->quantidadeDePerfis] = perfil;
    this->quantidadeDePerfis++;
    return true;
  }
  return false;
}

void RedeSocial::imprimir () {
  cout << endl << "------------------------------ " << endl;
  cout << "RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  cout << "------------------------------ " << endl;
  if (quantidadeDePerfis == 0){
    cout << "Sem perfis" << endl;
    cout << "------------------------------ " << endl;
  } else {
    for (int i = 0; i < quantidadeDePerfis; i++){
      perfis[i]->imprimir();
      cout << "------------------------------ " << endl;
    }
  }
  cout << endl;
}
/*
void RedeSocial::imprimirEstatisticas() {
  int qtdAlunos = 0;
  int qtdProf = 0;
  int qtdDisc = 0;
  int qtdPerf = 0;

  for(int i=0; i<quantidadeDePerfis; i++){
      Aluno *a = dynamic_cast<Aluno*>(perfis[i]);
      Professor *p = dynamic_cast<Professor*>(perfis[i]);
      Disciplina *d = dynamic_cast<Disciplina*>(perfis[i]);
      if (a != NULL){
          qtdAlunos++;
      } else if (p != NULL){
          qtdProf++;
      } else if (d != NULL) {
          qtdDisc++;
      } else {
          qtdPerf++;
      }
  }

  cout << "Alunos: " << qtdAlunos << endl;
  cout << "Professores: " << qtdProf << endl;
  cout << "Disciplinas: " << qtdDisc << endl;
  cout << "Perfis: " << qtdPerf << endl;
}
*/
