#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}


void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void selectsort(char **v, int n){
    int i, j, p;
    
    for (i = n - 1; i >= 1;  i--){
        p = i;
    
        for (j = 0; j < i; j++)
            if (comparar(v[j], v[p]) > 0)
                p = j;
        
        if (p != i)
            troca(v, p, i);
    }
}

int main() {
    int i, n;
    char **v;

    scanf("%d", &n);
    
    v = (char**) malloc(sizeof(char*) * n);
    
    for (i = 0; i < n; i++){
        v[i] = (char*) malloc(sizeof(char) * 50);
        
        scanf("%s", v[i]);
    }
    
    selectsort(v, n);
    
    for (i = 0; i < n; i++){
        printf("%s\n", v[i]);
        free(v[i]);
    }
    
    free(v);
    
    return 0;
}
