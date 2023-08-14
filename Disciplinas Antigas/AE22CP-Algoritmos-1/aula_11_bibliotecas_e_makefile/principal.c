#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"
#include "menu.h"

int main(){
    Lista *l;
    Pilha *p;
    Fila *f;

    l = criar_lista();
    p = criar_pilha();
    f = criar_fila();

    exibir_menu();

    return 0;
}
