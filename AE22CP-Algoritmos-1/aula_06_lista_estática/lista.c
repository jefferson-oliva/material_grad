#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


// Estrutura para uma lista estática
struct Lista{
    int item[MAX_SIZE]; // A lista pode ser de qualquer tipo. Nesse caso, é uma lista de int, mas também pode ser de float, char, string, etc.
    int tam; // quantidade de elementos preenchidos na lista
};

// Função para criar uma lista estática
Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    // Ao iniciar a lista, a mesma estará "vazia"
    l->tam = 0;

    return l;
}

// Retorna 1 se a lista está vazia ou 0, caso contrário
int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}

// Retorna 1 se a lista está cheia ou 0, caso contrário
int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}

// Procura a posição de um item com a chave e retorna a sua respectiva posição
// Caso o item não seja encontrado, é retornado -1
int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        // Procurar na parte "não vazia" da lista
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    // Se chegou aqui é porque a lista está vazia ou o item não foi encontrado
    return -1;
}

// Um item é inserido no final da lista caso ela não estiver cheia.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int inserir(Lista *l, int chave){
    // Se a lista for nula, podemos alocar um espaço para ela, já que
    // pretendemos fazer uma inserção nela
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        // O item é adicionado no final da lista
        l->item[l->tam] = chave;

        // Se foi adicionado um elemento, então a lista cresceu
        l->tam++; // l->tam = l->tam + 1; ou l->tam += 1;

        // A inserção foi bem-sucedida
        return 1;
    }

    // Se chegou aqui é porque a lista estava cheia (ou nula)
    return 0;
}

// O item procurado e removido da lista caso ela. Para isso, a lista não deve estar vazia e o item
// deve existir.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    // A chave foi encontrada
    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            // Deslocamento de itens da lista para ocupar o espaço do item removido
            // Se o item a ser removido for o último, o comando abaixo não é executado
            l->item[i] = l->item[i + 1];

        // Se foi removido um elemento, então a lista diminuiu
        l->tam--; // l->tam = l->tam - 1; ou l->tam -= 1;

        // Remoção bem-sucedida
        return 1;
    }

    return 0;
}

// Imprime o conteúdo da lista
void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

// Libera a lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}


// Resolução de exercício: concatenação
// Retorna uma lista resultante da concatenação
Lista* concatenar(Lista *l1, Lista *l2){
    Lista *l3 = NULL;
    int i;

    // Verificar se uma das listas está vazia
    if (l1 == NULL)
        l3 = l2;
    else if (l2 == NULL)
        l3 = l1;
    else{
        l3 = criar_lista();

        // Utilizando a função inserir para incluir elementos das listas,
        // fornecidas como parâmetros, na lista l3
        for (i = 0; i <  l1->tam; i++)
            inserir(l3, l1->item[i]);

        for (i = 0; i <  l2->tam; i++)
            inserir(l3, l2->item[i]);
    }

    return l3;
}


// Um item é inserido de forma ordenada lista caso ela não estiver cheia.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int inserir_ordenado(Lista *l, int chave){
    int i;

    // Se a lista for nula, podemos alocar um espaço para ela, já que
    // pretendemos fazer uma inserção nela
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        // Primeiramente, temos que sinalizar que a lista cresceu, já que
        // a inserção é feita de forma ordenada e precisaremos de fazer
        // deslocamento de elementos
        l->tam++;

	// Antes de fazermos a inserção, temos que deslocar elementos até
	// encontrarmos a posição adequada para o novo item.
	// Por exemplo, o pior cenário é quando o elemento a ser inserido
	// é o menor de todos, sendo necessário deslocar tam - 1 itens para
	// podermos colocar o novo item na posição "0" (zero)
        for (i = l->tam - 1; (i > 0) && (chave < l->item[i - 1]); i--)
            l->item[i] = l->item[i - 1];

        l->item[i] = chave;

        return  1;
    }

    return 0;
}

