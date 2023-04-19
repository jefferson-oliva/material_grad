#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void qtd_moedas(int v[], int n, int troco){
    int i, qtd = 0;

    for (i = 0; (i < n) && (troco > 0); i++){
        qtd = troco / v[i];
        
        while (qtd > 0){
            printf("%d\n", v[i]);
            qtd--;
        }
        
        troco = troco % v[i];
    }
}

int main() {
    int troco, n, i;
    int *v;
    
    scanf("%d", &troco);
    scanf("%d", &n);
    
    v = (int*) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    qtd_moedas(v, n, troco);
    
    free(v);
    
    return 0;
}

