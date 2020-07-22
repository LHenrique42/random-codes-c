#include <stdio.h>

void merge( int vetor[], int inicio, int fim );
void mergesort( int vetor[], int inicio, int fim );

int main( void )
{
	int a[ 8 ] = { 10, -33, 0, 5, -2, 1, 606, 125 };
    mergesort(a, 0, 7);
    for( int i = 0; i < 8; i++ ) printf("%d\n", a[i]);
}

void mergesort( int vetor[], int inicio, int fim )
{
	if( fim <= inicio ) return;
    int meio = ( inicio + fim )/2; // acha o indice meio
    mergesort(vetor, inicio, meio); // primeira parte
    mergesort(vetor, meio+1, fim); // segunda parte
    merge(vetor, inicio, fim); // merge as partes
}

void merge( int vetor[], int inicio, int fim )
{
	int i, j, k;  // auxiliares
    int aux[ fim - inicio + 1]; // aloca vetor auxiliar
    for( i = 0, j = inicio; i < ( fim - inicio + 1); i++ ) aux[ i ] = vetor[ j++ ]; // preenche vetor com todos elementos
    for( i = 0, j = ( fim - inicio + 1)/2, k = inicio; k <= fim; k++ )
    {
    	// loop para fazer o merge ordenado
        if( i == ( fim - inicio + 1)/2 ) vetor[ k ] = aux[ j++ ];
        else if( j == ( fim - inicio + 1 ) ) vetor[ k ] = aux[ i++ ];
        else (aux[ i ] <= aux[ j ]) ? (vetor[ k ] = aux[ i++ ]) : (vetor[ k ] = aux[ j++ ]);
    }
}