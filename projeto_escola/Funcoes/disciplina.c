#include "disciplina.h"

// Cadastrar Disciplina //

void cadastrarDisciplina(disciplina lista_disciplinas[], int *qtdDisciplina, professor lista_professores[], int qtdProfessor) {
    
    if (*qtdDisciplina == TAM) {
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

    // --- LÓGICA PARA SALVAR NO ARQUIVO ---
    FILE *arquivo = fopen("disciplinas.txt", "a"); // "a" de append (anexar)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de disciplinas!\n");
    } else {
        fprintf(arquivo, "Código: %d | Nome: %s | Semestre: %d | Professor: %s\n",
                lista_disciplinas[*qtdDisciplina - 1].codigo_disciplina,
                lista_disciplinas[*qtdDisciplina - 1].nome_disciplina,
                lista_disciplinas[*qtdDisciplina - 1].semestre,
                lista_disciplinas[*qtdDisciplina - 1].professor.nome);
        
        fclose(arquivo); 
        printf("Dados salvos em disciplinas.txt\n");
    }

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

    int idx_disc = -1;
    for(int i = 0; i < *qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina){
            idx_disc = i;
            break;
        }
    }

    if(idx_disc == -1){
        printf("\nErro: Disciplina com matricula %d não encontrado!\n", codigo_disciplina);
        return; 
    }

    if (lista_disciplinas[idx_disc].qtd_alunos >= lista_disciplinas[idx_disc].vagas) {
        printf("Erro: Disciplina sem vagas disponiveis!\n");
        return;
}

    printf("\nInforme a matricula do aluno: \n");
    int matricula_aux; 
    scanf("%d", &matricula_aux); 
    limpar_buffer();

    int idx_aluno = -1;
    for(int i = 0; i < *qtdAluno; i++){
        if(matricula_aux == lista_aluno[i].matricula){
            idx_aluno = i;
            break;
        }
    }

    if(idx_aluno == -1){
        printf("Erro: Aluno não encontrado!\n");
        return;
    }

    int pos = lista_disciplinas[idx_disc].qtd_alunos;

    lista_disciplinas[*qtdDisciplina].codigo_disciplina = codigo_disciplina;
    lista_disciplinas[idx_disc].alunos[pos] = lista_aluno[idx_aluno];
    lista_disciplinas[idx_disc].qtd_alunos++;
    

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
    int matricula_aux; 
    scanf("%d", &matricula_aux); 
    limpar_buffer();

    int idx_aluno = -1;
    for(int i = 0; i < *qtdAluno; i++){
        if(matricula_aux == lista_aluno[i].matricula){
            idx_aluno = i;
            break;
        }
    }

    if(idx_aluno == -1){
        printf("Erro: Aluno não encontrado!\n");
        return;
    }

    int id_disc = -1;
    for(int i = 0; i < *qtdDisciplina; i++){
        if(codigo_disciplina == lista_disciplinas[i].codigo_disciplina){
            id_disc = i;
            break;
        }
    }

    // 2. Agora vamos procurar o aluno DENTRO dessa disciplina específica
    int achou_aluno_na_disc = -1;
    for(int j = 0; j < lista_disciplinas[id_disc].qtd_alunos; j++) {
        if(lista_disciplinas[id_disc].alunos[j].matricula == matricula_aux) {
            achou_aluno_na_disc = j;
            break;
        }
    }

    // 3. Se achou, removemos "puxando" os próximos para a esquerda
    if(achou_aluno_na_disc != -1) {
        for(int k = achou_aluno_na_disc; k < lista_disciplinas[id_disc].qtd_alunos - 1; k++) {
            lista_disciplinas[id_disc].alunos[k] = lista_disciplinas[id_disc].alunos[k+1];
        }
        // 4. Diminui a quantidade de alunos cadastrados NESSA disciplina
        lista_disciplinas[id_disc].qtd_alunos--;
        printf("\nAluno Excluido da Disciplina com Sucesso!\n");
    } else {
        printf("\nErro: Este aluno não está matriculado nesta disciplina!\n");
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

    printf("--------------- Dados da Disciplina -------------\n");
    printf("Codigo da Disciplina: %d\n", lista_disciplinas[achou].codigo_disciplina);
    printf("Nome da Disciplina: %s\n", lista_disciplinas[achou].nome_disciplina);
    printf("Professor(a): %s\n", lista_disciplinas[achou].professor.nome);
    
    printf("\nAlunos Matriculados:\n");

    if (lista_disciplinas[achou].qtd_alunos == 0) {
        printf("Nenhum aluno matriculado nesta disciplina.\n");
    } else {
        for(int j = 0; j < lista_disciplinas[achou].qtd_alunos; j++) {
            printf("  > Aluno: %s (Matrícula: %d)\n", 
                    lista_disciplinas[achou].alunos[j].nome, 
                    lista_disciplinas[achou].alunos[j].matricula);
        }
    }
    printf("--------------------------------------------\n");

}

// Lista de Disciplinas que extrapolam 40 vagas //

void listaDisciplinasExtrapolam40Vagas(disciplina lista_disciplinas[], int qtdDisciplina, professor lista_professor[], int qtdProfessor) {   
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