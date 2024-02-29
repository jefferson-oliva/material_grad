#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaE.h"


// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa célula para qualquer 
              // tipo de informação, recomendo o uso de ponteiro 
              // genérico. Exemplo: void* item;
    Cell *next;
};


// Estrutura de dados para representar uma pilha
struct PilhaE{
    Cell *topo;
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma pilha encadeada
PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


// Retorna 1 se a pilha está vazia ou 0, caso contrário
int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


// Inserir, no topo de uma pilha, um novo elemento
void empilhar(int key, PilhaE *p){
    Cell *aux; // Nova célula

    // Caso a pilha encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (p == NULL)
        p = criar_pilhaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Apontar a nova célula para o topo da pilha
    aux->next = p->topo;

    // Atualizar topo da pilha
    p->topo = aux;
}


// Remover um item do topo da pilha
int desempilhar(PilhaE *p){
    Cell *aux; // Topo da pilha a ser removido
    int item = INT_MIN; // Valor que está no topo

    if (!pilhaE_vazia(p)){
        // obter a célula do topo da pilha
        aux = p->topo;
        
        // Acessar o conteúdo da célula
        item = aux->item;

        // Atualizar o topo da pilha
        p->topo = aux->next;

        // Liberar a célula desempilhada
        free(aux);
    }

    return item;
}


// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(PilhaE *p){
    if (!pilhaE_vazia(p))
        return p->topo->item;
    else
        return INT_MIN;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(PilhaE *p){
    Cell *aux; // Para percorrer a pilha, deve ser utilizada
    	       // uma variável auxiliar para não perder o
    	       // topo da pilha

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }
        
        printf("\n");
    }
}


// Desalocar pilha
int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}
