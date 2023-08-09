typedef struct{
    int n;
    int *v;
}Vetor;

Vetor* criar_vetor(int n);

int maior(Vetor* v);

Vetor* soma(Vetor* v1, Vetor* v2);
