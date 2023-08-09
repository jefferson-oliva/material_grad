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

                while ((aux != NULL) && (aux->item < item))
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
    return (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}


void trocar(int item, int l, int c, Spa_Mat* mat){
    Cell *auxA, *auxP, *novo;

    if (validar_pos_matriz(l, c, mat)){
        // Verificar se a l-ésima lista da matriz tem a cabeça vazia ou a coluna em que
        // a coluna em que haverá inserção é menor em comparação com a da primeira célula da lista.
        // Também, é checado se o item é maior que zero (indicando inserção).
        // Caso esse teste passe, a célula será inserida na primeira posição da l-ésima lista
        if ((item > 0) && ((mat->lin[l]->head == NULL) || (c < mat->lin[l]->head->col))){
            novo = criar_celula(item, c);
            novo->next = mat->lin[l]->head;
            mat->lin[l]->head = novo;

        // Caso a primeira coluna já exista, é feita outra verificação
        }else if ((mat->lin[l]->head != NULL) && (c == mat->lin[l]->head->col)){
            // Se item for igual a zero, a célula é removida
            if (item == 0){
                auxA = mat->lin[l]->head;
                mat->lin[l]->head = mat->lin[l]->head->next;

                free(auxA);
            }else // Caso contrário, apenas o valor da célula é modificado
                mat->lin[l]->head->item = item;
        }else{ // Caso a inserção seja após a cabeça da l-ésima lista, serão feitos outros testes
            auxA = mat->lin[l]->head; // a nova célula deverá ser colocada entre auxP e auxA
            auxP = auxA; // Se for feita a remoção (item = 0), auxP será removido e auxA->next = auxP->next

            // Encontrar uma posição adequada para inserção/remoção
            while ((auxP != NULL) && (auxP->col < c)){
                auxA = auxP;
                auxP = auxP->next;
            }

            // Se o valor de item for maior que zero, isso significa deverá ser feita uma atualização
            // ou inserção na l-ésima lista
            if (item > 0){
                // Se existe a coluna c, basta apenas atualizar o valor da respectiva célula
                if ((auxP != NULL) && (c == auxP->col))
                    auxP->item = item;
                else{
                    // Caso contrário, criar uma nova célula e posicionar entre auxA e auxP, se possível
                    novo = criar_celula(item, c);
                    novo->next = auxA->next;
                    auxA->next = novo;
                }
            // Se item for <= 0, isso significa que a célula auxP deverá ser deletada
            }else if ((auxP != NULL) && (c == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
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

/*
// Testar uma das operações
int main() {

    Spa_Mat *matrix = criar(3, 3);

    trocar(1, 0, 0, matrix);
    trocar(2, 0, 1, matrix);
    trocar(3, 0, 2, matrix);

    imprimir(matrix);


    return 0;
}
*/

