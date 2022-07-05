#define N 5 // ordem da árvore

typedef struct NodeB NodeB;


NodeB* criar();

int liberar(NodeB *tree);

int pesquisar(int key, NodeB *tree);

int pesquisaSequencial(int key, NodeB *tree);

NodeB* inserir(NodeB *tree, int key);
