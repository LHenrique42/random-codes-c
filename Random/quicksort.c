#include <stdio.h>
#include <stdlib.h>

void swap( int *element1Ptr, int *element2Ptr );
int partition(int s[], int l, int h);
void quicksort(int s[], int l, int h);
int particao( int vetor[], int inicio, int fim );
void quicksort_v2( int vetor[], int inicio, int fim );

int main( void )
{
	int vetor[ 8 ] = { 1, 15, -33, 5, 45, 15, 132, 15 };
    quicksort_v2( vetor, 0, 7 );
    for ( int i = 0; i < 8; i++ ) printf("%-4d", vetor[ i ]);
    puts("");
}

void swap( int *element1Ptr, int *element2Ptr )
{
	int hold = *element1Ptr; // temporario
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}



int partition(int s[], int l, int h)
{
	int i;
	/* counter */
	int p;
	/* pivot element index */
	int firsthigh;
	/* divider position for pivot element */
	
	p = h;
	firsthigh = l;
	for (i=l; i<h; i++)
		if (s[i] < s[p]) {
			swap(&s[i],&s[firsthigh]);
			firsthigh ++;
		}
	swap(&s[p],&s[firsthigh]);
	return(firsthigh);
}

void quicksort(int s[], int l, int h)
{
	int p;
	/* index of partition */
	if ((h-l)>0) {
		p = partition(s,l,h);
		quicksort(s,l,p-1);
		quicksort(s,p+1,h);
	}
}



void quicksort_v2( int vetor[], int inicio, int fim )
{
	if( fim <= inicio ) return;
	int m = particao( vetor, inicio, fim );
	quicksort_v2( vetor, inicio, m - 1 );
	quicksort_v2( vetor, m + 1, fim );
}

int particao( int vetor[], int inicio, int fim )
{
	int pivor = inicio;
	int esq = inicio + 1;
	int dir = fim;
	while ( 1 )
	{
		while( vetor[ esq ] < vetor [ pivor ] )	esq++;
		while( vetor[ dir ] > vetor [ pivor ] ) dir--;
		if( dir <= esq ) break;	
		swap( &vetor[ esq ], &vetor[ dir ]);
	}
	swap( &vetor[ pivor ], &vetor[ dir ]);
	return dir;
}














