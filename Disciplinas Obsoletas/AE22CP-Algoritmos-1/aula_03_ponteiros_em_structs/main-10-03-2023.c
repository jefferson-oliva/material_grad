#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {um = 1, dois, tres, quatro, cinco}digitos;

typedef struct {
     char nome[101];
     int RA;
     float coef;
}Aluno;

typedef struct {
     char nome[101];
     int *RA;
     float coef;
}Estudante;

typedef struct{
    int x, y;
}vet_r2;

typedef union {
    int val_int;
    long val_long;
    double val_double;
}umpratodos;

typedef struct {
    char marca[20];
    umpratodos x;
    union{
        long nro_id;
        char char_id[20];
    };
    int tipo;
}inventario;




/*vet_r2* somar(vet_r2* v1, vet_r2* v2){
    vet_r2* v3;
    vet_r2 aux;

    v3 = &aux;

    v3->x = v1->x + v2->x;
    v3->y = v1->y + v2->y;

    return v3;
}*/

int main(void){
    /*Aluno a;
    Estudante b;
    Aluno *pa;
    int x;
    Estudante *pb;

    b.RA = &x;
    *b.RA = 1234;

    pa = &a;
    pb = &b;

    //(*pa).RA = 123;
    pa->RA = 123;
    //strcpy((*pa).nome, "Gil B.");
    strcpy(pa->nome, "Gil B.");
    //(*pa).coef = 0.7;
    pa->coef = 0.7;

    //printf("%d\n\n", *(*pb).RA);
    printf("%d\n\n", *pb->RA);

    printf("%d\n\n", *b.RA);
    printf("%x\n\n", &a.coef);
    printf("%x\n\n", &a);*/

//    (*pa).RA = 123;
//    strcpy((*pa).nome, "Gil B.");
//    (*pa).coef = 0.7;
//
//    printf("%d\n\n", *(*pb).RA);
//    printf("%d\n\n", *b.RA);
//    printf("%x\n\n", &a.coef);
//    printf("%x\n\n", &a);

     umpratodos u;
     umpratodos *pu;
     inventario a;
     digitos d = cinco;

     printf("%d\n", d);

     a.x.val_int;


     pu = &u;

     //u.val_int = 15;
     pu->val_int = 15;
     //printf("%d\n", u.val_int);
     printf("%d\n", pu->val_int);


     //u.val_double = 1.38;
     printf("%g\n", u.val_double);
     printf("%d\n", u.val_long);

    return 0;
}



