#include "RedeSocial.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"

int main() {

  // 1
  Professor *nelson = new Professor("Prof. Nelson", "PCS");
  // 2
  nelson->imprimir();

  // 3
  Professor *francisco = new Professor("Prof. Francisco");
  // 4
  francisco->imprimir();


  // 5
  Aluno *gabriela = new Aluno("Gabriela Ferreira");
  // 6
  gabriela->imprimir();

  // 7
  Aluno *jorge = new Aluno("Jorge Castanho");
  // 8
  jorge->imprimir();

  // 9
  Disciplina *pcs3210 = new Disciplina("PCS3210", "Algoritmos I", nelson);
  // 10
  pcs3210->imprimir();

  // 11
  Disciplina *pcs3211 = new Disciplina("PCS3211", "Algoritmos II", francisco);
  // 12
  pcs3211->imprimir();


  // 13 Crie uma RedeSocial
  RedeSocial *rede = new RedeSocial();

  // 14
  rede->adicionar(nelson);
  rede->adicionar(francisco);
  rede->adicionar(gabriela);
  rede->adicionar(jorge);
  rede->adicionar(pcs3210);
  rede->adicionar(pcs3211);

  // 15
  nelson->adicionarSeguidor(gabriela);

  // 16
  francisco->adicionarSeguidor(jorge);

  // 17
  pcs3210->adicionarSeguidor(gabriela);

  // 18
  pcs3211->adicionarSeguidor(jorge);

  // 19
  nelson->publicar("N1");
  francisco->publicar("F1");
  gabriela->publicar("G1");
  jorge->publicar("J1");
  pcs3210->publicar("D1");
  pcs3211->publicar("D2");
  
  // Imprima a rede
  rede->imprimir();

  rede->imprimirEstatisticas();

  // Destrua a rede
  delete rede;

  return 0;
}
