#define TAM_MAX 100 // tamanho máximo da fila

typedef struct Fila Fila;

// Criar uma fila vazia
Fila* criar_fila();

// Verificar se a fila está cheia
int fila_cheia(Fila *f);

// Verificar se a fila está vazia
int fila_vazia(Fila *f);

// Colocar um item na fila
int enfileirar(Fila *f, int chave);

// remover um item da fila
int desenfileirar(Fila *f);

// verifica o item que está no início fila
int verificar_inicio(Fila *f);

// verifica o item que está no fim fila
int verificar_fim(Fila *f);

// Imprimir conteúdo da fila
void imprimir_fila(Fila *f);

// liberar fila
void liberar_fila(Fila *f);
