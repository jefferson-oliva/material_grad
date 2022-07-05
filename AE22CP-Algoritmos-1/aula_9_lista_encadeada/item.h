typedef struct Item Item;

// Alocação dinâmica para a estrutura do tipo Item
Item* criar_item(int key);

// Acessar elemento dentro de uma variável do tipo Item
int acessar_chave(Item *item);

// Acessar elemento dentro de uma variável do tipo Item
int alterar_chave(Item *item, int key);

// Liberar o espaço alocado para uma variável do tipo Item
int liberar_item(Item *item);
