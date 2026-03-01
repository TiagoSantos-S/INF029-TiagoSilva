#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"
#include "aluno.h"


#define MAX_NOME_DISCIPLINA 50

typedef struct disciplina{
    char nome_disciplina[MAX_NOME_DISCIPLINA];
    int codigo_disciplina;
    int semestre;
    int vagas;
    professor professor;
    aluno alunos;
    int qtd_alunos;
} disciplina;



#endif