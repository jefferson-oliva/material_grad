#define ITENSPAGINA 4
// Uma entrada da tabela de índice das páginas
typedef struct {
	int posicao;
	int chave;
}Indice;

typedef struct{
	int chave;
	char descricao[51];
	float preco;
/* outros componentes */
}Item;


int buscar(Indice tab[], int tam, Item* item, FILE *arq){
	Item pagina[ITENSPAGINA];
	int i, n_itens;
	long desloc;
	
	for (i = 0; i < tam && tab[i].chave <= item->chave; i++);
	
	if ((i == 0) && (tab[i].posicao < item->chave)) 
		return 0;
	else {
		if (i < tam) 
			n_itens = ITENSPAGINA;
		else {
			fseek(arq, 0, SEEK_END);
			n_itens = (ftell(arq) / sizeof(Item)) % ITENSPAGINA;
		}
			desloc = (tab[i - 1].posicao) * ITENSPAGINA * sizeof(Item);
			fseek (arq, desloc, SEEK_SET);
			fread(&pagina, sizeof(Item), n_itens, arq);
			
			for (i = 0; i < n_itens; i++)
				if (pagina[i].chave == item->chave){
					*item = pagina[i];
					return 1;
				}
		return 0;
	}
}
