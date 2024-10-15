#include <stdio.h>
#include <math.h>
#include <time.h>

double raiz_enesima(double p, int m, int *iteracoes) {
    double x0 = p / m;  // estimativa inicial
    double x1;
    double erro = 1e-7;  // erro tolerado
    *iteracoes = 0;
    
    while (1) {
        x1 = ((m - 1) * x0 + p / pow(x0, m - 1)) / m;  // metodo de Newton-Raphson
        (*iteracoes)++;
        
        if (fabs(x1 - x0) < erro) break;
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
    
    // Inicia o calculo do tempo
    inicio = clock();
    
    // Calcula a raiz enesima
    double resultado = raiz_enesima(p, m, &iteracoes);
    
    // Fim do calculo do tempo
    fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    // Mostra as iteracoes e o resultado final
    
    printf("Raiz %d de %.6f: %.6f\n", m, p, resultado);
    printf("Numero de iteracoes: %d\n", iteracoes);
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);
    
    return 0;
}
