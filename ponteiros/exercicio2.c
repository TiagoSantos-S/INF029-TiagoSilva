// implemente uma fila comum //

#include <stdio.h>
#include <stdlib.h>

typedef struct  No{
    int valor;
    struct No * proximo;
};

void inserirNo (No** inicio, int valor){
    No * novo_no = (No*)malloc(sizeof(No));
        if(novo_no == NULL){
            printf("erro");
            return;
        }
}

void buscarno(No* inicio, int valor){

    No * atual = inicio;
    while(atual != NULL){
        if(atual->valor == valor){
            printf("elemento encontrado");
        }
        atual = atual->proximo;
    }
    printf("não achou");
}

void apagarno(No** inicion int valor){
    No*atual = *inicio;
    No*anterior = NULL;
    if(atual != NULL && atual->valor == valor){
        *inicio = ataul -> proximo;
        free(atual);
        return;
    }
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){
        return;
    }
    anterior->proximo = atual->proximo;
    free(atual);
}

int main(){


}