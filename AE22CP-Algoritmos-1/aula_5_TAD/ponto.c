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
