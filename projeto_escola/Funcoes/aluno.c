#include "aluno.h"


int pegarAnoAtual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}

int gerarMatricula(int *sequencia) {

    int ano = pegarAnoAtual();

    int matricula = ano * 1000 + (*sequencia);

    (*sequencia)++;

    return matricula;
}

// CADASTRAR ALUNO //

void cadastrarAluno(aluno lista_aluno[], int *qtdAluno, int *sequencia) {

    char nome[MAX_NOME_PESSOA];
    char buffer[50];
    char cpfDigitado[20];
    char cpfLimpo[12];

    printf("Cadastrar Aluno\n");

    if (*qtdAluno == TAM) {
        printf("Lista de alunos cheia\n");
        return;
    }

    int matricula = gerarMatricula(sequencia);

    printf("Matrícula gerada automaticamente: %d\n", matricula);

    if (matricula < 0) {
        printf("Matrícula inválida\n");
        return;
    }

    printf("Informe o sexo (M/F):\n");
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

    if (cpfJaExiste(lista_aluno, *qtdAluno, cpfLimpo)) {
        printf("CPF ja cadastrado\n");
        continue;
    }

    break;
    }   

    printf("Informe o nome do aluno:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("informe a data de nascimento no formato D/M/A\n");
    lerDataNascimento(lista_aluno, *qtdAluno);
    
    lista_aluno[*qtdAluno].matricula = matricula;
    lista_aluno[*qtdAluno].sexo = sexo;
    strcpy(lista_aluno[*qtdAluno].cpf, cpfLimpo);
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
        printf("Data de nascimento: %d/%d/%d\n", copia[i].data_nascimento.dia, copia[i].data_nascimento.mes, copia[i].data_nascimento.ano);
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
            char cpfDigitado[20];
            char cpfLimpo[12];

            printf("Informe o novo CPF:\n");
            fgets(cpfDigitado, sizeof(cpfDigitado), stdin);
            cpfDigitado[strcspn(cpfDigitado, "\n")] = '\0';

            limparCPF(cpfDigitado, cpfLimpo);

            if (!validarCPF(cpfLimpo)) {
                printf("CPF inválido\n");
                return;
            }

            strcpy(lista_aluno[indice].cpf, cpfLimpo);
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

// tirar . espaços e - do cpf //

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

bool cpfJaExiste(aluno lista_aluno[], int qtdAluno, char cpf[]) {

    for (int i = 0; i < qtdAluno; i++) {

        if (lista_aluno[i].ativo && strcmp(lista_aluno[i].cpf, cpf) == 0) {
            return true;
        }

    }

    return false;
}


void lerDataNascimento(aluno lista_aluno[], int indice) {

    int dia, mes, ano;

    while (1) {

        scanf("%d/%d/%d", &dia, &mes, &ano);
        limpar_buffer();

        if (!validarData(dia, mes, ano)) {
            printf("Data inválida. Tente novamente.\n");
            continue;
        }

        lista_aluno[indice].data_nascimento.dia = dia;
        lista_aluno[indice].data_nascimento.mes = mes;
        lista_aluno[indice].data_nascimento.ano = ano;

        break;
    }
}

int validarData(int dia, int mes, int ano) {

    if (ano < 1900 || ano > pegarAnoAtual())
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1 || dia > 31)
        return 0;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30)
            return 0;
    }

    if (mes == 2) {

        int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

        if (bissexto) {
            if (dia > 29)
                return 0;
        } else {
            if (dia > 28)
                return 0;
        }
    }

    return 1;
}