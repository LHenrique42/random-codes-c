#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// prototypes
void bubbleSort( int * const array, size_t size, _Bool (*compare)(int a, int b) );
_Bool crescente( int a, int b );
_Bool decrescente( int a, int b );



int main( void )
{ // begin main
	system("clear");
	int array[ SIZE ] = { 20, 30, 10, 7, 3, -65, 43, 25, 54, 8 }; // array
	size_t i; // counter
	unsigned short ordem; // ordem crescente ou descrescente


	printf("1 - Ordem crescente\n2 - Ordem decrescente\nValor: ");
	scanf("%hu", &ordem); // ler opcao

	if( ordem == 1 ) {
		// se for crescente 
		bubbleSort( array, SIZE, crescente );
	}
	else {
		// se for decrescente
		bubbleSort( array, SIZE, decrescente );
	}

	// imprime array
	puts("Elementos do array: ");

	for( i = 0; i < SIZE; i++ ) {
		printf("%5d", array[i] );
	}
	puts("");

} // end main

// Bubble Sort
void bubbleSort( int * const array, size_t size, _Bool (*compare)(int a, int b) )
{ // begin bubbleSort
	void swap( int *element1Ptr, int *element2Ptr );
	size_t i; // counter
	unsigned int passo; // counter passo

	// loop para ordenar
	for( passo = 0; passo < SIZE - 1; passo++ ) {
		for( i = 0; i < SIZE - 1 - passo; i++ ) {
			if( (*compare)( array[i], array[i+1] ) ) swap( &array[i], &array[i+1] ); // se for preciso troca, chama funcao swap 
		}
	}
} // end bubbleSort

// retorna verdadeiro se crescente
_Bool crescente( int a, int b )
{
	return a > b;
}

// retorna verdadeiro se decrescente
_Bool decrescente( int a, int b )
{
	return a < b;
}

// troca elementos 
void swap( int *element1Ptr, int *element2Ptr )
{
	int hold = *element1Ptr; // temporario
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}