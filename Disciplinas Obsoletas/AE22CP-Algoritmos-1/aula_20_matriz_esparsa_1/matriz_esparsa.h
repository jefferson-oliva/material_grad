typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;


Spa_Mat* criar(int l, int c);

Cell* criar_celula(int item, int col);

// verifica a existência de um item
int buscar(int item, Spa_Mat* mat);

// retorna o que há na posição [l][c] da matriz
int buscar_pos(int l, int c, Spa_Mat* mat);

// trocar de valor, inserir, remover
void trocar(int item, int l, int c, Spa_Mat* mat);

void imprimir(Spa_Mat* mat);

