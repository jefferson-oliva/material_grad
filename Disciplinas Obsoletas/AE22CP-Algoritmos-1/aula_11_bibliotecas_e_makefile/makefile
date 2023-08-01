COMPILADOR=gcc
APAGA=rm -f

all: saida3 clean

saida3: principal.o menu.o lista.o pilha.o fila.o
	$(COMPILADOR) -o saida3 principal.o menu.o lista.o pilha.o fila.o

principal.o: principal.c menu.h lista.h pilha.h fila.h
	$(COMPILADOR) -c principal.c

menu.o: menu.h menu.c
	$(COMPILADOR) -c menu.c

lista.o: lista.h lista.c
	$(COMPILADOR) -c lista.c

pilha.o: pilha.h pilha.c
	$(COMPILADOR) -c pilha.c

fila.o: fila.h fila.c
	$(COMPILADOR) -c fila.c

clean:
	$(APAGA) *.o
