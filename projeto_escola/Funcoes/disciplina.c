#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor listar_professor[], int *qtdProfessor) {
    
    char nome_disciplina[MAX_NOME_DISCIPLINA];
    char buffer[50];
    int achou = 0;

    printf("== Cadastrar Disciplina ==\n");

    if(*qtdDisciplina == TAM){
        printf("Lista de Disciplinas cheia\n");
        return;
    }

    printf("Digite o codigo da Disciplina: \n");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].codigo_disciplina);
    if(lista_disciplinas[*qtdDisciplina].codigo_disciplina == 0){
        printf("Codigo da disciplina Inválida\n");
        return;
    }

    printf("Informe o nome da disciplina:\n");
    fgets(nome_disciplina, sizeof(nome_disciplina), stdin);
    nome_disciplina[strcspn(nome_disciplina, "\n")] = '\0';

    printf("Informe o semestre da disciplina:\n");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].semestre);

    printf("Informe a matricula do professor da disciplina:\n");
    fgets(buffer, sizeof(buffer), stdin);
    int matricula = atoi(buffer);
    if(matricula < 0){
        printf("Matrícula inválida\n");
        return;
    }

    for(int i = 0; i < *qtdProfessor; i++){
        if(matricula == listar_professor[i].matricula){
            achou = 1;
        }
    }

    if(achou == 0){
        printf("Matricula do Professor não encontrada!");
    } 

    listar_professor[*qtdProfessor].matricula = matricula;

    (*qtdDisciplina)++;

    printf("Disciplina Cadastrada com Sucesso!");

}