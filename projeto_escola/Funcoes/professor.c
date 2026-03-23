#include "professor.h"

int pegarAnoAtual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}

int gerarMatricula(int *sequencia) {

    int ano = pegarAnoAtual();

    int matricula = ano * 1005 + (*sequencia);

    (*sequencia)++;

    return matricula;
}

// Casdastrar Professor //

void cadastrarProfessor(professor listar_professor[], int *qtdProfessor) {

    char cpf[CPF];
    char nome[MAX_NOME_PESSOA];
    char buffer[50];
    char cpfDigitado[20];
    char cpfLimpo[12];

    printf("=== Cadastrar Professor ===\n");

    if(*qtdProfessor == TAM){
        printf("Lista de professores cheia!\n");
        return;
    }

    int matricula = gerarMatricula(qtdProfessor);

    printf("Matrícula do professor gerada automaticamente: %d\n", matricula);
    
    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    printf("Informe o sexo (M/F): \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexo = buffer[0];

    while (1) {

    printf("Informe o CPF:\n");
    fgets(cpfDigitado, sizeof(cpfDigitado), stdin);
    cpfDigitado[strcspn(cpfDigitado, "\n")] = '\0';

    limparCPF(cpfDigitado, cpfLimpo);

    if (!validarCPF(cpfLimpo)) {
       printf("CPF invalido\n");
       continue;
    }

    if (cpfJaExiste(listar_professor, *qtdProfessor, cpfLimpo)) {
        printf("CPF ja cadastrado\n");
        continue;
    }

    break;
    }   

    printf("Informe o nome completo do professor: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    listar_professor[*qtdProfessor].matricula = matricula;
    listar_professor[*qtdProfessor].sexo = sexo;
    strcpy(listar_professor[*qtdProfessor].cpf, cpf);
    strcpy(listar_professor[*qtdProfessor].nome, nome);
    listar_professor[*qtdProfessor].ativo = true;

    (*qtdProfessor)++;

    printf("Professor Cadastrado com Sucesso!\n");

}

// Listar Professor //

void listarProfessor(professor listar_professor[], int qtdProfessor){
        printf("=== Listar Professor ===\n");

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

// Atualizar Professor //

void atualizarProfessor(professor listar_professor[], int qtdProfessor) {

    if (qtdProfessor == 0) {
    printf("Nenhum Professor cadastrado\n");
    return;
    }

    printf("=== Atualizar Professor ===\n");
    printf("Digite a matricula:\n");

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

// Excluir Professor //

void excluirProfessor(professor listar_professor[], int *qtdProfessor) {

    printf("=== Excluir Professor ===\n");
    printf("Digite a matricula\n");

    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

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

// Funções auxiliares //

void limparCPF(char cpfOriginal[], char cpfLimpo[]) {

    int j = 0;

    for (int i = 0; cpfOriginal[i] != '\0'; i++) {

        if (cpfOriginal[i] >= '0' && cpfOriginal[i] <= '9') {
            cpfLimpo[j] = cpfOriginal[i];
            j++;
        }

    }

    cpfLimpo[j] = '\0';
}

// 

int validarCPF(char cpf[]) {

    // CPF precisa ter 11 dígitos
    if (strlen(cpf) != 11)
        return 0;

    // Verifica se todos os números são iguais (ex: 11111111111)
    int iguais = 1;

    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }

    if (iguais)
        return 0;

    int soma = 0;
    int resto;

    // Cálculo do primeiro dígito verificador
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }

    resto = soma % 11;

    int dig1;

    if (resto < 2)
        dig1 = 0;
    else
        dig1 = 11 - resto;

    // Confere o primeiro dígito
    if (dig1 != (cpf[9] - '0'))
        return 0;

    // Cálculo do segundo dígito verificador
    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = soma % 11;

    int dig2;

    if (resto < 2)
        dig2 = 0;
    else
        dig2 = 11 - resto;

    // Confere o segundo dígito
    if (dig2 != (cpf[10] - '0'))
        return 0;

    return 1;
}

bool cpfJaExiste(professor lista_professor[], int qtdProfessor, char cpf[]) {

    for (int i = 0; i < qtdProfessor; i++) {

        if (lista_professor[i].ativo && strcmp(lista_professor[i].cpf, cpf) == 0) {
            return true;
        }

    }

    return false;
}