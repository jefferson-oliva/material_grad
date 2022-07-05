#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Assim como qualquer tipo de dado, o uso de ponteiros segue a mesma regra para as structs

Os operadores * e & possuem os mesmos significados para ponteiros de structs
*/

typedef struct aluno{
    char nome[101];
    int RA;
    float coef;
}aluno;

int main(void){
    aluno variavel;
    aluno *ponteiro;

    ponteiro = &variavel;

    (*ponteiro).RA = 238;
    
    (*ponteiro).coef = 0.57;
    strcpy((*ponteiro).nome, "Gilberto");

    /**Lembrem-se (*ponteiro).campo é diferente de (*ponteiro.campo)

    (*ponteiro).campo: é utilizado quando a variável de estrutura é declarada como ponteiro

    (*ponteiro.campo): quando um campo de um registro é declarado como ponteiro. Exemplo:

    typedef struct X{
        int *var;
    }X;

    X r;
    X *p;

    int i = 2;
    int j = 3;

    (*r.var) = &i; // equivalente a *r.var = &i;

    p = &r;
    
    (*p).var = &j;

    *(*p).var = 3; // o * interno é referente ao ponteiro da estrutura e o * externo é referente ao ponteiro do registro
    
    //ou *p->var = 3;
    */

    // Outra forma de atribuição de ponteiros de structs
    /**
    Os ponteiros de struct possuem um operador para abreviar o comando de acesso ao valor
    --"->": acesso ao valor do campo no endereço
    -- "p->" equivale ao uso de "(*p)."
    */
    ponteiro->RA = 238;
    ponteiro->coef = 0.57;
    strcpy(ponteiro->nome, "Gilberto");

    return 0;
}
