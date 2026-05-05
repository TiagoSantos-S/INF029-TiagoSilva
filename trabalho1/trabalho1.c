// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Tiago santos da silva
//  email: 20251160045@ifba.edu.br
//  Matrícula: 20251160045
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h"
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
#include <stdio.h>
#include <string.h>

int q1(char data[])
{
    int dia = 0, mes = 0, ano = 0;
    int i = 0;
    int qtd_barra = 0;

    while (data[i] != '\0' && data[i] != '\n')
    {
        if (data[i] == '/')
        {
            qtd_barra++;
        }
        else
        {
            // validar se é número
            if (data[i] < '0' || data[i] > '9')
                return 0;

            int valor = data[i] - '0';

            if (qtd_barra == 0)
                dia = dia * 10 + valor;
            else if (qtd_barra == 1)
                mes = mes * 10 + valor;
            else if (qtd_barra == 2)
                ano = ano * 10 + valor;
            else
                return 0;
        }
        i++;
    }

    if (qtd_barra != 2)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1)
        return 0;

    int diasMes;

    if (mes == 2)
    {
        // ano bissexto (considerando ano com 2 ou 4 dígitos)
        int anoCompleto = ano;
        if (ano < 100)
            anoCompleto += 2000;

        if ((anoCompleto % 4 == 0 && anoCompleto % 100 != 0) || (anoCompleto % 400 == 0))
            diasMes = 29;
        else
            diasMes = 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        diasMes = 30;
    else
        diasMes = 31;

    if (dia > diasMes)
        return 0;

    return 1;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;

    // validações
    if (q1(datainicial) == 0)
    {
        dma.retorno = 2;
        return dma;
    }
    if (q1(datafinal) == 0)
    {
        dma.retorno = 3;
        return dma;
    }

    int d1 = 0, m1 = 0, a1 = 0;
    int d2 = 0, m2 = 0, a2 = 0;

    int i, barra;

    // -------------------------
    // separar data inicial
    i = 0;
    barra = 0;
    while (datainicial[i] != '\0' && datainicial[i] != '\n')
    {
        if (datainicial[i] == '/')
        {
            barra++;
        }
        else
        {
            int v = datainicial[i] - '0';
            if (barra == 0)
                d1 = d1 * 10 + v;
            else if (barra == 1)
                m1 = m1 * 10 + v;
            else
                a1 = a1 * 10 + v;
        }
        i++;
    }

    if (a1 < 100)
        a1 += 2000;

    // -------------------------
    // separar data final
    i = 0;
    barra = 0;
    while (datafinal[i] != '\0' && datafinal[i] != '\n')
    {
        if (datafinal[i] == '/')
        {
            barra++;
        }
        else
        {
            int v = datafinal[i] - '0';
            if (barra == 0)
                d2 = d2 * 10 + v;
            else if (barra == 1)
                m2 = m2 * 10 + v;
            else
                a2 = a2 * 10 + v;
        }
        i++;
    }

    if (a2 < 100)
        a2 += 2000;

    // -------------------------
    // verificar ordem
    if (a1 > a2 ||
        (a1 == a2 && m1 > m2) ||
        (a1 == a2 && m1 == m2 && d1 > d2))
    {
        dma.retorno = 4;
        return dma;
    }

    // -------------------------
    // cálculo

    // AJUSTE DIAS
    if (d2 < d1)
    {
        m2--;

        int mesAux = m2;
        int anoAux = a2;

        if (mesAux == 0)
        {
            mesAux = 12;
            anoAux--;
        }

        int diasMes;

        if (mesAux == 2)
        {
            if ((anoAux % 4 == 0 && anoAux % 100 != 0) || (anoAux % 400 == 0))
                diasMes = 29;
            else
                diasMes = 28;
        }
        else if (mesAux == 4 || mesAux == 6 || mesAux == 9 || mesAux == 11)
            diasMes = 30;
        else
            diasMes = 31;

        d2 += diasMes;
    }

    // AJUSTE MESES
    if (m2 < m1)
    {
        a2--;
        m2 += 12;
    }

    dma.qtdDias = d2 - d1;
    dma.qtdMeses = m2 - m1;
    dma.qtdAnos = a2 - a1;

    dma.retorno = 1;
    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i = 0;

    if (isCaseSensitive == 1)
    {
        while (texto[i] != '\0' && texto[i] != '\n')
        {
            if (texto[i] == c)
            {
                qtdOcorrencias += 1;
            }
            i++;
        }
    }
    else
    {
        while (texto[i] != '\0' && texto[i] != '\n')
        {
            if (texto[i] == c || texto[i] == c + 32 || texto[i] == c - 32)
            {
                qtdOcorrencias += 1;
            }
            i++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra
    (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência,
    a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias.
    Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string
    "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;

    int i, j, k;
    int pos = 0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);

    for (i = 0, j = 0; i < tamTexto; i++)
    {
        if (strTexto[i] != -61)
        {
            strTexto[j] = strTexto[i];
            j++;
        }
    }

    strTexto[j] = '\0';
    tamTexto = strlen(strTexto);

    for (i = 0; i < tamTexto; i++)
    {
        for (j = i, k = 0; k < tamBusca && j < tamTexto && strTexto[j] == strBusca[k]; j++, k++)
            ;

        if (k == tamBusca)
        {
            qtdOcorrencias++;

            posicoes[pos++] = i + 1;
            posicoes[pos++] = j;

            i += tamBusca - 1;
        }
    }

    return qtdOcorrencias; 
}

    /*
     Q5 = inverte número
     @objetivo
        Inverter número inteiro
     @entrada
        uma int num.
     @saida
        Número invertido
     */

    int q5(int num)
    {
        int invertido = 0;

        while (num != 0)
        {
            int digito = num % 10;               // pega último dígito
            invertido = invertido * 10 + digito; // adiciona no novo número
            num = num / 10;                      // remove último dígito
        }

        num = invertido;

        return num;
    }

    /*
     Q6 = ocorrência de um número em outro
     @objetivo
        Verificar quantidade de vezes da ocorrência de um número em outro
     @entrada
        Um número base (numerobase) e um número de busca (numerobusca).
     @saida
        Quantidade de vezes que número de busca ocorre em número base
     */

    int q6(int numerobase, int numerobusca)
    {
        int qtd = 0;

        if (numerobase < 0)
            numerobase = -numerobase;
        if (numerobusca < 0)
            numerobusca = -numerobusca;

        int temp = numerobusca;
        int tamanho = 0;

        // contar dígitos da busca
        if (temp == 0)
            tamanho = 1;
        while (temp > 0)
        {
            temp /= 10;
            tamanho++;
        }

        int divisor = 1;
        for (int i = 0; i < tamanho; i++)
        {
            divisor *= 10;
        }

        while (numerobase > 0)
        {
            if (numerobase % divisor == numerobusca)
            {
                qtd++;
                numerobase /= divisor; //  PULA o tamanho da busca
            }
            else
            {
                numerobase /= 10; // anda normal
            }
        }

        return qtd;
    }

    /*
     Q7 = jogo busca palavras
     @objetivo
        Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
     @entrada
        Uma matriz de caracteres e uma string de busca (palavra).
     @saida
        1 se achou 0 se não achou
     */

    int q7(char matriz[8][10], char palavra[5])
    {
        int linha, coluna, k;

        for (linha = 0; linha < 8; linha++)
        {
            for (coluna = 0; coluna < 10; coluna++)
            {

                // tenta só se primeira letra bater
                if (matriz[linha][coluna] != palavra[0])
                    continue;

                //  DIREITA →
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (coluna + k >= 10)
                        break;
                    if (matriz[linha][coluna + k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  ESQUERDA ←
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (coluna - k < 0)
                        break;
                    if (matriz[linha][coluna - k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  BAIXO ↓
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha + k >= 8)
                        break;
                    if (matriz[linha + k][coluna] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  CIMA ↑
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha - k < 0)
                        break;
                    if (matriz[linha - k][coluna] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  DIAGONAL ↘
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha + k >= 8 || coluna + k >= 10)
                        break;
                    if (matriz[linha + k][coluna + k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  DIAGONAL ↙
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha + k >= 8 || coluna - k < 0)
                        break;
                    if (matriz[linha + k][coluna - k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  DIAGONAL ↗
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha - k < 0 || coluna + k >= 10)
                        break;
                    if (matriz[linha - k][coluna + k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;

                //  DIAGONAL ↖
                for (k = 0; palavra[k] != '\0'; k++)
                {
                    if (linha - k < 0 || coluna - k < 0)
                        break;
                    if (matriz[linha - k][coluna - k] != palavra[k])
                        break;
                }
                if (palavra[k] == '\0')
                    return 1;
            }
        }

        return 0;
    }

    DataQuebrada quebraData(char data[])
    {
        DataQuebrada dq;
        char sDia[3];
        char sMes[3];
        char sAno[5];
        int i;

        for (i = 0; data[i] != '/'; i++)
        {
            sDia[i] = data[i];
        }
        if (i == 1 || i == 2)
        {                   // testa se tem 1 ou dois digitos
            sDia[i] = '\0'; // coloca o barra zero no final
        }
        else
        {
            dq.valido = 0;
            return dq;
        }

        int j = i + 1; // anda 1 cada para pular a barra
        i = 0;

        for (; data[j] != '/'; j++)
        {
            sMes[i] = data[j];
            i++;
        }

        if (i == 1 || i == 2)
        {                   // testa se tem 1 ou dois digitos
            sMes[i] = '\0'; // coloca o barra zero no final
        }
        else
        {
            dq.valido = 0;
            return dq;
        }

        j = j + 1; // anda 1 cada para pular a barra
        i = 0;

        for (; data[j] != '\0'; j++)
        {
            sAno[i] = data[j];
            i++;
        }

        if (i == 2 || i == 4)
        {                   // testa se tem 2 ou 4 digitos
            sAno[i] = '\0'; // coloca o barra zero no final
        }
        else
        {
            dq.valido = 0;
            return dq;
        }

        dq.iDia = atoi(sDia);
        dq.iMes = atoi(sMes);
        dq.iAno = atoi(sAno);

        dq.valido = 1;

        return dq;
    }
