#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displayBits( unsigned int value );

int main( void )
{
	unsigned int number;
	printf("%s", "Insira um número não-negativo: ");
	scanf("%u", &number);
	displayBits(number);
}

void displayBits( unsigned int value )
{
	unsigned int counter; // counter
	unsigned int mask = 1 << CHAR_BIT * sizeof( unsigned int ) - 1 ; // mascara ( CHAR_BIT -> limits.h)
	puts("Value:");
	printf("     ");
	for( counter = 1; counter <= CHAR_BIT * sizeof( unsigned int ); ++counter ) {
		putchar( value & mask ? '1' : '0' );
		value <<= 1;
		if( counter % 8 == 0 ) putchar( ' ' );
	}
	puts("");
}
