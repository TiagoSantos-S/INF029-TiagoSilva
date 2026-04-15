#include "professor.h"

// Casdastrar Professor //

void cadastrarProfessor(professor listar_professor[], int *qtdProfessor, int *sequencia) {

    char nome[MAX_NOME_PESSOA];
    char buffer[50];
    char cpfDigitado[20];
    char cpfLimpo[12];

    printf("\n========== Cadastrar Professor ==========\n");

    if(*qtdProfessor == TAM){
        printf("Lista de professores cheia!\n");
        return;
    }

    int matricula = gerarMatricula(sequencia);

    matricula = matricula + 200;

    printf("\nMatrícula do professor gerada automaticamente: %d\n", matricula);
    
    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    printf("\nInforme o sexo (M/F): \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexo = buffer[0];

    while (1) {

    printf("\nInforme o CPF:\n");
    fgets(cpfDigitado, sizeof(cpfDigitado), stdin);
    cpfDigitado[strcspn(cpfDigitado, "\n")] = '\0';

    limparCPF(cpfDigitado, cpfLimpo);

    if (!validarCPF(cpfLimpo)) {
       printf("CPF invalido\n");
       continue;
    }

    if (cpfProfessorJaExiste(listar_professor, *qtdProfessor, cpfLimpo)) {
        printf("CPF ja cadastrado\n");
        continue;
    }

    break;
    }   

    printf("\nInforme o nome completo do professor: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    listar_professor[*qtdProfessor].matricula = matricula;
    listar_professor[*qtdProfessor].sexo = sexo;
    strcpy(listar_professor[*qtdProfessor].cpf, cpfLimpo);
    strcpy(listar_professor[*qtdProfessor].nome, nome);
    listar_professor[*qtdProfessor].ativo = true;

    (*qtdProfessor)++;

    // --- LÓGICA PARA SALVAR NO ARQUIVO ---
    FILE *arquivo = fopen("professores.txt", "a"); // "a" de append (anexar)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de professores!\n");
    } else {
        fprintf(arquivo, "Matrícula: %d | Nome: %s | Sexo: %c | CPF: %s\n",
                listar_professor[*qtdProfessor - 1].matricula,
                listar_professor[*qtdProfessor - 1].nome,
                listar_professor[*qtdProfessor - 1].sexo,
                listar_professor[*qtdProfessor - 1].cpf);
        fclose(arquivo);
        printf("Dados salvos em professores.txt\n");
    }

    printf("\nProfessor Cadastrado com Sucesso!!!\n");

}

// Listar Professor //

void listarProfessor(professor listar_professor[], int qtdProfessor){
    printf("\n========== Listar Professor ==========\n");

    int contador = 1;

    if (qtdProfessor == 0) {
        printf("Lista do Professor vazia\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (listar_professor[i].ativo) {
                printf("--------------- Professor: %d -------------\n", contador++);
                printf("Matrícula: %d\n", listar_professor[i].matricula);
                printf("Nome do(a) Professor(a): %s\n", listar_professor[i].nome);
                printf("Sexo do(a) Professor(a): %c\n", listar_professor[i].sexo);
                printf("CPF do(a) Professor(a): %s\n", listar_professor[i].cpf);
                printf("--------------------------------------------\n");
            }
        }
    }
}

// Atualizar Professor //

void atualizarProfessor(professor listar_professor[], int qtdProfessor) {

    if (qtdProfessor == 0) {
    printf("\nNenhum Professor cadastrado\n");
    return;
    }

    printf("\n========== Atualizar Professor ==========\n");
    printf("\nDigite a matricula:\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    int indice = -1;

    // procurar professor //
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

    // menu de atualização //
    printf("\n0 - Voltar\n");
    printf("1 - Atualizar CPF\n");
    printf("2 - Atualizar Nome\n");

    int opcao;
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao) {

        case 0:
            printf("\nVoltando...\n");
            break;

        case 1: {
            char cpf[CPF];
            printf("\nInforme o novo CPF:\n");
            fgets(cpf, CPF, stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            strcpy(listar_professor[indice].cpf, cpf);
            printf("\nCPF atualizado com sucesso\n");
            salvarProfessor(listar_professor, qtdProfessor);
            break;
        }

        case 2: {
            char nome[MAX_NOME_PESSOA];
            printf("\nInforme o novo nome:\n");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            strcpy(listar_professor[indice].nome, nome);
            printf("\nNome atualizado com sucesso\n");
            salvarProfessor(listar_professor, qtdProfessor);
            break;
        }

        default:
            printf("Opção inválida\n");
    }
}

// Excluir Professor //

void excluirProfessor(professor listar_professor[], int *qtdProfessor) {

    printf("\n========== Excluir Professor ==========\n");
    printf("\nDigite a matricula\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

    int achou = 0;

    if (matricula < 0) {
        printf("\nMatrícula Inválida\n");
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

    if (achou) {
    printf("\nProfessor excluído com sucesso\n");
    salvarProfessor(listar_professor, *qtdProfessor);
    } else {
    printf("\nMatrícula inexistente\n");
    }
}

bool cpfProfessorJaExiste(professor lista_professor[], int qtdProfessor, char cpf[]) {

    for (int i = 0; i < qtdProfessor; i++) {

        if (lista_professor[i].ativo && strcmp(lista_professor[i].cpf, cpf) == 0) {
            return true;
        }

    }

    return false;
}

void salvarProfessor(professor lista_professor[], int qtdProfessor) {

    FILE *arquivo = fopen("professores.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao atualizar o arquivo!\n");
        return;
    }

    for (int i = 0; i < qtdProfessor; i++) {

        if (!lista_professor[i].ativo)
            continue;

        fprintf(arquivo,
            "Matrícula: %d | Nome: %s | Sexo: %c | CPF: %s\n",
            lista_professor[i].matricula,
            lista_professor[i].nome,
            lista_professor[i].sexo,
            lista_professor[i].cpf
        );
    }

    fclose(arquivo);
    printf("Arquivo de professores atualizado!\n");
}
