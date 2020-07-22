/*	
	km_por_litro.c
	Calcula km/litro
	04/09/17
*/

#include <stdio.h>
#include <stdlib.h>

// funcao main
int main()
{
	// Declaracao variaveis
	float litros_gasolina = 0.01,
		  km_percorridos = 0.01;
	while( litros_gasolina >= 0.00 && km_percorridos >= 0.00 ){
		printf("Informe quantidade de litros de gasolina utilizado (-1 para encerrar): ");
		scanf("%f", &litros_gasolina);
		if ( litros_gasolina < 0 ) break;
		else if( litros_gasolina == 0 ){
			puts("Numero deve ser maior ou igual a zero !!");
			continue;
		}
		printf("Informe quantidade de kilometros percorridos: ");
		scanf("%f", &km_percorridos);
		if ( km_percorridos < 0 ) break;
		else if( km_percorridos == 0 ){
			puts("Numero deve ser maior ou igual a zero !!");
			continue;
		}
		printf("Km/litro = %.2f\n\n", km_percorridos/litros_gasolina);
	}
	return 0;

} // fim da funcao main