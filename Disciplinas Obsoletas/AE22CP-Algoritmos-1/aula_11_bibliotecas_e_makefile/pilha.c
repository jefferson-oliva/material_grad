#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct ItemP{
    int chave;

    /*
    Outros campos
    */
};

struct Pilha{
    ItemP item[TAM_MAX];
    int topo;
};

// Criar uma pilha vazia
Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p){
    // Uma solução simples
    // Antes de verificar o topo da pilha, primeiro devemos verificar se
    // a pilha é nula
    //return (p != NULL) && p->topo == (TAM_MAX - 1);

    //outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    // 0: se a pilha não estiver cheia
    // 1: se a pilha estiver cheia
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

// Verificar se a pilha está vazia (stack overflow)
int pilha_vazia(Pilha *p){
    // Uma solução simples
    // Pilha nula ou com o topo igual a -1 é uma pilha vazia
    //return (p == NULL) || (p->topo == -1);

    //outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    // 0: se a pilha não estiver vazia
    // 1: se a pilha estiver vazia
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int chave){
    ItemP item;

    // Se a pilha for nula, reservar um espaço na memória para ela
    if (p == NULL)
        p = criar_pilha();

    // Se a pilha não estiver cheia, empilhar um item
    // ! => operação lógica de negação
    // Exemplos:
    // !0 = 1
    // !(número diferente de 0) = 0
    // Caso a pilha seja nula, antes de entrar no comando if, ela é criada
    // ou seja, não precisa fazer "if (pilha_cheia(p) == 0)"
    if (!pilha_cheia(p)){
        item.chave = chave; // atribuir a chave ao item

        p->topo++; // a pilha aumenta

        p->item[p->topo] = item; // um novo item é empilhado

        return 1; // operação bem sucedida
    }

    return 0; // opera
}

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
ItemP* desempilhar (Pilha *p){
    ItemP *item = NULL;

    // Verificar se a pilha é vazia (1) ou nula (-1)
    // A única condição para "entrar" no comando if é a função abaixo
    // retornar 0, cuja negação é 1
    // Para qualquer retorno diferente de 0, a negação será 0
    if (!pilha_vazia(p)){
        item = (ItemP*) malloc(sizeof(ItemP));

        *item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p){
    // Uma cópia da pilha deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela operação desempilhar, ou seja,
    // se usarmos a pilha original (p), perderíamos os seus dados
    Pilha aux = *p;
    ItemP *item;

    // Como a variável aux não é ponteiro, para utilizamos o seu
    // endereço como parâmetro para chamarmos a função pilha_vazia
    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item->chave);

        // Para cada item desempilhado, um espaço na memória é alocado
        // para armazená-lo. Por essa razão, devemos liberá-lo após cada
        // uso
        liberar_itemP(item);
    }
}

// Liberar a pilha
void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

// Liberar um item
void liberar_itemP(ItemP *item){
    if (item != NULL)
        free(item);
}

// Obter chave de um item
// Como não podemos acessar diretamente os registros das estruturas
// fora do arquivo em que os mesmos são declarados, devemos criar
// funções para acessá-los
int obter_chaveP(ItemP *item){
    return item->chave;
}

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}
