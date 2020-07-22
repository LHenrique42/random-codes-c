



/*
Forty students were asked to rate the quality of the food in the student cafeteria on a
scale of 1 to 10 (1 means awful and 10 means excellent). Place the 40 responses in an
integer array and summarize the results of the poll.


#include <stdio.h>
#define RESPONSES_SIZE 20
#define FREQUENCY_SIZE 10

int main( void )
{
	short int answers[ RESPONSES_SIZE ] = { 1, 2, 3, 3, 4, 6, 7, 4, 6, 8, 10, 8, 7, 6, 5, 3, 8, 9, 8, 9 };
	short int frequency[ FREQUENCY_SIZE ] = { 0 };

	size_t i; // counter

	for( i = 0; i < RESPONSES_SIZE; i++ ){
		++frequency[ answers[i] - 1 ];
	}

	printf("%s%15s\n", "Nota", "Frequência");
	for( i = 1; i <= FREQUENCY_SIZE; i++ ){
		printf("%4lu%14hu\n", i, frequency[i - 1]);
	}
}*/


/* 
#include <stdio.h>
Variavel tipo size:

int main( void )
{
    int n[ 10 ];
    size_t i; // counter

    for ( i = 0; i < 10; i++ ) {
        n[ i ] = 0;
    }

    printf( "%s%13s\n", "Element", "Value" );

    for ( i = 0; i < 10; i++ ) {
        printf( "%7u%13d\n", i, n[ i ] );
    }
} */