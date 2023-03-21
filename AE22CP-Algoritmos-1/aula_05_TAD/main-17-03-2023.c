#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

typedef struct{
    char nome[101];
    int ano, temporadas;
    float avaliacao;
}Anime;


Anime iniciar(char nome[], int ano,
        int temporadas, float avaliacao){
    Anime a;

    strcpy(a.nome, nome);
    a.ano = ano;
    a.temporadas = temporadas;
    a.avaliacao = avaliacao;

    return a;
}


int main() {
    /*Anime a;
    char nome[101];
    int ano, temporadas;
    float avaliacao;

    printf("Nome anime: ");
    scanf("%[^\n]s", nome);
    printf("Ano: ");
    scanf("%d", &ano);
    printf("Temporadas: ");
    scanf("%d", &temporadas);
    printf("Avaliacao: ");
    scanf("%f", &avaliacao);

    a = iniciar(nome, ano, temporadas, avaliacao);*/

    float x;
    ponto *p = criar(2.0, 3.0);

    x = get_x(p);

    imprimir_ponto(p);

    return 0;
}



