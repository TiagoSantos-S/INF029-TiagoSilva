#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "include.h"
#include "professor.h"
#include "aluno.h"

#define MAX_NOME_DISCIPLINA 50
#define MAX_ALUNOS_DISCIPLINA 40

typedef struct disciplina{
    char nome_disciplina[MAX_NOME_DISCIPLINA];
    int codigo_disciplina;
    int semestre;
    int vagas;
    professor professor;
    aluno alunos[MAX_ALUNOS_DISCIPLINA];
    int qtd_alunos;
} disciplina;

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor lista_professores[], int qtdProfessor);
void listaDisciplinaSemDadosAlunos(disciplina lista_disciplinas[], int qtdDisciplina, professor lista_professores[], int qtdProfessor);
void cadastrarAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno);
void excluirAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno);
void listaDisciplinaComDadosAlunos(disciplina lista_disciplinas[], int qtdDisciplina, aluno lista_aluno[], int qtdAluno);
void listaDisciplinasExtrapolam40Vagas(disciplina lista_disciplinas[], int qtdDisciplina, professor lista_professor[], int qtdProfessor);

#endif