#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>


#define TAM 3
#define MAX_NOME_PESSOA 256
#define CPF 13

typedef struct data{
    int dia, mes, ano;
} data;

typedef struct pessoa{
    int matricula;
    data data_nascimento;
    char cpf[CPF];
    char sexo;
    char nome[MAX_NOME_PESSOA];
    int qtd_disciplinas;
    int ativo;
} pessoa;

#endif

