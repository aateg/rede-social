#include "Perfil.h"
#include <iostream>
using namespace std;

Perfil::Perfil(int numeroUSP, string nome, string email){
    this->nome = nome;
    this->numeroUSP = numeroUSP;
    this->email = email;
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

string Perfil::getEmail(){
    return this->email;
}

int Perfil::getNumeroUSP(){
    return this->numeroUSP;
}

bool Perfil::adicionarSeguidor(Perfil *seguidor){
    if (this->quantidadeDeSeguidores < MAXIMO_SEGUIDORES){
        if (!this->verificaSeguidor(seguidor)){
            
            this->seguidores[this->quantidadeDeSeguidores] = seguidor;
            this->quantidadeDeSeguidores++;

            // envia publicacao para si
            Publicacao *p = new Publicacao(this, "Novo seguidor: " + seguidor->getNome());
            this->receber(p);
            //delete p; //verificar

            return true;
        }
    }
    return false;
}

bool Perfil::verificaSeguidor(Perfil *perfil){
    for (int i = 0; i < this->quantidadeDeSeguidores; i++){
        if (this->seguidores[i] == perfil){
            return true;
        }
    }
    if (this == perfil){
        return true;
    }
    return false;
}

bool Perfil::publicar(string texto){
    if (this->quantidadeDePublicacoesFeitas < MAXIMO_PUBLICACOES){
        // cria publicacao
        Publicacao *p = new Publicacao(this, texto);

        // adiciona publicacao
        this->feitas[this->quantidadeDePublicacoesFeitas] = p;
        this->quantidadeDePublicacoesFeitas++;

        // adiciona so perfil dos seguidores
        for (int i = 0; i < this->quantidadeDeSeguidores; i++){
            this->seguidores[i]->receber(p);
            //(*(*this).seguidores[i]).receber(p); // outra maneira de escrever
        }
        return true;
    }
    return false;
}

bool Perfil::publicar(string texto, string data){
    if (this->quantidadeDePublicacoesFeitas < MAXIMO_PUBLICACOES){
        // cria publicacao
        Evento *e = new Evento(this, texto, data);

        // adiciona publicacao
        this->feitas[this->quantidadeDePublicacoesFeitas] = e;
        this->quantidadeDePublicacoesFeitas++;

        // adiciona so perfil dos seguidores
        for (int i = 0; i < this->quantidadeDeSeguidores; i++){
            this->seguidores[i]->receber(e);
            //(*(*this).seguidores[i]).receber(e); // outra maneira de escrever
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

Publicacao** Perfil::getPublicacoesFeitas(){
    return this->feitas;
}

int Perfil::getQuantidadeDePublicacoesFeitas(){
    return this->quantidadeDePublicacoesFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas(){
    return this->recebidas;
}

int getQuantidadeDePublicacoesRecebidas(){
    return this->quantidadeDePublicacoesRecebidas;
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