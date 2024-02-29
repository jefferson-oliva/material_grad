typedef struct Cell Cell; // Renomeação da struct Cell

typedef struct ListaE ListaE; // Renomeação da struct ListaE

// Cria uma nova célula
Cell* criar_celula(int key);

// Função para criar uma lista encadeada
ListaE* criar_listaE();

// Retorna 1 se a lista está vazia ou 0, caso contrário
int listaE_vazia(ListaE *l);

// Verifica se um item existe na lista
int procurar(int key, ListaE *l);

// Um item é inserido no início da lista
void inserir_primeiro(int key, ListaE *l);

// Um item é inserido no final da lista
void inserir_ultimo(int key, ListaE *l);

// Um item é inserido de forma ordenada na lista
void inserir_ordenado(int key, ListaE *l);

// O item procurado e removido da lista caso ela. Para isso, a lista não deve estar vazia e o item
// deve existir.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int remover(int key, ListaE *l);

// Imprimir o conteúdo da lista
void imprimir(ListaE *l);

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaE *l);

// Obter o tamanho de uma lista encadeada
int tamanho_LE(ListaE *l);
