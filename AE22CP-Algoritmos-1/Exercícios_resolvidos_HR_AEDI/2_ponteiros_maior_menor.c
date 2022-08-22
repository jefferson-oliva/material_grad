#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troca(int *A, int *B){
    int aux;
    
    if (*A < *B){
        aux = *A;
        *A = *B;
        *B = aux;
    }
}

int main() {
    int i, n, A, B;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++){
        scanf("%d %d", &A, &B);
        troca(&A, &B);
        printf("A=%d B=%d\n", A, B);
    }

    return 0;
}

