#include <stdio.h>
#include <stdlib.h>
#include "hashT.h"

/**
Valores possíveis para cada bucket da tabela hash
-1: bucket vazio
0: bucket vazio, mas já houve uma chave, a qual foi removida
> 0: há uma chave no bucket
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


// Implementação de uma função rehash por overflow progressinvo
// hashC: resultado de uma função hash
// tentativa: é o número da tentativa para localizar ou posicionar uma chave
static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}

//Antes
/*int buscar(int key, HashT *t){
    int x = hashingF(key, t->tam);

    if (t->buckets[x] == key)
        return x;

    return -1;
}*/


//Depois
int buscar(int key, HashT *t){
    int x = hashingF(key, t->tam); // Posição ou código hash (primeira tentativa) para chave key
    int i, rh;

    if (t->buckets[x] == key) // se chave foi encontrada na primeira tentativa, retornar a posição definida pela função hash
        return x;
    else if (t->buckets[x] >= 0){ // Se a chave localizada na tabela hash for diferente da procurada, verificar se o bucket da posição x não está vazia (ou seja, não tenha o valor -1)
        i = 1; // tentativa
        rh = x; // rehash

        /* Loop para continuar a busca da chave através de rehash
        Critérios de parada:
        1: as tentativas foram esgotadas (i == t->tam)
        2: a chave foi encontrada (t->buckets[rh] == key)
        3: uma posição vazia é encontrada (t->buckets[rh] == -1)
        */
        while ((i < t->tam) && (t->buckets[rh] >= 0) && (t->buckets[rh] != key)){
            rh = overflow_prog(x, t->tam, i); // aplicar a função rehash

            i++; // atualizar a tentativa
        }

        // Verificar se a chave foi encontrada, ou seja, não foram esgotadas as tentativas
        // e o bucket na posição rh não  vazio (chave maior que -1)
        if ((i < t->tam) && (t->buckets[rh] == key))
            return rh;
    }
    
    return -1;
}

//Antes
/*int inserir(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] < 0){
            t->buckets[x] = key;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int inserir(int key, HashT *t){
    int x;
    int i, rh;

    // verificar se a tabela não é nula e se a chave a ser inserida é válida
    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam); // Aplicação de função hash na chave key

        // Caso o bucket na posição x seja vazio (valor negativo) ou represente uma
        // remoção (igual a zero), basta incluir a chave key
        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{ // Se a posição x não for vazia, tentar encontrar um bucket vazio
            i = 1; // tentativa
            rh = x; // rehash

            /*
            Loop para procurar um bucket vazio
            Critérios de parada:
            1: as tentativas foram esgotadas (i == t->tam), ou seja, a tabela está cheia
            2: a chave foi encontrada (t->buckets[rh] == key): como a chave já existe, então não é feita a inserção
            3: uma posição vazia é encontrada (t->buckets[rh] == -1)
            */
            while ((i < t->tam) && (t->buckets[rh] > 0) && (t->buckets[rh] != key)){
                rh = overflow_prog(x, t->tam, i); // aplicar a função rehash

                i++; // atualizar a tentativa
            }

            // Se as tentativas não foram esgotadas e um bucket apropriado (vazio ou com sinal de que a chave foi removida) foi encontrado, incluir a chave na posição rh
            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}


// Antes
/*int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = hashingF(key, t->tam);

        if (t->buckets[x] == key){
            t->buckets[x] = -1;

            return 1;
        }
    }

    return 0;
}*/


// Depois
int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(key, t); // procurar a chave

        // Se a chave existir, basta atribuir valor 0 para sinalizar a remoção da chave key na posição x
        if (x >= 0){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
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
