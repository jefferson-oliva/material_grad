#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char str[255];
    int inteiro;
    float real;
}Chaves;


void gravar_txt(char *str, Chaves f[], int n){
    FILE *arq = fopen(str, "w+");

    if (arq != NULL){
        for (int i = 0; i < n; i++)
            fprintf(arq, "%s %d %f\n", f[i].str,
                    f[i].inteiro, f[i].real);

        fclose(arq);
    }
}


Chaves* ler_txt(char *str, int n){
    FILE *arq = fopen(str, "r+");
    Chaves* f = NULL;
    if (arq != NULL){
        f = malloc(sizeof(Chaves) * n);
        for (int i = 0; (i < n) && !feof(arq); i++)
            fscanf(arq, "%s %d %f", f[i].str,
                    &f[i].inteiro, &f[i].real);

        fclose(arq);
    }

    return  f;
}


void copy(FILE *orig, FILE *dest){
    while (!feof(orig)){
        char str[100];
        fgets(str, 100, orig);
        fputs(str, dest);
   }
}


void concatenarV2(char *o1, char *o2, char *d){
    FILE *aO1 = fopen(o1, "r+");
    FILE *aO2 = fopen(o2, "r+");
    FILE *aD = fopen(d, "w+");

    if (aO1 != NULL){
        copy(aO1, aD);
        fclose(aO1);
    }

    if (aO2 != NULL){
        copy(aO2, aD);
        fclose(aO2);
    }

    fclose(aD);
}


void concatenar(char *o1, char *o2, char *d){
    FILE *aO1 = fopen(o1, "r+");
    FILE *aO2 = fopen(o2, "r+");
    FILE *aD = fopen(d, "w+");

    if (aO1 != NULL){
        while (!feof(aO1)){
            char str[100];
            fgets(str, 100, aO1);
            fputs(str, aD);
        }

        fclose(aO1);
    }

    if (aO2 != NULL){
        while (!feof(aO2)){
            char str[100];
            fgets(str, 100, aO2);
            fputs(str, aD);
        }

        fclose(aO2);
    }

    fclose(aD);
}


int main() {
    //Chaves f[6];

    /*strcpy(f[0].str, "chiforimpola");
    f[0].inteiro = 100;
    f[0].real = 6.0;

    strcpy(f[1].str, "espiriguidiberto");
    f[1].inteiro = 200;
    f[1].real = 5.0;

    strcpy(f[2].str, "ramon");
    f[2].inteiro = 300;
    f[2].real = 4.0;

    strcpy(f[3].str, "chirimoia");
    f[3].inteiro = 400;
    f[3].real = 3.0;

    strcpy(f[4].str, "mentecinco");
    f[4].inteiro = 500;
    f[4].real = 2.0;

    strcpy(f[5].str, "frederico");
    f[5].inteiro = 650;
    f[5].real = 6.5;*/

    /*FILE *arq = fopen("chavo.dat", "rb+");
    Chaves x;

    fseek(arq, sizeof(Chaves) * 3, SEEK_SET);

    fread(&x, sizeof(Chaves), 1, arq);

    printf("%s %d %f\n", x.str, x.inteiro, x.real);

    fseek(arq, 0, SEEK_END);

    printf("Tamanho ====> %d\n\n", ftell(arq));
    printf("Unidades ====> %d\n\n", ftell(arq)/sizeof(Chaves));

    fclose(arq);*/

    char str[20];

    fgets(str, 20, stdin);

    printf("%s", str);

    return 0;
}
