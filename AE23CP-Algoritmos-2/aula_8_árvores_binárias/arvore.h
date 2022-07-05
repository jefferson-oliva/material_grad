#include <stdio.h>

typedef struct Node Node;

Node* criar(int item);

Node* pesquisar(int item, Node* tree);

int min(Node* tree);

int max(Node* tree);

Node* inserir(int item, Node* tree);

int remover(int item, Node* tree);

void imprimirInfix(Node* tree);

void imprimirPrefix(Node* tree);

void imprimirPosfix(Node* tree);

void liberar_arvore(Node* tree);
