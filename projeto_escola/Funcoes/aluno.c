#include "aluno.h"

    void cadastrarAluno(aluno lista_aluno[], int *qtdAluno) {
    // LIMPA QUALQUER LIXO DO BUFFER
    char cpf[CPF];
    limpar_buffer();
    char nome[MAX_NOME_PESSOA];
    limpar_buffer();
    char buffer[50];
    limpar_buffer();
    printf("Cadastrar Aluno\n");

    if (*qtdAluno == TAM) {
        printf("Lista de alunos cheia\n");
        return;
    }

    printf("Digite a matricula:\n");
    fgets(buffer, sizeof(buffer), stdin);
    int matricula = atoi(buffer);
    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    printf("Informe o sexo (M/F):\n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexo = buffer[0];

    printf("Informe seu cpf:\n");
    fgets(cpf, CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    printf("Informe o nome do aluno:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    lista_aluno[*qtdAluno].matricula = matricula;
    lista_aluno[*qtdAluno].sexo = sexo;
    strcpy(lista_aluno[*qtdAluno].cpf, cpf);
    strcpy(lista_aluno[*qtdAluno].nome, nome);
    lista_aluno[*qtdAluno].ativo = true;

    (*qtdAluno)++;

    printf("Cadastrado com sucesso\n");
}