#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int busca_bin_it(int chave, int *v, int n){
    int ini = 0;
    int fim = n - 1;
    int meio;

    while (ini <= fim){
        meio = (ini + fim) / 2;

        if (chave == v[meio])
            return meio;
        else if (chave < v[meio])
            fim = meio - 1;
        else
            ini = meio + 1;
    }

    return -1;
}

int main() {
    int *v, n, i, n_chaves, chave;
    
    scanf("%d", &n);
    
    v = (int*) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    scanf("%d", &n_chaves);
    
    while (n_chaves > 0){
        scanf("%d", &chave);
        
        printf("%d\n", busca_bin_it(chave, v, n));
        
        n_chaves--;
    }
    
    free(v);

    return 0;
}


