#include <stdio.h>
#include <stdlib.h>
#include "listaE_rec.h"

struct Cell{
    int item;
    Cell *next;
};


struct ListaE{
    Cell *head;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));

    c->item = key;
    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

static int procurar_rec(Cell *c, int item){
    if (c == NULL)
        return 0;
    else if (c->item == item)
        return 1;
    else
        return procurar_rec(c->next, item);
}


int procurar(int key, ListaE *l){
    return (l != NULL) ? procurar_rec(l->head, key) : 0;
}


void inserir_primeiro(int key, ListaE *l){
    Cell *nova = criar_celula(key);

    if (l == NULL)
        l = criar_listaE();

    nova->next = l->head;

    l->head = nova;
}


static void inserir_ultimo_recursivo(Cell *c, int key){
    Cell *novo;
    if (c->next == NULL){
        novo = criar_celula(key);
        c->next = novo;
    }else
        inserir_ultimo_recursivo(c->next, key);
}


void inserir_ultimo(int key, ListaE *l){
    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else
        inserir_ultimo_recursivo(l->head, key);

}

static Cell* inserir_ordenado_rec(Cell *c, int item){
    Cell *novo;

    if (c == NULL)
        c = criar_celula(item);
    else if (item < c->item){
        novo = criar_celula(item);
        novo->next = c;
        c = novo;
    }else
        c->next = inserir_ordenado_rec(c->next, item);

    return c;
}

void inserir_ordenado(int key, ListaE *l){
    if (l == NULL)
        l = criar_listaE();

    l->head = inserir_ordenado_rec(l->head, key);
}


static Cell* remover_rec(Cell *c, int item, int *sucesso){
    Cell *aux;

    if (c != NULL){
        if (c->item == item){
            aux = c;
            c = c->next;
            free(aux);
            *sucesso = 1;
        }else
            c->next = remover_rec(c->next, item, sucesso);
    }

    return c;
}


int remover(int key, ListaE *l){
    int s = 0;

    if (!listaE_vazia(l))
        l->head = remover_rec(l->head, key, &s);

    return s;
}

static void imprimir_rec(Cell *c){
    if (c != NULL){
        printf("%d ", c->item);
        imprimir_rec(c->next);
    }
}

void imprimir(ListaE *l){
    if (!listaE_vazia(l)){
        imprimir_rec(l->head);
        printf("\n");
    }
    
}

static void imprimir_inverso_rec(Cell *c){
    if (c != NULL){
        imprimir_inverso_rec(c->next);
        printf("%d ", c->item);
    }
}

void imprimir_inverso(ListaE *l){
    if (!listaE_vazia(l)){
        imprimir_inverso_rec(l->head);
        printf("\n");
    }
}


static void liberar_LE_rec(Cell *c){
    if (c != NULL){
        liberar_LE_rec(c->next);
        free(c);
    }
}

int liberar_LE(ListaE *l){
    if (l != NULL){
        liberar_LE_rec(l->head);

        free(l);

        return 1;
    }

    return 0;
}


static int tamanho_LE_rec(Cell *c){
    if (c ==  NULL)
        return 0;
    else
        return 1 + tamanho_LE_rec(c);
}


int tamanho_LE(ListaE *l){
    return (l != NULL) ? tamanho_LE_rec(l->head) : 0;
}


