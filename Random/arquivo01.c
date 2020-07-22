#include <stdio.h>
#include <stdlib.h>

/* C11 provides exclusive write mode, which you indicate by adding an x to the end
of the w, w+, wb or wb+ modes */

/* 
r - Open an existing file for reading.
w  - Create a file for writing. If the file already exists, discard the current contents.
a  - Append: open or create a file for writing at the end of the file.
r+  - Open an existing file for update (reading and writing).
w+  - Create a file for update. If the file already exists, discard the current contents.
a+  - Append: open or create a file for update; writing is done at the end of the file.
rb  - Open an existing file for reading in binary mode.
wb  - Create a file for writing in binary mode. If the file already exists, discard the
current contents.
ab  - Append: open or create a file for writing at the end of the file in binary mode.
rb+ - Open an existing file for update (reading and writing) in binary mode.
wb+ - Create a file for update in binary mode. If the file already exists, discard the
current contents.
ab+ - Append: open or create a file for update in binary mode; writing is done at the
end of the file. 
*/

int main( void )
{
	unsigned int accountNumber;
	char name[ 80 ];
	double balance;

	FILE *arquivoPtr; // cria arquivo

	// abre arquivo
	if( (arquivoPtr = fopen( "arquivo01.dat", "r" ) ) == NULL )	{
		puts("Erro ao abrir o arquivo !");
	}
/* 	else {
		// ESCRITA ARQUIVO 
		puts("Insira o número da conta, nome e saldo.");
		puts("Insira E0F ( Ctrl ^ d ) para encerrar.");
		printf("%s ", "?");
		// FIXME: ler essa merda direito
		scanf("%d%29s%lf", &accountNumber, name, &balance); // apenas um nome 

		// escreve no arquivo e le mais contas até EOF ser inserido
		while ( !feof( stdin ) ) {
			fprintf( arquivoPtr, "%d %s %.2f\n", accountNumber, name, balance );
			printf("%s ", "?");
			scanf("%d%29s%lf", &accountNumber, name, &balance); // apenas um nome 
		}

		// fecha o arquivo
		fclose(arquivoPtr);
	} */
	
	else {
		// LEITURA ARQUIVO
		// FIXME: escrever essa merda direito
		printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
		fscanf(arquivoPtr, "%d%29s%lf", &accountNumber, name, &balance);	
		
		while( !feof(arquivoPtr) ) {
			printf("%-10d%-13s%.2f\n", accountNumber, name, balance );
			fscanf(arquivoPtr, "%d%29s%lf", &accountNumber, name, &balance);			
		}
	}
}