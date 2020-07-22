#include <stdio.h>
#include <stdlib.h>

void heapsort(int vetor[], int tamanho);
void constroiHeap(int vetor[], int n);
void swap( int *element1Ptr, int *element2Ptr );

int main( void )
{
    int vetor[ 8 ] = { 8, 32, 15, 5, 0, -3, 7, 9 };
    constroiHeap( vetor, 8 );
    heapsort(vetor, 8);
    for ( int i = 0; i < 8; i++ ) printf("%-4d", vetor[ i ]);
    puts("");
}
 
//Dado um vetor[1...n], rearranja transformando-o em um Heap
void constroiHeap(int vetor[], int n)
{
    int i;
    int count;
    for( count = 1; count < n; count++ )
    {
        i = count;
        while( i > 0 && vetor[ i/2 ] < vetor[ i ] )
        {
            swap( &vetor[ i ], &vetor[ i/ 2 ]);
            i /= 2;
        }
    }
}

void heapsort(int vetor[], int tamanho)
{
    while( tamanho > 0 )
    {
        swap( &vetor[0], &vetor[tamanho - 1]);
        constroiHeap( vetor, --tamanho);
    } 
}

// troca elementos 
void swap( int *element1Ptr, int *element2Ptr )
{
	int hold = *element1Ptr; // temporario
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}
