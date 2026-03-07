#include "disciplina.h"

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
    if (*qtdDisciplina >= TAM) {
        printf("Lista de Disciplinas cheia\n");
        return;
    }

    printf("== Cadastrar Disciplina ==\n");

    printf("Digite o codigo da Disciplina: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].codigo_disciplina);
    getchar(); 

    if (lista_disciplinas[*qtdDisciplina].codigo_disciplina <= 0) {
        printf("Codigo da disciplina Invalido\n");
        return;
    }

    printf("Informe o nome da disciplina: ");
    fgets(lista_disciplinas[*qtdDisciplina].nome_disciplina, MAX_NOME_DISCIPLINA, stdin);
    lista_disciplinas[*qtdDisciplina].nome_disciplina[strcspn(lista_disciplinas[*qtdDisciplina].nome_disciplina, "\n")] = '\0';

    printf("Informe o semestre: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].semestre);
    getchar();

    printf("Informe a matricula do professor: ");
    int matricula;
    scanf("%d", &matricula);
    getchar(); 

    int achou = -1;
    for (int i = 0; i < qtdProfessor; i++) {
        if (matricula == lista_professores[i].matricula) {
            achou = i;
            break;
        }
    }

    if (achou == -1) {
        printf("Erro: Professor com matricula %d nao encontrado!\n", matricula);
        return; 
    } 

    lista_disciplinas[*qtdDisciplina].professor = lista_professores[achou];
    
    (*qtdDisciplina)++;
    printf("Disciplina Cadastrada com Sucesso!\n");
}