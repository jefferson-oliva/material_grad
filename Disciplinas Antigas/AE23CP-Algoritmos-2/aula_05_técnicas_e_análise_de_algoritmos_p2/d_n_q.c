#include <stdio.h>
#define max(a, b) a > b ? a : b

int maxI(int v[], int n){
    int i, m = v[0];

    for (i = 1; i < n; i++)
        if (m < v[i])
            m = v[i];

    return m;
}


int maxDQ(int v[], int ini, int fim){
    int m, a, b;

    if ((fim - ini) <= 1)
        return max(v[ini], v[fim]);
    else{
        m = (ini + fim) / 2;
        a = maxDQ(v, ini, m);
        b = maxDQ(v, m + 1, fim);
    }

    return max(a, b);
}


int main(){
    int v[] = {1, 4, 3, 0, 2, 5, 9, 8};

    printf("%d\n", maxI(v, 8));
    printf("%d\n", maxDQ(v, 0, 8));

    return 0;
}
