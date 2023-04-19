#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pot(int a, int b){
    int x;
    
    if (b <= 0)
        return 1;
    else if (b == 1)
        return a;
    else if ((b % 2) == 0){
        x = pot(a, b / 2);
        
        return x * x;
    }else{
        x = pot(a, (b - 1) / 2);
        
        return a * x * x;
    }
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d", pot(a, b));
    
    return 0;
}

