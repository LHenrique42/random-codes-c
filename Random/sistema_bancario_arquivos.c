#include <stdio.h>
#include <assert.h>

/*
    TODO: Criar sistema bancario, onde possa criar conta, atualizar ( saque/ debito ),
            deletar e gerar arquivos com todas as contas.
    TODO: Corrigir erros: nao esta atualizando/deletando
*/

struct client {
    unsigned int account; // number account
    char first_name[ 20 ]; // first name
    char last_name[ 20 ]; // last name
    double balance; // account balance
};

void newAccount( FILE* );
void updateAccount( FILE* );
void deleteAccount( FILE* );
void textFile( FILE* );
unsigned int enterChoice( void );

int main( void )
{
    unsigned int choice;
    FILE* bank;
    if( ( bank = fopen("banco.dat", "ab+")) == NULL ) {
        puts("File can't be open !");
    }
    else {
        choice = enterChoice();

        while( choice != 5 ) {
            switch( choice ) {
                case 1:
                    newAccount( bank );
                    break;
                case 2:
                    updateAccount( bank );
                    break;
                case 3:
                    deleteAccount( bank );
                    break;
                case 4:
                    textFile( bank );
                    break;
                default:
                    puts("The choice doesn't exist !");
            }
            puts("--------------------------------");
            puts("");
            choice = enterChoice();
        }
    }
}

void textFile( FILE* bank )
{
    int result;
    struct client acct = { 0, "", "", 0.00 };
    FILE* bank_accounts;
    if( (bank_accounts = fopen("bank_accounts.txt", "w")) == NULL ) puts("Erro ao abrir o arquivo");
    else {
        rewind( bank ); // sets pointer to beginning of file
        fprintf( bank_accounts, "%-6s%-11s%-10s%5s\n", "Acct", "Firstname", "Lastname", "Balance");
        while( !feof( bank )) {
            result = fread( &acct, sizeof( struct client ), 1, bank );
            if( result != 0 && acct.account != 0 ) {
                fprintf( bank_accounts, "%-6u%-11s%-10s%5.2f\n", acct.account, acct.first_name, acct.last_name, acct.balance);
            }
        }
        puts("Text file generate with success !!");
        fclose(bank_accounts);
    }
}

void deleteAccount( FILE* filePtr )
{
    struct client acct = { 0, "", "", 0.00 };
    struct client blank = { 0, "", "", 0.00 };    
    unsigned int account;

    printf("Enter the account number to delete: ");
    scanf("%d", &account );
    fseek( filePtr, ( account - 1 ) * sizeof( struct client ), SEEK_SET );
    fread( &acct, sizeof( struct client ), 1, filePtr );
    if( acct.account == 0 ) puts("Account doesn't exist !");
    else {
        fseek( filePtr, ( account - 1 ) * sizeof( struct client ), SEEK_SET );
        fwrite( &blank, sizeof( struct client), 1, filePtr );
        puts("Account delete with success !");
    }
}

void updateAccount( FILE* filePtr )
{
    struct client update = { 0, "", "", 0.00 };
    unsigned int account;
    double valor;

    printf("Enter the account number: ");
    scanf("%d", &account );
    fseek( filePtr, ( account - 1 ) * sizeof( struct client ), SEEK_SET );
    fread( &update, sizeof( struct client ), 1, filePtr );
    if( update.account == 0 ) puts("Account doesn't exist !");
    else {
        printf("%-6s%-11s%-10s%5s\n", "Acct", "Firstname", "Lastname", "Balance");
        printf("%-6u%-11s%-10s%5.2f\n", update.account, update.first_name, update.last_name, update.balance);
        printf("Enter the new balance: ");
        scanf("%lf", &update.balance);
        fseek( filePtr, ( account - 1 ) * sizeof( struct client ), SEEK_SET );
        fwrite( &update, sizeof( struct client), 1, filePtr );
    }

}

unsigned int enterChoice( void )
{
    unsigned int choice;
    printf("1 - Create Account\n2 - Update Account\n3 - Delete Account\n4 - Text File\n5 - Encerrar\nEnter: ");
    scanf("%u", &choice);

    return choice;
}

void newAccount( FILE* filePtr )
{
    struct client new = { 0, "", "", 0.00 };

    printf("Enter de account number: ");
    scanf("%d", &new.account);
    printf("Enter de first name: ");
    scanf("%19s", new.first_name);
    printf("Enter de last name: ");
    scanf("%19s", new.last_name);
    printf("Enter de balance: ");
    scanf("%lf", &new.balance);
    fseek( filePtr, ( new.account - 1 ) * sizeof( struct client ), SEEK_SET );
    fwrite( &new, sizeof( struct client ), 1, filePtr );
}
