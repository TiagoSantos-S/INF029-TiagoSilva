#include <windows.h>
#include "Funcoes/disciplina.h"
#include "Funcoes/menu.h"
#include "Funcoes/aluno.h"
#include "Funcoes/professor.h"

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    aluno lista_aluno[TAM] = {0};

    int opcao;
    int qtdAluno = 0;
    int sair = false;

    while (!sair) {
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf(" %d", &opcao);

        switch (opcao) {

            case 0: {
                sair = true;
                break;
            }

            case 1: {
                printf("Módulo Aluno\n");

                int sairAluno = false;
                int opcao_aluno;

                while (!sairAluno) {
                    printf("0 - Voltar\n");
                    printf("1 - Casdatrar Aluno\n");
                    printf("2 - Listar Aluno\n");
                    printf("3 - Atualizar Aluno\n");
                    printf("4 - Excluir Aluno\n");

                    scanf("%d", &opcao_aluno);
                    limpar_buffer();

                    switch (opcao_aluno) {

                        case 0: {
                            sairAluno = true;
                            break;
                        }

                        case 1: {
                          cadastrarAluno(lista_aluno, &qtdAluno);
                          break;
                        }

                        case 2: {
                            printf("Listar Aluno\n");

                            if (qtdAluno == 0) {
                                printf("Lista aluno vazia\n");
                            } else {
                                for (int i = 0; i < qtdAluno; i++) {
                                    if (lista_aluno[i].ativo) {
                                        printf("Matrícula: %d\n", lista_aluno[i].matricula);
                                        printf("Nome do(a) Aluno(a): %s\n", lista_aluno[i].nome);
                                        printf("Sexo do(a) Aluno(a): %c\n", lista_aluno[i].sexo);
                                        printf("CPF do(a) Aluno(a): %s\n", lista_aluno[i].cpf);
                                        printf("--------------------------------------------\n");
                                    }
                                }
                            }
                            break;
                        }

                        case 3: {
                            printf("Atualizar Aluno\n");
                            break;
                        }

                        case 4: {
                            printf("Excluir Aluno\n");
                            printf("Digite a matricula\n");

                            int matricula;
                            scanf("%d", &matricula);

                            int achou = false;

                            if (matricula < 0) {
                                printf("Matrícula Inválida\n");
                            } else {
                                for (int i = 0; i < qtdAluno; i++) {
                                    if (matricula == lista_aluno[i].matricula) {

                                        for (int j = i; j < qtdAluno - 1; j++) {
                                            lista_aluno[j] = lista_aluno[j + 1];
                                        }

                                        qtdAluno--;
                                        achou = true;
                                        break;
                                    }
                                }

                                if (achou)
                                    printf("Aluno excluído com sucesso\n");
                                else
                                    printf("Matrícula inexistente\n");
                            }

                            break;
                        }

                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    }
                }

                break;
            }

            case 2:
                printf("Opção Professor selecionada.\n");
                break;

            case 3:
                printf("Opção Disciplina selecionada.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}