#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/


int *vetorPrincipal[TAM];
int tamanhoDaEstrutura[TAM] = {0};
int quantidadeDeElementos[TAM] = {0};


int criarEstruturaAuxiliar(int posicao, int tamanho)
{   
    if (posicao < 1 || posicao > 10) return POSICAO_INVALIDA;
    if (tamanho < 1) return TAMANHO_INVALIDO;
    if (vetorPrincipal[posicao - 1] != NULL) return JA_TEM_ESTRUTURA_AUXILIAR;

    
    vetorPrincipal[posicao - 1] = (int *) malloc(tamanho * sizeof(int));

    if (vetorPrincipal[posicao - 1] == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    // Anota qual foi o tamanho solicitado para essa posição
    tamanhoDaEstrutura[posicao - 1] = tamanho; 
    
    // Anota que, como acabou de ser criada, tem 0 números lá dentro
    quantidadeDeElementos[posicao - 1] = 0;    

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10){ 
        return POSICAO_INVALIDA;
    }
    else{
        if (vetorPrincipal[posicao - 1] != NULL){
            retorno = SEM_ESPACO;

            if (quantidadeDeElementos[posicao - 1] < tamanhoDaEstrutura[posicao - 1])
            {
                vetorPrincipal[posicao - 1][quantidadeDeElementos[posicao - 1]] = valor;
                quantidadeDeElementos[posicao-1] += 1;
                retorno = SUCESSO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, 
a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
 int excluirNumeroDoFinaldaEstrutura(int posicao)
{   

    if(posicao > 10 || posicao < 1){
        return POSICAO_INVALIDA;
    }

    int indice_real = posicao - 1;

    if (vetorPrincipal[indice_real] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if(quantidadeDeElementos[indice_real] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    if(vetorPrincipal[indice_real] != NULL){
        quantidadeDeElementos[indice_real]--;
    }

    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{

    int i = 0;

    if(posicao > 10 || posicao < 1){
        return POSICAO_INVALIDA;
    }

    int indice_real = posicao - 1;

    if (vetorPrincipal[indice_real] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if(quantidadeDeElementos[indice_real] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int quantidade = quantidadeDeElementos[indice_real];
    int posicao_encontrada = -1;

    for(int i = 0; i < quantidade; i++) {
        if(vetorPrincipal[indice_real][i] == valor) {
            posicao_encontrada = i; 
            break; 
        }
    }

    if(posicao_encontrada == -1) {
        return NUMERO_INEXISTENTE;
    }

    for(int i = posicao_encontrada; i < quantidade - 1; i++) {
        vetorPrincipal[indice_real][i] = vetorPrincipal[indice_real][i + 1];
    }

    quantidadeDeElementos[indice_real]--;

    return SUCESSO; 
}


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int valido = ehPosicaoValida(posicao);
    
    if(valido == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }
    
    int quantidade = quantidadeDeElementos[posicao - 1]; 

    if (vetorPrincipal[posicao - 1] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for(int i = 0; i < quantidade; i++){
        vetorAux[i] = vetorPrincipal[posicao - 1][i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int valido = ehPosicaoValida(posicao);
    int aux;
    
    if(valido == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }
    
    int quantidade = quantidadeDeElementos[posicao - 1]; 

    if (vetorPrincipal[posicao - 1] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for(int i = 0; i < quantidade; i++){
        vetorAux[i] = vetorPrincipal[posicao - 1][i];
    }

    for(int i = 0; i < quantidade - 1; i++){
        for(int j = 0; j < quantidade - 1 - i; j++){
            if(vetorAux[j] > vetorAux[j+1]){
                aux = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = aux;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int temElementos = 0;
    
    for(int i = 0; i < 10; i++){
        if (vetorPrincipal[i] != NULL && quantidadeDeElementos[i] > 0) {
            temElementos = 1;
            break; 
        }
    }

    if(temElementos == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    int y = 0;

    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){
            int quantidade = quantidadeDeElementos[i];
            for(int j = 0; j < quantidade; j++){
                vetorAux[y] = vetorPrincipal[i][j];   
                y++;
            }
        }
    }


    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if (retorno == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    int totalElementos = 0;
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){
            totalElementos += quantidadeDeElementos[i];
        }
    }

    for(int i = 0; i < totalElementos - 1; i++){
        for(int j = 0; j < totalElementos - i - 1; j++){
            
            if(vetorAux[j] > vetorAux[j+1]){
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }

    return SUCESSO;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int valido = ehPosicaoValida(posicao);
    if (valido == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice_real = posicao - 1;

    if (vetorPrincipal[indice_real] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int novoTamanhoFinal = tamanhoDaEstrutura[indice_real] + novoTamanho;

    if (novoTamanhoFinal < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    size_t tamanhoEmBytes = (size_t)novoTamanhoFinal * sizeof(int);
    int *novoPonteiro = (int *) realloc(vetorPrincipal[indice_real], tamanhoEmBytes);

    if (novoPonteiro == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice_real] = novoPonteiro;
    tamanhoDaEstrutura[indice_real] = novoTamanhoFinal;

    // Se encolheu além da quantidade já inserida, trunca logicamente:
    // os elementos que não cabem mais são descartados (mantém os primeiros).
    if (quantidadeDeElementos[indice_real] > novoTamanhoFinal) {
        quantidadeDeElementos[indice_real] = novoTamanhoFinal;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int valido = ehPosicaoValida(posicao);
    if (valido == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice_real = posicao - 1;

    if (vetorPrincipal[indice_real] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (quantidadeDeElementos[indice_real] == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    return quantidadeDeElementos[indice_real];
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No *montarListaEncadeadaComCabecote()
{

    int temElementos = 0;
    for(int i = 0; i < TAM; i++){
        if (vetorPrincipal[i] != NULL && quantidadeDeElementos[i] > 0) {
            temElementos = 1;
            break; 
        }
    }

    if (temElementos == 0) {
        return NULL;
    }

    No *cabecote = malloc(sizeof(No));
    if (cabecote == NULL) return NULL; // Proteção caso falte memória
    
    cabecote->prox = NULL;
    cabecote->conteudo = 0; // O valor do cabeçote geralmente é ignorado

    // Ponteiro auxiliar para sabermos onde colocar o próximo nó (sempre no final da lista encadeada)
    No *ultimoNoDaLista = cabecote;

    // 3. Percorrer o vetor principal e suas respectivas estruturas auxiliares
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i] != NULL){
            int quantidade = quantidadeDeElementos[i];
            
            // Percorre os elementos da estrutura auxiliar atual
            for(int j = 0; j < quantidade; j++){
                
                // Aloca memória para o novo nó da lista encadeada
                No *novoNo = malloc(sizeof(No));
                if (novoNo == NULL) return NULL; 

                // Preenche o novo nó com o número guardado na estrutura
                novoNo->conteudo = vetorPrincipal[i][j];
                novoNo->prox = NULL;

                // Liga o último nó da lista ao novo nó criado
                ultimoNoDaLista->prox = novoNo;
                
                // Atualiza o ponteiro para que o novo nó seja o "último"
                ultimoNoDaLista = novoNo;   
            }
        }
    }

    return cabecote;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{

    No *atual = inicio->prox;
    int i = 0;

    while(atual != NULL)
    {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *prox;

    while(atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int i = 0; i < 10; i++) {
        vetorPrincipal[i] = NULL;
    }
}


/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/


void finalizar()
{
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){

            free(vetorPrincipal[i]);
            
            vetorPrincipal[i] = NULL;
            
            quantidadeDeElementos[i] = 0;
        }
    }
}
