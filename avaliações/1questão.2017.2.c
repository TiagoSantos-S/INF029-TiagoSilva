#include <stdio.h>
#define tam 10

char inserircaracter(char vetor[tam]){

    char caracter;
    char retorno = '1';
    int contador = 0;

    printf("qual caracter deseja inserir no vetor ?\n");
    scanf(" %c", &caracter);

    for(int icont = 0; icont < tam; icont++){

        if(vetor[icont] != ' ' && vetor[icont] != '\0'){
            contador++;
        }

        if(vetor[icont] == ' ' || vetor[icont] == '\0'){
            vetor[icont] = caracter;
            return retorno;
        }
    }

    if(contador == tam){
        retorno = '0';
    }

    return retorno;
}

char troca_caracter(char vetor[tam]){
    
    char novo_caracter;
    char caracter_saiu;
    
    printf("informe o caracter que deseja por de novo\n");
    scanf(" %c", &novo_caracter);

    for(int icont = 0; icont < tam; icont++){

        if(vetor[icont] == ' ' || vetor[icont] == '\0'){
            continue;
        }

        if(vetor[icont] > novo_caracter){

            caracter_saiu = vetor[icont];
            vetor[icont] = novo_caracter;

            return caracter_saiu;
        }
    }

    return '1';
}

void excluir_caracter(char vetor[tam]){

    for(int icont = tam - 1; icont >= 0; icont--){

        if(vetor[icont] != ' ' && vetor[icont] != '\0'){

            vetor[icont] = ' ';
            printf("ultimo caracter excluido com sucesso !\n");
            return;
        }
    }

    printf("vetor vazio !\n");
} 

void listar_caracter(char vetor[tam]){

    for(int icont = 0; icont < tam; icont++){

        if(vetor[icont] != ' ' && vetor[icont] != '\0'){
            printf("%c\n", vetor[icont]);
        }
    }
}

void listar_caracter_expecifico(char vetor[tam]){
    
    int ocorrencia = 0;
    int repetido;
    char letra;
    
    for(int icont = 0; icont < tam; icont++){

        if(vetor[icont] == ' ' || vetor[icont] == '\0'){
            continue;
        }

        repetido = 0;
        letra = vetor[icont];

        for(int k = 0; k < icont; k++){

            if(letra == vetor[k]){
                repetido = 1;
            }
        }

        if(repetido == 1){
            continue;
        }

        ocorrencia = 0;

        for(int jcont = 0; jcont < tam; jcont++){

            if(letra == vetor[jcont]){
                ocorrencia++;
            }
        }

        printf("%c aparece %d vezes\n", letra, ocorrencia);
    }
}

int main(){

    char vetor[tam] = {'t','i','a',' ','g','o','1','2','3','\0'};
    char resultado;
    char caracter;

    resultado = inserircaracter(vetor);

    if(resultado == '1'){

        printf("caracter inserido com sucesso !\n");

    }else if(resultado == '0'){

        printf("vetor cheio, impossivel inserir caracter !\n");
        return 0;
    }

    resultado = troca_caracter(vetor);

    if(resultado == '1'){

        printf("erro, caracter maior que os outros !\n");

    }else{

        printf("troca feita com sucesso, caracter que saiu = %c !\n", resultado);
    }

    while(caracter != '1' && caracter != '2' && caracter != '3'){
        printf("\ndeseja excluir um caracter ?\n");
        printf("digite '1' para excluir\n");
        printf("digite '2' para listar caracteres\n");
        printf("digite '3' para listar ocorrencias\n");

        scanf(" %c", &caracter);

        if(caracter == '1'){

            excluir_caracter(vetor);
            printf("---------------------------------------------\n");

        }else if(caracter == '2'){

            listar_caracter(vetor);
            printf("---------------------------------------------\n");

        }else if(caracter == '3'){

            listar_caracter_expecifico(vetor);
        }
    }

    return 0;
}