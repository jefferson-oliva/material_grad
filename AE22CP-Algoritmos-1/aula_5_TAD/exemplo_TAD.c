#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

/**
Tipo abstrato de dados (TAD)

Tipo de dado: define um conjunto de valores que uma variável

Estrutura de Dados: define um relacionamento lógico entre tipos de dados
- Estruturas de dados homogêneas: vetores, matrizes e strings
- Estruturas de dados heterogêneas: registros (structs) e uniões (unions)

TAD: conjunto bem definido de estruturas de dados e do grupo de operações que podem ser aplicadas nesses dados

Os dados armazenados devem ser manipulados apenas pelos operadores
- Ocultamento dos detalhes de representação e implementação, apenas funcionalidade é conhecida
- Encapsulamento dos dados e do comportamento: acesso e processamento de dados apenas por funções
- Reutilização e flexibilidade do TAD em diferentes aplicações
*/


/**
Ao falar de TAD, devemos modularizar o código, ou seja, dividir um programa em várias funções (módulos)

Modularizar possibilita "esconder" a implementação e facilita a manutenção e a reutilização do código

Na linguagem C, o TAD pode ser implementado em dois tipos de arquivos (convenção):
- Cabeçalho (.h): contém protótipo de funções, typedefs, e variáveis globais
- Fonte (.c): declaração dos tipos de dados e implementação dos protótipos
*/

int main() {
    Ponto *p1, *p2; // p1 e p2 agora são ponteiros
    float d;

    p1 = cria_ponto(10, 20);
    p2 = cria_ponto(10, 30);
    imprime_ponto(p1);
    imprime_ponto(p2);

    d = distancia(p1, p2);
    printf("%.2f", d);
}
