#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


void quicksort(int v[], int esq, int dir){
    int i = esq;
    int j = dir; 
    int pivo = v[(i + j) / 2];

    do{
        while (v[i] < pivo)
            i++;

        while (v[j] > pivo)
            j--;

	if (i <= j){
            troca(&v[i], &v[j]);
            i++;
            j--;
        }
    }while (i <= j);

    if (j > esq)
        quicksort(v, esq, j);
    if (i < dir)
        quicksort(v, i, dir);
}


// Outra implementação do quicksort
//*******************************************
static int particionar(int v[], int esq, int dir){
    int pivo = v[esq];
    int i = esq + 1;
    int j = dir;
    
    while (i <= j){
        while ((v[i] <= pivo) && (i <= dir))
            i++;
        
        while ((v[j] > pivo) && (j >= esq))
            j--;
        
        if (i < j)
            troca(&v[i], &v[j]);
    }
    
    troca(&v[esq], &v[j]);
    
    return j;
}

void quicksort2(int v[], int esq, int dir){
    if (esq < dir){
        int j = particionar(v, esq, dir);
        quicksort2(v, esq, j - 1);
        quicksort2(v, j + 1, dir);
    }
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
