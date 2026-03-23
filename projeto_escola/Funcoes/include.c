#include "include.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

