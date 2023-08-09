typedef struct CellDE CellDE; // Renomeação da struct CellDE

typedef struct ListaDE ListaDE; // Renomeação da struct ListaDE

// Cria uma nova célula
CellDE* criar_celulaDE(int key);

// Função para criar uma lista encadeada
ListaDE* criar_ListaDE();

// Retorna 1 se a lista está vazia ou 0, caso contrário
int ListaDE_vazia(ListaDE *l);

// Verifica se um item existe na lista
int procurar(int key, ListaDE *l);

// Um item é inserido no início da lista
void inserir_primeiro(int key, ListaDE *l);

// Um item é inserido no final da lista
void inserir_ultimo(int key, ListaDE *l);

// Um item é inserido de forma ordenada na lista
void inserir_ordenado(int key, ListaDE *l);

// O item procurado e removido da lista caso ela. Para isso, a lista não deve estar vazia e o item
// deve existir.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int remover(int key, ListaDE *l);

// Imprimir o conteúdo da lista
void imprimir(ListaDE *l);

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaDE *l);

// Obter o tamanho de uma lista encadeada
int tamanho_LE(ListaDE *l);
