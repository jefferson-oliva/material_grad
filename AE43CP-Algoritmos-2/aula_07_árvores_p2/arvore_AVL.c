#include <stdio.h>
#include <stdlib.h>
#include "arvore_AVL.h"

struct Node{
	int item; // chave
	int fb; // fator de balanceamento
	struct Node *left; // sub-árvore esquerda
	struct Node *right; // sub-árvore direita
};


Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));

	tree->item = item;
    	tree->fb = 0;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}


// Implementações das rotações LL e LR
// Nos slides da aula sobre árvores AVL contêm ilustrações das rotações
static Node* rotateL(Node *tree){
	Node *auxA = tree->left, *auxB;

	// Quanto o filho esquerdo possui o fator de balanceamento positivo
	// então a rotação é LL
	if (auxA->fb == +1){
		tree->left = auxA->right;
		auxA->right = tree;
		tree->fb = 0;
		tree = auxA;
	}else{ // Caso contrário (fb negativo), a rotação é LR
		auxB = auxA->right;
		auxA->right = auxB->left;
		auxB->left = auxA;
		tree->left = auxB->right;
		auxB->right = tree;

		// Atualização dos fatores de balanceamento
		if (auxB->fb == +1)
			tree->fb = -1; // A inserção foi na sub-árvore esquerda de auxB (caso 1)
		else
			tree->fb = 0; // A inserção foi na sub-árvore direita de auxB (caso 2)

		if (auxB->fb == -1)
			auxA->fb = +1; // A inserção foi na sub-árvore direita de auxB (caso 2)
		else
			auxA->fb = 0; // A inserção foi na sub-árvore esquerda de auxB (caso 1)

		tree = auxB;
	}
	
	return tree;
}


// Implementações das rotações RR e RL
// Nos slides da aula sobre árvores AVL contêm ilustrações das rotações
static Node* rotateR(Node *tree){
	Node *auxA = tree->right, *auxB;

	// Quanto o filho direito possui o fator de balanceamento positivo
	// então a rotação é RR
	if (auxA->fb == -1){
		tree->right = auxA->left;
		auxA->left = tree;
		tree->fb = 0;
		tree = auxA;
	}else{ // Caso contrário (fb negativo), a rotação é RL
		auxB = auxA->left;
		auxA->left = auxB->right;
		auxB->right = auxA;
		tree->right = auxB->left;
		auxB->left = tree;

		// Atualização dos fatores de balanceamento
		if (auxB->fb == -1)
			tree->fb = +1; // A inserção foi na sub-árvore direita de auxB (caso 1)
		else
			tree->fb = 0; // A inserção foi na sub-árvore direita de auxB (caso 2)

		if (auxB-> fb == +1)
			auxA->fb = -1; // A inserção foi na sub-árvore direita de auxB (caso 2)
		else
			auxA->fb = 0; // A inserção foi na sub-árvore direita de auxB (caso 1)

		tree = auxB;
	}
	
	return tree;
}


//
Node* inserir(Node* tree, int value, int *grown){
	if(tree == NULL){
		tree = criar(value);

		*grown = 1;

	}else if (value < tree->item){
		tree->left = inserir(tree->left, value, grown);

		if (*grown){ // verificar se aumentou a árvore pelo lado esquerdo
			switch (tree->fb){
				case -1: tree->fb = 0; *grown = 0; break; // AVL balanceada
				case 0: tree->fb = +1; break;// AVL balanceada
				case +1: tree = rotateL(tree); tree->fb = 0; *grown = 0;// AVL desbalanceada
			}
		}
	}else if (value > tree->item){
		tree->right = inserir(tree->right, value, grown);

		if (*grown){
			switch (tree->fb){ // verificar se aumentou a árvore pelo lado direto
				case +1: tree->fb = 0; *grown = 0; break;
				case 0: tree->fb = -1; break;
				case -1: tree = rotateR(tree); tree->fb = 0; *grown = 0;
			}
		}
	}

	return tree;
}




static Node* rotateLRM(Node *tree, int *reduced){
	Node *auxA, *auxB;

	switch (tree->fb){
        case +1: tree->fb = 0; break; // AVL balanceada
        case 0: tree->fb = -1; *reduced = 0; break;// AVL balanceada
        case -1:
            auxA = tree->right;

            if (auxA->fb <= 0){ // rotação RR
                tree->right = auxA->left;
                auxA->left = tree;

                if(auxA->fb == 0){
                    tree->fb = -1;
                    auxA->fb = +1;
                    *reduced = 0;
                }else
                    tree->fb = auxA->fb = 0;

                tree = auxA;
            }else{ // Rotação RL
                auxB = auxA->left;
                auxA->left = auxB->right;
                auxB->right = auxA;
                tree->right = auxB->left;
                auxB->left = tree;

                if (auxB->fb == -1)
                    tree->fb = +1;
                else
                    tree->fb = 0;

                if (auxB->fb == +1)
                    auxA->fb = -1;
                else
                    auxA->fb = 0;

                tree = auxB;
                auxB->fb = 0;
            }
    }

	return tree;
}


static Node* rotateRRM(Node *tree, int *reduced){
	Node *auxA, *auxB;

	switch (tree->fb){
        case -1: tree->fb = 0; *reduced = 0; break;
        case 0: tree->fb = 1; break;
        case +1:
            auxA = tree->left;

            if (auxA->fb >= 0){ // rotação LL
                tree->left = auxA->right;
                auxA->right = tree;

                if(auxA->fb == 0){
                    tree->fb = +1;
                    auxA->fb = -1;
                    *reduced = 0;
                }else
                    tree->fb = auxA->fb = 0;

                tree = auxA;
            }else{ // Rotação LR
                auxB = auxA->right;
                auxA->right = auxB->left;
                auxB->left = auxA;
                tree->left = auxB->right;
                auxB->right = tree;

                // Atualização dos fatores de balanceamento
                if (auxB->fb == +1)
                    tree->fb = -1;
                else
                    tree->fb = 0;

                if (auxB->fb == -1)
                    auxA->fb = +1;
                else
                    auxA->fb = 0;

                tree = auxB;
                auxB->fb = 0;
            }
    }

	return tree;
}


// Verificar se este código está correto
Node* remover(Node* tree, int valor, int *reduced){
    Node *aux, *auxP, *auxF;

    if (tree != NULL){
        if (valor < tree->item){
            tree->left = remover(tree->left, valor, reduced);

            if (*reduced)
                tree = rotateLRM(tree, reduced);
        }else if (valor > tree->item){
            tree->right = remover(tree->right, valor, reduced);

            if (*reduced)
                tree = rotateRRM(tree, reduced);
        }else{
            aux = tree;

            if (aux->left == NULL)
                tree = tree->right;
            else if (aux->right == NULL)
                tree = tree->left;
             else{
                auxP = aux->right;
                auxF = auxP;

                while (auxF->left != NULL){
                    auxP = auxF;
                    auxF = auxF->left;
                }

                if (auxP != auxF){
                    auxP->left = auxF->right;
                    auxF->left = aux->left;
                }

                auxF->right = aux->right;

                tree = auxF;
            }

            *reduced = 1;
            free(aux);
        }
    }

    return tree;
}


void imprimirInfix(Node* tree){
    if (tree != NULL){
        imprimirInfix(tree->left);
        printf("%i ", tree->item);
        imprimirInfix(tree->right);
    }
}


void imprimirPrefix(Node* tree){
    if (tree != NULL){
        printf("%i ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}


void imprimirPosfix(Node* tree){
    if (tree != NULL){
        imprimirPosfix(tree->left);
        imprimirPosfix(tree->right);
        printf("%i ", tree->item);
    }
}

void liberar_arvore(Node* tree){
    if (tree != NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

