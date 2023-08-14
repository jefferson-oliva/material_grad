// cabeçalho do TAD hashT

typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;


HashT *criar(unsigned int tam);

int buscar(int key, HashT *t);

int inserir(int key, HashT *t);

int remover(int key, HashT *t);

void imprimir(HashT *t);

int liberar(HashT *t);
