#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    FILE *newFile;
    unsigned int counter; // counter
    char buffer[27];
    
    if( (newFile = fopen( "arquivo02.dat", "w+" ) ) == NULL ) {
        puts("File can't be open ! ");        
    }
    // if( (newFile = fopen( "arquivo02.dat", "w" ) ) == NULL )	{
    //     puts("Erro ao abrir o arquivo !");
    // }
    else {
        for( counter = 'A'; counter <= 'Z'; ++counter ) {
            fputc( counter, newFile );
        }

        rewind( newFile );
        fread( buffer, 1, 26, newFile );
        fclose( newFile );
        buffer[26] = '\0';
        puts(buffer);
    }
}