typedef struct Node Node;

Node* criar(int item);

Node* inserir(Node* tree, int value, int *grown);

Node* remover(Node* tree, int valor, int *reduced);

void imprimirInfix(Node* tree);

void imprimirPrefix(Node* tree);

void imprimirPosfix(Node* tree);

void liberar_arvore(Node* tree);

