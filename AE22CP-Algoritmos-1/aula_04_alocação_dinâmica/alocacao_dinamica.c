#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Funções comumente utilizadas na alocação dinâmica

- void* malloc(size_t x): responsável por alocar um tamanho x (em bytes) de memória,
e retornar um ponteiro para o endereço base de memória

- void* calloc(size_t x, size_t y): aloca x vezes o tamanho y, devolvendo um
ponteiro para o endereço base da região alocada

- void* realloc(void* ptr, size_t x): modifica o tamanho de memória já alocada

- void free(void* ptr): devolve ao heap a memória apontada por ptr
*/

int main(){
    int *v1;
    int *v2;
    int n = 10;

    // alocação de um espaço de memória de n * 4 bytes
    v1 = (int*) malloc(n * sizeof(int));
    v2 = (int*) calloc(n, sizeof(int));

    // realocação de memória para aumentar uma unidade no vetor de inteiros
    v1 = realloc(v1, (n + 1) * sizeof(int));
    v2 = realloc(v2, (n + 1) * sizeof(int));

    // Liberar espaço na memória
    free(v1);
    free(v2);

    return 0;
}


// Exemplo de função para geração de vetor com n elementos
int* vetor(int n){
    int *p = (int*) malloc(n * sizeof(int));

    return p;
}
