#include "Funcoes/disciplina.h"
#include "Funcoes/include.h"
#include "Funcoes/aluno.h"
#include "Funcoes/professor.h"

// Run : gcc projeto_escola.c Funcoes/*.c -I Funcoes -o projeto_escola && ./projeto_escola 

int main(void) {
    aluno lista_aluno[TAM] = {0};
    professor lista_professor[TAM] = {0};
    disciplina lista_disciplina[TAM] = {0};

    int sequenciaMatricula = 1;
    int sequenciaMatriculaProfessor = 1;
    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int qtdDisciplina = 0;
    int sair = false;

    while (!sair) {
        printf("\n========== Projeto Escola ==========\n");
        printf("\n 0 - Sair\n");
        printf(" 1 - Módulo Aluno\n");
        printf(" 2 - Módulo Professor\n");
        printf(" 3 - Módulo Disciplina\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {

            case 0: {
                sair = true;
                break;
            }

            case 1: {
                printf("\n********** Módulo Aluno **********\n");

                int sairAluno = false;
                int opcao_aluno;

                while (!sairAluno) {
                    printf("\n 0 - Voltar\n");
                    printf(" 1 - Cadastrar Aluno\n");
                    printf(" 2 - Listar Aluno\n");
                    printf(" 3 - Atualizar Aluno\n");
                    printf(" 4 - Excluir Aluno\n");

                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcao_aluno);
                    limpar_buffer();

                    switch (opcao_aluno) {

                        case 0: {
                            sairAluno = true;
                            break;
                        }

                        case 1: {
                          cadastrarAluno(lista_aluno, &qtdAluno, &sequenciaMatricula);
                          break;
                        }

                        case 2: {
                            menuListagem();
                            int opcao;
                            scanf("%d", &opcao);
                            limpar_buffer();
                            listarAlunos(lista_aluno, qtdAluno, opcao);
                            break;
                        }

                        case 3: {
                            atualizarAluno(lista_aluno, qtdAluno);
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

            case 2: {
                printf("\n********** Módulo Professor **********\n");

                int sairProfessor = false;
                int opcao_professor;

                while (!sairProfessor) {
                    printf("\n 0 - Voltar\n");
                    printf(" 1 - Cadastrar Professor\n");
                    printf(" 2 - Listar Professor\n");
                    printf(" 3 - Atualizar Professor\n");
                    printf(" 4 - Excluir Professor\n");

                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcao_professor);
                    limpar_buffer();

                    switch (opcao_professor) {

                        case 0: {
                            sairProfessor = true;
                            break;
                        }

                        case 1: {
                            cadastrarProfessor(lista_professor, &qtdProfessor, &sequenciaMatriculaProfessor);
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
            }

            case 3: {
                printf("\n********** Módulo Disciplina **********\n");

                int sairDisciplina = false;
                int opcao_disciplina;

                while (!sairDisciplina) {
                    printf("\n 0 - Voltar\n");
                    printf(" 1 - Cadastrar Disciplina\n");
                    printf(" 2 - Listar Disciplinas\n");
                    printf(" 3 - Inserir aluno em uma disciplina\n");
                    printf(" 4 - Excluir aluno de uma disciplina\n");
                    printf(" 5 - Listar uma Disciplina com os dados dos alunos\n");
                    printf(" 6 - Lista de Disciplinas que extrapolam mais de 40 vagas\n");

                    printf("\nDigite a opção desejada: ");
                    if (scanf("%d", &opcao_disciplina) != 1) {
                        limpar_buffer();
                        continue;
                    }
                    limpar_buffer();

                    switch (opcao_disciplina) {

                        case 0: {
                            sairDisciplina = true;
                            break;
                        }

                        case 1: {
                          cadastrarDisciplina(lista_disciplina, &qtdDisciplina, lista_professor, qtdProfessor);
                          break;
                        }

                        case 2: {
                          listaDisciplinaSemDadosAlunos(lista_disciplina, qtdDisciplina, lista_professor, qtdProfessor);
                          break;
                        }

                        case 3: {
                          cadastrarAlunosDisciplina(lista_disciplina, &qtdDisciplina, lista_aluno, &qtdAluno);
                          break;
                        }

                        case 4: {
                          excluirAlunosDisciplina(lista_disciplina, &qtdDisciplina, lista_aluno, &qtdAluno);
                          break;
                        }

                        case 5: {
                          listaDisciplinaComDadosAlunos(lista_disciplina, qtdDisciplina, lista_aluno, qtdAluno);
                          break;
                        }

                        case 6: {
                          listaDisciplinasExtrapolam40Vagas(lista_disciplina, qtdDisciplina, lista_aluno, qtdAluno, lista_professor, qtdProfessor);
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

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;

}
