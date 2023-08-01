#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Funções comumente utilizadas na alocação dinâmica

- void* malloc(size_t x): responsável por alocar um tamanho x (em bytes) de memória,
e retornar um ponteiro para o endereço base de memória

- void* calloc(size_t x, size_t y): aloca x vezes o tamanho y, devolvendo um
ponteiro para o endereço base da região alocada

- void* realloc(void* ptr, size_t x): modifica o tamanho de memória já alocada

- void free(void* ptr): devolve ao heap a memória apontada por ptr
*/


/* 
Suponha que desejamos criar uma estrutura que represente um arranjo com capacidade 
de 100 itens. A ideia seria inicializá-la "vazia" e na medida que seja inserido ou 
removido um elemento, o campo quantidade seria manipulado.

*/
typedef struct{
	int item[100]; // como este campo é um vetor estático, na alocação dinâmica,
	               // um espaço para 100 itens do tipo int é alocado no momento
	               // da declaração de uma variável ou alocação de espaço para
	               // dados do tipo "Vetor"
	int quantidade;
}Vetor;

/*
Exemplo de estrutura para o armazenamento de um arranjo de tamanho n. Como uma 
ideia seria de que o tamanho do arranjo pode ser alterado, então vamos a 
estrutura de VetorD, referente ao arranjo dinâmico, onde o seu respectivo tamanho
poderia ser alterado.
*/
typedef struct{
	int n;
	int *item; // Como este campo é um ponteiro, um espaço deve ser alocado ou
	           // um endereço deve atribuído ao "item", tanto na alocação estática 
	           // quanto na aloção dinâmica.
}VetorD;


/* 
Função que retorna um ponteiro do tipo Vetor: exemplo de cenário em que
o uso da função calloc é mais adequada para a alocação dinâmica
*/
Vetor* iniciar_vetor(){
	int i;
	Vetor* v = (Vetor*) malloc(sizeof(Vetor));
	
	// Se fosse usada a função calloc, as inicializações abaixo não seriam 
	// necessárias, já que a função "zera" a memória
	v->quantidade = 0;

	for (i = 0; i < 100; i++)
	      v->item[i] = 0;

	return v;
}

// Outra versão de função que retorna um ponteiro do tipo Vetor
/*Vetor* iniciar_vetor(){
	Vetor* v = (Vetor*) calloc(1, sizeof(Vetor));

	return v;
}*/
Vetor* iniciar_vetor_v2(){
	return (Vetor*) calloc(1, sizeof(Vetor));
}


/* 
Função para alocar espaço, dinamicamente, para um ponteiro do tipo VetorD.

Nesse exemplo, a função malloc é a mais adequada, já que o espaço alocado
geralmente seria preenchido logo após a alocação.
*/
VetorD* iniciar_vetorD(int n){
	VetorD* v = (VetorD*) malloc(sizeof(Vetor));

	v->n = n;
	
	// Como o campo item é um ponteiro, no momento da alocação de um
	// ponteiro do tipo VetorD, o campo item será nulo. Nesse caso,
	// deve ser alocado um espaço para o campo item também.
	v->item = (int*) malloc(sizeof(int) * n);

	return v;
}


// Exemplo de função para geração de vetor com n elementos
int* vetor(int n){
    int *p = (int*) malloc(n * sizeof(int));

    return p;
}


int** create_matrix(int l, int c){
	int i;
	int** mat; // Uso de ponteiro de ponteiro: tipo de variável que armazena o 
	           // endereço de outro ponteiro
	
	// Um vetor de ponteiros é alocado: vetor com l ponteiros, sendo que cada um
	// será apontado para um vetor de números inteiros
	mat = malloc(l * sizeof(int*));
	
	for (i = 0; i < l; i++)
		mat[i] = malloc(sizeof(int) * c); // Um vetor para cada linha da matriz 
		                                  //é alocado: cada ponteiro recebe um vetor alocado dinamicamente
	
	/*
	Um ponteiro de ponteiro é retornado: ao ser alocado na heap, a matriz continuará existindo após finalizar a
	função; A matriz só será liberada quando o programa finalizar ou ser dado um comando free(mat).
	*/
	return mat;
}



int main(){
    int *v1;
    int *v2;
    int n = 10;

    // alocação de um espaço de memória de n * 4 bytes
    v1 = (int*) malloc(n * sizeof(int));
    v2 = (int*) calloc(n, sizeof(int));

    // realocação de memória para aumentar uma unidade no vetor de inteiros
    v1 = realloc(v1, (n + 1) * sizeof(int));
    v2 = realloc(v2, (n + 1) * sizeof(int));

    // Liberar espaço na memória
    free(v1);
    free(v2);

    return 0;
}



