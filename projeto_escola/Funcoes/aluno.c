#include "aluno.h"

// CADASTRAR ALUNO //

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

// menu //

void menuListagem() {
    printf("\n=== LISTAR ALUNOS ===\n");
    printf("1 - Ordem Alfabética\n");
    printf("2 - Ordem por Matrícula\n");
    printf("3 - Apenas Sexo Feminino\n");
    printf("4 - Apenas Sexo Masculino\n");
    printf("Escolha uma opção: ");
}

// LISTAR ALUNO //

void listarAlunos(aluno lista_aluno[], int qtdAluno, int criterio) {

    if (qtdAluno == 0) {
        printf("Lista aluno vazia\n");
        return;
    }

    aluno copia[qtdAluno];

    // Copiando lista
    for (int i = 0; i < qtdAluno; i++) {
        copia[i] = lista_aluno[i];
    }

    // ORDENAÇÃO

    if (criterio == 1) { 
        // Ordem alfabética
        for (int i = 0; i < qtdAluno - 1; i++) {
            for (int j = i + 1; j < qtdAluno; j++) {
                if (strcmp(copia[i].nome, copia[j].nome) > 0) {
                    aluno temp = copia[i];
                    copia[i] = copia[j];
                    copia[j] = temp;
                }
            }
        }
    }

    if (criterio == 2) {
        // Ordem por matrícula
        for (int i = 0; i < qtdAluno - 1; i++) {
            for (int j = i + 1; j < qtdAluno; j++) {
                if (copia[i].matricula > copia[j].matricula) {
                    aluno temp = copia[i];
                    copia[i] = copia[j];
                    copia[j] = temp;
                }
            }
        }
    }

    // IMPRESSÃO

    int contador = 1;

    for (int i = 0; i < qtdAluno; i++) {

        if (!copia[i].ativo)
            continue;

        if (criterio == 3 && copia[i].sexo != 'F')
            continue;

        if (criterio == 4 && copia[i].sexo != 'M')
            continue;

        printf("--------------- Aluno: %d -------------\n", contador++);
        printf("Matrícula: %d\n", copia[i].matricula);
        printf("Nome do(a) Aluno(a): %s\n", copia[i].nome);
        printf("Sexo do(a) Aluno(a): %c\n", copia[i].sexo);
        printf("CPF do(a) Aluno(a): %s\n", copia[i].cpf);
        printf("--------------------------------------------\n");
    }

    if (contador == 1) {
        printf("Nenhum aluno encontrado nesse critério.\n");
    }
}

    // ATUALIZAR ALUNO //

void atualizarAluno(aluno lista_aluno[], int qtdAluno) {

    if (qtdAluno == 0) {
    printf("Nenhum aluno cadastrado\n");
    return;
    }


    printf("Atualizar Aluno\n");
    printf("Digite a matricula:\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    int indice = -1;

    // procurar aluno
    for (int i = 0; i < qtdAluno; i++) {
        if (lista_aluno[i].matricula == matricula &&
            lista_aluno[i].ativo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Matrícula não encontrada\n");
        return;
    }

    // menu de atualização
    printf("0 - Voltar\n");
    printf("1 - Atualizar CPF\n");
    printf("2 - Atualizar Nome\n");

    int opcao;
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao) {

        case 0:
            printf("Voltando...\n");
            break;

        case 1: {
            char cpf[CPF];
            printf("Informe o novo CPF:\n");
            fgets(cpf, CPF, stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            strcpy(lista_aluno[indice].cpf, cpf);
            printf("CPF atualizado com sucesso\n");
            break;
        }

        case 2: {
            char nome[MAX_NOME_PESSOA];
            printf("Informe o novo nome:\n");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            strcpy(lista_aluno[indice].nome, nome);
            printf("Nome atualizado com sucesso\n");
            break;
        }

        default:
            printf("Opção inválida\n");
    }
}

// EXCLUIR ALUNO //

void excluirAluno(aluno lista_aluno[], int *qtdAluno) {

    printf("Excluir Aluno\n");
    printf("Digite a matricula\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

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

