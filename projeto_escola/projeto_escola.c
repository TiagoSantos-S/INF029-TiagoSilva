#include "escola.h"

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Aluno lista_aluno[TAM_ALUNOS];
    Professor lista_professor[TAM_PROFESSORES]; 
    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int sair = false;

while (!sair){
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
  
    scanf("%d", &opcao);

    switch(opcao){
      case 0:{
        sair = true;
        break;
      }
      case 1:{
        printf("Módulo Aluno\n");
        int sairAluno = false;
        int opcao_aluno;
        while(!sair){
          printf("0 - Voltar\n");
          printf("1 - Casdatrar Aluno\n");
          printf("2 - Listar Aluno\n");
          printf("3 - Atualizar Aluno\n");
          printf("4 - Excluir Aluno\n");
          scanf("%d", &opcao_aluno);

          switch(opcao_aluno){
            case 0:{
              sairAluno = true;
              break;
            }
            case 1:{
                char nome[256];
                printf("Casdatrar Aluno\n");
                if (qtdAluno == TAM_ALUNOS){
                    printf("Lista de alunos cheia\n"); 
                }else{
                    printf("Digite a matricula\n");

                int matricula;
                scanf("%d", &matricula);
                getchar();

                if(matricula < 0){
                  printf("Matrícula Inválida\n");
                  break;
                }

                lista_aluno[qtdAluno].matricula = matricula;

                printf("Informe o nome do aluno:\n");
                fgets(nome, 256, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                strcpy(lista_aluno[qtdAluno].nome, nome);

                lista_aluno[qtdAluno].ativo = true;
                qtdAluno++;
                printf("Cadastrado com sucesso\n");
              }
              
              break;
            }

            case 2:{
              printf("Listar Aluno\n");
              if (qtdAluno == 0){
                printf("Lista aluno vazia\n");
              } else{
                for (int i = 0; i < qtdAluno ; i++){
                  if (lista_aluno[i].ativo)
                    printf("Matrícula: %d\n", lista_aluno[i].matricula);
                    printf("Nome do(a) Aluno(a): %s\n", lista_aluno[i].nome);
                }  
              }
            }

            case 3:{
              printf("Atualizar Aluno\n");

              break;

            }

            case 4:{
              printf("Excluir Aluno\n");
              printf("Digite a matricula\n");

              int matricula;
              scanf("%d", &matricula);

              int achou = false;
              if (matricula < 0){
                printf("Matrícula Inválida\n");
              }else{
                for (int i = 0; i < qtdAluno; i++)
                {
                  if (matricula == lista_aluno[i].matricula){
                    lista_aluno[i].ativo = -1;
                    
                    for (int j = i; j < qtdAluno - 1; j++) {
                        lista_aluno[j].matricula = lista_aluno[j+1].matricula;
                        lista_aluno[j].sexo = lista_aluno[j+1].sexo;
                        lista_aluno[j].ativo = lista_aluno[j+1].ativo;
                        strcpy(lista_aluno[j].nome, lista_aluno[j+1].nome);
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
            default:{
              printf("Opção Inválida\n");  
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


