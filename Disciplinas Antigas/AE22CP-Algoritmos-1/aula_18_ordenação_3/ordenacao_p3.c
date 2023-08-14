#include <stdio.h>



void shellsort(int v[], int n){
	int h = 1;
	int x, i, j;

	while (h < n)
		h = 3 * h + 1;

	h /= 3;

	while (h >= 1){
		for (i = h; i < n; i++){
			x = v[i];
			j = i;

			while ((j >= h) && (x < v[j - h])){
				v[j] = v[j - h];
				j -= h;
			}

			v[j] = x;
		}

		h /= 3;
	}
}


// Implementações relacionadas ao mergesort
//************************************************
void merge(int v[], int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int L[n1 + 1];
    int R[n2 + 1];

    for (i = 0; i < n1; i++)
        L[i] = v[esq + i];

    for (j = 0; j < n2; j++)
        R[j] = v[meio + j + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for (k = esq; k <= dir; k++)
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
}

void mergesort(int v[], int esq, int dir){
    int meio;

    if (esq < dir){
        meio = (esq + dir) / 2;
        mergesort(v, esq, meio);
        mergesort(v, meio + 1, dir);
        merge(v, esq, meio, dir);
    }
}
//************************************************


int main(){

    return 0;
}
