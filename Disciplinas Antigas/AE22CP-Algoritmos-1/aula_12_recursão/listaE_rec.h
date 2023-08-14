typedef struct Cell Cell;

typedef struct ListaE ListaE;


static Cell* criar_celula(int key);

ListaE* criar_listaE();

int listaE_vazia(ListaE *l);

int procurar(int key, ListaE *l);

void inserir_primeiro(int key, ListaE *l);

void inserir_ultimo(int key, ListaE *l);

void inserir_ordenado(int key, ListaE *l);

int remover(int key, ListaE *l);

void imprimir(ListaE *l);

void imprimir_inverso(ListaE *l);

int liberar_LE(ListaE *l);

int tamanho_LE(ListaE *l);
