#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define min(a, b) a < b ? a : b

int menorDQ(int *v, int ini, int fim){
    int m;
    
    if ((fim - ini) <= 1)
        return min(v[ini], v[fim]);
    else{
        m = (fim + ini) / 2;
        
        return min(menorDQ(v, ini, m), menorDQ(v, m + 1, fim));
    }
}

int main() {
    int i, n, *v;
    
    scanf("%d", &n);
    
    v = (int*) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    printf("%d", menorDQ(v, 0, n - 1));
    
    free(v);
    
    return 0;
}

