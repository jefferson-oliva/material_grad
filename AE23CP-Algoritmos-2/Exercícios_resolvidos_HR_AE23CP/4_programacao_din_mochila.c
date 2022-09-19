#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int mochila_pd(int *p, int *c, int n, int b){
    int i, j, mat[b+1][n+1];
    
    for (i = 0; i <= b; i++)
        mat[i][0] = 0;
    
    // coluna
    for (j = 1; j <= n; j++){
        //linha
        for (i = 0; i <= b; i++)
            if (i - p[j - 1] < 0)
                mat[i][j] = mat[i][j - 1];
            else
                mat[i][j] = max(mat[i][j - 1], c[j - 1] + mat[i - p[j - 1]][j - 1]);
    }
    
    return mat[b][n];
}

int main() {
    int i, n, b;
    int *p, *c;
    
    scanf("%d", &b);
    scanf("%d", &n);
    
    p = (int*) malloc(sizeof(int) * n);
    c = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d %d", &p[i], &c[i]);
    
    printf("%d", mochila_pd(p, c, n, b));
    
    free(p);
    free(c);  
    return 0;
}

