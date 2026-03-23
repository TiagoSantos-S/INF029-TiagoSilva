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
        printf("Erro: Professor com matricula %d não encontrado!\n", matricula);
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

void listaDisciplinaSemDadosAlunos(disciplina lista_disciplinas[], int qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
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

void cadastrarAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno) {   
    printf("=== Cadastrar Aluno em uma Disciplina ===\n");
    printf("Informe o codigo da disciplina que deseja cadastrar o aluno: \n");
    int codigo_disciplina = 0;
    scanf("%d", &codigo_disciplina);
    limpar_buffer();

    if (codigo_disciplina <= 0) {
        printf("Codigo da disciplina Invalido\n");
        return;
    }

    int achou = -1;
    for(int i = 0; i < *qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina){
            achou = i;
            break;
        }
    }

    if(achou == -1){
        printf("Erro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    printf("Informe a matricula do aluno: \n");
    scanf("%d", &lista_aluno[*qtdAluno].matricula);
    limpar_buffer();

    int matricula = lista_aluno[*qtdAluno].matricula;

    if (matricula <= 0) {
        printf("Matricula do Aluno Invalido\n");
        return;
    }

    achou = -1;
    for(int i = 0; i < *qtdAluno; i++){
        if(matricula == lista_aluno[i].matricula){
            achou = i;
            break;
        }
    }

    if(achou == -1){
        printf("Erro: Aluno com matricula %d não encontrado!\n", matricula);
        return; 
    }

    lista_disciplinas[*qtdDisciplina].alunos = lista_aluno[achou];
    lista_disciplinas[*qtdDisciplina].codigo_disciplina = codigo_disciplina;

    (*qtdDisciplina)++;

    printf("Aluno Cadastrado na Disciplina com Sucesso!\n");
    
}

void excluirAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno) {   
    printf("=== Excluir Aluno de uma Disciplina ===\n");
    printf("Digite o codigo da disciplina: \n");
    int codigo_disciplina = 0;
    scanf("%d", &codigo_disciplina);
    limpar_buffer();

    if (codigo_disciplina <= 0) {
        printf("Codigo da disciplina Invalido\n");
        return;
    }

    int achou = -1;
    for(int i = 0; i < *qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina){
            achou = i;
            break;
        }
    }

    if(achou == -1){
        printf("Erro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    printf("Informe a matricula do aluno: \n");
    scanf("%d", &lista_aluno[*qtdAluno].matricula);
    limpar_buffer();

    int matricula = lista_aluno[*qtdAluno].matricula;

    if (matricula <= 0) {
        printf("Matricula do Aluno Invalido\n");
        return;
    }

    achou = -1;
    for(int i = 0; i < *qtdAluno; i++){
        if(matricula == lista_aluno[i].matricula){
            achou = i;
            break;
        }
    }

    if(achou == -1){
        printf("Erro: Aluno com matricula %d não encontrado!\n", matricula);
        return; 
    }

    achou = 0;
    for(int i = 0; i < *qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina && matricula == lista_disciplinas[i].alunos.matricula){

            for(int j = i; j < *qtdAluno - 1; j++){
                lista_aluno[j]= lista_aluno[j + 1];
            }

            (*qtdAluno)--;
            achou = 1;
            break;
        }
    }

    if(achou){
        printf("Aluno Excluido da Disciplina com Sucesso!");
    }

}

void listaDisciplinaComDadosAlunos(disciplina lista_disciplinas[], int qtdDisciplina, aluno lista_aluno[], int qtdAluno) {   

}

void disciplina40vagas(disciplina lista_disciplinas[], int qtdDisciplina, aluno lista_aluno[], int qtdAluno, professor lista_professor[], int qtdProfessor) {   

}