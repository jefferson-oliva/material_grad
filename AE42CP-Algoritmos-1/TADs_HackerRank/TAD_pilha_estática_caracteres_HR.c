#define TAM_MAX 100

typedef struct PilhaC PilhaC;

struct PilhaC{
    char item[TAM_MAX];
    int topo;
};

PilhaC* criar_pilha(){
    PilhaC *p = (PilhaC*) malloc(sizeof(PilhaC));

    p->topo = -1;

    return p;
}

int pilha_cheia(PilhaC *p){
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(PilhaC *p){
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}


int empilhar(PilhaC *p, char item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


char desempilhar (PilhaC *p){
    char item = ' ';

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(PilhaC *p){
    PilhaC aux = *p;
    char item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

void liberar_pilha(PilhaC *p){
    if (p != NULL)
        free(p);
}


int obter_posicao_topo(PilhaC *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}
