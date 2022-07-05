typedef struct Cell Cell; // Renomeação da struct Cell

typedef struct PilhaE PilhaE;  // Renomeação da struct PilhaE

// Cria uma nova célula
Cell* criar_celula(int key);

// Função para criar uma pilha encadeada
PilhaE* criar_pilhaE();

// Retorna 1 se a pilha está vazia ou 0, caso contrário
int pilhaE_vazia(PilhaE *p);

// Inserir, no topo de uma pilha, um novo elemento
void empilhar(int key, PilhaE *p);

// Remover um item do topo da pilha
int desempilhar(PilhaE *p);

// Imprimir conteúdo da pilha
void imprimir_pilha(PilhaE *p);

// Desalocar pilha
int liberar_pilha(PilhaE *p);


