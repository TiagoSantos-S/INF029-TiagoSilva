#define qtd_barcos 1
#define tam_tabuleiro 10
#include <stdio.h>

void iniciarTab(char tabuleiro1[tam_tabuleiro][tam_tabuleiro]){
    for(int i = 0; i < tam_tabuleiro; i++){
        for(int j = 0; j < tam_tabuleiro; j++){
            tabuleiro1[i][j] = ' ';
        }
    }
}

void tabuleiro1 (char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro]){

    printf("    1   2   3   4   5   6   7   8   9   10\n");
    printf("A  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[0][0], tabuleiro_jogador1[0][1], tabuleiro_jogador1[0][2], tabuleiro_jogador1[0][3], tabuleiro_jogador1[0][4], tabuleiro_jogador1[0][5], tabuleiro_jogador1[0][6], tabuleiro_jogador1[0][7], tabuleiro_jogador1[0][8], tabuleiro_jogador1[0][9]);
    printf("  ----------------------------------------\n");
    printf("B  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[1][0], tabuleiro_jogador1[1][1], tabuleiro_jogador1[1][2], tabuleiro_jogador1[1][3], tabuleiro_jogador1[1][4], tabuleiro_jogador1[1][5], tabuleiro_jogador1[1][6], tabuleiro_jogador1[1][7], tabuleiro_jogador1[1][8], tabuleiro_jogador1[1][9]);
    printf("  ----------------------------------------\n");
    printf("C  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[2][0], tabuleiro_jogador1[2][1], tabuleiro_jogador1[2][2], tabuleiro_jogador1[2][3], tabuleiro_jogador1[2][4], tabuleiro_jogador1[2][5], tabuleiro_jogador1[2][6], tabuleiro_jogador1[2][7], tabuleiro_jogador1[2][8], tabuleiro_jogador1[2][9]);
    printf("  ----------------------------------------\n");
    printf("D  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[3][0], tabuleiro_jogador1[3][1], tabuleiro_jogador1[3][2], tabuleiro_jogador1[3][3], tabuleiro_jogador1[3][4], tabuleiro_jogador1[3][5], tabuleiro_jogador1[3][6], tabuleiro_jogador1[3][7], tabuleiro_jogador1[3][8], tabuleiro_jogador1[3][9]);
    printf("  ----------------------------------------\n");
    printf("E  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[4][0], tabuleiro_jogador1[4][1], tabuleiro_jogador1[4][2], tabuleiro_jogador1[4][3], tabuleiro_jogador1[4][4], tabuleiro_jogador1[4][5], tabuleiro_jogador1[4][6], tabuleiro_jogador1[4][7], tabuleiro_jogador1[4][8], tabuleiro_jogador1[4][9]);
    printf("  ----------------------------------------\n");
    printf("F  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[5][0], tabuleiro_jogador1[5][1], tabuleiro_jogador1[5][2], tabuleiro_jogador1[5][3], tabuleiro_jogador1[5][4], tabuleiro_jogador1[5][5], tabuleiro_jogador1[5][6], tabuleiro_jogador1[5][7], tabuleiro_jogador1[5][8], tabuleiro_jogador1[5][9]);
    printf("  ----------------------------------------\n");
    printf("G  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[6][0], tabuleiro_jogador1[6][1], tabuleiro_jogador1[6][2], tabuleiro_jogador1[6][3], tabuleiro_jogador1[6][4], tabuleiro_jogador1[6][5], tabuleiro_jogador1[6][6], tabuleiro_jogador1[6][7], tabuleiro_jogador1[6][8], tabuleiro_jogador1[6][9]);
    printf("  ----------------------------------------\n");
    printf("H  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[7][0], tabuleiro_jogador1[7][1], tabuleiro_jogador1[7][2], tabuleiro_jogador1[7][3], tabuleiro_jogador1[7][4], tabuleiro_jogador1[7][5], tabuleiro_jogador1[7][6], tabuleiro_jogador1[7][7], tabuleiro_jogador1[7][8], tabuleiro_jogador1[7][9]);
    printf("  ----------------------------------------\n");
    printf("I  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[8][0], tabuleiro_jogador1[8][1], tabuleiro_jogador1[8][2], tabuleiro_jogador1[8][3], tabuleiro_jogador1[8][4], tabuleiro_jogador1[8][5], tabuleiro_jogador1[8][6], tabuleiro_jogador1[8][7], tabuleiro_jogador1[8][8], tabuleiro_jogador1[8][9]);
    printf("  ----------------------------------------\n");
    printf("J  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador1[9][0], tabuleiro_jogador1[9][1], tabuleiro_jogador1[9][2], tabuleiro_jogador1[9][3], tabuleiro_jogador1[9][4], tabuleiro_jogador1[9][5], tabuleiro_jogador1[9][6], tabuleiro_jogador1[9][7], tabuleiro_jogador1[9][8], tabuleiro_jogador1[9][9]);

}

void tabuleiro2 (char tabuleiro_jogador2[tam_tabuleiro][tam_tabuleiro]){

    printf("    1   2   3   4   5   6   7   8   9   10\n");
    printf("A  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[0][0], tabuleiro_jogador2[0][1], tabuleiro_jogador2[0][2], tabuleiro_jogador2[0][3], tabuleiro_jogador2[0][4], tabuleiro_jogador2[0][5], tabuleiro_jogador2[0][6], tabuleiro_jogador2[0][7], tabuleiro_jogador2[0][8], tabuleiro_jogador2[0][9]);
    printf("  ----------------------------------------\n");
    printf("B  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[1][0], tabuleiro_jogador2[1][1], tabuleiro_jogador2[1][2], tabuleiro_jogador2[1][3], tabuleiro_jogador2[1][4], tabuleiro_jogador2[1][5], tabuleiro_jogador2[1][6], tabuleiro_jogador2[1][7], tabuleiro_jogador2[1][8], tabuleiro_jogador2[1][9]);
    printf("  ----------------------------------------\n");
    printf("C  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[2][0], tabuleiro_jogador2[2][1], tabuleiro_jogador2[2][2], tabuleiro_jogador2[2][3], tabuleiro_jogador2[2][4], tabuleiro_jogador2[2][5], tabuleiro_jogador2[2][6], tabuleiro_jogador2[2][7], tabuleiro_jogador2[2][8], tabuleiro_jogador2[2][9]);
    printf("  ----------------------------------------\n");
    printf("D  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[3][0], tabuleiro_jogador2[3][1], tabuleiro_jogador2[3][2], tabuleiro_jogador2[3][3], tabuleiro_jogador2[3][4], tabuleiro_jogador2[3][5], tabuleiro_jogador2[3][6], tabuleiro_jogador2[3][7], tabuleiro_jogador2[3][8], tabuleiro_jogador2[3][9]);
    printf("  ----------------------------------------\n");
    printf("E  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[4][0], tabuleiro_jogador2[4][1], tabuleiro_jogador2[4][2], tabuleiro_jogador2[4][3], tabuleiro_jogador2[4][4], tabuleiro_jogador2[4][5], tabuleiro_jogador2[4][6], tabuleiro_jogador2[4][7], tabuleiro_jogador2[4][8], tabuleiro_jogador2[4][9]);
    printf("  ----------------------------------------\n");
    printf("F  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[5][0], tabuleiro_jogador2[5][1], tabuleiro_jogador2[5][2], tabuleiro_jogador2[5][3], tabuleiro_jogador2[5][4], tabuleiro_jogador2[5][5], tabuleiro_jogador2[5][6], tabuleiro_jogador2[5][7], tabuleiro_jogador2[5][8], tabuleiro_jogador2[5][9]);
    printf("  ----------------------------------------\n");
    printf("G  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[6][0], tabuleiro_jogador2[6][1], tabuleiro_jogador2[6][2], tabuleiro_jogador2[6][3], tabuleiro_jogador2[6][4], tabuleiro_jogador2[6][5], tabuleiro_jogador2[6][6], tabuleiro_jogador2[6][7], tabuleiro_jogador2[6][8], tabuleiro_jogador2[6][9]);
    printf("  ----------------------------------------\n");
    printf("H  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[7][0], tabuleiro_jogador2[7][1], tabuleiro_jogador2[7][2], tabuleiro_jogador2[7][3], tabuleiro_jogador2[7][4], tabuleiro_jogador2[7][5], tabuleiro_jogador2[7][6], tabuleiro_jogador2[7][7], tabuleiro_jogador2[7][8], tabuleiro_jogador2[7][9]);
    printf("  ----------------------------------------\n");
    printf("I  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[8][0], tabuleiro_jogador2[8][1], tabuleiro_jogador2[8][2], tabuleiro_jogador2[8][3], tabuleiro_jogador2[8][4], tabuleiro_jogador2[8][5], tabuleiro_jogador2[8][6], tabuleiro_jogador2[8][7], tabuleiro_jogador2[8][8], tabuleiro_jogador2[8][9]);
    printf("  ----------------------------------------\n");
    printf("J  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]\n", tabuleiro_jogador2[9][0], tabuleiro_jogador2[9][1], tabuleiro_jogador2[9][2], tabuleiro_jogador2[9][3], tabuleiro_jogador2[9][4], tabuleiro_jogador2[9][5], tabuleiro_jogador2[9][6], tabuleiro_jogador2[9][7], tabuleiro_jogador2[9][8], tabuleiro_jogador2[9][9]);
}

int cima(char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro], int l, int c, int tam_barco1){
    if(l - tam_barco1 + 1 < 0) return 0;
    for(int icont = l; icont > l - tam_barco1; icont--){
        tabuleiro_jogador1[icont][c] = 'N';
    }
    return 1;       
}

int baixo(char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro], int l, int c, int tam_barco1){
    if(l+tam_barco1 > tam_tabuleiro) return 0;
    for(int icont = l; icont < l+tam_barco1; icont++){
        tabuleiro_jogador1[icont][c] = 'N';
    }
    return 1;       
}

int esquerda(char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro], int l, int c, int tam_barco1){
    if(c - tam_barco1 + 1 < 0) return 0;
    for(int icont = c; icont > c - tam_barco1; icont--){
        tabuleiro_jogador1[l][icont] = 'N';
    }
    return 1;       
}

int direita(char tabuleiro_jogador1[tam_tabuleiro][tam_tabuleiro], int l, int c, int tam_barco1){
    if(c+tam_barco1 > tam_tabuleiro) return 0;
    for(int icont = c; icont < c+tam_barco1; icont++){
        tabuleiro_jogador1[l][icont] = 'N';
    }
    return 1;       
}

void inserirbarco1(char tabuleiro1[tam_tabuleiro][tam_tabuleiro], int totalbarcos, int *qtd_totalbarcos1){
    char linha;
    int coluna;
    int direcao;
    int tam_barcos;
    
    while(totalbarcos != qtd_barcos){
        printf("\nPosicionando barco %d de %d\n", totalbarcos + 1, qtd_barcos);
        printf("Onde deseja por o barco? (Ex: A5): ");
        scanf(" %c%d", &linha, &coluna);

        if(linha >= 'a' && linha <= 'z') linha -= 32;

        int l = linha - 'A';
        int c = coluna - 1;

        if (l < 0 || l >= tam_tabuleiro || c < 0 || c >= tam_tabuleiro) {
            printf("Posicao invalida!\n");
            continue;
        }

        printf("informe o tamanho do barco:\n");
        scanf("%d", &tam_barcos);

        if(tam_barcos != 1) {
            printf("Para qual direcao?\n1-Cima | 2-Baixo | 3-Esquerda | 4-Direita: ");
            scanf("%d", &direcao);
        } else {
            direcao = 1;
        }

        int sucesso = 0;
        if(direcao == 1) sucesso = cima(tabuleiro1, l, c, tam_barcos);
        else if(direcao == 2) sucesso = baixo(tabuleiro1, l, c, tam_barcos);
        else if(direcao == 3) sucesso = esquerda(tabuleiro1, l, c, tam_barcos);
        else if(direcao == 4) sucesso = direita(tabuleiro1, l, c, tam_barcos);

        if(sucesso) {
            *qtd_totalbarcos1 = *qtd_totalbarcos1 + tam_barcos;
            totalbarcos++;
            printf("Barco adicionado com sucesso!\n");
        } else {
            printf("Erro: O barco ultrapassa os limites! Tente outra posicao.\n");
        }
    }
}

int atirarbarcos(char tabuleiro_inimigo[tam_tabuleiro][tam_tabuleiro], int qtd_totalbarcos, int *qtdacertos){
    char linha;
    int coluna;    

    while(1){
        printf("Insira a posicao que deseja atirar (Ex: B4): ");
        scanf(" %c%d", &linha, &coluna);

        if(linha >= 'a' && linha <= 'z') linha -= 32;

        int l = linha - 'A';
        int c = coluna - 1;

        if(l < 0 || l >= tam_tabuleiro || c < 0 || c >= tam_tabuleiro){
            printf("Posicao invalida\n");
            continue;
        }

        if(tabuleiro_inimigo[l][c] == 'N'){
            printf("Acertou!\n");
            tabuleiro_inimigo[l][c] = '0'; 
            (*qtdacertos)++;
            break; 
        } else if(tabuleiro_inimigo[l][c] == ' '){
            printf("Errou!\n");
            tabuleiro_inimigo[l][c] = 'X'; 
            break; 
        } else {
            printf("Voce ja atirou nessa posicao! Tente outra.\n");
        }
    }

    if(*qtdacertos == qtd_totalbarcos){
        return 1; 
    }
    return 0;
}

int main(){
    int totalbarcos1 = 0;
    int totalbarcos2 = 0;
    int qtd_totalbarcos1 = 0;
    int qtd_totalbarcos2 = 0;
    int acertos1 = 0;
    int acertos2 = 0;

    char tabuleirojogador1[tam_tabuleiro][tam_tabuleiro];
    char tabuleirojogador2[tam_tabuleiro][tam_tabuleiro];

    iniciarTab(tabuleirojogador1);
    iniciarTab(tabuleirojogador2);

    char mascara[tam_tabuleiro][tam_tabuleiro];

    printf("\n===== JOGADOR 1 =====\n");
    tabuleiro1(tabuleirojogador1);
    inserirbarco1(tabuleirojogador1, totalbarcos1, &qtd_totalbarcos1);

    printf("\n===== JOGADOR 2 =====\n");
    tabuleiro2(tabuleirojogador2);
    inserirbarco1(tabuleirojogador2, totalbarcos2, &qtd_totalbarcos2);

    while(1){
        printf("\n========= VEZ DO JOGADOR 1 =========\n");
        
        printf("Seu Tabuleiro (Suas defesas e tiros do oponente):\n");
        tabuleiro1(tabuleirojogador1); 

        printf("Tabuleiro do Inimigo (Seus ataques):\n");
        for(int i=0; i<tam_tabuleiro; i++) {
            for(int j=0; j<tam_tabuleiro; j++) {
                if(tabuleirojogador2[i][j] == 'N') mascara[i][j] = ' ';
                else mascara[i][j] = tabuleirojogador2[i][j];
            }
        }
        tabuleiro2(mascara); 

        if(atirarbarcos(tabuleirojogador2, qtd_totalbarcos2, &acertos1) == 1){
            printf("\nJOGADOR 1 VENCEU!\n");
            break;
        }

        printf("\n========= VEZ DO JOGADOR 2 =========\n");
        
        printf("Seu Tabuleiro (Suas defesas e tiros do oponente):\n");
        tabuleiro2(tabuleirojogador2); 

        printf("Tabuleiro do Inimigo (Seus ataques):\n");
        for(int i=0; i<tam_tabuleiro; i++) {
            for(int j=0; j<tam_tabuleiro; j++) {
                if(tabuleirojogador1[i][j] == 'N') mascara[i][j] = ' ';
                else mascara[i][j] = tabuleirojogador1[i][j];
            }
        }
        tabuleiro1(mascara); 

        if(atirarbarcos(tabuleirojogador1, qtd_totalbarcos1, &acertos2) == 1){
            printf("\nJOGADOR 2 VENCEU!\n");
            break;
        }
    }

    return 0;
}