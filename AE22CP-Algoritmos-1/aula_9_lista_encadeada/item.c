#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct{
    int key;
}Item;

// Alocação dinâmica para a estrutura do tipo Item
Item* criar_item(int key){
    Item* item = malloc(sizeof(Item));
    item->key = key;

    return item;
}

// Acessar elemento dentro de uma variável do tipo Item
int acessar_chave(Item *item){
    return item->key;
}

// Acessar elemento dentro de uma variável do tipo Item
int alterar_chave(Item *item, int key){
    if (item != NULL){
        item->key = key;

        return 1;
    }

    return 0;
}

// Liberar o espaço alocado para uma variável do tipo Item
int liberar_item(Item *item){
    if (item != NULL){
        free(item);

        return 1;
    }

    return 0;
}
