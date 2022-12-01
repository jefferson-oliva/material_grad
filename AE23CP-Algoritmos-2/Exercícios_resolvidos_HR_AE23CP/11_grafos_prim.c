#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct GrafoMA GrafoMA;

struct GrafoMA{
    int V, A;
    int *nafila;
    int *pai;
    int *key;
    int **mat;
};

typedef struct Cell Cell;

typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};

struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

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
    G->nafila = (int*) malloc(sizeof(int) * v);
    G->pai = (int*) malloc(sizeof(int) * v);
    G->key = (int*) malloc(sizeof(int) * v);
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


static int extract_min(FilaE *f, GrafoMA *g){
    int vM;
    Cell *aux, *auxM;
    
    auxM = f->inicio;
    aux = auxM->next;
    
    while (aux != NULL){
        if (g->key[aux->item] < g->key[auxM->item])
            auxM = aux;
        
        aux = aux->next;
    }
    
    if (auxM != f->inicio){
        vM = f->inicio->item;
        f->inicio->item = auxM->item;
        auxM->item = vM;
    }
    
    return desenfileirar(f);
}


void prim(GrafoMA *G, int s){
    int u, v;
    FilaE *f = criar_filaE();
    
    if (valida_vertice(G, s)){
        for (v = 0; v < G->V; v++){
            G->pai[v] = -1;
            G->key[v] = INT_MAX;
            G->nafila[v] = 1;
            enfileirar(v, f);
        }
        
        G->key[s] = 0;
        
        while (!filaE_vazia(f)){
            u = extract_min(f, G);
            G->nafila[u] = 0;
            
            for (v = 0; v < G->V; v++){
                if ((G->mat[u][v] != 0) && (G->nafila[v]) && (G->mat[u][v] < G->key[v])){
                    G->key[v] = G->mat[u][v];
                    G->pai[v] = u;
                }
            }
        }
        
        for (v = 0; v < G->V; v++){
            printf("%d: ", v);

            if (G->pai[v] >= 0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");
        }
        
        liberar_filaE(f);
    }
}


int main() {
    int i, j, V, s;
    GrafoMA *G;
    
    scanf("%d", &V);
    
    G = iniciar_grafoMA(V);
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &G->mat[i][j]);
    
    scanf("%d", &s);

    prim(G, s);
    
    return 0;
}

