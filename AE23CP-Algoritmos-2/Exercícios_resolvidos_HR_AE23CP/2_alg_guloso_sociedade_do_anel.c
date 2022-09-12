#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int proximo_passo(int **mat, int l, int c, int *lp, int *cp){
    int i, menor = INT_MAX;
    int al, ac;
    int ml = *lp, mc = *cp;
    int movX[] = {-1, 0, 1, 0};
    int movY[] = {0, -1, 0, 1};
    
    for (i = 0; i < 4; i++){
        al = *lp + movX[i];
        ac = *cp + movY[i];
        
        if ((al >= 0) && (al < l) && (ac >= 0) && (ac < c) && (menor > mat[al][ac])){
            ml = al;
            mc = ac;
            menor = mat[al][ac];
        }
    }
    
    *lp = ml;
    *cp = mc;
    
    return menor;
}


int percurso(int **mat, int l, int c, int lp, int cp, int custo){
    int aux;
    
    if ((lp == l - 1) && (cp == c - 1))
        return custo;
    else{
        mat[lp][cp] = INT_MAX;
        
        aux = proximo_passo(mat, l, c, &lp, &cp);
        
        if (aux < INT_MAX){
            return percurso(mat, l, c, lp, cp, custo + mat[lp][cp]);
        }else
            return INT_MAX;
    }
}


int main() {
    int **mat, l, c, i, j, res;
    
    scanf("%d %d", &l, &c);
    
    mat = (int**) malloc(sizeof(int*) * l);
    
    for (i = 0; i < c; i++)
        mat[i] = (int*) malloc(sizeof(int) * c);
    
    for (i = 0; i < l; i++)
        for (j = 0; j < l; j++)
            scanf("%d", &mat[i][j]);
    
    res = percurso(mat, l, c, 0, 0, 0);
    
    if (res < INT_MAX)
        printf("%d", res);
    else
        printf("sem solucao");
    
    free(mat);
    
    return 0;
}

