#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "time.h"

#define TAM 3
#define MAX_NOME_PESSOA 256
#define CPF 15

void limpar_buffer();

int gerarMatricula(int *sequencia);
int pegarAnoAtual();

int validarCPF(char cpf[]);
void limparCPF(char cpfOriginal[], char cpfLimpo[]);

#endif