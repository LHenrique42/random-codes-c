#include <stdio.h>
#include <ctype.h>


/* CONST
void test(const int *nPtr)
{
	printf("%d\n", *nPtr);
}

int main( void )
{
	int num = 5;
	int *nPtr = &num;
	test(nPtr);
}*/

// ------------------------------------------------------

/* CONVERT TO UPPER CASE
void convertToUpperCase( char *stringPtr )
{
	while( *stringPtr != '\0' ) {
		*stringPtr = toupper( *stringPtr );
		++stringPtr;
	}
}

int main( void )
{
	char string[] = "heLLo WorLd!!";
	printf( "%s\n", string );
	convertToUpperCase( string );
	printf("%s\n", string);
}*/

// ------------------------------------------------------

/* CONST - 2
int main( void )
{
	int num = 5;
	int x = 3;
	int const *numPtr = &num; // ponteiro constante, sempre aponta mesma memoria;
	const int const *numPtr2 = &x; // ponteiro constante e valor constante
}*/

// ------------------------------------------------------

