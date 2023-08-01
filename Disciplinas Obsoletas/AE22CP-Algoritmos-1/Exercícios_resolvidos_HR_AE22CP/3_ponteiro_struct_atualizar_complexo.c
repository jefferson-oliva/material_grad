#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float real, img, mod;
}complexo;

void atualizar_complexo(complexo *c, float real, float img){
    c->real = real;
    c->img = img;
    c->mod = sqrt(real * real + img * img);
}

int main() {
    float r, m;
    complexo c;
    
    scanf("%f %f", &r, &m);
    
    atualizar_complexo(&c, r, m);
    
    if (c.img >= 0)
        printf("%.1f+%.1fi\n", c.real, c.img);
    else    
        printf("%.1f%.1fi\n", c.real, c.img);
    
    printf("%.1f", c.mod);

    return 0;
}

