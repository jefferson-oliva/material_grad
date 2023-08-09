#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letra;
    int numero;
    float flutuante;
}exemplo;


void troca(int a, int b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void troca2(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}




int main(void){
    /*char c = 'Q';
    int a = 15;
    exemplo x;

    printf("%i\n", a);
    printf("%i\n", &a);
    printf("%x\n", &a);
    printf("%c\n", c);
    printf("%i\n", &c);
    printf("%x\n", &c);


    printf("Tamanho char: %i\n", sizeof(char));
    printf("Tamanho int: %i\n", sizeof(int));
    printf("Tamanho struct exemplo:%i\n", sizeof(exemplo));

    scanf("%i", &a);*/
    /*int x = 15;
    int *p, *pi;

    p = &x;

    *p = 18;

    printf("%i\n", x);
    printf("%i\n", &x);
    printf("%i\n", p);
    printf("%i\n", *p);
    printf("%i\n", &p);*/

    int a = 10, b = 15;
    char c = 'A';
    char *pc = &c;
    int *pa = &a;
    void *p;

    p = &a;

    pa = (int*) p;

    printf("%d", *pa);

    //pc--;

    //pa++;

    /*printf("Antes\na=%d b=%d\nDepois\n", a, b);

    troca(a, b);

    printf("a=%d b=%d\n", a, b);


    troca2(&a, &b);

    printf("a=%d b=%d\n", a, b);*/

    return 0;
}



