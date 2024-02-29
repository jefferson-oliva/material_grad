#include <stdio.h>
#include <stdlib.h>

int mochila_fb(int custo[], int peso[], int n, int capacidade, int i, int max){
    int c1, c2;
    
    if (i >= n){ // Verificar se todos os objetos foram explorados
        if (capacidade < 0)
            return 0; // se b tiver valor negativo, então será retornado 0, já que a capacidade da mochila foi extrapolada.
        else
            return max; // caso contrário, será retornado o custo máximo acumulado
    }else{
    	c1 = mochila_fb(custo, peso, n, capacidade, i + 1, max);  // o objeto na posição i não foi colocado na solução
        
        c2 = mochila_fb(custo, peso, n, capacidade - peso[i], i + 1, max + custo[i]); // o objeto na posição i foi colocado na solução
        
        return c1 > c2 ? c1 : c2;
        
    }
}

int mochila(int custo[], int peso[], int n, int capacidade){
    return mochila_fb(custo, peso, n, capacidade, 0, 0);
}


int qtd_moedas(int moedas[], int n, int troco){
    int qtd = 0;
    int i;

    for (i = 0; (i < n) && (troco > 0); i++){
        qtd += troco / moedas[i];
        troco = troco % moedas[i];
    }

    if (troco == 0)
        return qtd;
    else
        return -1;
}


int mochila_g(int custo[], int peso[], int n, int capacidade){
     int i = 0;
     float valor = 0;
     
     while ((i < n) && (peso[i] <= b)){
          valor += custo[i];
          capacidade -= peso[i];
          i++;
     }
     
     if ((capacidade > 0) && (i < n))
          valor += ((float) capacidade / peso[i]) * custo[i];
          
     return valor;
}



int main(){
    

    return 0;
}
