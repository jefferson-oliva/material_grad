typedef struct IF_Item IF_Item;

typedef struct Arq_Seq_In Arq_Seq_In;


Arq_Seq_In* criar_arq_seq_ind(int tam_index, int *tabela, int n);

int buscar_item(int chave, Arq_Seq_In* arqSI);

