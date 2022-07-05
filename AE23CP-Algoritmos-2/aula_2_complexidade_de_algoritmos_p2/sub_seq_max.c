#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sub_seq_max(int v[], int n){
    int i, j, k;
    int aux, ssq = 0; // 1

    for (i = 1; i <= n; i++) // 1 + n * (1 + 4i² + 9i + 4 + 1) + 1 => n * (4i² + 9i) + 6n + 2
        for (j = 0; j < n - i + 1; j++){ // 1 + i * (3 + 1 + 4i + 3 + 2) + 3 => i * (4i + 9) + 4 => 4i² + 9i + 4
            aux = 0; // 1

            for (k = j; k < j + i; k++) // 1 + i * (2 + 1 + 1) + 2 => 4i + 3
                aux += v[k];

            if (aux > ssq) // 2
                ssq = aux;
        }

    return ssq; // 1
} // total: n * (4i² + 9i) + 6n + 4




int main(){
    int v[6] = {-2, 11, -4, 13, -5, -2};

    printf("%d\n\n", sub_seq_max(v, 6));

    return 0;
}

