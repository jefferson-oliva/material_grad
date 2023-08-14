#ifndef _PILHA_
#define _PILHA_

#define TAM_MAX 100

typedef struct ItemP ItemP;

typedef struct Pilha Pilha;


// Criar uma pilha vazia
Pilha* criar_pilha();

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p);

// Verificar se a pilha está vazia (stack overflow)
int pilha_vazia(Pilha *p);

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int chave);

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
ItemP* desempilhar (Pilha *p);

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p);

// Liberar a pilha
void liberar_pilha(Pilha *p);

// Liberar um item
void liberar_itemP(ItemP *item);

// Obter chave de um item
int obter_chaveP(ItemP *item);

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p);

#endif // _PILHA_
