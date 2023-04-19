#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mochila_fb(int c[], int p[], int n, int b, int i, int max){
    int c1, c2;
    
    if (i >= n){
        if (b < 0)
            return 0;
        else
            return max;
    }else{
        c1 = mochila_fb(c, p, n, b, i + 1, max);
        
        c2 = mochila_fb(c, p, n, b - p[i], i + 1, max + c[i]);
        
        return c1 > c2 ? c1 : c2;
        
    }
}

int mochila(int c[], int p[], int n, int b){
    return mochila_fb(c, p, n, b, 0, 0);
}

int main() {
    int i, n, b;
    int *c, *p;
    
    scanf("%d", &b);
    scanf("%d", &n);
    
    c = (int*) malloc(sizeof(int) * n);
    p = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d %d", &p[i], &c[i]);
    
    printf("%d", mochila(c, p, n, b));
    
    free(c);
    free(p);
    
    return 0;
}

