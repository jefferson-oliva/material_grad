typedef struct Cell Cell;
typedef struct Lista Lista;


Lista* criar_lista();

Cell* criar_celula(int key);

int lista_vazia(Lista *l);

int procurar(int key, Lista *l);

int remover_na_lista(int key, Lista *l);

void inserir_na_lista(int key, Lista *l);

void imprimir_lista(Lista *l);

int liberar_lista(Lista *l);
