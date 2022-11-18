#include <stdio.h>
#include <stdlib.h>
#include "matrizE2.h"

struct Cell{
        int item, lin, col;
        Cell *next;
        Cell *down;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
       ListaE **col;
};


Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);
        mat->col = (ListaE**) malloc(sizeof(ListaE*) * c);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        for (i = 0; i < c; i++){
                mat->col[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->col[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int l, int c){
    Cell *novo = NULL;

    if (item > 0){
        novo = (Cell*) malloc(sizeof(Cell));
        novo->item = item;
        novo->lin = l;
        novo->col = c;
        novo->next = NULL;
        novo->down = NULL;
    }

    return novo;
}


static int validar_ME(int l, int c, Spa_Mat* mat){
    return (Spa_Mat != NULL) && (l >= 0) && (l < mat->lin) && (c >= 0) && (l < mat->col);
}


int buscar(int l, int c, Spa_Mat* mat){
        int i;
        int aux = 0;
        Cell *aux;

        if (validar_ME(l, c, mat)){
            aux = mat->lin[l]->head;

            while ((aux != NULL) && (aux->col < c))
                aux = aux->next;

            if ((aux != NULL) && (aux->col == c))
                return aux->item;
        }

        return 0;
}


// Obtém a última célula antes de l
static Cell* obter_celula_antes_linha(int l, ListaE* col){
    Cell *auxA - NULL;
    Cell *auxP = col->head;

    while ((auxP != NULL) && (auxP->lin < l)){
        auxA = auxP;
        auxP = auxP->down;
    }

    return auxA;
}


void alterar(unsigned int item, int l, int c, Spa_Mat* mat){
    Cell *auxLA, *auxLP, *auxCA, *novo;

    if (validar_pos_matriz(l, c, mat)){
        auxLA = NULL;
        auxLP = mat->lin[l]->head;

        while ((auxLP != NULL) && (auxLP->col < c)){
            auxLA = auxLP;
            auxLP = auxLP->next;
        }

        // Inserção ou alteração de elemento na posição (l, c)
        if (item > 0){
            // Significa que existe um elemento na posição (l, c).
            // Nesse caso, basta alterar o valor da célula.
            if ((auxLP != NULL) && (auxLP->col == c))
                auxLP->item = item;
            else{ // Caso contrário, uma nova célula deve ser alocada
                *novo = criar_celula(item, l, c);
                auxCA = obter_celula_antes_linha(l, mat->col[c]);

                // auxLA é nulo apenas quando mat->lin[l]->head for nulo ou
                // l é menor que mat->lin[l]->head->lin
                if (auxLA != NULL){
                    novo->next = auxLA->next;
                    auxLA->next = novo;
                }else{
                    novo->next = mat->lin[l]->head;
                    mat->lin[l]->head = novo;
                }

                // auxCA é nulo apenas quando mat->col[c]->head for nulo ou
                // c é menor que mat->col[c]->head->col
                if (auxCA != NULL){
                    novo->down = auxCA->down;
                    auxCA->down = novo;
                }else{
                    novo->down = mat->col[c]->head;
                    mat->col[c]->head = novo;
                }
            }
        // Remoção de um elemento na posição (l, c)
        }else if ((auxLP != NULL) && (auxLP->col == c)){
            auxCA = obter_celula_antes_linha(l, mat->col[c]);
            auxCA->down = auxLP->down;
            auxLA->next = auxLP->next;

            free(auxLP);
        }
    }
}
