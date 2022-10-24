#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int palindromo(char *str, int i, int f){
    if ((i >= f))
        return 1;
    else if (str[i] != str[f])
        return 0;
    else
        return palindromo(str, i + 1, f - 1);
}

int main() {
    char str[20];
    
    scanf("%s", str);
    
    if (palindromo(str, 0, strlen(str) - 1))
        printf("palindromo");
    else
        printf("nao palindromo");

    return 0;
}
