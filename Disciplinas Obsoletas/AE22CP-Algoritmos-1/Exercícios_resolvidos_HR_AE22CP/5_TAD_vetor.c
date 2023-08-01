#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct{
    int *item; // Array (vetor) de tamanho n
    int q; // quantidade de itens inseridos em v
    int n; // tamanho (capacidade) de v
}Vetor;

Vetor * iniciar(int n){
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));
    
    v->n = n;
    
    v->item = (int*) malloc(sizeof(int) * n);
    
    v->q = 0;
    
    return v;
}

int inserir(Vetor *v, int x){
    if ((v != NULL) && (v->q < v->n)){
        v->item[v->q] = x;
        v->q++;
        
        return 1;
    }
    
    return 0;
}


Vetor * intercalar(Vetor *v1, Vetor *v2){
    int i;
    Vetor *v3 = NULL;
    
    if (v1 == NULL)
        return v2;
    else if (v2 == NULL)
        return v1;
    else{
        v3 = iniciar(v1->q + v2->q);
        
        for (i = 0; (i < v1->q) && (i < v2->q); i++){
            inserir(v3, v1->item[i]);
            inserir(v3, v2->item[i]);
        }
        
        for (i = v2->q; i < v1->q; i++)
            inserir(v3, v1->item[i]);
        
        for (i = v1->q; i < v2->q; i++)
            inserir(v3, v2->item[i]);
        
        return v3;
    }
}


Vetor * concatenar(Vetor *v1, Vetor *v2){
    int i;
    Vetor *v3 = NULL;
    
    if (v1 == NULL)
        return v2;
    else if (v2 == NULL)
        return v1;
    else{
        v3 = iniciar(v1->q + v2->q);
        
        for (i = 0; i < v1->q; i++)
            inserir(v3, v1->item[i]);
        
        for (i = 0; i < v2->q; i++)
            inserir(v3, v2->item[i]);
        
        return v3;
    }
}


Vetor * subvetor(Vetor *v1, int ini, int fim){
    Vetor *v2 = NULL;
    int i;
    
    if ((v1 != NULL) && (ini >= 0) && (fim < v1->q) && (ini <= fim)){
        v2 = iniciar(fim - ini + 1);
        
        for (i = ini; i <= fim; i++)
            inserir(v2, v1->item[i]);
    }
    
    return v2;
}

void imprimir(Vetor *v){
    int i;
    
    if (v != NULL){
        for (i = 0; i < v->q; i++)
            printf("%d ", v->item[i]);
        
        printf("\n");
    }
}

int main() {
    Vetor *v1, *v2, *v3, *v4, *v5;
    int i, n, item, ini, fim;
    
    scanf("%d", &n);
    
    v1 = iniciar(n);
    
    for (i = 0; i < n; i++){
        scanf("%d", &item);
        
        inserir(v1, item);
    }
    
    scanf("%d", &n);
    
    v2 = iniciar(n);
    
    for (i = 0; i < n; i++){
        scanf("%d", &item);
        
        inserir(v2, item);
    }
    
    scanf("%d %d", &ini, &fim);
    
    v3 = intercalar(v1, v2);
    
    imprimir(v3);
    
    v4 = concatenar(v1, v2);
    
    imprimir(v4);
    
    v5 = subvetor(v1, ini, fim);
    
    imprimir(v5);
    
    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);
    
    return 0;
}

