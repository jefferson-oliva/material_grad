#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}vetor_r2;

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2){
    vetor_r2 v3;
    
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    
    return v3;
}

int main() {
    vetor_r2 v1, v2, v3;
    
    scanf("%d %d", &v1.x, &v1.y);
    scanf("%d %d", &v2.x, &v2.y);
    
    v3 = soma_vec(v1, v2);
    
    
    printf("%d %d", v3.x, v3.y);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
