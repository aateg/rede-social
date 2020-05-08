#ifndef PERFIL_H
#define PERFIL_H

#include <string>
#include "Publicacao.h"
using namespace std;

#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

class Publicacao;

class Perfil {
    public:
        // construtor
        Perfil(string nome);
        // destrutor
        virtual ~Perfil();
        // Adiciona um perfil como seguidor deste perfil.
        bool adicionarSeguidor(Perfil* seguidor);
        // Faz uma publicacao, que eh divulgada a todos os seguidores do perfil.
        bool publicar(string texto);
        // Recebe as publicacoes feitas por um Perfil seguido.
        bool receber(Publicacao *p);
        // Imprime o Perfil.
        virtual void imprimir();
        // Getters e setters
        string getNome();
        void setNome (string nome);
        
    protected:
        Perfil *seguidores[MAXIMO_SEGUIDORES];
        int quantidadeDeSeguidores = 0;
        
    private:
        // Atributos
        string nome;
        Publicacao *feitas[MAXIMO_PUBLICACOES];
        int quantidadeDePublicacoesFeitas = 0;
        Publicacao *recebidas[MAXIMO_PUBLICACOES];
        int quantidadeDePublicacoesRecebidas = 0;
};

#endif // PERFIL_H