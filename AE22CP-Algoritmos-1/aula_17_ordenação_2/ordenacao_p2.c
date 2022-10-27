#include <stdio.h>
#include <stdlib.h>

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


// Implementações relacionadas ao heapsort
//*******************************************
static void gerarHeap(int v[], int n){
	int esq = n / 2;

	// Para o vetor ser rearranjado como heap, o processo começa
	// pelos "nós folhas" e a troca pode ocorrer até o "nó raiz" 
	while (esq >= 0){
		refazer(v, esq, n - 1);
		esq--;
	}
}


static void refazer(int v[], int esq, int dir){
	int j = (esq + 1) * 2 - 1; // posição de um nó descendente (esquerda) 
				    // do nó localizado na posição esq
	int x = v[esq]; // representa o nó raiz, ou seja, o elemento a partir
			// do qual será testada a condição de heap

	// Pa partir do nó na posição esq, o arranjo é percorrido até o 
	// "nó folha"
	while (j <= dir){
		// É verificado se o "nó filho" esquerdo é menor que o direito
		if ((j < dir) && (v[j] < v[j + 1]))
			j++;

		// Se o x for maior que o seu descendente, a condição de heap
		// não foi violada
		if (x > v[j])
			break;

		// Quando a condição de heap é violada, devem haver trocas
		// de posições entre os elementos
		v[esq] = v[j];
		esq = j; // posição de um dos descendentes do elemento localizado
		         // em esq
		j = (esq + 1) * 2 - 1; // descendente "esquerdo" de v[esq]
	}

	v[esq] = x;
}


void heapsort(int v[], int n){
	int x;
	int dir = n - 1;

	gerarHeap(v, n); // primeiro passo, geração da heap

	// Em cada passo dessa repetição, a raiz da heap é
	// reposicionada em sua posição correta e a heap
	// é refeita. Isso é feito até que a heap esteja
	// "vazia".
	while (dir > 0){
		x = v[0];
		v[0] = v[dir];
		v[dir] = x;
		dir--;

		refazer(v, 0, dir);
	}
}
//*******************************************


int main(){

    return 0;
}
