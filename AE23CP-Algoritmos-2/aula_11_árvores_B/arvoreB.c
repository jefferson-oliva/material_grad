#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvoreB.h"

struct NodeB{
     int nro_chaves;    // quantidade de chaves (elementos) na página
     int chaves[N - 1]; // Elementos da página
     NodeB *filhos[N];  // Referências para as próximas páginas
     int eh_no_folha;   // Verificar se a página é folha: onde as operações de inserção são realizadas
};


NodeB* criar(){
    NodeB *tree = malloc(sizeof(NodeB));
    int i;

    tree->eh_no_folha = 1;
    tree->nro_chaves = 0;

    for (i = 0; i < N; i++)
        tree->filhos[i] = NULL;

    return tree;
}


int liberar(NodeB *tree){
    if (tree != NULL){
        free(tree);

        return 1;
    }

    return 0;
}


/*
Método auxiliar das funções pesquisar e inserir_pagina_nao_cheia.

Tem a finalidade de encontrar a posição da chave em um determinado nó.
*/
static int busca_binaria(int key, NodeB *tree){
    int ini, fim, meio;

    if (tree != NULL){
        ini = 0;
        fim = tree->nro_chaves - 1;

        while (ini <= fim){
            meio = (ini + fim) / 2;

            if (tree->chaves[meio] == key)
                return meio; // Aqui, a chave foi encontrada
            else if (tree->chaves[meio] > key)
                fim = meio - 1;
            else
                ini = meio + 1;
        }

	// A chave não foi encontrada.
	// Neste caso, o ini é posição do filho (ponteiro para filho).
        return ini;
    }

    return -1;
}


int pesquisaSequencial(int key, NodeB *tree){
    int i;

    if (tree != NULL){
        for (i = 0; i < tree->nro_chaves && key < tree->chaves[i]; i++);

	if ((i < tree->nro_chaves) && (key == tree->chaves[i]))
        	return 1;
        else
        	return pesquisaSequencial(key, tree->filhos[i]);
    }

    return 0;
}


int pesquisar(int key, NodeB *tree){
    int pos = busca_binaria(key, tree);

    if (pos >= 0){
        if (tree->chaves[pos] == key)
            return 1;
        else
            return pesquisar(key, tree->filhos[pos]);
    }

    return 0;
}


/* 
Método auxiliar da função "inserir"

Este método tem a finalidade de dividir uma página cheia (nó) em duas.
Essa função deve ser executada antes a inclusão de uma nova chave.

Parâmetros
- pai: página pai do nó cheio
- posF_cheio: a posição da página filha em que foi feita a tentativa de inserção
*/
static NodeB * split_pag(NodeB *pai, int posF_cheio){
    int i;
    
    // A página que será dividida: as (N - 1)/2 menores chaves permanecerão nessa página.
    NodeB *pag_esq = pai->filhos[posF_cheio];
    
    // A nova página, onde serão colocadas as (N - 1)/2 maiores chaves, que estão na pag_esq.
    // É importante ressaltar que, entre a nova chave e as que estão na página cheia, 
    // uma será promovida. Por isso, cada página deverá conter por volta de (N - 1)/2 .
    NodeB *pag_dir;

    pag_dir = criar(); // nova página é gerada

    // Se a pagina que está cheia é nó folha, então a nova página deverá ser folha também. 
    // Isso vale também para as páginas não folha (nós internos).
    pag_dir->eh_no_folha = pag_esq->eh_no_folha; 

    //Quantidade de elementos (chaves) maiores que a chave "central".
    pag_dir->nro_chaves = round((N - 1) / 2);

    // preencher a nova página com (N - 1) / 2 maiores itens da página cheia.
    for (i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_esq->chaves[i + pag_dir->nro_chaves];

    // se a página esquerda não for nó-folha, a página direita deve herdar os descendentes
    // de suas respectivas chaves.
    if (!pag_esq->eh_no_folha)
        for (i = 0; i < pag_dir->nro_chaves; i++)
            pag_dir->filhos[i] = pag_esq->filhos[i + pag_dir->nro_chaves];

    pag_esq->nro_chaves = (N - 1) / 2;

    // A partir daqui, é atualizada a página pai, para que na mesma seja adicionada a chave que 
    // foi promovida. Os descendentes da página pai são deslocados em uma posição para a adição 
    // da nova página descendente. A página esquerda permanecerá no mesmo lugar. Como uma chave 
    // foi promovida, então um ponteiro deve apontar para a pag_dir. Esse ponteiro ficará na 
    // posição posF_cheio + 1.
    for (i = pai->nro_chaves + 1; i > posF_cheio + 1; i--)
        pai->filhos[i + 1] = pai->filhos[i];

    // a nova página é ligada à página pai e ocupará a posição posF_cheio + 1 entre os filhos.
    pai->filhos[posF_cheio + 1] = pag_dir;
    
    // a  página esquerda também é ligada à página pai, ocupará a posição posF_cheio entre os filhos.
    pai->filhos[posF_cheio] = pag_esq;
    
    // Promoção da menor chave da página direita (anteriormente, era a posição média).
    // Essa chave passará a separar pag_esq e  pag_dir.
    pai->chaves[posF_cheio] = pag_dir->chaves[0];
    
    // A quantidade de chaves da página pai é atualizada
    pai->nro_chaves++;

    // Anteriormente a posição dos filhos da página pai foi atualizada. Agora, as chaves da página
    // direita terão a suas respectivas posições atualizadas para alocar a chave promovida.
    for (i = 0; i < pag_dir->nro_chaves ; i++)
        pag_dir->chaves[i] = pag_dir->chaves[i + 1];

    pag_dir->nro_chaves--;

    
    return pai;
}


/* 
Método auxiliar da função "inserir"

Esse método tem o prósito de adicionar uma chave em uma página, sendo essa não cheia.

Caso a página seja folha, basta deslocar chaves para colocar a nova chave em sua respectiva posição.

Caso contrário, um teste adicional deve ser feito: se página não folha não estiver cheia, a inserção
pode ser feita sem problemas em uma página descendente (chamada recursiva dessa função).

Se página não folha estiver cheia, a mesma deve ser divida utilizando a função split_pag e uma nova 
tentativa de inserção (chamada recursiva dessa função) deve ser efetuada.

Parâmetros:
- tree: página onde deverá ser adicionada a chave, se houver espaço
- key: chave a ser inserida em uma página
*/
static NodeB * inserir_pagina_nao_cheia(NodeB *tree, int key){
    int i;
    int pos = busca_binaria(key, tree); // encontrar a posição para adicionar a chave ou a posição de 
                                        // uma outra página para continuar a busca.

    // Verificar se uma página é folha. Caso positivo, é presumido que a página não esteja cheia.
    // CASO BASE
    if (tree->eh_no_folha){
        // Um deslocamento de chaves da página pode ser realizado para colocar a nova chave em sua posição
        // correta.
        for (i = tree->nro_chaves; i > pos; i--)
            tree->chaves[i] = tree->chaves[i - 1];

        // Posicionamento da nova chave na página.
        tree->chaves[i] = key;

        // atualização da quantidade de chaves.
        tree->nro_chaves++;

    // CASO ITERATIVO
    }else{ // Caso a página seja não folha...
        // Se a página analisada estiver cheia, a mesma deve ser dividida previamente. Por mais que a nova 
        // chave não seja inserida nessa página, uma outra chave será promovida.
        if (tree->filhos[pos]->nro_chaves == N - 1){
            tree = split_pag(tree, pos);

            // Como pos é resultante da busca binária implementada neste TAD, o resultado deve ser a posição
            // da chave ou a posição de uma página filha, onde pode ser efetuada uma nova busca.
            // Após a divisão de uma página filha, a página pai será atualizada. Nessa operação, "pos" poderá 
            // ficar obsoleta, pois uma chave menor poderá ocupar essa posição na página. Por isso, "pos" deve 
            // ser incrementada para indicarmos a página onde será feita a próxima busca (chamada recursiva).
            if (key > tree->chaves[pos])
                pos++;
        }

        // Uma chamada recursiva é realizada para tentar inserir a nova chave em uma das páginas filho
        // Essa chamada será repetida até que a chave seja inserida em uma página
        tree->filhos[pos] = inserir_pagina_nao_cheia(tree->filhos[pos], key);

    }

    return tree;
}


/*
Implementação do método inserir em árvore B

Parâmetros:
- tree: árvore B
- key: chave a ser inserida em uma página
*/
NodeB * inserir(NodeB *tree, int key){
    NodeB *aux = tree;
    NodeB *nova_pag;

    // Se a página raiz estiver cheia a mesma deve ser dividida, pois uma chave pode ser promovida.
    // Durante a inserção, se a raiz estiver cheia, a mesma deve ser repartida. Quando isso ocorre,
    // a altura da árvore aumenta.
    if (aux->nro_chaves == N - 1){
        nova_pag = criar();
        
        // a nova página será a raiz.
        tree = nova_pag;

        nova_pag->eh_no_folha = 0;

        // A nova página passa a ser raiz, onde o lado esquerdo do seu primeiro elemento (a ser promovido)
        // será a que era raiz, a qual será dividida.
        nova_pag->filhos[0] = aux;

        // a página aux será dividida
        nova_pag = split_pag(nova_pag, 0);

        // Por fim, feita a tentativa de inserção da nova chave na árvore, na qual será procurada uma 
        // página folha.
        nova_pag = inserir_pagina_nao_cheia(nova_pag, key);

        // atualização da raiz.
        tree = nova_pag;
    }else
    // Se a raiz não estiver cheia, a inserção  feita em uma das páginas folhas, as quais podem ser divididas
    // se as mesmas estiverem cheias.
        tree = inserir_pagina_nao_cheia(aux, key);

    return tree;
}
