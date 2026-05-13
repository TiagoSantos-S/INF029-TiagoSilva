#define tam 3
#include <stdio.h>

void tabuleiro(char jogoDaVelha[tam][tam]) {
    printf("   1   2   3\n");
    printf("A  %c | %c | %c\n", jogoDaVelha[0][0], jogoDaVelha[0][1], jogoDaVelha[0][2]);
    printf("  ------------\n");
    printf("B  %c | %c | %c\n", jogoDaVelha[1][0], jogoDaVelha[1][1], jogoDaVelha[1][2]);
    printf("  ------------\n");
    printf("C  %c | %c | %c\n", jogoDaVelha[2][0], jogoDaVelha[2][1], jogoDaVelha[2][2]);
}

void preenchertabuleiro(char jogoDaVelha[tam][tam], int total_escolhas){

    char linha, coluna;

    while(1){

        printf("Onde deseja marcar? ");
        scanf(" %c%c", &linha, &coluna);

        if(linha == 'a') linha = 'A';
        if(linha == 'b') linha = 'B';
        if(linha == 'c') linha = 'C';

        if(linha < 'A' || linha > 'C' || coluna < '1' || coluna > '3'){
            printf("Entrada invalida\n");
            continue;
        }

        int l = linha - 'A';
        int c = coluna - '1';

        if(jogoDaVelha[l][c] != ' '){
            printf("Posicao ja ocupada!\n");
            continue;
        }

        jogoDaVelha[l][c] = (total_escolhas % 2 == 0) ? 'X' : 'O';

        break;
    }
}

int verificaganhador(char jogoDaVelha[tam][tam]) {
    int venceu = 0;

    /* VERIFICAR LINHAS */
    for (int icont = 0; icont < tam; icont++) {
        if (jogoDaVelha[icont][0] != ' ' &&
            jogoDaVelha[icont][0] == jogoDaVelha[icont][1] &&
            jogoDaVelha[icont][1] == jogoDaVelha[icont][2]) {

            if (jogoDaVelha[icont][0] == 'X') {
                venceu = 1;
            } else {
                venceu = 2;
            }
        }
    }

    /* VERIFICAR COLUNAS */
    for (int jcont = 0; jcont < tam; jcont++) {
        if (jogoDaVelha[0][jcont] != ' ' &&
            jogoDaVelha[0][jcont] == jogoDaVelha[1][jcont] &&
            jogoDaVelha[1][jcont] == jogoDaVelha[2][jcont]) {

            if (jogoDaVelha[0][jcont] == 'X') {
                venceu = 1;
            } else {
                venceu = 2;
            }
        }
    }

    /* DIAGONAL PRINCIPAL */
    if (jogoDaVelha[0][0] != ' ' &&
        jogoDaVelha[0][0] == jogoDaVelha[1][1] &&
        jogoDaVelha[1][1] == jogoDaVelha[2][2]) {

        if (jogoDaVelha[0][0] == 'X') {
            venceu = 1;
        } else {
            venceu = 2;
        }
    }

    /* DIAGONAL SECUNDARIA */
    if (jogoDaVelha[0][2] != ' ' &&
        jogoDaVelha[0][2] == jogoDaVelha[1][1] &&
        jogoDaVelha[1][1] == jogoDaVelha[2][0]) {

        if (jogoDaVelha[0][2] == 'X') {
            venceu = 1;
        } else {
            venceu = 2;
        }
    }

    return venceu;
}

int main() {

    int total_escolhas = 0;
    int venceu = 0;
    int valido;

    char jogoDaVelha[tam][tam] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    while (total_escolhas != 9 && venceu == 0) {

        tabuleiro(jogoDaVelha);

        preenchertabuleiro(jogoDaVelha, total_escolhas);

        total_escolhas++;

        venceu = verificaganhador(jogoDaVelha);
    }

    if (venceu == 1) {
        printf("---- Vencedor X ----");
    }
    else if (venceu == 2) {
        printf("---- Vencedor O ----");
    }
    else {
        printf("---- EMPATE ----");
    }

    return 0;
}