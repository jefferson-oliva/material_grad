#include <stdio.h>
#include <stdlib.h>

//Implementação ingênua do bubblesort
void bubblesort(int v[], int n){
	int i, j, x;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
			}
}


// Melhoria do bubblesort
void bubblesort_V2(int v[], int n){
	int i, j, x, troca = 1;

	for (i = 0; (i < n - 1) && (troca); i++){
		troca = 0;

		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
				troca = 1;
			}
	}
}


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



int main(){
    int i;
    int v[] = {7,5,6,8,1,3,2,4};

    quicksort(v, 0, 7);

    for (i = 0; i < 8; i++)
        printf("==> %d\n", v[i]);

    return 0;
}

