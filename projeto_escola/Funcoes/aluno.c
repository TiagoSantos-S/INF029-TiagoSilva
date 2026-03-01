#include "aluno.h"

    void cadastrarAluno(aluno lista_aluno[], int *qtdAluno) {
        
    char cpf[CPF];
    char nome[MAX_NOME_PESSOA];
    char buffer[50];

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
    limpar_buffer();

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

void listarAlunos(aluno lista_aluno[], int qtdAluno) {
    
    printf("Listar Aluno\n");

    if (qtdAluno == 0) {
        printf("Lista aluno vazia\n");
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (lista_aluno[i].ativo) {
                printf("--------------- Aluno: %d -------------\n", i + 1);
                printf("Matrícula: %d\n", lista_aluno[i].matricula);
                printf("Nome do(a) Aluno(a): %s\n", lista_aluno[i].nome);
                printf("Sexo do(a) Aluno(a): %c\n", lista_aluno[i].sexo);
                printf("CPF do(a) Aluno(a): %s\n", lista_aluno[i].cpf);
                printf("--------------------------------------------\n");
            }
        }
    }
}

void excluirAluno(aluno lista_aluno[], int *qtdAluno) {

    printf("Excluir Aluno\n");
    printf("Digite a matricula\n");

    int matricula;
    scanf("%d", &matricula);

    int achou = 0;

    if (matricula < 0) {
        printf("Matrícula Inválida\n");
        return;
    }

    for (int i = 0; i < *qtdAluno; i++) {
        if (matricula == lista_aluno[i].matricula) {

            for (int j = i; j < *qtdAluno - 1; j++) {
                lista_aluno[j] = lista_aluno[j + 1];
            }

            (*qtdAluno)--;
            achou = 1;
            break;
        }
    }

    if (achou)
        printf("Aluno excluído com sucesso\n");
    else
        printf("Matrícula inexistente\n");
}