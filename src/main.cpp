#include "RedeSocial.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "Evento.h"
#include <string>

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

	if (prof == "n") {
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
    int numeroDoResponsavel;
    //Professor* responsavel = NULL;
    //int npreRequisito;
    //Disciplina* preRequisito = NULL;

	cout << "Informe os dados da disciplina: " << endl;
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

	if (numeroDoResponsavel == 0){
		cout << "0 - Operacao cancelada!" << endl;
		escolherOpcao(rede);
	}
}

void listarPerfis(RedeSocial *rede){
	for (int i = 0;  i < rede->getQuantidadeDePerfis(); i++){
		cout << to_string(i+1) << ") " << rede->getPerfis[i]->getNome() << endl;
	}
	cout << endl;
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
