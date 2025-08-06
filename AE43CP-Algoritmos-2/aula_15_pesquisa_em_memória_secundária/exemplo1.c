#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct{
	long RA;
	char nome[70];
	int codigo_curso;
	float coef;
}Aluno;

typedef struct{
	Aluno itens[ITENSPAGINA];
}Pagina;


int buscar(Aluno* aluno, FILE *arq){
	Pagina pag;
	int i = 0;
	int tam = tamanho_arquivo(arq);

	fseek(arq, 0, SEEK_SET);

	if (tam > 0){
		do{
			fread(pag, sizeof(Pagina), 1, arq);

			for (i = 0; (i < ITENSPAGINA) && (aluno->RA < pag->itens[i]->RA); j++);

			if ((i < ITENSPAGINA) && (aluno->RA == pag->itens[i]->RA)){
				*aluno = pag->itens[i];
				return 1;
			}
		}while (ftell(arq) < tam);
	}
	return 0;
}


int tamanho_arquivo(FILE *arq){
	fseek(arq, 0, SEEK_END);
	return ftell(arq);
}

int main(){
    char str[6];

    fgets(str, 6, stdin);

    printf("%s\n\n\n", str);

    return 0;
}

