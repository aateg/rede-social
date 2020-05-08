#include "Publicacao.h"
#include <iostream>
using namespace std;

Publicacao::Publicacao(Perfil *autor, string texto){
    this->autor = autor;
    this->texto = texto;
    this->quantidadeDeCurtidas = 0;
}

Publicacao::~Publicacao(){
    cout << "Destrutor de publicacao: " << this->texto << endl;
}

// getters
string Publicacao::getTexto(){
    return this->texto;
}

Perfil *Publicacao::getAutor(){
    return this->autor;
}

void Publicacao::curtir(Perfil* quemCurtiu){
    if (quemCurtiu != this->autor){
        this->quantidadeDeCurtidas++;
    }
}

int Publicacao::getCurtidas(){
    return quantidadeDeCurtidas;
}

void Publicacao::imprimir(){
    cout << "Texto: " << this->texto << " - Autor: " 
        << this->autor->getNome() << endl;
}