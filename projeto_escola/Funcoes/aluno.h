#ifndef ALUNO_H
#define ALUNO_H

#include "include.h"

typedef struct data_A{
    int dia, mes, ano;
} data_A;

typedef struct aluno{
    int matricula;
    data_A data_nascimento;
    char cpf[CPF];
    char sexo;
    char nome[MAX_NOME_PESSOA];
    int qtd_disciplinas;
    int ativo;
} aluno;

void cadastrarAluno(aluno lista_aluno[], int *qtdAluno);
void listarAlunos(aluno lista_aluno[], int qtdAluno);
void atualizarAluno(aluno lista_aluno[], int qtdAluno);
void excluirAluno(aluno lista_aluno[], int *qtdAluno);


#endif
