#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int conta_digito(int digito, int numero){
    if ((abs(numero) >= 0) && (abs(numero) <= 9))
        return digito == numero;
    else
        return (digito == (numero % 10)) + conta_digito(digito, numero / 10);
}

int main() {
    int d, n;
    
    scanf("%d %d", &d, &n);
    
    printf("%d", conta_digito(d, n));

    return 0;
}
