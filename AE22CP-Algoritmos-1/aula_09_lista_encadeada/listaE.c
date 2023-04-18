#include <stdio.h>
#include <stdlib.h>
#include "listaE.h"


// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou qualquer tipo de dados.
              // Para possibilitar o reuso dessa célula para qualquer
              // tipo de informação, recomendo o uso de ponteiro
              // genérico. Exemplo: void* item;
    Cell *next;
};


// Estrutura para representar listas encadeadas
struct ListaE{
    Cell *head; // Ponteiro para o primeiro elemento da lista
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma lista encadeada
ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


// Retorna 1 se a lista está vazia ou 0, caso contrário
int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}


// Verifica se um item existe na lista
int procurar(int key, ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    if (l != NULL){
        aux = l->head;

	// Percorrer a lista encadeada: enquanto a chave não
	// for encotrada e o valor nulo (NULL) não for
	// alcançado, percorrer cada célula
        while (aux != NULL){
            if (aux->item == key)
            	return 1;

            aux = aux->next;
        }
    }

    return 0;
}


// Um item é inserido no início da lista
void inserir_primeiro(int key, ListaE *l){
    Cell *aux; // Nova célula

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Apontar a nova célula para a cabeça da
    // lista
    aux->next = l->head;

    // Atualizar a cabeça da lista
    l->head = aux;
}


// Um item é inserido no final da lista
void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *nova; // célula auxiliar e nova,
                      // respectivamente

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Se a lista estiver vazia, não faz sentido
    // percorrê-la
    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

	// Percorrer a lista até encontrar a última
	// célula
        while(aux->next != NULL)
            aux = aux->next;

        // Criar nova célula
        nova = criar_celula(key);

	// O último elemento da lista aponta para a
	// nova célula
        aux->next = nova;
    }
}


void inserir_ordenado(int key, ListaE *l){
    Cell *auxA, *auxP, *nova; // células auxiliares
    
    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        nova = criar_celula(key);

        // Verificar se a lista está vazia ou se o key é menor
        // que o primeiro elemento.
        if ((l->head == NULL) || (l->head->item <= key)){
            nova->next = l->head;
            l->head = nova;
        }else{
            auxP = auxA = l->head;

            // Procurar lugar na lista onde deve ser inserido
            // o nova elemento
            while((auxA != NULL) && (key > auxA->item)){
                auxP = auxA; // Guardar o endereço auxA

                auxA = auxA->next; // Atualizar auxA
            }

            // aqui o auxP terá o maior elemento que tem valor 
            // menor em comparação com a nova célula, ou seja,
            // o próximo elemento de auxP passará a ser a nova
            // célula
            auxP->next = nova;
            
            // A nova célula aponta para auxA, que pode ser nula
            // ou ter um valor menor igual em relação à nova chave
            nova->next = auxA;
        }
    }
}


/* O item procurado e removido da lista caso ela. Para isso,
 a lista não deve estar vazia e o item deve existir.
 A função retorna 1 se a operação for bem sucedida ou 0,
 caso contrário*/
int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL; // células auxiliares

    if (!listaE_vazia(l)){
        auxA = l->head; // apontar o auxA para a cabeça da lista

        // Verificar se o elemento está na cabeça da lista
        if(auxA->item == key){
            // Atualizar a cabeça
            l->head = l->head->next;
        }else{
            // apontar auxP para auxA
            auxP = auxA;

            // Procurar a célula que deve ser removida
            while((auxA != NULL) && (auxA->item != key)){
                auxP = auxA; // Guardar o endereço auxA

                auxA = auxA->next; // Atualizar auxA
            }
        }

        if (auxA != NULL){
            // Caso a chave seja encontrada, ou seja, auxA diferente de
            // nulo, fazer a célula predecessora (auxP) apontar o ponteiro
            // "next" para o próximo elemento de auxA.
            // Esta comparação é necessária, pois o elemento a ser removido
            // pode ser a primeira célula da lista, na qual auxP == NULL
            if (auxP != NULL)
            	auxP->next = auxA->next; // funciona mesmo se auxP for igual a auxA

            // Agora, a célula auxA pode ser removida com segurança
            free(auxA);

            return 1; // Operação bem-sucedida
        }
    }

    return 0;
}


// Imprimir o conteúdo da lista
void imprimir(ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaE *l){
    Cell *aux = NULL; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    // Diferentemente de uma lista estática, que pode ser ter todos
    // seus elementos desalocados de uma vez, em uma lista encadeada,
    // primeiramente deve ser desolocada célula por célula
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


// Obter o tamanho de uma lista encadeada
int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}


