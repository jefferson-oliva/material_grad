typedef struct ponto Ponto;

/**
Ao definirmos uma estrutura dentro de um TAD, ao usá-lo em um outro
arquivo através de ponteiros, pois não há como saber quanto espaço
a tal estrutura ocupará. Essa é justamente a ideia de que o usuário 
do TAD não deve conhecer ou ter acesso direto a estrutura. Isso se 
chama encapsulamento. Isso é feito para o usuário não possa fazer 
alterações inesperadas sobre a estrutura.
*/

// Função que cria e retorna um Ponto*
Ponto * cria_ponto(float x, float y);

// Imprimir conteúdo de Ponto*
void imprime_ponto(Ponto *p);

// Calcular a distância Euclidiana entre dois pontos
float distancia(Ponto *p1, Ponto *p2);

// Liberar a área alocada para Ponto
void libera_ponto(Ponto *p);
