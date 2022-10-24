#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

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


int procurar(int key, ListaE *l){
    Cell *aux;
    
    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}



void inserir_primeiro(int key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}


void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;
    
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


int busca_transposicao(int chave, ListaE *l){
    Cell *aux, *auxC;
    int x;
    
    if ((l != NULL) && (l->head)){
        if (chave == l->head->item)
            return 1;
        else{
            auxC = l->head;
            
            while ((auxC != NULL) && (auxC->item != chave)){
                aux = auxC;
                auxC = auxC->next;
            }
            
            if (auxC != NULL){
                x = aux->item;
                aux->item = auxC->item;
                auxC->item = x;
                
                return 1;
            }
        }
    }
    
    return 0;
}


int main() {
    ListaE *l = criar_listaE();
    int testes, valor = 0;
    
    while (valor != -1){
        scanf("%d", &valor);
        
        if (valor != -1)
            inserir_ultimo(valor, l);
    }
    
    scanf("%d", &testes);
    
    while (testes > 0){
        scanf("%d", &valor);
        
        busca_transposicao(valor, l);
        
        testes--;
    }
    
    imprimir(l);
    
    //liberar_LE(l);

    return 0;
}

