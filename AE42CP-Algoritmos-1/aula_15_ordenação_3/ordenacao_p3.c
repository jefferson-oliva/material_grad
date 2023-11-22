#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Exemplo de algoritmo de ordenação linear
void counting_sort(int *A, int *B, int n, int k){
    int i, j, C[k + 1];

    for (i = 0; i <= k; i++)
        C[i] = 0;

    for (j = 0; j < n; j++)
        C[A[j]]++;

    // Para cada i = {0, 1, ..., k}, aqui é determinado
    // quantos elementos são menores ou iguais a "i"
    for (i = 1; i <= k; i++)
    	// C[i] vai representar a posição em que a chave i deve
    	// estar localizada
        C[i] += C[i - 1];

    for (j = n - 1; j >= 0; j--){
    	
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--; // caso houver chave repetida, ela virá uma posição antes
    }
}


//Ordenação de strings
//************************************************

// Outrar versão do compara_char: #define comparar2(c1, c2) c1 == c2 ? 0 : c1 < c2 ? -1 : 1
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


void bubblesort(char **vstr, int n){
    int i, j, t = 1;

    for (i = 0; (i < n - 1) && t; i++){
        t = 0;

    for (j = 0; j < n - i - 1; j++)
        if (comparar(vstr[j], vstr[j + 1]) > 0){
            troca(vstr, j, j + 1);
            t = 1;
        }
    }
}


void quicksort(char **vstr, int n_cima, int n_baixo){
    int i = n_cima, j = n_baixo;
    char *pivo = vstr[(i + j) / 2];

    do{
        while ((comparar(vstr[i], pivo) < 0) && (i < j))
            i++;

        while ((comparar(vstr[j], pivo) > 0) && (j > i))
            j--;

        if (i <= j){
            troca(vstr, i, j);
            i++;
            j--;
        }
    }while (i <= j);

	if (j > n_cima)
		quicksort(vstr, n_cima, j);
	if (i < n_baixo)
		quicksort(vstr, i, n_baixo);
}


void imprimir_vet_str(char **vstr, int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", vstr[i]);
}


int main(){
    int i;
    char **vstr = (char**) malloc(6 * sizeof(char*));

    for (i = 0; i < 6; i++)
        vstr[i] = (char*) malloc(5 * sizeof(char));

    strcpy(vstr[0], "fffff");
    strcpy(vstr[1], "eeeee");
    strcpy(vstr[2], "ddddd");
    strcpy(vstr[3], "ccccc");
    strcpy(vstr[4], "bbbbb");
    strcpy(vstr[5], "aaaaa");

    printf("---------\nAntes:\n");
    imprimir_vet_str(vstr, 6);
    printf("---------\nDepois:\n");

    quicksort(vstr, 0, 5);

    imprimir_vet_str(vstr, 6);

    return 0;
}

