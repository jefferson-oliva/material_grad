typedef struct NodeVP NodeVP;

NodeVP * criar_AVP(int key);

int liberar_AVP(NodeVP *tree);

NodeVP* pesquisar(NodeVP *tree, int key);

NodeVP * inserir(NodeVP *tree, int key);
