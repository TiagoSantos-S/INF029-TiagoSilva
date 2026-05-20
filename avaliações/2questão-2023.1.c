#include <stdio.h>
#define tam 20
#define traços 4

int menu(){
    int opcao;
    printf("\n=== MENU TRIANGULO ===\n");
    printf("1. Verificar varetas\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    while(getchar() != '\n'); 
    
    return opcao;
}

int verificar_varetas(int primeiro, int segundo, int terceiro, int quarto){
    if(primeiro < segundo + terceiro && 
        segundo < primeiro + terceiro &&
        terceiro < segundo + primeiro){
        return 1;
    }
    else if(primeiro < segundo + quarto && 
        segundo < primeiro + quarto &&
        quarto < segundo + primeiro){
        return 2;
    }
    else if(primeiro < terceiro + quarto && 
        terceiro < primeiro + quarto &&
        quarto < terceiro + primeiro){
        return 3;
    }
    else if(segundo < terceiro + quarto && 
        terceiro < segundo + quarto &&
        quarto < terceiro + segundo){
        return 4;
    }else{
        return 0;
    }
}

int valida_entrada(char varetas[tam]){
    int qtd_traços = 0;
    int icont = 0;
    int primeiro = 0;
    int segundo = 0;
    int terceiro = 0;
    int quarto = 0;

    while(varetas[icont] != '\0' && varetas[icont] != '\n'){
        
        if(varetas[icont] == '-'){
            qtd_traços++;
            icont++;
            continue; 
        }
        else if(varetas[icont] >= '0' && varetas[icont] <= '9'){
            int valor = varetas[icont] - '0';
            
            if(qtd_traços == 0){
                primeiro = primeiro * 10 + valor;
            }
            else if(qtd_traços == 1){
                segundo = segundo * 10 + valor;
            }
            else if(qtd_traços == 2){
                terceiro = terceiro * 10 + valor;
            }
            else if(qtd_traços == 3){ 
                quarto = quarto * 10 + valor;
            }
        }
        
        icont++;
    }

    if(primeiro < 0 || primeiro > 100 || segundo < 0 || segundo > 100 || terceiro < 0 || terceiro > 100 || quarto < 0 || quarto > 100){
        return 0;
    }else{
        return verificar_varetas(primeiro, segundo, terceiro, quarto);
    }
}

int main(){
    int opção_menu = 1;
    char varetas[tam];

    while(opção_menu != 2){
        opção_menu = menu();

        if(opção_menu == 2){
            return 0;
        }else if(opção_menu == 1){
            printf("informe o tamanho das varetas seguido de um -\n");
            fgets(varetas, tam, stdin);

            int valor = valida_entrada(varetas);

            if(valor == 1){
                printf("varetas usadas primeiro, segundo, terceiro\n");
            }else if(valor == 2){
                printf("varetas usadas primeiro, segundo, quarto\n");
            }else if(valor == 3){
                printf("varetas usadas primeiro, terceiro, quarto\n");
            }else if(valor == 4){ 
                printf("varetas usadas segundo, terceiro, quarto\n");
            }else if(valor == 0){
                printf("impossivel formar um triangulo\n");
            }
        }
    }
    return 0;
}