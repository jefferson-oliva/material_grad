#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mochila_bkt(int *p, int *c, int n, int b, int i, int max){
    int c1, c2;
    
    if (b < 0)
        return 0;
    else if (i < n){
        c1 = mochila_bkt(p, c, n, b, i + 1, max);
        
        c2 = mochila_bkt(p, c, n, b - p[i], i + 1, max + c[i]);
        
        return c1 > c2 ? c1 : c2;
    }else
        return max;
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
    
    printf("%d", mochila_bkt(p, c, n, b, 0, 0));
    
    free(p);
    free(c);  
    return 0;
}

