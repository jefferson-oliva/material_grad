#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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


int valida_parenteses(char *s){
    PilhaC *p = criar_pilha();
    int i, vdd = 1;
    
    for (i = 0; (i < strlen(s)) && vdd; i++){
        if (s[i] == '(')
            empilhar(p, s[i]);
        else if (s[i] == ')'){
            if (!pilha_vazia(p))
                desempilhar(p);
            else
                vdd = 0;
        }
    }
    
    if ((vdd == 1) && !pilha_vazia(p))
        vdd = 0;
    
    liberar_pilha(p);
    
    return vdd;
}


int main() {
    char *str;
    int i, n,  res;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        str = (char*) malloc(sizeof(char) * 20);
        
        scanf("%s", str);
        
        res = valida_parenteses(str);
        
        if (res == 1)
            printf("correct\n");
        else
            printf("incorrect\n");
        
        free(str);
    }
    
    return 0;
}

