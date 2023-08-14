#define TAM_MAX 100

typedef struct Pilha Pilha;


// Criar uma pilha vazia
Pilha* criar_pilha();

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p);

// Verificar se a pilha está vazia (stack underflow)
int pilha_vazia(Pilha *p);

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int chave);

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
int desempilhar(Pilha *p);

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p);

// Liberar a pilha
void liberar_pilha(Pilha *p);

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p);

// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(Pilha *p);
