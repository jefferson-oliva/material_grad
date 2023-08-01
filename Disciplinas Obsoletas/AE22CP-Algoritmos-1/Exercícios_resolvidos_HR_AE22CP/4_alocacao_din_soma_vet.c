#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* soma(int *v1, int n1, int *v2, int n2){
    int n3, i;
    int *v3 = NULL;
    
    if ((v1 != NULL) && (v2 != NULL)){
        if (n1 > n2)
            n3 = n1;
        else
            n3 = n2;
        
        v3 = (int*) malloc(sizeof(int) * n3);
        
        for (i = 0; (i < n1) && (i < n2); i++)
            v3[i] = v1[i] + v2[i];
        
        for (i = n2; i < n1; i++)
            v3[i] = v1[i];
        
        for (i = n1; i < n2; i++)
            v3[i] = v2[i];
    }
    
    return v3;
}

void imprimir(int *v, int n){
    int i;
    if (v != NULL)
        for (i = 0; i < n; i++)
            printf("%d ", v[i]);
}


int main() {
    int *v1, *v2, *v3;
    int i, n1, n2, n3;
    
    scanf("%d", &n1);
    
    v1 = (int*) malloc(sizeof(int) * n1);
    
    for (i = 0; i < n1; i++)
        scanf("%d", &v1[i]);
    
    scanf("%d", &n2);
    
    v2 = (int*) malloc(sizeof(int) * n2);
    
    for (i = 0; i < n2; i++)
        scanf("%d", &v2[i]);
    
    v3 = soma(v1, n1, v2, n2);
    
    if (n1 > n2)
        n3 = n1;
    else
        n3 = n2;
    
    imprimir(v3, n3);

    free(v1);
    free(v2);
    free(v3);
    
    return 0;
}

