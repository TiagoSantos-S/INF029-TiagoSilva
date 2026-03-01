#include "professor.h"

void cadastrarProfessor(professor listar_professor[], int *qtdProfessor) {

    char cpf[CPF];
    char nome[MAX_NOME_PESSOA];
    char buffer[50];

    printf("== Cadastrar Professor ==\n");

    if(*qtdProfessor == TAM){
        printf("Lista de professores cheia!\n");
        return;
    }

    printf("Informe a matrícula:\n");
    fgets(buffer, sizeof(buffer), stdin);
    int matricula = atoi(buffer);
    if(matricula < 0){
        printf("Matrícula inválida\n");
        return;
    }
    
    printf("Informe o sexo (M/F): \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexo = buffer[0];

    printf("Informe o seu CPF: \n");
    fgets(cpf, CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    limpar_buffer();

    printf("Informe o nome completo do professor: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    listar_professor[*qtdProfessor].matricula = matricula;
    listar_professor[*qtdProfessor].sexo = sexo;
    strcpy(listar_professor[*qtdProfessor].cpf, cpf);
    strcpy(listar_professor[*qtdProfessor].nome, nome);
    listar_professor[*qtdProfessor].ativo = true;

    (*qtdProfessor)++;

    printf("Professor Cadastrado com Sucesso!");

}

void listarProfessor(professor listar_professor[], int *qtdProfessor){
        printf("Listar Professor\n");

    if (qtdProfessor == 0) {
        printf("Lista do Professor vazia\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (listar_professor[i].ativo) {
                printf("--------------- Professor: %d -------------\n", i + 1);
                printf("Matrícula: %d\n", listar_professor[i].matricula);
                printf("Nome do(a) Professor(a): %s\n", listar_professor[i].nome);
                printf("Sexo do(a) Professor(a): %c\n", listar_professor[i].sexo);
                printf("CPF do(a) Professor(a): %s\n", listar_professor[i].cpf);
                printf("--------------------------------------------\n");
            }
        }
    }
}

void atualizarProfessor(professor listar_professor[], int *qtdProfessor) {

    if (qtdProfessor == 0) {
    printf("Nenhum Professor cadastrado\n");
    return;
    }

    printf("Atualizar Professor\n");
    printf("Digite a matricula:\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    int indice = -1;

    // procurar professor
    for (int i = 0; i < qtdProfessor; i++) {
        if (listar_professor[i].matricula == matricula &&
            listar_professor[i].ativo) {
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

            strcpy(listar_professor[indice].cpf, cpf);
            printf("CPF atualizado com sucesso\n");
            break;
        }

        case 2: {
            char nome[MAX_NOME_PESSOA];
            printf("Informe o novo nome:\n");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            strcpy(listar_professor[indice].nome, nome);
            printf("Nome atualizado com sucesso\n");
            break;
        }

        default:
            printf("Opção inválida\n");
    }
}

void excluirProfessor(professor listar_professor[], int *qtdProfessor) {

    printf("Excluir Professor\n");
    printf("Digite a matricula\n");

    int matricula;
    scanf("%d", &matricula);

    int achou = 0;

    if (matricula < 0) {
        printf("Matrícula Inválida\n");
        return;
    }

    for (int i = 0; i < *qtdProfessor; i++) {
        if (matricula == listar_professor[i].matricula) {

            for (int j = i; j < *qtdProfessor - 1; j++) {
                listar_professor[j] = listar_professor[j + 1];
            }

            (*qtdProfessor)--;
            achou = 1;
            break;
        }
    }

    if (achou)
        printf("Professor excluído com sucesso\n");
    else
        printf("Matrícula inexistente\n");
}