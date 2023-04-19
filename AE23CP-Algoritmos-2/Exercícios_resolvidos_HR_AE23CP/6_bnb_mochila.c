#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mochila_bnb(int *p, int *c, int n, int b, int i){
    int c1, c2;
    
    if ((b > 0) && (i < n)){
        c1 = mochila_bnb(p, c, n, b, i + 1);
        
        if (b - p[i] >= 0)
            c2 = c[i] + mochila_bnb(p, c, n, b - p[i], i + 1);
        else
            c2 = 0;
        
        return c1 > c2 ? c1 : c2;
    }
    
    return 0;
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
    
    printf("%d", mochila_bnb(p, c, n, b, 0));
    
    free(p);
    free(c);
    
    return 0;
}
