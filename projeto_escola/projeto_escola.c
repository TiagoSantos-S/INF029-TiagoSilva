#include <windows.h>
#include "Funcoes/disciplina.h"
#include "Funcoes/menu.h"
#include "Funcoes/aluno.h"
#include "Funcoes/professor.h"

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    aluno lista_aluno[TAM] = {0};
    professor lista_professor[TAM] = {0};

    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int sair = false;

    while (!sair) {
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

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
                            listarAlunos(lista_aluno, qtdAluno);
                            break;
                        }

                        case 3: {
                            printf("Atualizar Aluno\n");
                            break;
                        }

                        case 4: {
                            excluirAluno(lista_aluno, &qtdAluno);
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
                printf("Módulo Professor\n");

                int sairProfessor = false;
                int opcao_professor;

                while (!sairProfessor) {
                    printf("0 - Voltar\n");
                    printf("1 - Casdatrar Professor\n");
                    printf("2 - Listar Professor\n");
                    printf("3 - Atualizar Professor\n");
                    printf("4 - Excluir Professor\n");

                    scanf("%d", &opcao_professor);
                    limpar_buffer();

                    switch (opcao_professor) {

                        case 0: {
                            sairProfessor = true;
                            break;
                        }

                        case 1: {
                            cadastrarProfessor(lista_professor, &qtdProfessor);
                            break;
                        }

                        case 2: {
                            listarProfessor(lista_professor, qtdProfessor);
                            break;
                        }

                        case 3: {
                            atualizarProfessor(lista_professor, qtdProfessor);
                            break;
                        }

                        case 4: {
                            excluirProfessor(lista_professor, &qtdProfessor);
                            break;
                        }

                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    }
                }

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