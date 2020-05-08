#include "RedeSocial.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Evento.h"
#include <string>
#include <iostream>

using namespace std;

void escolherOpcao(RedeSocial *rede){
	cout << "Escolha uma opcao:" << endl;
	cout << "1) Cadastrar Perfil" << endl;
	cout << "1) Cadastrar Disciplina" << endl;
	cout << "1) Logar" << endl;
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
		if (dynamic_cast<Professor*>(rede->getPerfis[numeroDoResponsavel - 1]) != NULL){ // rever oq esse cara faz
			// se eh professor
			Disciplina* perfil = new Disciplina(sigla, nome, rede->getPerfis[numeroDoResponsavel - 1]);
			
			rede->adicionar(perfil);

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
		opcaoCancelar(rede);
	} else if (estaNaLista){
		// numero valido
	}
}

void listarPerfis(RedeSocial *rede){
	for (int i = 0;  i < rede->getQuantidadeDePerfis(); i++){
		cout << to_string(i+1) << ") " << rede->getPerfis[i]->getNome() << endl;
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
