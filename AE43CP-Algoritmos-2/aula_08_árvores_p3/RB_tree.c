#include <stdio.h>
#include <stdlib.h>
#include "RB_tree.h"

struct NodeVP{
    int key;
    int color; // 0 - vermelho, 1 - preto
    NodeVP *father;
    NodeVP *left;
    NodeVP *right;
};


NodeVP* criar_AVP(int key){
    NodeVP* tree = (NodeVP*) malloc(sizeof(NodeVP));
    tree->key = key;
    tree->color = 0;
    tree->left = NULL;
    tree->right = NULL;
    tree->father = NULL;

    return tree;
}


NodeVP* pesquisar(NodeVP *tree, int key){
    if (tree != NULL){
        if (key == tree->key)
            return tree;
        else if (key < tree->key)
            return pesquisar(tree->left, key);
        else
            return pesquisar(tree->right, key);
    }

    return NULL;
}



static NodeVP* obter_avo(NodeVP *no){
    if ((no != NULL) && (no->father != NULL)){
        return no->father->father;
    }

    return NULL;
}


static NodeVP* obter_tio(NodeVP *no){
    NodeVP* avo = obter_avo(no);
    NodeVP* aux = NULL;
    

    if (avo != NULL){
        if (avo->left == no->father){
            aux = avo->right;
        }else
            aux = avo->left;
    }

    return aux;
}


static NodeVP* rotacionar_dir(NodeVP *x){
    NodeVP *p = x->father; // pai de x
    NodeVP *a = p->father; // avô de x
    
    p->father = a->father; // o nó "p" será "promovido", ou seja, o nó "a" passará
                           // a ser o filho direito de "p". Nesse caso, temos que
                           // atualizar o pai de "p", que passará a ser o pai de
                           // "a" (a->father) mais adiante
    
    if (a->father != NULL){
        // Se o nó "a" tem pai, então a sua decedência também deve ser atualizada.
    	// Assim, temos que verificar qual sub-árvore do nó bisavô de "x" tem a raiz
    	// igual ao nó "a".
        if (a->father->left == a)
            a->father->left = p; // o nó "p" será o filho esquerdo do pai de "a"
        else
            a->father->right = p; // o nó "p" será o filho direito do pai de "a"
    }
    
    a->father = p; // o nó "p" passa a ser pai de "a"
    a->left = p->right; // antes de atualizarmos o descendente direito de "p", temos
    			 // que garantir que não perderemos a sua respectiva subárvore
    p->right = a; // atualização do filho direito de "p"
    
    x = p; // atualização do nó "x"
    
    return x;
}


static NodeVP* rotacionar_esq(NodeVP *x){
    NodeVP *p = x->father; // pai de x
    NodeVP * a = p->father; // avô de x
    
    p->father = a->father; // o nó "p" será "promovido", ou seja, o nó "a" passará
                           // a ser o filho direito de "p". Nesse caso, temos que
                           // atualizar o pai de "p", que passará a ser o pai de
                           // "a" (a->father) mais adiante
    
    if (a->father != NULL){
    	// Se o nó avô tem pai, então a sua decedência também deve ser atualizada.
    	// Assim, temos que verificar qual sub-árvore do nó bisavô tem a raiz
    	// igual ao nó avô.
        if (a->father->right == a)
            a->father->right = p; // o nó "p" será o filho direito do pai de "a"
        else
            a->father->left = p; // o nó "p" será o filho esquerdo do pai de "a"
    }
    
    a->father = p; // o nó "p" passa a ser pai de "a"
    a->right = p->left; // antes de atualizarmos o descendente esquerdo de "p", temos
    			 // que garantir que não perderemos a sua respectiva subárvore
    p->left = a; // atualização do filho esquerdo de "p"

    x = p; // atualização do nó "x"
    
    return x;
}


static NodeVP* rotacionar_dir_esq(NodeVP *x){
    NodeVP *p = x->father; // pai de x
    NodeVP *a = p->father; // avô de x
    
    // Rotação à direita
    x->father = a;
    a->right = x;
    p->left = x->right;
    x->right = p;
    p->father = x;
    
    // Rotação à esquerda
    x = rotacionar_esq(p);

    return x;
}


static NodeVP* rotacionar_esq_dir(NodeVP *x){
    NodeVP *p = x->father; // pai de x
    NodeVP * a = p->father; // avô de x
    
    // Rotação à esquerda
    x->father = a;
    a->left = x;
    p->father = x;
    p->right = x->left;
    x->left = p;
    
    // Rotação à direita
    x = rotacionar_dir(p);

    return x;
}


static NodeVP* balancear(NodeVP *x){
    NodeVP *pai, *tio;

    if (x->father == NULL){ // caso 1
        x->color = 1;
    }else{
        pai = x->father;

        if (pai->color == 0){
            tio = obter_tio(x);

            if ((tio != NULL) && (tio->color == 0)){ // caso 2
                pai->color = tio->color = 1;
                x = obter_avo(x);
        
            if (x->father != NULL)
                x->color = 0;
            }else{ // caso 3
                if (pai->left == x){ // caso 3: rotação à direita
                    if (pai->father->left == pai)
                        x = rotacionar_dir(x); // caso 3a
                    else
                        x = rotacionar_dir_esq(x); // caso 3c
                }else{ // caso 3: rotação à esquerda
                    if (pai->father->right == pai)
                        x = rotacionar_esq(x); // caso 3b
                    else
                        x = rotacionar_esq_dir(x); // caso 3d
                }

                x->color = 1;
                
                if (x->left != NULL)
                    x->left->color = 0;
                
                if (x->right != NULL)
                    x->right->color = 0;
            }
        }
    }
    
    return x;
}


NodeVP* inserir(NodeVP *tree, int key){
    NodeVP *auxP, *auxF;

    if (tree == NULL){
        tree = criar_AVP(key);
        tree->color = 1;
    }else{
        auxP = auxF = tree;

        while (auxF != NULL){
            auxP = auxF;

            if (key < auxF->key)
                auxF = auxF->left;
            else
                auxF = auxF->right;
        }

	// Nas linhas anteriores, o processo de busca é igual ao da árvore binária de 
	// busca "convencional". A partir da, nesta função, após o novo nó ser criado, 
	// o seu pai deve ser atualizado (que deverá ser auxP)
        auxF = criar_AVP(key);
        auxF->father = auxP;

	// Atualizar o filho de auxP (a inserção é praticamente igual ao da árvore de 
	// busca "convencional")
        if (auxF->key < auxP->key)
            auxP->left = auxF;
        else
            auxP->right = auxF;

	// Após a inserção estar completa, a árvore deve ser rebalanceada
        while ((auxF->father != NULL) && (auxF->color == 0) && (auxF->father->color == 0))
            auxF = balancear(auxF);
        
        // Procura pelo nó raiz
        while (auxF->father != NULL)
            auxF = auxF->father;

	// atualização do nó raiz da árvore
        tree = auxF;
    }
    
    return tree;
}
