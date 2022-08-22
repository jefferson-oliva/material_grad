#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n, int * in, float * fr){
    *in = n;
    *fr = (float) n - (float) *in;
}

int main() {
    int i, in, c;
    float fr, n;
    
    scanf("%d", &c);
    
    for (i = 0; i < c; i++){
        scanf("%f", &n);
        frac(n, &in, &fr);
        printf("N=%.3f I=%d F=%.3f\n", n, in, fr);
    }
 
    return 0;
}

