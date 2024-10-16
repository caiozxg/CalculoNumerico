#include <stdio.h>
#include <math.h>
#include <time.h>

double raiz_enesima(double p, int m, int *iteracoes) {
    double x0 = 1;  // estimativa inicial
    double x1;
    double erro = 1e-7; 
    *iteracoes = 0;
    
    printf("Iterações:\n");

    // Faz a iteração pelo menos 9 vezes
    while (*iteracoes < 9 || fabs(x1 - x0) >= erro) {
        x1 = ((m - 1) * x0 + p / pow(x0, m - 1)) / m;  
        (*iteracoes)++;
        
        // Mostra o valor atual da iteração
        printf("Iteração %d: x = %.10f\n", *iteracoes, x1);
        
        if (fabs(x1 - x0) < erro && *iteracoes >= 9) break;
        x0 = x1;
    }
    
    return x1;
}

int main() {
    double p;
    int m, iteracoes;
    clock_t inicio, fim;
    
    // Leitura de entrada
    printf("Qual o valor do numero dentro da raiz?digite apenas numero positivo: ");
    scanf("%lf", &p);
    printf("Qual o valor do grau da raiz: ");
    scanf("%d", &m);
    
    // Inicia o cálculo do tempo
    inicio = clock();
    
    // Calcula a raiz enésima
    double resultado = raiz_enesima(p, m, &iteracoes);
    
    // Fim do cálculo do tempo
    fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    // Mostra o resultado final
    printf("Raiz de %.6f com expoente %d: %.6f\n", p, m, resultado);
    printf("Número de iterações: %d\n", iteracoes);
    printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
    
    return 0;
}
