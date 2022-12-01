#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

struct Node{
    int item;
    struct Node *left;
    struct Node *right;
};


Node* criar(int item){
    Node * tree = (Node *) malloc(sizeof(Node));
    
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
        
    return tree;
}


Node* pesquisar(int item, Node* tree){
    if (tree != NULL){
        if (item == tree->item)
            return tree;
        else if (item < tree->item)
            return pesquisar(item, tree->left);
        else
            return pesquisar(item, tree->right);
    }else
        return NULL;
}


int min(Node* tree){
    Node* aux = tree;
    
    if (aux != NULL){
        while (aux->left != NULL)
            aux = aux->left;
        
        return aux->item;
    }
    
    return INT_MIN;
}


int max(Node* tree){
    Node* aux = tree;
    
    if (aux != NULL){
        while (aux->right != NULL)
            aux = aux->right;
        
        return aux->item;
    }
    
    return INT_MAX;
}



Node* inserir(int item, Node* tree){
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);
        
    return tree;
}


Node* remover(int item, Node* tree){
    Node *aux, *auxP, *auxF;
    
    if (tree != NULL){
        if (item < tree->item)
            tree->left = remover(item, tree->left);
        else if (item > tree->item)
            tree->right = remover(item, tree->right);
        else{
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
            
            free(aux);
        }
    }
    
    return tree;
}

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


NodeAVL* abb_2_avl(Node *tree, NodeAVL *tb){
    int grown = 0;
    
    if (tree != NULL){
        tb = inserirAVL(tb, tree->item, &grown);
        tb = abb_2_avl(tree->left, tb);
        tb = abb_2_avl(tree->right, tb);
    }
    
    return tb;
}


void imprimirAVLPrefix(NodeAVL* tree){
    if (tree != NULL){
        printf("%d ", tree->item);
        imprimirAVLPrefix(tree->left);
        imprimirAVLPrefix(tree->right);
    }
}

void imprimirPrefix(Node* tree){
    if (tree != NULL){
        printf("%d ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}


int main() {
    int n, i, item;
    Node *tree = NULL;
    NodeAVL *avl = NULL;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%d", &item);
        tree = inserir(item, tree);
    }
    
    avl = abb_2_avl(tree, avl);
    
    imprimirAVLPrefix(avl);
    
    return 0;
}
