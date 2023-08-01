#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h" // Funciona no codeblocks quando criarmos os arquivos dentro de um projeto


struct ponto {
    float x;
    float y;
};


// Função que cria e retorna um Ponto*
Ponto* cria_ponto(float x, float y){
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

// Retornar o valor do campo X de um ponto
float get_x(ponto *p){
    if (p != NULL)
        return p->x;

    return 999999.999999;
}

//Retornar o valor do campo Y de um ponto
float get_y(ponto *p){
    if (p != NULL)
        return p->y;

    return 999999.999999;
}

// Alterar os os dados de um ponto
int alterar(ponto *p, float x, float y){
    if (p != NULL){
        p->x = x;
        p->y = y;

        return 1;
    }

    return 0;
}


// Imprimir conteúdo de Ponto*
void imprime_ponto(Ponto * p){
    printf("%.2f, %.2f\n", p->x, p->y);
}


// Calcular a distância Euclidiana entre dois pontos
float distancia(Ponto *p1, Ponto *p2) {
    float dx, dy, dt;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    dt = sqrt(pow(dx, 2) + pow(dy, 2));
    return dt;
}


// Liberar a área alocada para Ponto
void libera_ponto(Ponto *p) {
    free(p);
}
