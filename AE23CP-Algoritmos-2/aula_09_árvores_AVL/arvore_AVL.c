#include <stdio.h>
#include "arvore.h"

struct Pointer{
	int item; // chave
	int fb; // fator de balanceamento
	struct Pointer *left; // sub-árvore esquerda
	struct Pointer *right; // sub-árvore direita
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
	Node *auxA, *auxB;

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







