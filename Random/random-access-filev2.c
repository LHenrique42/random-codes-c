#include <stdio.h>

/*
    Cria contas no arquivo

*/

// struct cliente
struct client {
    unsigned int account; // number account
    char first_name[ 20 ]; // first name
    char last_name[ 20 ]; // last name
    double balance; // account balance
};

int main( void )
{
    struct client client = { 0, "", "", 0.0 }; // cria um cliente em branco
    unsigned int counter; // counter

    FILE *newFile; // cria arquivo

    // abre arquivo
    if( ( newFile = fopen("random-access.dat", "wb")) == NULL ) {
        puts("File can't be open !");
    }

    else {
        // le numero conta
        printf("%s", "Enter account number( 1 - 100, 0 to end program ): ");
        scanf("%u", &client.account);
        
        while( client.account != 0 ) {
            // le informacoes
            printf("%s", "Enter lastname, firstname, balance\n? ");
            fscanf( stdin, "%14s%9s%lf", client.last_name, client.first_name, &client.balance );
        
            // seek position in file to user-specified record 
            fseek( newFile, ( client.account - 1 ) * sizeof( struct client ), SEEK_SET );

            // write user-specified information in file 
            fwrite( &client, sizeof( struct client ), 1, newFile );

            printf( "%s", "Enter account number\n? " );
            scanf( "%d", &client.account );

        }

        fclose( newFile ); // fecha arquivo
    }
}
