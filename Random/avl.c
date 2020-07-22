#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
	int elemento;
	struct arv* esq;
	struct arv* dir;
	short int fator_b;
} ARV;

ARV* rotacao_esquerda( ARV* raiz );
ARV* rotacao_direita( ARV* raiz );
ARV* rotacao_dir_esq( ARV* raiz );
ARV* rotacao_esq_dir( ARV* raiz );



int main( void )
{

}


ARV* rotacao_direita( ARV* raiz )
{
	ARV* temp = raiz -> esq;
	raiz -> fator_b = 0;
	temp -> fator_b = 0;
	raiz -> esq = temp -> dir;
	temp -> dir = raiz;
	raiz = temp;
	return raiz;
}

ARV* rotacao_esquerda( ARV* raiz )
{
	ARV* temp = raiz -> dir;
	raiz -> fator_b = 0;
	temp -> fator_b = 0;
	raiz -> dir = temp -> esq;
	temp -> esq = raiz;
	raiz = temp;
	return raiz;
}

ARV* rotacao_esq_dir( ARV* raiz )
{

}

ARV* rotacao_dir_esq( ARV* raiz )
{

}
