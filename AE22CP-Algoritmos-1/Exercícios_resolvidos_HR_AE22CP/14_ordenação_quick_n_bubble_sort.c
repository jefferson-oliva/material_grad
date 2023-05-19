#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quick_n_bubble_sort(int x[], int esq, int dir, int m){
    int i = esq, j = dir, pivo, aux, troca;

    if (dir - esq > m){
        pivo =  x[(i + j) / 2];
        
        do{
            while (x[i] < pivo)
                i++;

            while (x[j] > pivo)
                j--;

            if (i <= j){
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
                i++;
                j--;
            }
        }while (i <= j);

        if (j > esq)
            quick_n_bubble_sort(x, esq, j, m);
        if (i < dir)
            quick_n_bubble_sort(x, i, dir, m);
    }else{
        troca = 1;
        
        for (i = esq; (i < dir) && (troca); i++){
            troca = 0;

            for (j = esq; j <= dir - i - 1; j++)
                if (x[j] > x[j + 1]){
                    aux = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = aux;
                    troca = 1;
                }
        }
        
    }
}


int main() {
    int i, n, m, *v;
    
    scanf("%d", &n);
    
    v = malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d ", &v[i]);
    
    scanf("%d", &m);

    quick_n_bubble_sort(v, 0, n - 1, m);
    
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    
    free(v);
    
    return 0;
}



