typedef struct Cell Cell; // Renomeação da struct Cell

typedef struct FilaE FilaE; // Renomeação da estruct FilaE

// Cria uma nova célula
Cell* criar_celula(int key);

// Função para criar uma fila encadeada
FilaE* criar_filaE();

// Retorna 1 se a fila está vazia ou 0, caso contrário
int filaE_vazia(FilaE* f);

// Enfileirar um item
void enfileirar(int key, FilaE* f);

// Desenfileirar um item da fila
int desenfileirar(FilaE* f);

// verifica o item que está no início fila
int verificar_inicio(FilaE *f);

// verifica o item que está no fim fila
int verificar_fim(FilaE *f);

// Imprimir o conteúdo da fila
void imprimir_fila(FilaE* f);

// Desalocar a fila
int liberar_filaE(FilaE* f);
