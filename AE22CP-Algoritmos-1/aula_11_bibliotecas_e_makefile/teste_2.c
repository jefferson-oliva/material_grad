#include <stdio.h>
#define max(A, B) ((A > B) ? (A) : (B))



#ifdef MENSAGEM
void mostra(){
	printf("Me chamo Jefferson!\n");
}
#else
void mostra(){
	printf("Eu nao!\n");
}
#endif

int main(){
	printf("Oi! Eu sou o Gokku! E voce?\n");
	
	mostra(0);
	
	return 0;
}

