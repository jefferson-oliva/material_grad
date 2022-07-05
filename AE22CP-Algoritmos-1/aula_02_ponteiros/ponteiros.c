#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Ponteiro: variável que contém um endereço de memória

declaração de ponteiro: tipo * nome_variavel;

Exemplo: int *pa;


Operadores de ponteiros
- & ("endereço de"). Exemplo:
    int a = 10; // variável do tipo int que recebe o valor 10
    int pa = &a; // ponteiro do tipo int que aponta para o endereço da variável a

- * ("valor de"). Exemplo:
    *pa = 25; // mudança de valor no campo do endereço apontado por pa.
              // Em outras palavras, o valor da variável a também é alterado.



*/


/**
Parte do exemplo de passagem de parâmetros
*/
void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}


int main(){
    int x; // variável do tipo int
    int *p; // ponteiro do tipo int

    x = 52; // atribuição na variável v
    p = &x; // ponteiro p aponta para o endereço da variável v
    *p = 25; // alteração do valor. Ao imprimir a variável x, será impresso 25
    
    //int *p2 = 10; Essa atribuição não é permitida, pois p2 não aponta para algum endereço
    int a = 1;
    int b = 2;

    // passagem de parâmetros por referência (endereço)
    troca(&a, &b);

    // a forma de uso da função abaixo não é permitida
    // troca(a, b);

    //Aritmética de ponteiros
    char c = '0';
    int i = 0;
    char *pc;
    int *pi;
    pc = &c;
    pi = &i;
    pc++; // desloca 1 byte
    pi++; // desloca 4 bytes

    // Vetor
    int v[5];
    *v = 0;
    *(v + 1) = 10;
    *(v + 2) = 20;
    *(v + 3) = 30;
    *(v + 4) = 40;

    // Impressão do conteúdo do vetor com operações de ponteiro. Cada elemento é acessado po deslocamento
    // de endereços através da variável i. Não importa o tipo de dado, para cada valor de i, o deslocamento,
    // em bytes, será equivalente ao tamanho do tipo de dado armazenado no vetor
    for (i = 0; i < 5; i++)
        printf("%d\n", *(v + i));

    // ponteiro genérico
    void *pg; // ponteiro genérico

    c = 'S';

    pg = &c;

    printf("Char: %c\n", c);
    printf("ponteiro: %c\n", *(char*) pg); // casting

    return 0;
}
