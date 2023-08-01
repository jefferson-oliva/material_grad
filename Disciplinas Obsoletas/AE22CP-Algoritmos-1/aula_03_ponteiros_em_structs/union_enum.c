#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Uma união (union) é um formato de dados que pode armazenar tipos diferentes, mas apenas um tipo de cada vez

Uma struct pode armazenar um int e um char e um double

Uma união pode armazenar um int ou um long ou um double

A forma de declaração é igual a da struct, mas usando o comando union. Exemplo:

*/

/**
Enum Define um enumerado como um novo tipo

Estabelece símbolos (palavras) como constantes simbólicas para números inteiros entre 0 e o número de símbolos menos 1

Exemplo de sintaxe:
    enum enumerado {simb1, ..., simbn};
*/

typedef union {
    int val_int;
    long val_long;
    double val_double;
}umpratodos;

typedef enum {vermelho, laranja, amarelo, verde, azul, violeta, anil, ultravioleta}espectro;

int main() {
    // União
    umpratodos u;

    u.val_int = 15;

    printf("%d\n", u.val_int);

    u.val_double = 1.38;

    printf("%g\n", u.val_double);
    printf("%d\n", u.val_int);

    /**
    Ponteiro de union possui a mesma sintaxe em relação à struct

    União anônima:
    

    typedef struct {
        char marca[20];
        union{ // formato depende do tipo inventario
            long nro_id; // inventários do tipo 1
            char char_id[20]; // outros inventários
        };
        int tipo;
    }inventario;
    */

    // Enumerado
    espectro banda;
    banda = azul; // válido, azul é um enumerador
    //banda = 2000; // inválido!, 2000 não é um enumerador
    banda = laranja; // válido
    banda++; // válido
    banda = laranja + vermelho; // válido
    int cor = azul; // válido, tipo espectro promovido a int
    banda = 3; // válido, o tipo espectro atribui um valor para cada tipo
    cor = 3 + vermelho; // válido, vermelho é convertido para
    //banda = espectro(3); // inválido

    return 0;
}
