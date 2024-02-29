#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "filaE.h"


// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa célula para qualquer 
              // tipo de informação, recomendo o uso de ponteiro 
              // genérico. Exemplo: void* item;
    Cell *next;
};


// Estrutura para representar filas encadeadas
struct FilaE{
    Cell *inicio;
    Cell *fim;
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma fila encadeada
FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


// Retorna 1 se a fila está vazia ou 0, caso contrário
int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


// Enfileirar um item
void enfileirar(int key, FilaE* f){
    Cell *aux; // Nova célula

    // Caso a pilha encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (f == NULL)
        f = criar_filaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Caso a fila ainda esteja vazia, o primeiro e
    // o último elemento são iguais
    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        // Caso a fila não esteja vazia, basta atualizar
        // o final da estrutura
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


// Desenfileirar um item da fila
int desenfileirar(FilaE* f){
    Cell *aux; // Primeiro elemento da fila
    int item = INT_MIN; // Valor que está no início da fila

    if (!filaE_vazia(f)){
    	// obter o primeiro elemento da fila
        aux = f->inicio;

        f->inicio = aux->next;
        
        if (f->inicio == NULL)
        	f->fim = NULL;

        // Acessar o conteúdo da célula
        item = aux->item;

        // Liberar a célula desenfileirada
        free(aux);
    }

    return item;
}


// verifica o item que está no início fila
int verificar_inicio(FilaE *f){
    if (!filaE_vazia(f))
        return f>inicio->item;
    else
        return INT_MIN;
}


// verifica o item que está no fim fila
int verificar_fim(FilaE *f){
    if (!filaE_vazia(f))
        return f->fim->item;
    else
        return INT_MIN;
}

// Imprimir o conteúdo da fila
void imprimir_fila(FilaE* f){
    Cell *aux; // Para percorrer a fila, deve ser utilizada
    	       // uma variável auxiliar para não perder o
    	       // topo da lista

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


// Desalocar a fila
int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (!filaE_vazia(f))
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}


