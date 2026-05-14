#define qtd_barcos 5
#define tam_tabuleiro 9
#include <stdio.h>

void tabuleiro1 (char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro]) = {

    printf("    1    2    3    4    5    6   7    8    9 \n");
    printf("A  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[0][0], tabuleiro_jogador1[0][1], tabuleiro_jogador1[0][2], tabuleiro_jogador1[0][3], tabuleiro_jogador1[0][4], tabuleiro_jogador1[0][5], tabuleiro_jogador1[0][6], tabuleiro_jogador1[0][7], tabuleiro_jogador1[0][8], tabuleiro_jogador1[0][9]);
    printf("  -------------------------------------------------\n");
    printf("B  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[1][0], tabuleiro_jogador1[1][1], tabuleiro_jogador1[1][2], tabuleiro_jogador1[1][3], tabuleiro_jogador1[1][4], tabuleiro_jogador1[1][5], tabuleiro_jogador1[1][6], tabuleiro_jogador1[1][7], tabuleiro_jogador1[1][8], tabuleiro_jogador1[1][9]);
    printf("  -------------------------------------------------\n");
    printf("C  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[2][0], tabuleiro_jogador1[2][1], tabuleiro_jogador1[2][2], tabuleiro_jogador1[2][3], tabuleiro_jogador1[2][4], tabuleiro_jogador1[2][5], tabuleiro_jogador1[2][6], tabuleiro_jogador1[2][7], tabuleiro_jogador1[2][8], tabuleiro_jogador1[2][9]);
    printf("  -------------------------------------------------\n");
    printf("D  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[3][0], tabuleiro_jogador1[3][1], tabuleiro_jogador1[3][2], tabuleiro_jogador1[3][3], tabuleiro_jogador1[3][4], tabuleiro_jogador1[3][5], tabuleiro_jogador1[3][6], tabuleiro_jogador1[3][7], tabuleiro_jogador1[3][8], tabuleiro_jogador1[3][9]);
    printf("  -------------------------------------------------\n");
    printf("F  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[4][0], tabuleiro_jogador1[4][1], tabuleiro_jogador1[4][2], tabuleiro_jogador1[4][3], tabuleiro_jogador1[4][4], tabuleiro_jogador1[4][5], tabuleiro_jogador1[4][6], tabuleiro_jogador1[4][7], tabuleiro_jogador1[4][8], tabuleiro_jogador1[4][9]);
    printf("  -------------------------------------------------\n");
    printf("G  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[5][0], tabuleiro_jogador1[5][1], tabuleiro_jogador1[5][2], tabuleiro_jogador1[5][3], tabuleiro_jogador1[5][4], tabuleiro_jogador1[5][5], tabuleiro_jogador1[5][6], tabuleiro_jogador1[5][7], tabuleiro_jogador1[5][8], tabuleiro_jogador1[5][9]);
    printf("  -------------------------------------------------\n");
    printf("H  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[6][0], tabuleiro_jogador1[6][1], tabuleiro_jogador1[6][2], tabuleiro_jogador1[6][3], tabuleiro_jogador1[6][4], tabuleiro_jogador1[6][5], tabuleiro_jogador1[6][6], tabuleiro_jogador1[6][7], tabuleiro_jogador1[6][8], tabuleiro_jogador1[6][9]);
    printf("  -------------------------------------------------\n");
    printf("I  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[7][0], tabuleiro_jogador1[7][1], tabuleiro_jogador1[7][2], tabuleiro_jogador1[7][3], tabuleiro_jogador1[7][4], tabuleiro_jogador1[7][5], tabuleiro_jogador1[7][6], tabuleiro_jogador1[7][7], tabuleiro_jogador1[7][8], tabuleiro_jogador1[7][9]);
    printf("  -------------------------------------------------\n");
    printf("J  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[8][0], tabuleiro_jogador1[8][1], tabuleiro_jogador1[8][2], tabuleiro_jogador1[8][3], tabuleiro_jogador1[8][4], tabuleiro_jogador1[8][5], tabuleiro_jogador1[8][6], tabuleiro_jogador1[8][7], tabuleiro_jogador1[8][8], tabuleiro_jogador1[8][9]);
    printf("  -------------------------------------------------\n");
    printf("K  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador1[9][0], tabuleiro_jogador1[9][1], tabuleiro_jogador1[9][2], tabuleiro_jogador1[9][3], tabuleiro_jogador1[9][4], tabuleiro_jogador1[9][5], tabuleiro_jogador1[9][6], tabuleiro_jogador1[9][7], tabuleiro_jogador1[9][8], tabuleiro_jogador1[9][9]);

}

void tabuleiro2 (char tabuleiro_jogador2[tam_tabuleiro][tam_tabuleiro]) = {

    printf("    1    2    3    4    5    6   7    8    9 \n");
    printf("A  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[0][0], tabuleiro_jogador2[0][1], tabuleiro_jogador2[0][2], tabuleiro_jogador2[0][3], tabuleiro_jogador2[0][4], tabuleiro_jogador2[0][5], tabuleiro_jogador2[0][6], tabuleiro_jogador2[0][7], tabuleiro_jogador2[0][8], tabuleiro_jogador2[0][9]);
    printf("  -------------------------------------------------\n");
    printf("B  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[1][0], tabuleiro_jogador2[1][1], tabuleiro_jogador2[1][2], tabuleiro_jogador2[1][3], tabuleiro_jogador2[1][4], tabuleiro_jogador2[1][5], tabuleiro_jogador2[1][6], tabuleiro_jogador2[1][7], tabuleiro_jogador2[1][8], tabuleiro_jogador2[1][9]);
    printf("  -------------------------------------------------\n");
    printf("C  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[2][0], tabuleiro_jogador2[2][1], tabuleiro_jogador2[2][2], tabuleiro_jogador2[2][3], tabuleiro_jogador2[2][4], tabuleiro_jogador2[2][5], tabuleiro_jogador2[2][6], tabuleiro_jogador2[2][7], tabuleiro_jogador2[2][8], tabuleiro_jogador2[2][9]);
    printf("  -------------------------------------------------\n");
    printf("D  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[3][0], tabuleiro_jogador2[3][1], tabuleiro_jogador2[3][2], tabuleiro_jogador2[3][3], tabuleiro_jogador2[3][4], tabuleiro_jogador2[3][5], tabuleiro_jogador2[3][6], tabuleiro_jogador2[3][7], tabuleiro_jogador2[3][8], tabuleiro_jogador2[3][9]);
    printf("  -------------------------------------------------\n");
    printf("F  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[4][0], tabuleiro_jogador2[4][1], tabuleiro_jogador2[4][2], tabuleiro_jogador2[4][3], tabuleiro_jogador2[4][4], tabuleiro_jogador2[4][5], tabuleiro_jogador2[4][6], tabuleiro_jogador2[4][7], tabuleiro_jogador2[4][8], tabuleiro_jogador2[4][9]);
    printf("  -------------------------------------------------\n");
    printf("G  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[5][0], tabuleiro_jogador2[5][1], tabuleiro_jogador2[5][2], tabuleiro_jogador2[5][3], tabuleiro_jogador2[5][4], tabuleiro_jogador2[5][5], tabuleiro_jogador2[5][6], tabuleiro_jogador2[5][7], tabuleiro_jogador2[5][8], tabuleiro_jogador2[5][9]);
    printf("  -------------------------------------------------\n");
    printf("H  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[6][0], tabuleiro_jogador2[6][1], tabuleiro_jogador2[6][2], tabuleiro_jogador2[6][3], tabuleiro_jogador2[6][4], tabuleiro_jogador2[6][5], tabuleiro_jogador2[6][6], tabuleiro_jogador2[6][7], tabuleiro_jogador2[6][8], tabuleiro_jogador2[6][9]);
    printf("  -------------------------------------------------\n");
    printf("I  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[7][0], tabuleiro_jogador2[7][1], tabuleiro_jogador2[7][2], tabuleiro_jogador2[7][3], tabuleiro_jogador2[7][4], tabuleiro_jogador2[7][5], tabuleiro_jogador2[7][6], tabuleiro_jogador2[7][7], tabuleiro_jogador2[7][8], tabuleiro_jogador2[7][9]);
    printf("  -------------------------------------------------\n");
    printf("J  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[8][0], tabuleiro_jogador2[8][1], tabuleiro_jogador2[8][2], tabuleiro_jogador2[8][3], tabuleiro_jogador2[8][4], tabuleiro_jogador2[8][5], tabuleiro_jogador2[8][6], tabuleiro_jogador2[8][7], tabuleiro_jogador2[8][8], tabuleiro_jogador2[8][9]);
    printf("  -------------------------------------------------\n");
    printf("K  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", tabuleiro_jogador2[9][0], tabuleiro_jogador2[9][1], tabuleiro_jogador2[9][2], tabuleiro_jogador2[9][3], tabuleiro_jogador2[9][4], tabuleiro_jogador2[9][5], tabuleiro_jogador2[9][6], tabuleiro_jogador2[9][7], tabuleiro_jogador2[9][8], tabuleiro_jogador2[9][9]);

}

void inserirbarco1(char tabuleiro1[tam_tabuleiro][tam_tabuleiro], int barcos1){

    char linha, coluna;
    int direção;
    int tam_barcos;

    while(qtd_barcos != barcos1){

        printf("Onde deseja por o barco? ");
        scanf(" %c%c", &linha, &coluna);

        if(linha == 'a') linha = 'A';
        if(linha == 'b') linha = 'B';
        if(linha == 'c') linha = 'C';
        if(linha == 'd') linha = 'D';
        if(linha == 'e') linha = 'E';
        if(linha == 'f') linha = 'F';
        if(linha == 'g') linha = 'G';
        if(linha == 'h') linha = 'H';
        if(linha == 'i') linha = 'I';
        if(linha == 'j') linha = 'J';
        if(linha == 'k') linha = 'K';

        int l = linha - 'A';
        int c = coluna - 'A';

        printf("Para qual direção ?\n Para cima digite: 1\n Para baixo: digite 2\n Para esquerda: digite 3\n Para direita: digite 4\n");
        scanf(" %d", &direção);

        printf("informe o tamanho do barco, tamanhos disponiveis 4 - 3 - 1 - 1 - 1");
        scanf("%d", &tam_barcos);

        if(direção < 1 || direção > 4){
            printf("direção invalida");
            break;
        }

        //Cima//
        if(direção == 1){
            if()
            for(int icont = linha; icont < tam_tabuleiro; icont++){
                for(int jcont = coluna; icont < tam_tabuleiro; jcont++){
                    
                }
            }
            //BAIXO//
        }else if(direção == 2){

        }
        //Esquerda//
        else if(direção == 3){
            
        }
        //Direita//
        else if(direção == 4){

        }
        barcos1++;
    }
}

main(){
    int barcos1 = 0;
}