#include <stdio.h>

#define MAX 10

// Solução do problema do labirinto por backtracking
int resolver_labirinto(int lab[MAX][MAX], int m, int n, movX[], movY[], int li, int ci, int lf, int cf){
	/*
	l, c: posição de um passo no labirinto
	*/
	int l, c, i, passos;

	if ((li == lf) && (ci == cf)) return lab[li][ci];

	/*Todos os movimentos a partir da posição inicial são testados*/
	for (i = 0; i < 4; i++){
		// Posição do candidato a próximo passo
		l = li + movX[i];
		c = ci + movY[i];

		/*O movimento é verificado e caso seja válido, uma solução é gerada*/
		if ((l >= 0) && (l < m) && (c >= 0) && (c < n) && (lab[l][c] == -1)){
			lab[l][c] = lab[li][ci] + 1; // atualizar a quantidade de passos na posição l,c

			// Continuar o percurso no labirinto
			passos = resolver_labirinto(lab, m, n, movX, movY, l, c, lf, cf);
		
			if (passos > 0) return passos;
		}
	}
	return 0;
}


// Outra solução do problema do labirinto por backtracking
// Neste caso, a solução ótima deve ser encontrada
void resolver_labirinto2(int lab[MAX][MAX], int m, int n, movX[], movY[], int li, int ci, int lf, int cf, int *min){
	int l, c, i;

	if ((li == lf) && (ci == cf)){
		if (lab[lf][cf] < *min)
			*min = lab[lf][cf];
	}else{
	/*Todos os movimentos a partir da posição inicial são testados*/
		for (i = 0; i < 4; i++){
			l = li + movX[i];
			c = ci + movY[i];

			/*O movimento é verificado e caso seja válido, uma solução é gerada*/
			if ((l >= 0) && (l < m) && (c >= 0) && (c < n) && ((lab[l][c] == -1) || (lab[l][c] > 						lab[li][ci] + 1))){
				lab[l][c] = lab[li][ci] + 1;

				resolver_labirinto2(lab, m, n, movX, movY, l, c, lf, cf, min);
			}
		}
	}
}


// Outra solução do problema do labirinto por branch-and-bound
void resolver_labirintoBnB(int lab[MAX][MAX], int m, int n, movX[], movY[], int li, int ci, int lf, int cf, int *min){
	int l, c, i;

	if ((li == lf) && (ci == cf)){
		if (lab[lf][cf] < *min)
			*min = lab[lf][cf];
	}else{
		/*Todos os movimentos a partir da posição inicial são testados*/
		for (i = 0; i < 4; i++){
			l = li + movX[i];
			c = ci + movY[i];

			/*O movimento é verificado e caso seja válido, uma solução é gerada*/
			if ((l >= 0) && (l < m) && (c >= 0) && (c < n) && ((lab[l][c] == -1) || (lab[l][c] > 						lab[li][ci] + 1))){
				lab[l][c] = lab[li][ci] + 1;

				// Aqui são definidos os limitantes
				if (lab[l][c] + abs(l - lf) + abs(c - cf) < *min)
					resolver_labirintoBnB(lab, m, n, movX, movY, l, c, lf, cf, min);
			}
		}
	}
}


int main(){
	/*
	lab: labirinto
	n, m: número de linhas e de colunas ocupadas na matriz labirinto
	li, ci: posição inicial no labirinto
	lf, cf: posição final no labirinto
	resp: 1 se um caminho foi encontrado entre (li, ci) e (lf, cf), ou 0, caso contrário
	*/
	int lab[MAX][MAX], n, m, li, ci, lf, cf, resp;

	/*Movimentos válidos no labirinto
	
	Exemplo: movX[0] e movY[0] indica que o movimento é para baixo
	*/	
	int movX[] = {0, 1, 0, -1}; // Movimentos no eixo x da matriz
	int movY[] = {1, 0, -1, 0}; // Movimentos no eixo y da matriz

	/*inicializar as variáveis relacionadas ao labirinto*/
	//iniciar_labirinto(lab, m, n, li, ci, lf, cf); // implementar
	
	lab[ci][cf] = 0; // posição inicial no labirinto

	resp = resolver_labirinto(lab, m, n, movX, movY, li, ci, lf, cf);

	if (resp > 0) imprimir_labirinto(lab, m, n);
	eles printf("Solucao nao encontrada!\n");

	return 0;
}


