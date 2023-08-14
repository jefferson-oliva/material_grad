#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"


int main() {

    Spa_Mat *matrix = criar(3, 3);

    trocar(1, 0, 0, matrix);
    trocar(2, 0, 1, matrix);
    trocar(3, 0, 2, matrix);

    imprimir(matrix);


    return 0;
}

