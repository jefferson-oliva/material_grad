#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    int ano, temporadas;
    float avaliacao;
}Anime;

typedef struct{
    int n;
    int arr[100];
}Vetor1;

typedef struct{
    int n;
    int *arr;
}Vetor2;


/**
Roteiro:
- exemplos com struct
- função para iniciar vetor com malloc e com calloc ()
- Alocação estática de matrizes: slides 27-32
- alocação dinâmica de matrizes: slides 34-49
- Erros comuns: slides 51--

*/


Vetor1 *iniciar_v1(){
    Vetor1 *v = (Vetor1*) malloc(sizeof(Vetor1));
    int i;

    v->n = 0;

    for (i = 0; i < 100; i++)
        v->arr[i] = 0;

    return v;
}

Vetor1 *iniciar_v2(){
    Vetor1 *v = (Vetor1*) calloc(1, sizeof(Vetor1));

    return v;
}

Vetor2* iniciar_v3(int n){
    Vetor2 *v = (Vetor2*) malloc(sizeof(Vetor2));

    v->n = n;
    v->arr = (int*) malloc(sizeof(int) * n);

    return v;
}


int* func(int *v){
    int *p = (int*) malloc(sizeof(int) * 2);

    p[0] = v[0] * v[0];
    p[1] = v[1] * v[1];

    return p;
}

int** matriz(int n){
    int** m = (int**) malloc(sizeof(int*) * n);
    int i;

    for (i = 0; i < n; i++)
        m[i] = (int*) malloc(sizeof(int) *n);

    return m;
}


int main(void){
    /*int *p = (int*) malloc(sizeof(int));
    char *pc = (char*) malloc(sizeof(char) * 9);
    int i;
    int *v = (int*) malloc(sizeof(int)*10);
    int *v2 = (int*) calloc(10, sizeof(int));
    int *v3 = (int*) malloc(sizeof(int) * 2);
    int *v4 = NULL;

    v3[0] = 2;
    v3[1] = 3;

    v4 = func(v3);

    printf("%d\n", v4[0]);
    printf("%d\n", v4[1]);

    strcpy(pc, "rasengan");
    printf("%s\n", pc);

    pc = (char*) realloc(pc, 10);

    pc = strcat(pc, "!");


    printf("%s\n", pc);

    if (p != NULL){
        *p = 10;

        printf("%d\n", *p);
    }

    for (i = 0; i < 10; i++){
        v[i] = i + 1;
        printf("---> %d\n", v[i]);
    }

    free(p);
    free(pc);
    free(v);
    free(v2);
    free(v3);
    free(v4);*/

    Anime *a = malloc(sizeof(Anime) * 15);

    return 0;
}



