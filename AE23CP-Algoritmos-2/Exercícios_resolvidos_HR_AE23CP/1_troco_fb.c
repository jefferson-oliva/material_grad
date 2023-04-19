#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int troco_fb(int m[], int n, int t, int i, int min){
    int c1, c2;
    
    if (i >= n){
        if (t > 0)
            return INT_MAX;
        else
            return min;
    }else{
        c1 = troco_fb(m, n, t, i + 1, min);
        
        c2 = troco_fb(m, n, t % m[i], i + 1, min + t / m[i]); // (c, p, n, b - p[i], i + 1, max + c[i]);
        
        return c1 < c2 ? c1 : c2;
        
    }
}

int main() {
    int i, t, n, m[10];
    
    scanf("%d", &t);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &m[i]);
    
    printf("%d", troco_fb(m, n, t, 0, 0));
    
    return 0;
}
