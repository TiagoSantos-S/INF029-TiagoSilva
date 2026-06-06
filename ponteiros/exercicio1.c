// crie um vetor de 5 posições e acesse seus valores pelo ponteiro, trocando seus valores e percorendo o indice //

#include <stdio.h>
#define tam 5

int main(){

int vetor[tam];
int icont;
int indice, novovalor;

printf("preencha o vetor\n");

for(icont = 0; icont < tam; icont++){
    scanf("%d", &vetor[icont]);
}

int *p = vetor;

printf("qual indice deseja mudar e insira o novo valor");
scanf("%d %d", &indice, &novovalor);

if(indice >= 0 && indice < tam){
    *(p + indice) = novovalor;
}

printf("============================");

for(icont = 0; icont < tam; icont++){
    printf("%d\n", vetor[icont]);
}

return 0;
}