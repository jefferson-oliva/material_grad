#include <stdio.h>
#include <stdlib.h>
#include "pesquisa_bin_indexada.h"

struct IF_Item{
    int chave; // valor da chave no elemento do arquivo de índice
    int pos_arq; // posição onde a busca é iniciada no arquivo (tabela)
};

struct Arq_Seq_In{
    int tam_arq; // tamanho do arquivo (tabela)
    int tam_index; // tamanho do índice
    int *arq; // arquivo (tabela)
    struct IF_Item *index; // arquivo de índice
};



Arq_Seq_In* criar_arq_seq_ind(int tam_index, int *arquivo, int n){
    Arq_Seq_In* arqSI = (Arq_Seq_In*) malloc(sizeof(Arq_Seq_In));
    int i, tam_bloco;

    arqSI->tam_arq = n;
    arqSI->tam_index = tam_index;
    arqSI->arq = (int*) malloc(n * sizeof(int));
    arqSI->index = (IF_Item*) malloc(tam_index * sizeof(IF_Item));

    for (i = 0; i < n; i++)
        arqSI->arq[i] = arquivo[i];

    tam_bloco = n / tam_index;

    for (i = 0; i < tam_index; i++){
        arqSI->index[i].pos_arq = i * tam_bloco;
        arqSI->index[i].chave = arquivo[arqSI->index[i].pos_arq];
    }

    return arqSI;
}


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



// busca binária adaptada para a tabela de índice: caso a chave não
// seja encontrada, a função retorna a posição do "bloco" do arquivo
// deve ser continuada a busca.
static int busca_bin_TI(int x, IF_Item *tab_index, int ini, int fim){
	int meio;

	if (ini < fim){
		meio = (ini + fim) / 2;

		if (x == tab_index[meio].chave)
			return meio;
		else if (x < tab_index[meio].chave)
			return busca_bin(x, tab_index, ini, meio - 1);
		else
			return busca_bin(x, tab_index, meio + 1, fim);
	}else
		return ini;
}


int buscar_item(int chave, Arq_Seq_In* arqSI){
    int ini, fim, pos;

    if (arqSI != NULL){
        // Se a chave procurada for a menor que a primeira chava da tabela de índice,
        // então ela não está no arquivo
        if (chave < arqSI->index[0].chave)
            return -1;

        // busca no índice
        pos = busca_bin_TI(arqSI->index, arqSI->tam_index);

        if (chave == arqSI->index[pos].chave)
            return arqSI->index[pos].pos_arq;

        // busca na tabela
        else{
            // Esse caso deve ser tratado, pois o algoritmo busca_bin_TI pode parar em uma
            // posição com chave maior do que a que está sendo procurada
            if (chave < arqSI->index[pos].chave)
                pos--;

            ini = arqSI->index[pos].pos_arq ;

            if (pos + 1 < arqSI->tam_index)
                fim = arqSI->index[pos + 1].pos_arq - 1;
            else
                fim = arqSI->tam_arq - 1;



            return busca_bin(arqSI->arq, ini, fim);
        }
    }

    return -1;
}

