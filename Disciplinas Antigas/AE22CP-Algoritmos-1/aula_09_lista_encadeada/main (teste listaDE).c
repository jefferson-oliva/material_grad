#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDE.h"


int main() {
    ListaDE *l = criar_ListaDE();

    inserir_ultimoDE(1, l);
    inserir_ultimoDE(2, l);
    inserir_ultimoDE(3, l);
    inserir_ultimoDE(4, l);
    inserir_ultimoDE(5, l);
    inserir_ultimoDE(6, l);
    inserir_ultimoDE(7, l);
    inserir_ultimoDE(8, l);

    imprimirDE(l);

    removerDE(1, l);
    removerDE(5, l);
    removerDE(8, l);

    imprimirDE(l);

    return 0;
}
