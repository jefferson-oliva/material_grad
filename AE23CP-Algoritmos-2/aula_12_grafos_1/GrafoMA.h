typedef struct GrafoMA GrafoMA;


GrafoMA* iniciar_grafoMA(int v);

int aresta_existe(GrafoMA* G, int v1, int v2);

void inserir_aresta(GrafoMA* G, int v1, int v2);

void remover_aresta(GrafoMA* G, int v1, int v2);

void imprimir_arestas(GrafoMA* G);

void liberarGMA(GrafoMA* G);
