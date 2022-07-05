#include <stdio.h>
#include <stdlib.h>

int mochila_fb(int c[], int p[], int n, int b, int i, int max){
    int c1, c2;
    
    if (i >= n){ // Verificar se todos os objetos foram explorados
        if (b < 0)
            return 0; // se b tiver valor negativo, então será retornado 0, já que a capacidade da mochila foi extrapolada.
        else
            return max; // caso contrário, será retornado o custo máximo acumulado
    }else{
    	c1 = mochila_fb(c, p, n, b, i + 1, max);  // o objeto na posição i não foi colocado na solução
        
        c2 = mochila_fb(c, p, n, b - p[i], i + 1, max + c[i]); // o objeto na posição i foi colocado na solução
        
        return c1 > c2 ? c1 : c2;
        
    }
}

int mochila(int c[], int p[], int n, int b){
    return mochila_fb(c, p, n, b, 0, 0);
}


int qtd_moedas(int v[], int n, int troco){
    int qtd = 0;
    int i;

    for (i = 0; (i < n) && (troco > 0); i++){
        qtd += troco / v[i];
        troco = troco % v[i];
    }

    if (troco == 0)
        return qtd;
    else
        return -1;
}


int mochila_g(int p[], int c[], int n, int b){
     int i = 0;
     float valor = 0;
     
     while ((i < n) && (p[i] <= b)){
          valor += c[i];
          b -= p[i];
          i++;
     }
     
     if ((b > 0) && (i < n))
          valor += ((float) b / p[i]) * c[i];
          
     return valor;
}



int main(){
    

    return 0;
}
