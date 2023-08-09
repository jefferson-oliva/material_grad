#ifndef _LISTA_
#define _LISTA_

#define MAX_SIZE 100 // tamanho máximo da lista

typedef struct ItemL ItemL; // Renomeação da estrutura struct ItemL, que representa uma unidade da lista
typedef struct Lista Lista; // Renomeação da estrutura struct Lista

// Função para criar uma lista estática
Lista* criar_lista();

// Retorna 1 se a lista está vazia ou 0, caso contrário
int lista_vazia(Lista *l);

// Retorna 1 se a lista está cheia ou 0, caso contrário
int lista_cheia(Lista *l);

// Procura a posição de um item com a chave e retorna a sua respectiva posição
// Caso o item não seja encontrado, é retornado -1
int buscar(Lista *l, int chave);

// Um item é inserido no final da lista caso ela não estiver cheia.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int inserir(Lista *l, int chave);

// O item procurado e removido da lista caso ela. Para isso, a lista não deve estar vazia e o item
// deve existir.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int remover(Lista *l, int chave);

// Imprime o conteúdo da lista
void imprimir_lista(Lista *l);

// Libera a lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_lista(Lista *l);

#endif // _LISTA_

