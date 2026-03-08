#include "disciplina.h"

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
    if (*qtdDisciplina >= TAM) {
        printf("Lista de Disciplinas cheia\n");
        return;
    }

    printf("== Cadastrar Disciplina ==\n");

    printf("Digite o codigo da Disciplina: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].codigo_disciplina);
    limpar_buffer();

    if (lista_disciplinas[*qtdDisciplina].codigo_disciplina <= 0) {
        printf("Codigo da disciplina Invalido\n");
        return;
    }

    printf("Informe o nome da disciplina: ");
    fgets(lista_disciplinas[*qtdDisciplina].nome_disciplina, MAX_NOME_DISCIPLINA, stdin);
    lista_disciplinas[*qtdDisciplina].nome_disciplina[strcspn(lista_disciplinas[*qtdDisciplina].nome_disciplina, "\n")] = '\0';

    printf("Informe a matricula do professor: ");
    int matricula;
    scanf("%d", &matricula);
    limpar_buffer();

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

    printf("Informe o semestre: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].semestre);
    limpar_buffer();

    printf("Informe quantas vagas tem a Disciplina: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].vagas);
    limpar_buffer();

    lista_disciplinas[*qtdDisciplina].professor = lista_professores[achou];
    
    (*qtdDisciplina)++;
    printf("\nDisciplina Cadastrada com Sucesso!\n");
}

void listarDisciplinaSemAlunos(disciplina lista_disciplinas[], int qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
    if(qtdDisciplina == 0) {
        printf("Lista Disciplina vazia\n");
        return;
    }

    disciplina copia[qtdDisciplina];

    for(int i = 0; i < qtdDisciplina; i++){
        copia[i] = lista_disciplinas[i];
    }

    int contador = 1;

    for(int i = 0; i < qtdDisciplina; i++){
        printf("--------------- Disciplina: %d -------------\n", contador++);
        printf("Codigo da Disciplina: %d\n", copia[i].codigo_disciplina);
        printf("Nome da Disciplina: %s\n", copia[i].nome_disciplina);
        printf("Semestre da Disciplina: %d\n", copia[i].semestre);
        printf("Vagas da Disciplina: %d\n", copia[i].vagas);
        printf("Professor(a) da Disciplina: %s\n", copia[i].professor.nome);
        printf("--------------------------------------------\n");
    }

}