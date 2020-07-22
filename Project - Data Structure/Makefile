OPTIONS = -Wall

all: main.o novoTrab.o
	gcc novoTrab.o main.o -o main
novoTrab.o: novoTrab.c
	gcc $(OPTIONS) -c novoTrab.c
main.o: main.c
	gcc $(OPTIONS) -c main.c
clean:
	rm -rf *.o
