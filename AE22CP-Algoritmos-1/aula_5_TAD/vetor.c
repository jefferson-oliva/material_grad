#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"


Vetor* criar_vetor(int n){
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));

    v->n = n;

    v->v = (int*) malloc(sizeof(int) * n);

    return v;
}

int maior(Vetor* v){
    int i;
    int m = v->v[0];

    for (i = 1; i < v->n; i++)
        if (m > v->v[i])
            m = v->v[i];

    return m;
}

Vetor* soma(Vetor* v1, Vetor* v2){
    int nMaior, nMenor, i;
    Vetor *v3;

    if (v1->n > v2->n){
        nMaior = v1->n;
        nMenor = v2->n;
    }else{
        nMaior = v2->n;
        nMenor = v1->n;
    }

    v3 = criar_vetor(nMaior);

    for (i = 0; i < nMenor; i++)
        v3->v[i] = v1->v[i] + v2->v[i];

    for (i = nMenor; i < v1->n; i++)
        v3->v[i] = v1->v[i];

    for (i = nMenor; i < v2->n; i++)
        v3->v[i] = v2->v[i];

    return v3;
}
