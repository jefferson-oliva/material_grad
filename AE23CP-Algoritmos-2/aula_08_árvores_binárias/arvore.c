#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arvore.h"

struct Node{
	int item; // chave
	struct Node *left; // referência para a sub-árvore esquerda
	struct Node *right; // referência para a sub-árvore direita
};


// criar nó
Node* criar(int item){
	Node * tree = (Node *) malloc(sizeof(Node));
	
	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
		
	return tree;
}


// Pesquisar por um determinado valor na árvore
Node* pesquisar(int item, Node* tree){
	if (tree != NULL){
		if (item == tree->item)
			return tree; // caso o item seja encontrado, basta retornar o respectivo nó
		else if (item < tree->item) // o item procurando é menor que o do nó atual
			return pesquisar(item, tree->left); // chamada recursiva para a sub-árvore esquerda
		else // o item procurando é maior que o do nó atual
			return pesquisar(item, tree->right); // chamada recursiva para a sub-árvore direita
	}else
		return NULL;
}


// procurar o valor mínimo na árvore
int min(Node* tree){
	Node* aux = tree;
	
	if (aux != NULL){
		// o menor item é o nó "mais a esquerda" da árvore
		while (aux->left != NULL)
			aux = aux->left;
		
		return aux->item;
	}
	
	return INT_MIN;
}


// procurar o valor máximo na árvore
int max(Node* tree){
	Node* aux = tree;
	
	if (aux != NULL){
		// o maior item é o nó "mais a direita" da árvore
		while (aux->right != NULL)
			aux = aux->right;
		
		return aux->item;
	}
	
	return INT_MAX;
}


// inserir um novo elemento na árvore
Node* inserir(int item, Node* tree){
	// se o nó é nulo, basta criar um novo
	if (tree == NULL)
		tree = criar(item);
	// Se o valor do nó for maior que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore esquerda é
	// chamada
	else if (item < tree->item)
		tree->left = inserir(item, tree->left);
	// Se o valor do nó for menor que o do item a ser inserido,
	// uma chamada recursiva para a sub-árvore direita é
	// chamada
	else if (item > tree->item)
		tree->right = inserir(item, tree->right);
		
	return tree;
}


// remover um nó da árvore
int remover(int item, Node* tree){
	Node *aux, *auxP, *auxF;
	
	if (tree != NULL){
		// o nó a ser removido é procurado a partir de processo
		// de busca similar ao método "pesquisar"
		if (item < tree->item)
			remover(item, tree->left);
		else if (item > tree->item)
			remover(item, tree->right);
			
		// Esta parte significa que o item foi encontrado
		else{
			aux = tree;
			
			// Caso em que o nó a ser removido contém 
			// um (sub-árvore direita) ou nenhum descendente
			if (aux->left == NULL)
				tree = tree->right;
			// O nó contém apenas a sub-arvore esquerda como 
			// descendente
			else if (aux->right == NULL)
				tree = tree->left;
			// O nó contém 2 descendentes
			else{
				auxP = aux->right;
				auxF = auxP;
				
				// procurar o menor item da sub-árvore direita do
				// nó a ser removido
				while (auxF->left != NULL){
					auxP = auxF;
					auxF = auxF->left;
				}
				
				// Se ambos nós são iguais, significa que os mesmos
				// não têm descendentes, ou seja, a sub-árvore direita
				// do nó que deverá ser removido possui altura 0. Assim,
				// o laço a seguir não seria executado a seguir se a
				// afirmação da frase anterior for verdadeira.
				if (auxP != auxF){
					auxP->left = auxF->right;
					auxF->left = aux->left;
				}
				
				auxF->right = aux->right;
				
				tree = auxF;
			}
			
			free(aux);
			
			return 1;
		}
	}
	
	return 0;
}


// Imprime os elementos da árvore em ordem crescente (se os menores 
// elementos estiverem à esquerda) ou decrescente (caso contrário)
void imprimirInfix(Node* tree){
	if (tree != NULL){
		imprimirInfix(tree->left);
		printf("\n%i", tree->item);
		imprimirInfix(tree->right);
	}
}


// Impressão prefixa
void imprimirPrefix(Node* tree){
	if (tree != NULL){
		printf("\n%i", tree->item);
		imprimirPrefix(tree->left);
		imprimirPrefix(tree->right);
	}
}


// Impressão posfixa
void imprimirPosfix(Node* tree){
	if (tree != NULL){
		imprimirPosfix(tree->left);
		imprimirPosfix(tree->right);
		printf("\n%i", tree->item);
	}
}


// Desalocar todos os nós da árvore
void liberar_arvore(Node* tree){
    if (tree != Null){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

