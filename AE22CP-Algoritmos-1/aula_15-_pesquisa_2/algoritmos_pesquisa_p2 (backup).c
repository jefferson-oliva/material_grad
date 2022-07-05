#include <stdio.h>

static int busca_bin(int x, int v[], int ini, int fim){
	int meio;

	if ((ini == fim) && (x == v[ini]))
		return ini;
	else if (ini < fim){
		meio = (ini + fim) / 2;

		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			return busca_bin(x, v, ini, meio - 1);
		else
			return busca_bin(x, v, meio + 1, fim);
	else
		return -1;
}


int busca_binaria(int x, int v, int n){
	return busca_bin(x, v, 0, n - 1);
}


int busca_binaria_iterativa(int x, int v[], int n){
	int ini = 0;
	int fim = n - 1;
	int meio;

	while (ini <= fim){
		meio = (ini + fim) / 2;

		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			fim = meio - 1;
		else
			ini = meio + 1;
	}

	return -1;
}


static int busca_interpolacao(int x, int v[], int ini, int fim){
	int meio;
	if ((ini == fim) && (x == v[ini]))
		return ini;
	else if (ini < fim){
		meio = ini + (fim - ini) * (x - v[ini]) / (v[fim] - v[ini]);
		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			return busca_interpolacao(x, v, ini, meio - 1);
		else
			return busca_interpolacao(x, v, meio + 1, fim);
	}else
		return -1;
}


int busca_interpolacao_iterativa(int x, int v[], int n){
	int ini = 0;
	int fim = n - 1;
	int meio;
	while (ini <= fim){
		meio = ini + (fim - ini) * (x - v[ini]) / (v[fim] - v[ini]);
		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			fim = meio - 1;
		else
			ini = meio + 1;
	}

	return -1;
}


int main(){

    return 0;
}
