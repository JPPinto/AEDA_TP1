#ifndef ESCOLA_H_
#define ESCOLA_H_

#include <unordered_set>
#include <queue>
#include <iostream>
#include "Aluno.h"
#include "Turma.h"
#include "Excepcao.h"
#include "Horario.h"
#include "Disciplina.h"
#include "Professor.h"
#include "Livraria.h"
#include "Funcionario.h"
#include "BST.h"
#include <memory>

using namespace std;

///Representa uma Escola contendo todos os seus Alunos, Professores, Turmas, Disciplinas e Horarios
class Escola
{
	vector<Aluno*> _alunos;					///< Todos os alunos inscritos na Escola
	vector<Professor*> _professores;		///< Todos os Professores que leccionam na Escola
	vector<Turma*> _turmas;					///< Todas as turmas existentes na Escola
	//vector<Horario *> _horarios; N�o h� horarios sem turmas, tem de ser um atributo de Turma
	vector<Disciplina*> _disciplinas;		///< Todas as disciplinas existentes na Escola
	tr1::unordered_set<Professor *, Professor::Hash_Prof> _ex_profs;
	priority_queue<Livraria*, vector<Livraria*>, Livraria::minLivraria> _livrarias;	///< Toda a informacao de livrarias existente na Escola
	BST<Funcionario> arvoreFuncionarios  ;	// BST Funcionarios da Escola



public:

	Escola();

	//Aluno	
	vector<Aluno *> getAlunos();
	void setAlunos(vector<Aluno*> a);				///< Define o vector _alunos
	Aluno * getAlunoByNome(string n);				///< Devolve o Aluno com o nome igual a n

	bool addAluno(string nome,int numero, Turma* t);///< Adiciona um Aluno a Escola
	string showAluno(Aluno * a);					///< Mostra o Aluno no ecra
	bool updateAluno(Aluno * a);					///< Altera informacao do Aluno
	void removeAluno(string a);						///< Remove um Aluno da Escola
	void printAlunos();								///< Imprime os dados de todos os alunos

	//Professor
	vector<Professor *> getProfessores();			///< Devolve todos os professores existentes na Escola
	void setProfessores(vector<Professor*> p);		///< Define o vector _professores
	Professor * getProfessorByNome(const string n);	///< Devolve o Professor com o nome igual a n

	bool addProfessor(string n, string  d,int t, long c);	///< Adiciona um Professor a Escola
	bool addDirector(string n, string d, int t1, long c, int t2);	///< Adiciona um Director a Escola
	string showProfessor(Professor * p);			///< Mostra o Professor no ecra
	bool updateProfessor(Professor * p);			///< Altera a informacao do Professor
	void removeProfessor(const string n);			///< Remove um Professor da Escola
	void printProfessores();						///< Imprime os dados de todos os Professores
	void printDirectoresTurma();					///< Imprime os dados de todos os Directores de Tuma

	//Ex Professores
	tr1::unordered_set<Professor *, Professor::Hash_Prof> getExProfessores(){return _ex_profs;}
	void setExProfessores(tr1::unordered_set<Professor *, Professor::Hash_Prof> ex) {_ex_profs = ex;}
	Professor * getExProfessorByNome(const string s);
	void addExProfessor(Professor * prof);			///< Adiciona um professor a tabela de Ex Professores
	void removerExProfessor(const string n);		///< Remove um ex professor da tabela
	void printExProfessores()const;					///< Imprime os dados de todos os ex professores
	string printSaveData()const;					///< Imprime os dados de todos os ex professores em format para o ficheiro de output

	//Turma
	vector<Turma *> getTurmas();					///< Devolve todas as turmas existentes na Escola
	void setTurmas(vector<Turma*> t);				///< Define o vector _turmas
	Turma * getTurmaById(int id);					///< Devolve a Turma com o id igual a id
	bool emptyTurmas()const{return _turmas.empty();}///< Devolve se _turmas esta vazio

	bool addTurma(int id, int anoEscolar);			///< Adiciona uma Turma a Escola
	string showTurma(Turma * t);					///< Mostra a Turma no ecra
	bool updateTurma(Turma * t);					///< Altera a informacao da Turma
	void removeTurma(const int id);					///< Remove uma Turma da Escola
	void printTurmas();								///< Imprime os dados de todas as Turmas


	//Disciplina
	vector<Disciplina *> getDiscipinas();					///< Devolve todas as Disciplinas que sao leccionadas na Escola
	void setDisciplina(vector<Disciplina *> d);				///< Define o vector _disciplinas
	Disciplina * getDisciplinaByNome(const string n);		///< Devolve a Disciplina com o nome igual a n
	bool emptyDisciplinas()const{							///< Devolve se _turmas esta vazio
		return _disciplinas.empty();}						

	bool addDisciplina(string nome, int d, int h);			///< Adiciona uma Disciplina a Escola
	string showDisciplina(Disciplina * d);					///< Mostra a Disciplina no ecra
	bool updateDisciplina(Disciplina * d);					///< Altera a informacao da Disciplina
	void removeDisciplina(const string n);					///< Remove uma disciplina da Escola
	void printDisciplinas();								///< Imprime os dados de todas as Disciplinas

	//livraria
	priority_queue<Livraria*, vector<Livraria*>, Livraria::minLivraria> getLivrarias();				///< Devolve todas as livrarias com informacao existentes na Escola
	void setLivrarias(priority_queue<Livraria*, vector<Livraria*>, Livraria::minLivraria> livrarias);	///< Define a queue _livrarias
	Livraria * getLivrariaByDenominacao(const string n);	///< Devolve a Livraria com a denominacao igual a n
	void fillLivrarias(vector<Livraria*> liv);				///< Dado o vector liv, preenche a queue livrarias com liv

	void addLivraria(Livraria * liv);	///< Adiciona informacao de mais uma livraria a Escola
	bool updateLivraria(const string n);					///< Altera a informacao da livraria
	void removeLivraria(const string n);					///< Remove um informacao de uma livraria da Escola
	void printLivraria();									///< Imprime os dados de todas as livrarias
	Livraria* pesquisaEspecialidade(string especialidade);  ///< Pesquisa as livrarias por especialidade
	Livraria* pesquisaAno(int ano);							///< Pesquisa as livrarias por ano de escolaridade

	//Funcionario
	BST<Funcionario> getFuncionarios() const;               ///< Devolve BST com todos os funcionarios da Escola
	bool addFuncionario(string n, long contacto);           ///< Adiciona um Funcionario a Escola
	bool updateFuncionario(Funcionario * f);				///< Altera a informacao do Funcionario
	void removeFuncionario(const string n);					///< Remove um Funcionario da Escola
	bool addTurmaFunc(Turma *t, string nome);                            ///< Adiciona turma a ser supervisionada pelo Funcionario da Escola
	void printFuncionarios();								///< Imprime os dados de todos os Funcionarios


	~Escola();
};
#endif
