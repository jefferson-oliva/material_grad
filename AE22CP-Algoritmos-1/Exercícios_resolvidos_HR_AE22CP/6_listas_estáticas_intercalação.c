#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}


int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

 
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}


int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}

Lista* intercalar(Lista* l1, Lista* l2){
    Lista* l3 = NULL;
    int i;
    
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    else{
        l3 = criar_lista();
        
        for (i = 0; (i < l1->tam) && ((i < l2->tam)); i++){
            if (buscar(l3, l1->item[i]) == -1)
                inserir(l3, l1->item[i]);
            
            if (buscar(l3, l2->item[i]) == -1)
                inserir(l3, l2->item[i]);
        }
        
        for (i = l2->tam; i < l1->tam; i++)
            if (buscar(l3, l1->item[i]) == -1)
                inserir(l3, l1->item[i]);
        
        for (i = l1->tam; i < l2->tam; i++)
            if (buscar(l3, l2->item[i]) == -1)
                inserir(l3, l2->item[i]);
    }
    
    return l3;
}


int main() {
    int i, n, aux;
    Lista *l1, *l2, *l3;

    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        l1 = criar_lista();
        l2 = criar_lista();
        
        aux = 0;
        
        while (aux != -1){
            scanf("%d ", &aux);
            
            if (aux != -1)
                inserir(l1, aux);
        }
        
        aux = 0;
        
        while (aux != -1){
            scanf("%d ", &aux);
            
            if (aux != -1)
                inserir(l2, aux);
        }
        
        l3 = intercalar(l1, l2);
        
        imprimir_lista(l3);
        
        liberar_lista(l1);
        liberar_lista(l2);
        liberar_lista(l3);
    }
       
    return 0;
}
