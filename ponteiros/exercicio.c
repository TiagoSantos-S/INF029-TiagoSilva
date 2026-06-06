#include <stdio.h>

int main(){

int i = 2;
int *a = &i;
a = 10;

printf("%d\n", a);
printf(" %d ", *a);

/////////////////////////////////

int vetorint[5];
int *pvetor = vetorint; // pega o endereço do primeiro indice do vetor, não e preciso & pq a linguagem ja entende o vetor como endereço //


return 0;

}