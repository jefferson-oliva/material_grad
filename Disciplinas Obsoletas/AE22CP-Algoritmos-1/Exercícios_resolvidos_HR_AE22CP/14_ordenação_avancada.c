#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(int x[], int esq, int dir){
    int i = esq, j = dir, pivo = x[(i + j) / 2], aux;

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
        quicksort(x, esq, j);
    if (i < dir)
        quicksort(x, i, dir);
}


int main() {
    int i, n, *v;
    
    scanf("%d", &n);
    
    v = malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d ", &v[i]);

    quicksort(v, 0, n - 1);
    
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    
    free(v);
    
    return 0;
}
