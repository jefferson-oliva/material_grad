#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

/**
AVISO: o código não foi testado
*/

// Estrutura para representar células
struct CellDE{
    int item; // Pode ser uma struct, union, ou qualquer tipo de dados.
              // Para possibilitar o reuso dessa célula para qualquer
              // tipo de informação, recomendo o uso de ponteiro
              // genérico. Exemplo: void* item;
    CellDE *previous, *next;
};


// Estrutura para representar listas duplamente encadeadas
struct ListaDE{
    CellDE *head; // Ponteiro para o primeiro elemento da lista
};


// Cria uma nova célula
CellDE* criar_celulaDE(int key){
    CellDE *c = (CellDE*) malloc(sizeof(CellDE));
    c->item = key;

    c->previous = c->next = NULL;

    return c;
}


// Função para criar uma lista encadeada
ListaDE* criar_ListaDE(){
    ListaDE* l = (ListaDE*) malloc(sizeof(ListaDE));

    l->head = NULL;

    return l;
}


// Retorna 1 se a lista está vazia ou 0, caso contrário
int ListaDE_vazia(ListaDE *l){
    return (l == NULL) || (l->head == NULL);
}


// Verifica se um item existe na lista
int procurar(int key, ListaDE *l){
    CellDE *aux; // Para percorrer a lista, deve ser utilizada
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
void inserir_primeiro(int key, ListaDE *l){
    CellDE *aux; // Nova célula

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_ListaDE();

    // Criar nova célula
    aux = criar_celulaDE(key);

    // Apontar a nova célula para a cabeça da
    // lista
    aux->next = l->head;
    l->head->previous = aux;

    // Atualizar a cabeça da lista
    l->head = aux;
}


// Um item é inserido no final da lista
void inserir_ultimo(int key, ListaDE *l){
    CellDE *aux, *nova; // célula auxiliar e nova,
                      // respectivamente

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_ListaDE();

    // Se a lista estiver vazia, não faz sentido
    // percorrê-la
    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

	// Percorrer a lista até encontrar a última
	// célula
        while(aux->next != NULL)
            aux = aux->next;

        // Criar nova célula
        nova = criar_celulaDE(key);

	// O último elemento da lista aponta para a
	// nova célula
        aux->next = nova;
        nova->previous = aux;
    }
}


void inserir_ordenado(int key, ListaDE *l){
    CellDE *auxA, *auxP, *nova; // células auxiliares

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_ListaDE();

    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else{
        nova = criar_celulaDE(key);

        // Verificar se a lista está vazia ou se o key é menor
        // que o primeiro elemento.
        if (l->head == NULL)
            l->head = nova;
        else if (key < l->head->item){
            nova->next = l->head;
            l->head->previous = nova;
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
            nova->previous = auxP;

            // A nova célula aponta para auxA, que pode ser nula
            // ou ter um valor menor igual em relação à nova chave
            nova->next = auxA;

            if (auxA != NULL)
                auxA->previous = nova;
        }
    }
}


/* O item procurado e removido da lista caso for encontrado na mesma.
 Para isso, a lista não deve estar vazia e o item deve existir.
 A função retorna 1 se a operação for bem sucedida ou 0, caso 
 contrário*/
int remover(int key, ListaDE *l){
    CellDE *auxA; // células auxiliares

    if (!ListaDE_vazia(l)){
        auxA = l->head; // apontar o auxA para a cabeça da lista

        // Verificar se o elemento está na cabeça da lista
        if(auxA->item == key){
            // Atualizar a cabeça
            l->head = l->head->next;
            l->head->previous = NULL;
            free(auxA);
            
            return 1;
        }else{
            // Procurar a célula que deve ser removida
            while((auxA != NULL) && (auxA->item != key))
                auxA = auxA->next; // Atualizar auxA
                
            if (auxA != NULL){
                auxA->previous->next = auxA->next;
                
                if (auxA->next != NULL)
                    auxA->next->previous = auxA->previous;
            }
            
            free(auxA);
            
            return 1;
        }
    }

    return 0;
}


// Imprimir o conteúdo da lista
void imprimir(ListaDE *l){
    CellDE *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista


    if (!ListaDE_vazia(l)){
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
int liberar_LE(ListaDE *l){
    CellDE *aux = NULL; // Para percorrer a lista, deve ser utilizada
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
int tamanho_LE(ListaDE *l){
    CellDE *aux;
    int tam = 0;

     if (!ListaDE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}


