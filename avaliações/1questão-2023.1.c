#include <stdio.h>

float r_soma, r_sub, r_mult, r_div;

void calcular_operacoes(float num1, float num2) {
    r_soma = num1 + num2;
    r_sub  = num1 - num2;
    r_mult = num1 * num2;
    r_div  = num1 / num2;
}

int main() {
    float a, b;
    
    // Pede os números para o usuário
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &b);
    
    // Chama a função passando os números digitados
    calcular_operacoes(a, b);
    
    // Mostra os resultados na tela
    printf("\n--- Resultados ---\n");
    printf("Soma: %.2f\n", r_soma);
    printf("Subtracao: %.2f\n", r_sub);
    printf("Multiplicacao: %.2f\n", r_mult);
    printf("Divisao: %.2f\n", r_div);
    
    return 0;
}