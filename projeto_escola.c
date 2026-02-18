#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define tam_alunos 3
#define tam_professores 3

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int opcao;

    printf("Projeto Escola\n");
    printf("0 - sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    scanf("%d", &opcao);

    switch (opcao){
    case 0:
        printf("Saindo do programa...\n");
        break;
    case 1:
        printf("Opção Aluno selecionada.\n");
        break;
    case 2:
        printf("Opção Professor selecionada.\n");
        break;
    case 3:
        printf("Opção Disciplina selecionada.\n");
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
