#include <stdio.h>
#include <stdlib.h>

/*
    realloc
*/

typedef struct priority_queue 
{
    int *elementos;
    int qtdElementos;
} HEAP;

int main( void )
{
    HEAP *heap = ( HEAP* )malloc( sizeof( HEAP ) );
    int i = 0;
    while( i >= 0 )
    {
        printf("\n%s", "Insira 1: ");
        scanf("%d", &i);
        if( i >= 0 )
        {
            heap -> elementos = ( int* )realloc( heap -> elementos, i * sizeof( int ) );
            heap -> elementos[ i ] = i;
        }
    }
    printf("\n%d", heap -> elementos[ 1 ]);
    printf("\n%d", heap -> elementos[ 2 ]);
    printf("\n%d", heap -> elementos[ 3 ]);
}