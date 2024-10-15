#include <stdio.h>
#include <math.h>
#include <time.h>

// Função polinomial f(x) = c0 + c1*x + c2*x^2 + ... + cn*x^n
double polinomio(double x, double coef[], int grau) {
    double resultado = 0.0;
    for (int i = 0; i <= grau; i++) {
        resultado += coef[i] * pow(x, i);
    }
    return resultado;
}

int main() {
    int grau, a, b;
    clock_t inicio, fim;
    double tempo_execucao;
    
    // Entrada do grau do polinomio
    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);
    
    double coef[grau+1];
    
    // Geração automática dos coeficientes (exemplo)
    // Aqui, coeficiente c0 = 1, c1 = -2, c2 = 1 para grau 2 (polinômio exemplo: f(x) = x^2 - 2x + 1)
    for (int i = 0; i <= grau; i++) {
        coef[i] = (i % 2 == 0) ? 1 : -2;  // Alterna entre 1 e -2
    }
    
    // Entrada dos limites iniciais do intervalo [a, b]
    printf("Digite o intervalo inicial [a, b]:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    
    // Início da contagem do tempo de execução
    inicio = clock();
    
    // Verifica se o intervalo contém uma raiz
    for (int i = a; i < b; i++) {
        double fa = polinomio(i, coef, grau);
        double fb = polinomio(i + 1, coef, grau);
        
        if (fa == 0) {
            printf("Raiz encontrada em x = %d\n", i);
            printf("f(%d) = %.7f\n", i, fa);
        } else if (fb == 0) {
            printf("Raiz encontrada em x = %d\n", i + 1);
            printf("f(%d) = %.7f\n", i + 1, fb);
        } else if (fa * fb < 0) {
            printf("Intervalo [%d, %d] contem uma raiz\n", i, i + 1);
            printf("f(%d) = %.7f, f(%d) = %.7f\n", i, fa, i + 1, fb);
        }
    }
    
    // Fim da contagem do tempo de execução
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    // Exibe o tempo de execução
    printf("Tempo de execucao: %.7f segundos\n", tempo_execucao);
    
    return 0;
}
