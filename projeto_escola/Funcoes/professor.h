#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "include.h"
#include <time.h>

typedef struct data_P{
    int dia, mes, ano;
} data_P;

typedef struct professor{
    int matricula;
    data_P data_nascimento;
    char cpf[CPF];
    char sexo;
    char nome[MAX_NOME_PESSOA];
    int qtd_disciplinas;
    int ativo;
} professor;

int gerarMatricula(int *sequencia);
int pegarAnoAtual();

void cadastrarProfessor(professor listar_professor[], int *qtdProfessor, int *sequencia);
void listarProfessor(professor listar_professor[], int qtdProfessor);
void atualizarProfessor(professor listar_professor[], int qtdProfessor);
void excluirProfessor(professor listar_professor[], int *qtdProfessor);

int validarCPF(char cpf[]);
void limparCPF(char cpfOriginal[], char cpfLimpo[]);
bool cpfProfessorJaExiste(professor listar_professor[], int qtdProfessor, char cpf[]);
void salvarProfessor(professor lista_professor[], int qtdProfessor);

#endif

