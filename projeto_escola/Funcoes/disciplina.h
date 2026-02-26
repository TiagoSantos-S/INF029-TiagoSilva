#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <pessoa.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50

typedef struct disciplina{
    char nome_disciplina[MAX];
    int codigo_disciplina;
    int semestre;
    int vagas;
    pessoa professor;
    pessoa *alunos;
    int qtd_alunos;
} disciplina;



#endif