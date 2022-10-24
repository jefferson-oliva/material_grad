#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_digito(unsigned int numero){
    if ((numero >= 0) && (numero <= 9))
        return numero;
    else
        return (numero % 10) + soma_digito(numero / 10);
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    printf("%d", soma_digito(n));

    return 0;
}
