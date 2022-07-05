#include <stdio.h>
#include <limits.h>
#define MAX 100

int f[MAX];


// Sequência de Fibonacci por divisão e conquista
int fib(int n){
    if (n <= 0)
        return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}


// Sequência de Fibonacci por programação dinâmica
int fibPD(int n){
    if (f[n] < INT_MAX)
        return f[n];
    else if (n == 0)
        return f[n] = 0;
    else if (n == 1)
        return f[n] = 1;
    else
        return f[n] = fibPD(n - 1) + fibPD(n - 2);
}


int** create_matrix(int l, int c){
    int i = 0;
    int** mat = (int**) malloc(sizeof(int*) * l);

    for (i = 0; i < l; i++)
        mat[i] = (int*) malloc(sizeof(int) * c);

    return mat;
}


/** Retorna a quantidade mínima de operações para um conjunto de matrizes.

Parâmetros:
m: matriz onde são registrados custos mínimos para multiplicação de matrizes
n: dimensão da matriz
b: Vetor de dimensão de matrizes. O tamanho desse vetor é n + 1
*/
int multiplicacao_minima(int** m, int n, int b[]){
    int h, i, j, k, aux;

    for (i = 0; i < n; i++)
        m[i][i] = 0;

    // Indica qual diagonal após a principal será processada.
    // Por exemplo: se h = 1, a diagonal processada é logo após a principal
    for (h = 1; h < n; h++) {
        for (i = 1; i <= n - h; i++){ // n - h é a quantidade de elementos analisados na diagonal
            j = i + h; // i => linhas; j => colunas
            m[i - 1][j - 1] = INT_MAX;

            // Procura o menor custo para multiplicar as matrizes Mi X ... X Mj
            // Pode ser usado para parentesiação. Por exemplo, para m[0][2], qual forma de cálculo
            // custa menos: (M0 X M1) X M2 ou M1 X (M2 X M3)?
            for (k = i; k <= j - 1; k++){
                aux = m[i - 1][k - 1] + m[k][j - 1] + b[i - 1] * b[k] * b[j]; // m(i,k) + m(k + 1) + b(i - 1) * b (k) * b (j)

                if (aux < m[i - 1][j - 1])
                    m[i - 1][j - 1] = aux;
            }
        }
    }

    return m[0][n - 1];
}


int main(){
    int i;
    int b[] = {10, 20, 50, 1, 100};
    int** m = create_matrix(4, 4);
    int min = multiplicacao_minima(m, 4, b);

    for (i = 0; i < MAX; i++)
        f[i] = -1;


    printf("%d\n", fib(10));
    printf("%d\n", fibPD(10));

    printf("Operacoes minimas: %d", min);

    free(m);

    return 0;
}
