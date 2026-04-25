#include <stdio.h>

void Calculadora(float A, float B, float *soma, float *sub, float *mult, float *div) {
    *soma = A + B;
    *sub  = A - B;
    *mult = A * B;

    if (B != 0) {
        *div = A / B;
    } else {
        *div = 0; // ou algum valor indicativo de erro
    }
}

int main() {
    float A , B;
    printf("Digite ai va: ");
    scanf("%f %f", &A, &B);

    float soma, sub, mult, div;

    Calculadora(A, B, &soma, &sub, &mult, &div);

    printf("Soma: %.2f\n", soma);
    printf("Subtracao: %.2f\n", sub);
    printf("Multiplicacao: %.2f\n", mult);
    printf("Divisao: %.2f\n", div);

    return 0;
}
