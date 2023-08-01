#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pot(int a, unsigned int n){
    if (n == 0)
        return 1;
    else
        return a * pot(a, n - 1);
}

int main() {
    int a, n;
    
    scanf("%d %d", &a, &n);
    
    printf("%d", pot(a, n));
    
    return 0;
}

