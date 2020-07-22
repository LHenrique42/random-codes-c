#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bubbleSort( int * const array, size_t size ); // prototype

int main( void )
{
	system("clear");
	int array[ SIZE ] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // array
	size_t i; // counter
	puts("Dados antes do Bubble Sort:");
	// loop to print elements before bubble sort
	for( i = 0; i < SIZE - 1; i++ ) {
		printf("%4d", array[i]);
	}
	puts("");

	bubbleSort( array, SIZE ); // sort the array 

	puts("Dados após Bubble Sort:");
	// loop to print elements after bubble sort
	for( i = 0; i < SIZE - 1; i++ ) {
		printf("%4d", array[i]);
	}
	puts("");
}

void bubbleSort( int * const array, size_t size )
{
	/*
		1 pass - Leva o maior ate a ultima posicao
		2 pass - Leva o segundo maior ate a penultima posicao
		.
		.
		.
		last pass - o menor esta na primeira posicao
	*/
	void swap( int *element1Ptr, int *element2Ptr ); // prototype 
	unsigned int pass; // pass counter
	size_t i; // comparison counter

	for( pass = 0; pass < SIZE - 1; pass++ ) {

		for( i = 0; i < SIZE - 1 - pass; i++ ) {

			if( array[ i ] > array[ i + 1 ] ) swap( &array[ i ], &array[ i+1 ] );
		}
	}
}

void swap( int *element1Ptr, int *element2Ptr )
{
	int temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}