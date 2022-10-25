typedef struct GrafoLA GrafoLA;

GrafoLA* iniciar_grafoLA(int v);

int aresta_existeLA(GrafoLA* G, int v1, int v2);

void inserir_arestaLA(GrafoLA* G, int v1, int v2);

void remover_arestaLA(GrafoLA* G, int v1, int v2);

void imprimir_arestasLA(GrafoLA* G);

void liberarGLA(GrafoLA* G);
