#include <stdio.h>
#include <stdlib.h>

/*Coversao Inteiro -> Hexadecimal -> Binario -> Octal
unsigned int dec_to_bin(unsigned int k) 
{
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * dec_to_bin(k / 2)));
}

int main( void )
{
    unsigned int number = 0;
    while ( number < 10 ){
        printf("Integer: %d\nBinary: %u\nOctal: %o\nHexadecimal: %X\n\n", number, dec_to_bin(number), number, number);
        number++;
    }
    return 0;
} */


/*Caracter do tipo _Bool
int main( void )
{
    _Bool teste = 1;
    printf("%d\n", teste);
    return 0;
}*/

/* EOF
int main( void )
{
    char read;
    while ( (read = getchar()) != EOF ); // <ctrl> + d
    return 0;
}*/