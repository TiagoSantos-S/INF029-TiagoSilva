#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "include.h"


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

#endif

