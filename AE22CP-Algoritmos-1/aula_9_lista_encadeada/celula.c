#include <stdlib.h>
#include "celula.h"

// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa célula para qualquer 
              // tipo de informação, recomendo o uso de ponteiro 
              // genérico. Exemplo: void* item;
    Cell *next;
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

// Acessar conteúdo da célula
int acessar_celula(Cell* cell){
    return cell->item;
}

/**
Insira implementações aqui
*/
