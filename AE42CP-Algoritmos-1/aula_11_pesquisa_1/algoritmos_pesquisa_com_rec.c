#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_sequencial(int x, int v[], int n){
    int i;

    for (i = 0; i < n; i++)
        if (x == v[i])
            return i;

    return -1;
}

int busca_seq_rec(int x, int *v, int i, int n){
    if (i >= n)
        return -1;
    else if (x == v[i])
        return i;
    else
        return busca_seq_rec(x, v, i + 1, n);
}

int busca_seq_rec2(int x, int *v, int n){
    if (n <= 0)
        return -1;
    else if (x == v[n - 1])
        return n - 1;
    else
        return busca_seq_rec2(x, v, n - 1);
}

int busca_seq_rec3(int x, int *v, int i, int n){
    if (i < n)
        return (x == v[i]) ? i : busca_seq_rec3(x, v, i + 1, n);
        
    return -1;
}



int busca_sequencial4(int x, int v[], int n){
    int i, j;

    for (i = 0, j = n - 1; (i < j) && (x > v[i]) && (x < v[j]); i++, j--);

    if ((i < n) && (v[i] == x))
        return i;
    else  if ((j >= 0) && (v[j] == x))
            return j;
    else
        return -1;
}

int busca_seq_rec4(int x, int *v, int i, int j){
    if (i > j)
        return -1;
    else if (x == v[i])
        return i;
    else if (x == v[j])
        return j;
    else
        return busca_seq_rec4(x, v, i + 1, j - 1);
}

int busca_seq_rec5(int x, int *v, int i, int j){
    if (i < j)
        return (x == v[i]) ? i : (x == v[j]) ? j : 
                busca_seq_rec5(x, v, i + 1, j - 1);
    return -1;
}


int main() {
    int *v, n, i, n_chaves, chave;
    
    scanf("%d", &n);
    
    v = malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    scanf("%d", &n_chaves);
    
    for (i = 0; i < n_chaves; i++){
        scanf("%d", &chave);
        printf("%d\n", busca_seq_rec(chave, v, 0, n));
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

