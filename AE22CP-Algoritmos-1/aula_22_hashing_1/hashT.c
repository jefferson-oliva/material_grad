#include <stdio.h>
#include <stdlib.h>
#include "hashT.h"

/**
Valores possíveis para cada bucket da tabela hash
-1: bucket vazio
0: a chave foi removida
valor maior que 0: há uma chave no bucket
*/

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}


// Função hash, onde k é a chave e B é o tamanho da tabela
static int hashingF(int k, int B){
    return k % B;
}


int buscar(int key, HashT *t){
    if (t != NULL){
        int x = hashingF(key, t->tam);

        if (t->buckets[x] == key)
            return x;
    }

    return -1;
}


int inserir(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] < 0){
            t->buckets[x] = key;

            return 1;
        }
    }

    return 0;
}


int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] == key){
            t->buckets[x] = -1;

            return 1;
        }
    }

    return 0;
}


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] >= 0)
                printf("%d\n", t->buckets[i]);
        }
    }
}


int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}
