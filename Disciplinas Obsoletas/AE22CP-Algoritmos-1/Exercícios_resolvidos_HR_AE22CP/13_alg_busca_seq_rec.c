#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_seq_rec(int chave, int *v, int i, int n){
    if (i < n)
        return (chave == v[i]) ? i : busca_seq_rec(chave, v, i + 1, n);
    else
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
        
        printf("%d\n", busca_seq_rec(chave, v, 0, n));
        
        n_chaves--;
    }
    
    free(v);

    return 0;
}

