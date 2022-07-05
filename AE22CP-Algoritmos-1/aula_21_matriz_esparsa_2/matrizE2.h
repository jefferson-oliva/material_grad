typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;


Spa_Mat* criar(int l, int c);

Cell* criar_celula(int item, int l, int c);

int buscar(int item, Spa_Mat* mat);

void alterar(int item, int l, int c, Spa_Mat* mat);

