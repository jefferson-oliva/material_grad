#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct NodeAVL NodeAVL;

struct NodeAVL{
	int item;
	int fb;
	struct NodeAVL *left; 
	struct NodeAVL *right;
};


NodeAVL* criar_AVL(int item){
	NodeAVL * tree = (NodeAVL *) malloc(sizeof(NodeAVL));

	tree->item = item;
    	tree->fb = 0;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}


static NodeAVL* rotateL(NodeAVL *tree){
	NodeAVL *auxA = tree->left, *auxB;

	if (auxA->fb == +1){
		tree->left = auxA->right;
		auxA->right = tree;
		tree->fb = 0;
		tree = auxA;
	}else{
		auxB = auxA->right;
		auxA->right = auxB->left;
		auxB->left = auxA;
		tree->left = auxB->right;
		auxB->right = tree;

		if (auxB->fb == +1)
			tree->fb = -1;
		else
			tree->fb = 0;

		if (auxB->fb == -1)
			auxA->fb = +1;
		else
			auxA->fb = 0;

		tree = auxB;
	}
	
	return tree;
}


static NodeAVL* rotateR(NodeAVL *tree){
	NodeAVL *auxA = tree->right, *auxB;

	if (auxA->fb == -1){
		tree->right = auxA->left;
		auxA->left = tree;
		tree->fb = 0;
		tree = auxA;
	}else{
		auxB = auxA->left;
		auxA->left = auxB->right;
		auxB->right = auxA;
		tree->right = auxB->left;
		auxB->left = tree;

		if (auxB->fb == -1)
			tree->fb = +1;
		else
			tree->fb = 0;

		if (auxB-> fb == +1)
			auxA->fb = -1;
		else
			auxA->fb = 0;

		tree = auxB;
	}
	
	return tree;
}



NodeAVL* inserirAVL(NodeAVL* tree, int value, int *grown){
	NodeAVL *auxA, *auxB;

	if(tree == NULL){
		tree = criar_AVL(value);

		*grown = 1;

	}else if (value < tree->item){
		tree->left = inserirAVL(tree->left, value, grown);

		if (*grown){
			switch (tree->fb){
				case -1: tree->fb = 0; *grown = 0; break;
				case 0: tree->fb = +1; break;
				case +1: tree = rotateL(tree); tree->fb = 0; *grown = 0;
			}
		}
	}else if (value > tree->item){
		tree->right = inserirAVL(tree->right, value, grown);

		if (*grown){
			switch (tree->fb){
				case +1: tree->fb = 0; *grown = 0; break;
				case 0: tree->fb = -1; break;
				case -1: tree = rotateR(tree); tree->fb = 0; *grown = 0;
			}
		}
	}

	return tree;
}


