#include <stdio.h>

void insertsort(int v[], int n){
	int i, x;

	for (i = 1; i < n; i++){
		x = v[i];
		
		for (j = i - 1; (j >= 0) && (x  < v[j]); j--)
			v[j + 1] = v[j];

		v[j + 1] = x;
	}
}


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


int main(){

    return 0;
}
