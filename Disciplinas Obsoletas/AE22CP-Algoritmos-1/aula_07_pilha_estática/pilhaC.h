#define TAM_MAX 100

typedef struct PilhaC PilhaC;


PilhaC* criar_pilha();

int pilha_cheia(PilhaC *p);

int pilha_vazia(PilhaC *p);

int empilhar(PilhaC *p, char c);

char desempilhar(PilhaC *p);

void imprimir_pilha(PilhaC *p);

void liberar_pilha(PilhaC *p);

int obter_posicao_topo(PilhaC *p);
