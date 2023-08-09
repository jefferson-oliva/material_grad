#include <stdio.h>
#include <stdlib.h>
void print_file_content(char * path){
    FILE * arq = fopen(path, "r");
    char str[100];

    if (arq){
        while (!feof(arq)){
            fgets(str, 100, arq);
            printf("%s", str);
        }

        printf("\n");
        int close = fclose(arq);
        if (close == 0)
            printf("Operacao bem sucedida!\n");
        else
            printf("Falha ao fechar o arquivo.\n");
    }
}

int main()
{

    //print_file_content("/home/jefferson/Downloads/teste.txt");
    print_file_content("teste.txt");

    return 0;
}
