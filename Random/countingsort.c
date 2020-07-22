#include <stdio.h>
#include <stdlib.h>

//TODO: ERRO
void countingsort( int vetorA[], int vetorB[], int n, int k )
{
	int vetorC[ k ];
	int i, j;
	for( i = 0; i < k ; i++ ) vetorC[ i ] = 0;
	for( j = 0; j < n ; j++ ) vetorC[ vetorA[ j ] ] +=1;
	for( i = 1; i < k ; i++ ) vetorC[ i ] = vetorC[ i ] + vetorC[ i - 1 ];
//	for( i = 0; i < 8; i++ ) printf("%-5d", vetorC[ i ]);
//	puts("");
	for( j = n - 1; j >= 0; j-- )
	{
		vetorB[ vetorC[ vetorA[ j ] ] ] = vetorA[ j ];
		vetorC[ vetorA[ j ] ]-- ; 
	}

}

int main( void )
{
	int vetorA[ 9 ] = { 0, 7, 7, 6, 5, 2, 3, 1, 4 };
	int vetorB[ 8 ];
	countingsort( vetorA, vetorB, 8, 8 );
	puts("vetorA");
	for( int i = 1; i < 9; i++ ) printf("%-5d", vetorB[ i ]);
	puts("");
}