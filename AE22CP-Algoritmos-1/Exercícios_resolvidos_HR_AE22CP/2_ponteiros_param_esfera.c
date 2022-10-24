#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14

void param_esfera(float r, float *area, float *volume){
    *area = 4.0 * pi * pow(r, 2);
    *volume = (3.0 / 4.0) * pi * pow(r, 3);
}

int main() {
    float r, a, v;
    
    scanf("%f", &r);
    
    param_esfera(r, &a, &v);
    
    printf("%.2f %.2f", a, v);

    return 0;
}

