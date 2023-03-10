#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct {
    int RA;
    char nome[255];
    float notas[3];
}Aluno;


float media(float notas[], int n){
    float soma = 0.0;
    float tam = (float) n;
    int i;
    
    for (i = 0; i < n; i++)
        soma += notas[i];
    
    return soma / tam;
}


void imprimir_resultado(Aluno v[], int n){
    int i, med;
    
    for (i = 0; i < n; i++){
        med = media(v[i].notas, 3);
        if (med >= 6.0)
            printf("Aprovado!\n");
        else
            printf("Reprovado!\n");
    }
}


void maior(Aluno v[], int n){
    int i;
    int p_maior = 0;
    float maior = media(v[0].notas, 3);
    float aux;

    for (i = 1; i < n; i++){
        aux = media(v[i].notas, 3);
        
        if (aux > maior){
            p_maior = i;
            maior = aux;
        }
    }
    
    printf("O aluno com maior media e: %d %s %.1f\n", v[p_maior].RA, v[p_maior].nome, maior);
}


void menor(Aluno v[], int n){
    int i;
    int p_menor = 0;
    float menor = media(v[0].notas, 3);
    float aux;
        
   
    for (i = 1; i < n; i++){
        aux = media(v[i].notas, 3);
        if (aux < menor){
            p_menor = i;
            menor = aux;
        }
    }
    
    
    
    printf("O aluno com menor media e: %d %s %.1f\n", v[p_menor].RA, v[p_menor].nome, menor);
}


void maior_P1(Aluno v[], int n){
    int i;
    int p_maior = 0;
    float maior = v[0].notas[0];
    float aux;
    
    for (i = 1; i < n; i++){
        aux = v[0].notas[0];
        
        if (aux > maior){
            p_maior = i;
            maior = aux;
        }
    }
    
    printf("O aluno com maior P1 e: %d %s %.1f\n", v[p_maior].RA, v[p_maior].nome, maior);
}

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    Aluno v[n];
    
    for (i = 0; i < n; i++){
        scanf("%d", &v[i].RA);
        scanf("%s", v[i].nome);
        scanf("%f %f %f", &v[i].notas[0], &v[i].notas[1], &v[i].notas[2]);
    }
    
    imprimir_resultado(v, n);
    maior(v, n);
    menor(v, n);
    maior_P1(v, n);
        
    return 0;
}
