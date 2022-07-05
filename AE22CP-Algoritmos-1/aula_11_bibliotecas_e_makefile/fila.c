#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct ItemF{
	int chave;

	 /*
    Outros campos
    */
};

struct Fila{
	ItemF item[TAM_MAX];
	int ini; // posição do primeiro item
	int fim; // posição do último item
	int tam; // tamanho da fila
};

// Criar uma fila vazia
Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

// Verificar se a fila está cheia
int fila_cheia(Fila *f){

    if (f == NULL)
        return -1; // A fila é nula
    else if (f->tam < TAM_MAX)
        return 0; // A fila não está cheia, pois o seu tamanho atingiu a capacidade máxima
    else
        return 1; // fila cheia
}

// Verificar se a fila está vazia
int fila_vazia(Fila *f){
    if (f == NULL)
        return -1; // A fila é nula
    else if (f->tam > 0)
        return 0; // A fila não está vazia, pois o seu tamanho é maior que zero
    else
        return 1; // fila vazia
}

// Colocar um item na fila
int enfileirar(Fila *f, int chave){
    ItemF item;

    // Se a fila for vazia, um espaço é alocado para ela
    if (f != NULL){
        f = criar_fila();
        f->ini = 0;
    }

    // Se a fila não estiver cheia, enfileirar um item
    // ! => operação lógica de negação
    // Exemplos:
    // !0 = 1
    // !(número diferente de 0) = 0
    // Caso a fila seja nula, antes de entrar no comando if, ela é criada
    // ou seja, não precisa fazer "if (pilha_cheia(p) == 0)"
    if (!fila_cheia(f)){
        item.chave = chave;

        // Ao enfileirar um item, a posição do último elemento da fila
        // deve se atualizada. Antes da atualização, se a posição fim
        // for menor que a capacidade máxima da lista menos 1, basta
        // apenas incrementar o campo fim. Caso contrário, f->fim = 0;
        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        // Após a atualização da posição final da fila, basta atribuir o
        // novo item na última posição da fila
        f->item[f->fim] = item;

        // Atualizar o tamanho da fila, que aumentou
        f->tam++;

        return 1; // Operação bem sucedida
    }

    return 0; // A fila estava cheia
}

// remover um item da fila
ItemF* desenfileirar(Fila *f){
    ItemF *item = NULL;

    // Verificar se a fila é vazia (1) ou nula (-1)
    // A única condição para "entrar" no comando if é a função abaixo
    // retornar 0, cuja negação é 1
    // Para qualquer retorno diferente de 0, a negação será 0
    if (!fila_vazia(f)){
        item = (ItemF*) malloc(sizeof(ItemF));

        *item = f->item[f->ini];

        // Quando um elemento é desenfileirado, o campo ini deve ser
        // atualizado. Se a posição ini for menor que a capacidade
        // máxima da lista menos 1, basta apenas incrementar o campo
        // ini. Caso contrário, f->ini = 0;
        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0)
            f->ini = -1;
    }

    return item;
}

// Imprimir conteúdo da fila
void imprimir_fila(Fila *f){
    // Uma cópia da fila deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela operação desempilhar, ou seja,
    // se usarmos a fila original (f), perderíamos os seus dados
    Fila aux = *f;
    ItemF *item;

    // Como a variável aux não é ponteiro, para utilizamos o seu
    // endereço como parâmetro para chamarmos a função fila_vazia
    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d\n", obter_chaveF(item));

        // Para cada item desenfileirado, um espaço na memória é alocado
        // para armazená-lo. Por essa razão, devemos liberá-lo após cada
        // uso
        liberar_itemF(item);
    }
}

// liberar fila
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

// Liberar um item
void liberar_itemF(ItemF *item){
    if (item != NULL)
        free(item);
}

// Obter chave de um item
// Como não podemos acessar diretamente os registros das estruturas
// fora do arquivo em que os mesmos são declarados, devemos criar
// funções para acessá-los
int obter_chaveF(ItemF *item){
    return item->chave;
}
