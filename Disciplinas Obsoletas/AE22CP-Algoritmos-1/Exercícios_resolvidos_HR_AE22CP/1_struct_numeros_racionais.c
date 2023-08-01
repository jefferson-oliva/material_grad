#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int num, den;
}Rac;

Rac  div_rac(Rac a, Rac b){
    Rac c;
    
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    
    return c;
}

int main() {
    Rac a, b, c;
    
    scanf("%d %d", &a.num, &a.den);
    scanf("%d %d", &b.num, &b.den);
    
    c = div_rac(a, b);
    
    printf("%d %d\n", c.num, c.den);
    
    return 0;
}

