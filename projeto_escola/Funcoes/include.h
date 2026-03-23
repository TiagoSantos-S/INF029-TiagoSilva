#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "time.h"

#include "aluno.h"
#include "professor.h"

///professor.h//

#define TAM 3
#define MAX_NOME_PESSOA 256
#define CPF 15

void limpar_buffer();

int gerarMatricula(int *sequencia);
int pegarAnoAtual();

int validarCPF(char cpf[]);
void limparCPF(char cpfOriginal[], char cpfLimpo[]);
bool cpfAlunoJaExiste(aluno lista_aluno[], int qtdAluno, char cpf[]);
bool cpfProfessorJaExiste(professor lista_professor[], int qtdProfessor, char cpf[]);