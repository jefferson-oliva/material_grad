#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
};


Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}


int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}


int enfileirar(Fila *f, int chave){
    if (f == NULL)
        f = criar_fila();
    
    if (!fila_cheia(f)){
        if (f->ini < 0)
            f->ini = 0;
        
        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}


int desenfileirar(Fila *f){
    int item = INT_MIN;

    if (!fila_vazia(f)){
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}


void imprimir_fila(Fila *f){
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

int tamanho_fila(Fila *f){
    if (f != NULL)
        return f->tam;
    else
        return 0;
}


void divisao_intercalada(Fila *f1, Fila *f2, Fila *f3){
    if (f2 == NULL)
        f2 = criar_fila();
    if (f3 == NULL)
        f3 = criar_fila();
    
    if (!fila_vazia(f1) && fila_vazia(f2) && fila_vazia(f3)){
        while (!fila_vazia(f1)){
            enfileirar(f2, desenfileirar(f1));
            
            if (!fila_vazia(f1))
                enfileirar(f3, desenfileirar(f1));
        }
    }
}


int main() {
    int item = 0;
    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = criar_fila();
    
    while (item != -1){
        scanf("%d", &item);
        
        if (item > 0)
            enfileirar(f1, item);
    }
    
    divisao_intercalada(f1, f2, f3);
    
    imprimir_fila(f2);
    imprimir_fila(f3);
    
    liberar_fila(f1);
    liberar_fila(f2);
    liberar_fila(f3);
    
    return 0;
}
