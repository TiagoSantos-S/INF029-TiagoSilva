#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#define TAM_ALUNOS 3
#define TAM_PROFESSORES 3
#define TAM 128


typedef struct aluno{
    int matricula;
    char sexo;
    int ativo;
    char nome[256];
} Aluno;

typedef struct professor{
    int matricula;
    char sexo;
    int ativo;
    char nome[256];
} Professor;