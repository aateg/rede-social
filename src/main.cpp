#include "RedeSocial.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Evento.h"
#include <string>
#include <iostream>

using namespace std;

void cadastrarPerfil(RedeSocial *rede);
void cadastrarDisciplina(RedeSocial *rede);
void logar(RedeSocial *rede);
void listarPerfis(RedeSocial *rede); // lista todos os perfis
void listarPerfil(RedeSocial *rede, Perfil *perfil); // listar perfil em questao
void listarPublicacoesFeitas(RedeSocial *rede, Perfil *perfil);
void listarPublicacoesRecebidas(RedeSocial *rede, Perfil *perfil);
void seguirPerfil(RedeSocial *rede, Perfil *perfil); // opcao de seguir um perfil
void fazerPublicacao(RedeSocial *rede, Perfil *perfil);
void opcaoCancelar(RedeSocial *rede);
void opcaoInvalida(RedeSocial *rede);
void terminar(RedeSocial *rede);


void escolherOpcao(RedeSocial *rede){
	cout << "Escolha uma opcao:" << endl;
	cout << "1) Cadastrar Perfil" << endl;
	cout << "2) Cadastrar Disciplina" << endl;
	cout << "3) Logar" << endl;
	cout << "0) Terminar" << endl;

	int opcao;
	cin >> opcao;

	if (opcao == 1){
		cadastrarPerfil(rede);
	} else if (opcao == 2){
		cadastrarDisciplina(rede);
	} else if (opcao == 3){
		logar(rede);
	} else {
		terminar(rede);
	}
}

void cadastrarPerfil(RedeSocial *rede){

	int numeroUSP;
	string nome;
	string email;
	string professor;

	cout << "Informe os dados do perfil: " << endl;

	cout << "Numero USP: ";
    cin >> numeroUSP;
    cout << endl;

	cout << "Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << endl;

	cout << "Email: ";
    getline(cin, email);
    cout << endl;

	cout << "Professor (s/n): ";
    cin >> professor;
    cout << endl;

	if (professor == "n") {
        Perfil *perfil = new Perfil(numeroUSP, nome, email);
        rede->adicionar(perfil);
        escolherOpcao(rede);
    } else {

		string departamento;

		cout << "Departamento: ";
        cin >> departamento;
        cout << endl;
        Professor *perfil = new Professor(numeroUSP, nome, email, departamento);
        rede->adicionar(perfil);
        escolherOpcao(rede);
	}
}

void cadastrarDisciplina(RedeSocial *rede){
	string nome;
	string sigla;
    int numeroDoResponsavel;

	cout << "Informe os dados da disciplina: " << endl;
    cout << endl;

	cout << "Sigla: ";
    cin.ignore(100, '\n');
    getline(cin, sigla);
    cout << endl;

	cout << "Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << endl;

	cout << "Responsavel: " << endl;
    listarPerfis(rede);

	cout << "Digite o numero ou 0 para cancelar: ";
    cin >> numeroDoResponsavel;
    cout << endl;

	bool estaNaLista = numeroDoResponsavel > 0 && numeroDoResponsavel <= rede->getQuantidadeDePerfis();

	if (numeroDoResponsavel == 0){
		opcaoCancelar(rede);
	} else if (estaNaLista){
		if (dynamic_cast<Professor*>(rede->getPerfis()[numeroDoResponsavel - 1]) != NULL){ // rever oq esse cara faz
			// se eh professor
			Professor *professor = dynamic_cast<Professor*>(rede->getPerfis()[numeroDoResponsavel - 1]);
			Disciplina* disciplina = new Disciplina(sigla, nome, professor);

			rede->adicionar(disciplina);

			// adicionado com sucesso
			escolherOpcao(rede);
		} else {
			// se nao eh professor

            cout << "Somente professores podem ser responsaveis por disciplinas!" << endl;
            cout << endl;
            escolherOpcao(rede);
		}

	} else {
		opcaoInvalida(rede);
	}
}

void logar(RedeSocial *rede){

	int numeroDoPerfil;

	cout << "Escolha um perfil: " << endl;
    listarPerfis(rede);

	cout << "Digite o numero ou 0 para cancelar: ";
    cin >> numeroDoPerfil;
    cout << endl;

	bool estaNaLista = numeroDoPerfil > 0 && numeroDoPerfil <= rede->getQuantidadeDePerfis();

	if (numeroDoPerfil == 0){
        // voltar pras opcoes
		opcaoCancelar(rede);

	} else if (estaNaLista){
		// listar o perfil escolhido
		listarPerfil(rede, rede->getPerfis()[numeroDoPerfil - 1]);
	} else{
        opcaoInvalida(rede);
	}
}

void listarPerfil(RedeSocial *rede, Perfil *perfil){

    int numeroOpcao;

    if (dynamic_cast<Disciplina*>(perfil) == NULL) { // se for professor ou perfil
        cout << perfil->getNumeroUSP() << " - " << perfil->getNome() << endl;
    }
    if (dynamic_cast<Disciplina*>(perfil)!= NULL) {
        Disciplina* disciplina = dynamic_cast<Disciplina*>(perfil);
        cout << disciplina->getSigla() << " - " << disciplina->getNome() << endl;
    }
    if (dynamic_cast<Professor*>(perfil)!= NULL) {
        Professor* professor = dynamic_cast<Professor*>(perfil);
        cout << "Departamento: " << professor->getDepartamento() << endl;
    }

    cout << "Seguidores: " << perfil->getQuantidadeDeSeguidores() << endl;
    cout << "---" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1) Ver publicacoes feitas" << endl;
    cout << "2) Ver publicacoes recebidas" << endl;
    cout << "3) Fazer publicacao" << endl;

    if (dynamic_cast<Disciplina*>(perfil) == NULL) {
        cout << "4) Seguir perfil" << endl;
    }

    cout << "0) Deslogar" << endl;
    cout << endl;

    cin >> numeroOpcao;
    cout << endl;

    if (numeroOpcao == 0) {
        escolherOpcao(rede);

    } else if (numeroOpcao == 1) {
        listarPublicacoesFeitas(rede, perfil); // mostra publicacoes feitas
        listarPerfil(rede, perfil); // lista de novo o perfil

    } else if (numeroOpcao == 2) {
        listarPublicacoesRecebidas(rede, perfil); // mostra publicacoes recebidas
        listarPerfil(rede, perfil); // lista de novo o perfil

    } else if (numeroOpcao == 3) {
        fazerPublicacao(rede, perfil); // fazer essa funcao TODO

    } else if (numeroOpcao == 4 && dynamic_cast<Disciplina*>(perfil) == NULL) {
        seguirPerfil(rede, perfil);

    } else {
        opcaoInvalida(rede);
    }
}

void listarPublicacoesFeitas(RedeSocial *rede, Perfil *perfil){
    cout << "Publicacoes feitas: " << endl;
    for (int i = 0; i < perfil->getQuantidadeDePublicacoesFeitas(); i++) {

        Publicacao* publicacao = perfil->getPublicacoesFeitas()[i];

        if (dynamic_cast<Evento*>(publicacao) != NULL){
            Evento* evento = dynamic_cast<Evento*>(publicacao);
            cout << evento->getData() << " - " << evento->getTexto() << " (" << evento->getAutor() << ") [" << evento->getCurtidas() << "]" << endl;
        } else {
            cout << publicacao->getTexto() << " (" << publicacao->getAutor() << ") [" << publicacao->getCurtidas() << "]" << endl;
        }
    }
    cout << endl;
}

void listarPublicacoesRecebidas(RedeSocial *rede, Perfil *perfil){
    cout << "Publicacoes feitas: " << endl;
    for (int i = 0; i < perfil->getQuantidadeDePublicacoesRecebidas(); i++) {

        Publicacao* publicacao = perfil->getPublicacoesRecebidas()[i];

        if (dynamic_cast<Evento*>(publicacao) != NULL){
            Evento* evento = dynamic_cast<Evento*>(publicacao);
            cout << evento->getData() << " - " << evento->getTexto() << " (" << evento->getAutor() << ") [" << evento->getCurtidas() << "]" << endl;
        } else {
            cout << publicacao->getTexto() << " (" << publicacao->getAutor() << ") [" << publicacao->getCurtidas() << "]" << endl;
        }
    }
    cout << endl;
}
void seguirPerfil(RedeSocial *rede, Perfil *perfil){
    int numeroDoPerfil;

    cout << "Perfil:" << endl;
    listarPerfis(rede);
    cout << endl;
    cout << "Digite o numero ou 0 para cancelar: ";
    cin >> numeroDoPerfil;
    cout << endl;

    bool estaNaLista = numeroDoPerfil > 0 && numeroDoPerfil <= rede->getQuantidadeDePerfis();

    if (numeroDoPerfil == 0){
        listarPerfil(rede, perfil);
    } else if (estaNaLista){
        rede->getPerfis()[numeroDoPerfil - 1]->adicionarSeguidor(perfil);

        listarPerfil(rede, perfil);
    } else {
        cout << "Comando invalido!" << endl;
        listarPerfil(rede, perfil);
    }
}
void fazerPublicacao(RedeSocial *rede, Perfil *perfil){

    string ehEvento;
    string dataDoEvento;
    string texto;

    cout << "**** Nova Publicacao ****" << endl;
    cout << endl;
    cout << "Evento (s/n): ";
    cin >> ehEvento;
    cout << endl;
    cin.ignore(100, '\n');

    if (ehEvento == "s") {
        cout << "Data: ";
        getline(cin, dataDoEvento);
        cout << endl;
        cout << "Texto: ";
        getline(cin, texto);
        cout << endl;

        perfil->publicar(texto, dataDoEvento);
        listarPerfil(rede, perfil);

    } else if (ehEvento == "n"){
        cout << "Texto: ";
        getline(cin, texto);
        cout << endl;

        perfil->publicar(texto);
        listarPerfil(rede, perfil);
    } else {
        cout << "Comando invalido" << endl;
        listarPerfil(rede, perfil);
    }
}

void listarPerfis(RedeSocial *rede){
	for (int i = 0;  i < rede->getQuantidadeDePerfis(); i++){
		cout << std::to_string(i+1) << ") " << rede->getPerfis()[i]->getNome() << endl;
	}
	cout << endl;
}

void opcaoCancelar(RedeSocial *rede){
	cout << "0 - Operacao cancelada!" << endl;
	escolherOpcao(rede);
}

void opcaoInvalida(RedeSocial *rede){
	cout << "Opcao invalida!" << endl;
	escolherOpcao(rede);
}

void terminar(RedeSocial *rede){
	cout << "Fim" << endl;

	delete rede;
}

int main() {

	cout << "Tamanho da rede: ";

	int capacidade;
	cin >> capacidade;

	cout << endl;

	RedeSocial *rede = new RedeSocial(capacidade);

	escolherOpcao(rede);

	return 0;
}
