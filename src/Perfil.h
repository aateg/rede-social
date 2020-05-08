#ifndef PERFIL_H
#define PERFIL_H

#include <string>
//#include "Publicacao.h"
using namespace std;

#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

class Publicacao;
class Evento;

class Perfil {
    public:
        // construtor e destrutor
        Perfil(int numeroUSP, string nome, string email);
        virtual ~Perfil();
        
        bool adicionarSeguidor(Perfil* seguidor);
        
        virtual bool publicar(string texto);
        virtual bool publicar(string texto, string data);

        virtual void imprimir();
        
        bool receber(Publicacao *p);

        // Getters e setters
        int getNumeroUSP();
        string getNome();
        string getEmail();

        virtual Publicacao** getPublicacoesFeitas();
        virtual int getQuantidadeDePublicacoesFeitas(); 

        virtual Publicacao** getPublicacoesRecebidas();
        virtual int getQuantidadeDePublicacoesRecebidas();

        bool verificaSeguidor(Perfil *perfil); // true se ja eh seguidor false cc

        
        
    protected:
        Perfil *seguidores[MAXIMO_SEGUIDORES];
        int quantidadeDeSeguidores = 0;
        
    private:
        // Atributos
        string nome;
        string email;
        int numeroUSP;
        Publicacao *feitas[MAXIMO_PUBLICACOES];
        int quantidadeDePublicacoesFeitas = 0;
        Publicacao *recebidas[MAXIMO_PUBLICACOES];
        int quantidadeDePublicacoesRecebidas = 0;
};

#endif // PERFIL_H