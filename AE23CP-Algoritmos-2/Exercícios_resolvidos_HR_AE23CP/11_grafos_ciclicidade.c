#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct GrafoMA GrafoMA;

struct GrafoMA{
    int V, A;
    int *cor;
    int *pai;
    int *d;
    int *f;
    int **mat;
};


static int** iniciar_MA(int n){
    int i;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) calloc(n, sizeof(int));

    return mat;
}


static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->cor = (int*) malloc(sizeof(int) * v);
    G->pai = (int*) malloc(sizeof(int) * v);
    G->d = (int*) malloc(sizeof(int) * v);
    G->f = (int*) malloc(sizeof(int) * v);
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if (!aresta_existe(G, v1, v2)){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if (aresta_existe(G, v1, v2)){
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    int i, j;

    for (i = 1; i < G->V; i++)
        for (j = 0; j < i; j++)
            if (G->mat[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}


int busca_aresta_ret(GrafoMA *G, int u){
    int v, b = 0;
    
    G->cor[u] = 1;
    
    for (v = 0; (v < G->V) && (b == 0); v++)
        if ((G->mat[u][v] != 0)){
            if (G->cor[v] == 0){
                G->pai[v] = u;
                b = busca_aresta_ret(G, v);
            }else if ((G->pai[u] != v) && (G->cor[v] == 1))
                b = 1;
        }
    
    G->cor[u] = 2;
    
    return b;
}


int grafo_ciclico(GrafoMA *G){
    int u, b = 0;
    
    for (u = 0; u < G->V; u++){
        G->cor[u] = 0;
        G->pai[u] = -1;
    }
    
    for (u = 0; (u < G->V) && (b == 0); u++)
        if (G->cor[u] == 0)
            b = busca_aresta_ret(G, u);
    
    return b;
}


int main() {
    int i, j, V;
    GrafoMA *G;
    
    scanf("%d", &V);
    
    G = iniciar_grafoMA(V);
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &G->mat[i][j]);
    
    if (grafo_ciclico(G))
        printf("ciclico");
    else
        printf("aciclico");
    
    return 0;
}
