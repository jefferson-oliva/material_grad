#include <stdio.h>
#include <stdlib.h>
#include "pesquisa_indexada.h"

struct IF_Item{
    int chave; // valor da chave no elemento do arquivo de índice
    int pos_arq; // posição onde a busca é iniciada no arquivo (tabela)
};

struct Arq_Seq_In{
    int tam_arq; // tamanho do arquivo (tabela)
    int tam_index; // tamanho do índice
    int *arq; // arquivo (tabela)
    struct IF_Item *index; // arquivo de índice
};


Arq_Seq_In* criar_arq_seq_ind(int tam_index, int *arquivo, int n){
    Arq_Seq_In* arqSI = (Arq_Seq_In*) malloc(sizeof(Arq_Seq_In));
    int i, tam_bloco;

    arqSI->tam_arq = n;
    arqSI->tam_index = tam_index;
    arqSI->arq = (int*) malloc(n * sizeof(int));
    arqSI->index = (IF_Item*) malloc(tam_index * sizeof(IF_Item));

    for (i = 0; i < n; i++)
        arqSI->arq[i] = arquivo[i];

    tam_bloco = n / tam_index;
    
    for (i = 0; i < tam_index; i++){
        arqSI->index[i].pos_arq = i * tam_bloco;
        arqSI->index[i].chave = arquivo[arqSI->index[i].pos_arq];
    }

    return arqSI;
}


int buscar_item(int chave, Arq_Seq_In* arqSI){
    int i, j, n;

    if (arqSI != NULL){
        // Se a chave procurada for a menor que a primeira chava da tabela de índice,
        // então ela não está no arquivo
        if (chave < arqSI->index[0].chave)
            return -1;

        // busca no índice
        for (i = 0; (i < arqSI->tam_index) && (chave < arqSI->index[i].chave); i++);

        if (chave == arqSI->index[i].chave)
            return arqSI->index[i].pos_arq;

        // busca na tabela
        else{
            // Se a execução do código chegou até aqui, significa que arqSI->index[i].chave é a primeira
            // chave maior que a procurada
            // Próximo passo: obter o limite do espaço de busca
            // Caso a busca não seja a partir da posição do último elemento da tabela de índice, a busca 
            // pela chave na tabela será entre arqSI->index[i - 1].pos_arq + 1 e 
            // arqSI->index[i].pos_arq
            if (i < arqSI->tam_index)
                // Obter o limite do espaço de busca na tabela
                n = arqSI->index[i].pos_arq;
            // Caso i for maior ao tamanho da tabela de índice, significa que a busca será no último
            // "bloco" coberto pela tabela de índice, ou seja, entre arqSI->index[i - 1].pos_arq + 1
            // e arqSI->tam_arq
            else
                n = arqSI->tam_arq;

            // Como um dos critérios de parada do primeiro for é quando a chave da tabela de índices for
            // maior a chave procurada, então, busca é feita a partir da posição indicada pelo 
            // (i - 1)-ésimo elemento da tabela auxilar, já que a sua chave é a última a ser menor que a
            // procurada
            for (j = arqSI->index[i - 1].pos_arq + 1; j < n; j++)
                if (chave == arqSI->arq[j])
                    return j;
        }
    }

    return -1;
}

