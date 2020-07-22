#include "novoTrab.h"

NODE *inicializaNode(int numBolas){
	/*
		Inicializa a estrutura apontando para a primeira caixa.
		Requer o numero de bolas como parametro da primeira caixa.
	*/
	NODE *newBox = (NODE *)malloc(sizeof(NODE));
	newBox -> inicio = preencheCaixa(numBolas); // Chama a funcao para preencher as bolas
	return newBox; // retorna caixa
}


/*
	Programa principal, nele é feito a leitura do número de caixas, número de bolas de cada caixa e
	nome das bolas.
	Requer como parametro um NODE que é como um nó cabeça, porém que aponto apenas 
	para o inicio ( primeira caixa ), a estrutura passada, não deve estar alocada, deve apontar para NULL
*/
void programa(NODE *node){
	NODE *boxes = node; // recebe a variavel
	int numCaixas = -1 , numBolas; // variaveis para auxiliar na leitura
	int i = 0; // variavel para percorrer caixas
	system("clear"); // leitura da tela
	do {
		printf("Informe numero de caixas: ");
		__fpurge(stdin);
		if ( scanf("%d", &numCaixas) != 1 ){		
			printf("Insira valor maior ou igual a zero no numero de caixas.\n");
			numCaixas = -1;
		}
		else if ( numCaixas == 0 ){
			printf("Nenhuma caixa inserida ! Programa Encerrado !\n");
		}
		else if ( numCaixas < 0 ){
			printf("Insira valor maior ou igual a zero no numero de caixas.\n");
		}
	}while ( numCaixas < 0);

	if ( numCaixas > 0 ){
		/*
		 	Caso o número de caixas seja maior que zero, o programa passará a ler o número de bolas que
		 	cada caixa irá possuir e o nome de cada bola, respectivamente.
		*/
		while ( i < numCaixas ){
			/*
				loop para preecher todas as caixas
			*/
			printf("\nInsira número de bolas que a caixa %d irá possuir: ", i + 1);
			__fpurge(stdin);
			if (scanf("%d", &numBolas) != 1){	
				printf("Apenas numeros sao aceitos no numero de bolas da caixa !");
			}
			else if ( numBolas <= 0 ){
				printf("Numero de bolas da caixa deve ser maior que zero !");	
			} 
			else{
				system("clear");
				printf("\nEm relação a caixa %d:\n", i + 1 );
				/*
					Se for a primeira caixa, chama a funcao inicializaNode, caso contrário, 
					insere a nova caixa na lista existente de forma ordenada.
				*/
				if ( i == 0 ) boxes = inicializaNode(numBolas);
				else novaCaixa(boxes, numBolas);
				i++;
			}
		}
		system("clear");
		printf("Combinacoes possíveis: \n");
		/*
			Chamada da funcao para imprimir todas as possibilidades
		*/
		geraCombinacoes(boxes, boxes -> inicio);
	}
}

CAIXAS *preencheCaixa(int numBolas){
	/*
		Preenche caixa : le nome das bolas e coloca na caixa
	*/
	CAIXAS *newBox = (CAIXAS *)malloc(sizeof(CAIXAS));
	newBox -> numBolas = numBolas;
	newBox -> vectorBolas = (char *)malloc((numBolas+1)*sizeof(int));
	/*
		Implementacao da leitura das bolas
	*/
	for ( int i = 0; i < numBolas; i++){
		while ( isalpha(newBox->vectorBolas[i]) == 0 ){
			/*
				Enquanto não for igual a letra executa o loop
			*/
			printf("\nInforme letra da bola %d: ", i + 1);
			__fpurge(stdin);
			scanf("%c", &newBox->vectorBolas[i]);
			if ( isalpha(newBox->vectorBolas[i]) == 0 ){
				printf("\nERRO! Nome das bolas devem ser apenas letras maiusculas ou minusculas!\n");
			}
		}
	}
	system("clear"); 
	return newBox;
}

void novaCaixa(NODE *boxes, int numBolas){
	/*
		Coloca uma nova caixa no NODE ( no cabeca )
	*/
	CAIXAS *newBox = preencheCaixa(numBolas);
	/*
		Insere a nova caixa de forma ordenada
	*/
	CAIXAS *percorre = boxes -> inicio;
	CAIXAS *anterior = NULL;
	while ( percorre != NULL && percorre -> numBolas < numBolas ){
		anterior = percorre;
		percorre = percorre -> proximaCaixa;
	}
	/*
		Caso a caixa possua o menor numero de bolas da lista, é inserida no inicio.
		Caso contrário, é inserida na posição anterior a caixa com maior número de bolas que ela,
		ou na última posição.
	*/
	if ( anterior == NULL ){
		newBox -> proximaCaixa = boxes -> inicio;
		boxes -> inicio = newBox;	
	}
	else { 
		newBox -> proximaCaixa = anterior -> proximaCaixa;
		anterior -> proximaCaixa = newBox;
	}
}

void imprime(NODE *boxes){
	/*
		Imprime todas as bolas
	*/
	CAIXAS *percorre = boxes -> inicio;
	int i, j = 0;
	while ( percorre != NULL ){
		/*
			loop para percorrer todas as caixas
		*/
		printf("Cor %d : ", j + 1);
		for ( i = 0; i < percorre -> numBolas; i++ ){
			printf("%c ",percorre -> vectorBolas[i]);
		}
		printf("\t");
		percorre = percorre -> proximaCaixa;
		j++;
	}
	printf("\n");
}

int fatorial(int n){
	/*
		Calcula fatorial de forma recursiva
	*/
	if( n == 0 || n == 1) return 1;
	return (n * fatorial(n-1));
}


/*
	Funcao que gera todas as combinacoes possiveis.
	Implementação baseada no algoritmo de Trotter-Johnson
*/
void geraCombinacoes(NODE *boxes, CAIXAS *box){
	/*
		Verifica se a caixa é igual a NULL, se for imprime todas.
		OBS: Nunca a funcao será chamada com uma lista vazia, 
		então sempre haveŕa bolas a ser imprimidas na tela.
	*/

	if ( box == NULL ){
		imprime(boxes);
		return;	
	}
	int fat = fatorial(box -> numBolas); // calcula fatorial para poder gerar as N! possibilidades
	int esqDir = -1, dirEsq; // variaveis para saber se a troca esta sendo da direita pra esquerda ou o contrário
	dirEsq = box -> numBolas - 1; // começa trocando da esquerda pra direira
	char auxiliar, auxiliar2; // variaveis para auxliar na troca dos elementos
	for ( int i = 0; i < fat; i++){
		/*
			loop para gerar todas as combinacoes possiveis. 
			Ver funcionamento do algoritmo no slide.
		*/

		geraCombinacoes(boxes, box -> proximaCaixa); /* Recursao para percorrer as caixas permutando*/


		if ( dirEsq > 0 ){
			/*
				Caso a troca seja feita da esquerda pra direita 
			*/
			memcpy(&auxiliar, &box->vectorBolas[dirEsq], 1);
			memcpy(&auxiliar2, &box->vectorBolas[dirEsq - 1], 1);
			memcpy(&box->vectorBolas[dirEsq], &auxiliar2, 1);
			memcpy(&box->vectorBolas[dirEsq - 1], &auxiliar, 1);
			dirEsq--;
		}
		else if ( dirEsq == 0 ){
			/*
				Caso a troca da esquerda pra diretira tenha terminado, permuta os dois ultimos elementos.
			*/
			memcpy(&auxiliar, &box->vectorBolas[box -> numBolas - 1], 1);
			memcpy(&auxiliar2, &box->vectorBolas[box -> numBolas - 2], 1);
			memcpy(&box->vectorBolas[box -> numBolas - 1], & auxiliar2, 1);
			memcpy(&box->vectorBolas[box -> numBolas - 2], & auxiliar, 1);
			esqDir = 1;
			dirEsq = - 1;
		}
		
		else if ( esqDir > 0 && esqDir < box -> numBolas){
			/*
				caso a troca esteja sendo feita da direita pra esquerda
			*/
			memcpy(&auxiliar, &box->vectorBolas[esqDir - 1], 1);
			memcpy(&auxiliar2, &box->vectorBolas[esqDir], 1);
			memcpy(&box->vectorBolas[esqDir - 1], &auxiliar2, 1);
			memcpy(&box->vectorBolas[esqDir], &auxiliar, 1);
			esqDir++;			
		}
		else if( esqDir == box -> numBolas ){

			/*
				Caso a troca da direita pra esquerda tenha terminado, permuta os dois inicias.
			*/
			memcpy(&auxiliar, &box->vectorBolas[0], 1);
			memcpy(&auxiliar2, &box->vectorBolas[1], 1);
			memcpy(&box->vectorBolas[0], &auxiliar2, 1);
			memcpy(&box->vectorBolas[1], &auxiliar, 1);
			dirEsq = box -> numBolas - 1;
			esqDir = - 1;			
		}
	}
}