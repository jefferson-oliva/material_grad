#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

struct Cell{
        int item;
        int col;
        Cell *next;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
};


Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int col){
	Cell *nova = (Cell*) malloc(sizeof(Cell));
	nova->item = item;
	nova->col = col;
	nova->next = NULL;

	return nova;
}


static int procurar_lista(int item, ListaE *l){
        Cell *aux;

        if (l != NULL){
                aux = l->head;

                while ((aux != NULL) && (aux->item != item))
                	aux = aux->next;
        }

        if ((aux != NULL) && (aux->item == item))
                return 1;
        else
                return 0;
}


int buscar(int item, Spa_Mat* mat){
        int i;
        int aux = 0;

        for (i = 0; (i < mat->n_lin) && (aux == 0); i++)
                aux = procurar_lista(item, mat->lin[i]);

        return aux;
}


static int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}


// Se existir elemento na posição [l][c], retorne o valor. Caso contrário, retorne 0 (nulo)
int buscar_pos(int l, int c, Spa_Mat* mat){
    int i;
    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c < aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}


// Esta função só é chamada quando item > 0
// Caso a célula com coluna col exista, basta mudar o seu respectivo valor. Caso contrário,
// deve ser criada uma nova célula
static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;
    
    // Verificar se a lista da matriz tem a cabeça vazia ou a coluna em que a coluna em que 
    // haverá inserção é menor em comparação com a da primeira célula da lista.
    // Caso esse teste retornar verdadeiro, a célula será inserida na primeira posição da lista.
    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    // Se a lista não estiver vazia, é verificado se o seu primeiro elemento tem a coluna igual
    // a col. Caso positivo, apenas o valor da célula é trocado 
    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head; // a nova célula deverá ser colocada entre auxP e auxA
        auxP = auxA;

        // Encontrar uma posição adequada para inserção/troca
        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }
        
        // Se a coluna col existir, basta trocar o valor de item
        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        // Caso contrário, uma nova célula deve ser criada
        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next; // auxP
            auxA->next = novo;
        }
    }
}


// Esta função só é chamada quando item <= 0
// Caso a célula com coluna col exista, basta remover a céluna. Caso contrário, nada é feito.
static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;
    
    if (l->head != NULL){
    	// Verificar se a célula que deverá ser removida é o primeiro elemento da lista.
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA; // Se for feita a remoção, auxP será removida e auxA->next = auxP->next

            // Encontrar uma posição adequada para remoção
            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }
            
            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}


// Se item for <= 0, uma célula poderá ser removida. Caso contrário, poderá ocorrer um dos seguintes
// cenários:
// 1 - Se a coluna existir na l-ésima lista, a sua respectiva célula terá o seu valor alterado.
// 2 - Caso contrário, uma nova célula deverá ser criada e inserida de forma ordenada (por coluna)
//     na l-ésima lista 
void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}


void imprimir(Spa_Mat* mat){
    int i, j;
    Cell* aux;

    for (i = 0; i < mat->n_lin; i++){
        aux = mat->lin[i]->head;
        j = 0;

        while (aux != NULL){
            while (j < aux->col){
                printf("0 ");
                j++;
            }

            printf("%d ", aux->item);
            j++;
            aux = aux->next;
        }

        for (j; j < mat->n_col; j++)
            printf("0 ");

        printf("\n");
    }
}


