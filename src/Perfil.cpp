#include "Perfil.h"
#include <iostream>
using namespace std;

Perfil::Perfil(string nome){
    this->nome = nome;
}

Perfil::~Perfil(){
    cout << "Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: "
    << quantidadeDePublicacoesFeitas << endl;
    for (int i = 0; i < this->quantidadeDePublicacoesFeitas; i++){
        delete feitas[i];
    }
    cout << "Perfil deletado" << endl; 
}

void Perfil::setNome(string nome) {
    this->nome = nome;
}

string Perfil::getNome(){
    return this->nome;
}

bool Perfil::adicionarSeguidor(Perfil *seguidor){
    if (this->quantidadeDeSeguidores < MAXIMO_SEGUIDORES){
        this->seguidores[this->quantidadeDeSeguidores] = seguidor;
        this->quantidadeDeSeguidores++;
        return true;
    }
    return false;
}

bool Perfil::publicar(string texto){
    if (this->quantidadeDePublicacoesFeitas < MAXIMO_PUBLICACOES){
        // cria publicacao
        Publicacao *p = new Publicacao(this, texto);
        //p->setAutor(this);
        //p->setTexto(texto);

        // adiciona publicacao
        this->feitas[this->quantidadeDePublicacoesFeitas] = p;
        this->quantidadeDePublicacoesFeitas++;

        // adiciona so perfil dos seguidores
        for (int i=0; i < this->quantidadeDeSeguidores; i++){
            this->seguidores[i]->receber(p);
            //(*(*this).seguidores[i]).receber(p); // outra maneira de escrever
        }
        return true;
    }
    return false;
}

bool Perfil::receber(Publicacao *p){
    if (this->quantidadeDePublicacoesRecebidas < MAXIMO_PUBLICACOES){
        this->recebidas[quantidadeDePublicacoesRecebidas] = p;
        quantidadeDePublicacoesRecebidas++;
        return true;
    }
    return false;
}

void Perfil::imprimir() {
    cout << endl << "Nome: " << nome << endl;
    if (quantidadeDeSeguidores == 0)
        cout << "Sem seguidor " << endl;
    else {
        for (int i = 0; i < quantidadeDeSeguidores; i++) {
            cout << "Seguidor "<< seguidores[i]->getNome() << endl;
        }
    }
    cout << "Numero de publicacoes feitas: " << quantidadeDePublicacoesFeitas << endl;
    for (int i = 0; i < quantidadeDePublicacoesFeitas; i++)
        feitas[i]->imprimir();
    cout << "Numero de publicacoes recebidas: " << quantidadeDePublicacoesRecebidas
        << endl;
    for (int i = 0; i < quantidadeDePublicacoesRecebidas; i++)
        recebidas[i]->imprimir();
}