#ifndef PESSOA_H
#define PESSOA_H

#include <disciplina.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#define TAM 3
#define MAX 256
#define CPF 16

typedef struct data{
    int dia, mes, ano;
} data;

typedef struct pessoa{
    int matricula;
    data data_nascimento;
    char cpf[CPF];
    char sexo;
    char nome[MAX];
    int qtd_disciplinas;
} pessoa;

#endif

