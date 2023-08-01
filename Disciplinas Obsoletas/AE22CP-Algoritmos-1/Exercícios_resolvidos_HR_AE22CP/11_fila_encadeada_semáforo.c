#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cell Cell;


typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};


struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}


static void sinal_verde(FilaE *e, FilaE *r){
    int count = 3;
    
    while (!filaE_vazia(e) && (count > 0)){
        enfileirar(desenfileirar(e), r);
        count--;
        
    }
    
    
}


void gerenciar_transito(FilaE *e1, FilaE *e2, FilaE *e3, FilaE *r){
    if (r == NULL)
        r = criar_filaE();
    
    while (!filaE_vazia(e1) || !filaE_vazia(e2) || !filaE_vazia(e3)){
        sinal_verde(e1, r);
        sinal_verde(e2, r);
        sinal_verde(e3, r);
    }
}


FilaE *leitura(){
    FilaE *f = criar_filaE();
    int item = 0;
    
    while (item != -1){
        scanf("%d", &item);
        
        if (item != -1)
            enfileirar(item, f);
    }
    
    return f;
}


int main() {
    FilaE *e1 = leitura();
    FilaE *e2 = leitura();
    FilaE *e3 = leitura();
    FilaE *r = criar_filaE();
    
    semaforo(e1, e2, e3, r);
    
    imprimir_fila(r);
    
    liberar_filaE(e1);
    liberar_filaE(e2);
    liberar_filaE(e3);
    liberar_filaE(r);
   
    return 0;
}
