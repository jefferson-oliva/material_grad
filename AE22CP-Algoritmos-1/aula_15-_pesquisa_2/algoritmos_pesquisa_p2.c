#include <stdio.h>

// Busca binária, onde x é a chave procurada, v é o vetor (tabela),
// ini é a posição inicial do espaço de busca e fim, a posição final.
// Em outras palavras 
static int busca_bin(int x, int v[], int ini, int fim){
	int meio;

	// Caso base, quando ini é igual a fim
	if ((ini == fim) && (x == v[ini]))
		return ini;
	// Em seguida é verificada se ini é menor que fim
	else if (ini < fim){
		// A primeira comparação é sempre no meio do vetor,
		// ou sub-vetor (nas posições entre ini e fim)
		meio = (ini + fim) / 2;

		// E o elemento procurado for o do meio, retorna a posição
		if (x == v[meio])
			return meio;
		// Se a chave procurada for menor que a do meio vetor, a
		// busca é continuada na metade inferior
		else if (x < v[meio])
			return busca_bin(x, v, ini, meio - 1);
		// Caso contrário, a busca é continuada na metade superior
		else
			return busca_bin(x, v, meio + 1, fim);
	}else
		return -1;
}


int busca_binaria(int x, int v, int n){
	return busca_bin(x, v, 0, n - 1);
}


// A lógica para busca por interpolação é a mesma da binária.
// A única diverença é a forma em que o "meio" é calculado.
static int busca_in(int x, int v[], int ini, int fim){
	int meio;
	
	if ((ini == fim) && (x == v[ini]))
		return ini;
	else if (ini < fim){
		meio = ini + (fim - ini) * (x - v[ini]) / (v[fim] - v[ini]);
		if (x == v[meio])
			return meio;
		else if (x < v[meio])
			return busca_in(x, v, ini, meio - 1);
		else
			return busca_in(x, v, meio + 1, fim);
	}else
		return -1;
}


int busca_interpolacao(int x, int v[], int n){
	return busca_in(x, v, 0, n - 1);
}


int main(){

    return 0;
}
