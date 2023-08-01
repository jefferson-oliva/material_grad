#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Como organizar um conjunto de informações heterogêneas?

Structs
- Conjunto de variáveis
- Cada variável é um campo do registro
- Structs não são alocadas na memória: são definidas como um novo tipo

*/


// Exemplo de estrutura
/**
struct nome_registro{
	tipo_1 var_1;
	...
	tipo_n var_n;
};
*/

struct aluno{
    char nome[101];
    int RA;
    float coef;
};


// typedef
// sintaxe: typedef tipo novo_nome_tipo;
// sintaxe para struct: typedef struct estrutura novo_nome;
// Exemplo: typedef float real;
typedef struct aluno aluno; // O novo nome pode ser, praticamente, qualquer coisa,
                            // até mesmo o nome da estrutura

/**
Outras formas para o uso do typedef em structs

typedef struct aluno{
    char nome[101];
    int id;
    float coef;
}aluno;

ou

typedef struct {
    char nome[101];
    int id;
    float coef;
}aluno; // Neste caso, a declaração "struct aluno a;" acarretará em erro
*/

int main(){
    // declaração de uma variável struct:
    // struct nome_estrutura = nome_variavel;
    struct aluno a;
    aluno b; // essa declaração é permitida porque foi atribuído um "novo" nome para a estrutura

    // Exemplo de vetor de struct
    aluno turmaA[22];

    // incialização de uma struct
    aluno c = {"Hermes", 123, 0.73}; // nessa declaração, a ordem das variáveis devem ser de acordo
                                     // com o que foi feito na declaração da struct

    // Acesso aos elementos
    printf("%s - %d - %f\n", c.nome, c.RA, c.coef);

    // Atribuição
    a = c;
    strcpy(b.nome, c.nome);
    b.RA = c.RA;
    b.coef = c.coef;

    return 0;
}


// struct como argumento de função
void imprime_dados_aluno(aluno a){
    printf("\n Nome: %s", a.nome);
    printf("\n RA: %d", a.RA);
    printf("\n Coeficiente: %f\n", a.coef);
}


// Função que retorna struct
aluno gerar_aluno(char nome[101], int RA, float coef){
    aluno a;

    strcpy(a.nome, nome);
    a.RA = RA;
    a.coef = coef;

    return a;
}


/**
Structs aninhados
typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    char rua[151];
    int nro;
    char bairro[41];
    char cep[9];
    char cidade[41];
    char estado[41];
}Endereco;

typedef struct {
    char tel[11];
    char cel[12];
    char email[101];
}Contato;

typedef struct pessoa{
    char nome[121];
    char rg[9];
    char cpf[12];
    Data data_nasc;
    Endereco endereco;
    Contato contato;
}Pessoa;
*/
