#include "disciplina.h"

// Criar lista de aluno para cada disciplina, para isso é necessário criar um vetor de alunos dentro da struct disciplina, 
// e um contador de alunos para cada disciplina. Dessa forma, é possível cadastrar vários alunos em uma mesma disciplina, 
// e também excluir alunos de uma disciplina.

// Cadastrar Disciplina //

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
    if (*qtdDisciplina >= TAM) {
        printf("Lista de Disciplinas cheia\n");
        return;
    }

    printf("\n========== Cadastrar Disciplina ==========\n");

    printf("\nDigite o codigo da Disciplina: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].codigo_disciplina);
    limpar_buffer();

    if (lista_disciplinas[*qtdDisciplina].codigo_disciplina <= 0) {
        printf("Codigo da disciplina Invalido\n");
        return;
    }

    printf("\nInforme o nome da disciplina: ");
    fgets(lista_disciplinas[*qtdDisciplina].nome_disciplina, MAX_NOME_DISCIPLINA, stdin);
    lista_disciplinas[*qtdDisciplina].nome_disciplina[strcspn(lista_disciplinas[*qtdDisciplina].nome_disciplina, "\n")] = '\0';

    printf("\nInforme a matricula do professor: ");
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

    printf("\nInforme o semestre: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].semestre);
    limpar_buffer();

    printf("\nInforme quantas vagas tem a Disciplina: ");
    scanf("%d", &lista_disciplinas[*qtdDisciplina].vagas);
    limpar_buffer();

    lista_disciplinas[*qtdDisciplina].professor = lista_professores[achou];
    
    (*qtdDisciplina)++;
    printf("\nDisciplina Cadastrada com Sucesso!\n");
}

// Listar Disciplinas sem dados dos alunos //

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

// Inserir aluno em uma disciplina //

void cadastrarAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno) {   
    printf("\n========== Cadastrar Aluno em uma Disciplina ==========\n");
    printf("\nInforme o codigo da disciplina que deseja cadastrar o aluno: \n");
    int codigo_disciplina = 0;
    scanf("%d", &codigo_disciplina);
    limpar_buffer();

    if (codigo_disciplina <= 0) {
        printf("\nCodigo da disciplina Invalido\n");
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
        printf("\nErro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    printf("\nInforme a matricula do aluno: \n");
    scanf("%d", &lista_aluno[*qtdAluno].matricula);
    limpar_buffer();

    int matricula = lista_aluno[*qtdAluno].matricula;

    if (matricula <= 0) {
        printf("\nMatricula do Aluno Invalido\n");
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
        printf("\nErro: Aluno com matricula %d não encontrado!\n", matricula);
        return; 
    }

    lista_disciplinas[*qtdDisciplina].alunos = lista_aluno[achou];
    lista_disciplinas[*qtdDisciplina].codigo_disciplina = codigo_disciplina;

    // (*qtdDisciplina)++; -- Dessa forma ele cria uma nova disciplna
    lista_disciplinas[achou].alunos = lista_aluno[achou]; // -- forma correta de adicionar o aluno na disciplina

    printf("\nAluno Cadastrado na Disciplina com Sucesso!\n");
    
}

// Excluir aluno de uma disciplina //

void excluirAlunosDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, aluno lista_aluno[], int *qtdAluno) {   
    printf("\n========== Excluir Aluno de uma Disciplina ==========\n");
    printf("\nDigite o codigo da disciplina: \n");
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
        printf("\nErro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    printf("\nInforme a matricula do aluno: \n");
    scanf("%d", &lista_aluno[*qtdAluno].matricula);
    limpar_buffer();

    int matricula = lista_aluno[*qtdAluno].matricula;

    if (matricula <= 0) {
        printf("\nMatricula do Aluno Invalido\n");
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
        printf("\nErro: Aluno com matricula %d não encontrado!\n", matricula);
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
        printf("\nAluno Excluido da Disciplina com Sucesso!\n");
    }

}

// Listar uma Disciplina com os dados dos alunos //

void listaDisciplinaComDadosAlunos(disciplina lista_disciplinas[], int qtdDisciplina, aluno lista_aluno[], int qtdAluno) {   

    if(qtdDisciplina == 0) {
        printf("Lista Disciplina vazia\n");
        return;
    }

    printf("\nDigite o codigo da disciplina: \n");
    int codigo_disciplina = 0;
    scanf("%d", &codigo_disciplina);
    limpar_buffer();

    if (codigo_disciplina <= 0) {
        printf("\nCodigo da disciplina Invalido\n");
        return;
    }

    int achou = -1;
    for(int i = 0; i < qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina){
            achou = i;
            break;
        }
    }

    if(achou == -1){
        printf("\nErro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    int contador = 1;

    if(lista_disciplinas[achou].codigo_disciplina == codigo_disciplina){
        printf("--------------- Disciplina: %d -------------\n", contador++);
        printf("Codigo da Disciplina: %d\n", lista_disciplinas[achou].codigo_disciplina);
        printf("Nome da Disciplina: %s\n", lista_disciplinas[achou].nome_disciplina);
        printf("Professor(a) da Disciplina: %s\n", lista_disciplinas[achou].professor.nome);
        for(int j = 0; j < qtdAluno; j++){
            if(lista_disciplinas[achou].alunos.matricula == lista_aluno[j].matricula){
                printf("Matrícula do Aluno: %d\n", lista_aluno[j].matricula);
            }
        }
        printf("--------------------------------------------\n");
    }

}

// Lista de Disciplinas que extrapolam 40 vagas //

void listaDisciplinasExtrapolam40Vagas(disciplina lista_disciplinas[], int qtdDisciplina, aluno lista_aluno[], int qtdAluno, professor lista_professor[], int qtdProfessor) {   
    if(qtdDisciplina == 0) {
        printf("Lista Disciplina vazia\n");
        return;
    }

    int contador = 1;

    for(int i = 0; i < qtdDisciplina; i++){
        if(lista_disciplinas[i].vagas > 40){
            printf("--------------- Disciplina: %d -------------\n", contador++);
            printf("Codigo da Disciplina: %d\n", lista_disciplinas[i].codigo_disciplina);
            printf("Nome da Disciplina: %s\n", lista_disciplinas[i].nome_disciplina);
            printf("Semestre da Disciplina: %d\n", lista_disciplinas[i].semestre);
            printf("Vagas da Disciplina: %d\n", lista_disciplinas[i].vagas);
            printf("Professor(a) da Disciplina: %s\n", lista_disciplinas[i].professor.nome);
            printf("--------------------------------------------\n");
        }
    }
}