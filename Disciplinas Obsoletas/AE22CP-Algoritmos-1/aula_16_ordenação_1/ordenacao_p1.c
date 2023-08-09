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


// Implementação do selection sort
void selectsort(int v[], int n){
	int i, j, p, aux;
	
	for (i = n - 1; i >= 1;  i--){
		p = i;
	
		for (j = 0; j < i; j++)
			if (v[j] > v[p])
				p = j;
		
		aux = v[i];
		v[i] = v[p];
		v[p] = aux;
	}
}


// Segunda implementação do selection sort
// Provavelmente a forma ordenação simples mais implementada
void selectsort2(int v[], int n){
	int i, j, p, aux;
	
	for (i = 0; i < n - 1;  i++){
		p = i;
	
		for (j = i + 1; j < n; j++)
			if (v[j] < v[p])
				p = j;
		
		if (p != i){
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
		}
	}
}


// Implementação do método insertion sort
void insertsort(int v[], int n){
	int i, x;

	for (i = 1; i < n; i++){
		x = v[i];
		
		for (j = i - 1; (j >= 0) && (x  < v[j]); j--)
			v[j + 1] = v[j];

		v[j + 1] = x;
	}
}


int main(){

    return 0;
}

