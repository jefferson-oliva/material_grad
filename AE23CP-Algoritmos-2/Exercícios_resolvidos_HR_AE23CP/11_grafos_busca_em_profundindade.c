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


void visitar_vertice(GrafoMA *G, int u, int *tempo){
    int v;
    
    G->cor[u] = 1;
    *tempo = *tempo + 1;
    G->d[u] = *tempo;
    
    for (v = 0; v < G->V; v++)
        if ((G->mat[u][v] != 0) && (G->cor[v] == 0)){
            G->pai[v] = u;
            visitar_vertice(G, v, tempo);
        }
    
    G->cor[u] = 1;
    *tempo = *tempo + 1;
    G->f[u] = *tempo;
}


void busca_profundidade(GrafoMA *G){
    int u, tempo = 0;
    
    for (u = 0; u < G->V; u++){
        G->cor[u] = 0;
        G->pai[u] = -1;
    }
    
    for (u = 0; u < G->V; u++)
        if (G->cor[u] == 0)
            visitar_vertice(G, u, &tempo);
}


void imprimir_resultados_busca(GrafoMA *G){
    int v;
    
    if (G != NULL){
        printf("v d f p\n");
        
        for (v = 0; v < G->V; v++){
            printf("%d %d %d ", v, G->d[v], G->f[v]);
            
            if (G->pai[v] >= 0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");
        }
    }
}


int main() {
    int i, j, V;
    GrafoMA *G;
    
    scanf("%d", &V);
    
    G = iniciar_grafoMA(V);
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &G->mat[i][j]);
    
    busca_profundidade(G);
    
    imprimir_resultados_busca(G);
    
    return 0;
}
