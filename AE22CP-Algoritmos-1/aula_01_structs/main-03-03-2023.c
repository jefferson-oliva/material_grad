#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int INTEIRO;

typedef struct{
    int forca, defesa;
    float energia;
}stats;

struct P1{
    char nome[30];
    int nivel;
    stats st;
};


/*struct P1{
    char nome[30];
    int nivel;
    float energia;
    int forca, defesa;
};*/

typedef struct P1 Personagem1;


void imprimir_P(Personagem1 p){
    printf("%s %d %f %d %d\n", p.nome,
            p.nivel, p.st.energia, p.st.forca, p.st.defesa);
}

Personagem1 criar_P(char nome[], int nivel, float energia, int forca, int defesa){
    Personagem1 p;

    strcpy(p.nome, nome);
    p.nivel = nivel;
    p.energia = energia;
    p.forca = forca;
    p.defesa = defesa;

    return p;
}

/*typedef struct P2{
    char nome[30];
    int nivel;
    float energia;
    int forca, defesa;
}P2;


typedef struct {
    char nome[30];
    int nivel;
    float energia;
    int forca, defesa;
}P3;*/


/**
Roteiro



- Vetor de struct
- argumento e retorno de função com structs
- aninhamento de structs
- Erros comuns: a partir do slide 33
**/

int main(){
    /*int v[] = {1,2,3,4,5,6};
    int v2[6];
    char s1[] = "naruto";
    char s2[] = {'s', 'a', 'z', 'u', 'k', 'e'};
    char s3[5];
    char s4[8];
    int m1[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    m[0][0] = 10;

    s3[0] = 't';
    s3[1] = '0';

    v2[0] = 1;
    v2[1] = 2;

    strcpy(s4, "tobirama");*/

    /*char nome[6][30];
    int nivel[6];
    float energia[6];
    int forca[6], defesa[6];

    strcpy(nome[0], "vegeta");
    nivel[0] = 50;
    energia[0] = 100.1;
    forca[0] = 500;
    defesa[0] = 100;

    strcpy(nome[1], "goku");
    nivel[1] = 40;
    energia[1] = 90.1;
    forca[1] = 400;
    defesa[1] = 90;*/

    /*struct P1 p = {"vegeta", 50, 100.1, 500, 100};
    struct P1 p2;
    Personagem1 p3;
    int a;
    INTEIRO b;
    a = b = 10;


    struct P2 p4;
    P2 p5;

    p4 = pl;


    p2.defesa = 200;
    strcpy(p2.nome, "goku");
    p2.energia = 100.1;
    p2.forca = 400;
    p2.nivel = 50;

    p3 = p2;

    printf("%s\n", p3.nome);
    printf("%d\n", p3.nivel);
    printf("%f\n", p3.energia);
    printf("%d\n", p3.forca);
    printf("%d\n", p3.defesa);*/
    Personagem1 p;
    Personagem1 vp[6];
    int i;


    for (i = 0; i < 6; i++){
        vp[i] = criar_P("Pedro", i, (float) i * 50, i * 100, i *2);
        /*strcpy(vp[i].nome, "Pedro");
        vp[i].nivel = i;
        vp[i].energia = (float) i * 50;
        vp[i].forca = i * 100;
        vp[i].defesa = i * 2;*/
    }

    for (i = 0; i < 6; i++){
        imprimir_P(vp[i]);
    }

    return 0;
}



