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

void lerDataNascimento(aluno lista_aluno[], int indice);
void cadastrarAluno(aluno lista_aluno[], int *qtdAluno);
void menuListagem();
void listarAlunos(aluno lista_aluno[], int qtdAluno, int criterio);
void atualizarAluno(aluno lista_aluno[], int qtdAluno);
void excluirAluno(aluno lista_aluno[], int *qtdAluno);
int validarCPF(char cpf[]);
void limparCPF(char cpfOriginal[], char cpfLimpo[]);
bool cpfJaExiste(aluno lista_aluno[], int qtdAluno, char cpf[]);

#endif