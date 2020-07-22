#include <stdio.h>

/*
    Le contas do arquivo

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
    int result;

    FILE *newFile; // cria arquivo

    // abre arquivo
    if( ( newFile = fopen("random-access.dat", "rb")) == NULL ) {
        puts("File can't be open !");
    }

    else {

        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        while( !feof(newFile) ) {

            result = fread( &client, sizeof( struct client ), 1, newFile );

            if( result != 0 && client.account != 0 ) {
                // se houver a conta, imprime
                printf( "%-6d%-16s%-11s%10.2f\n", client.account, client.last_name, client.first_name, client.balance );
            }

        }

        fclose( newFile ); // fecha arquivo
    }
}

