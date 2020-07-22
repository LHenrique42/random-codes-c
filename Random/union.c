#include <stdio.h>
#include <stdio.h>

union teste { 
	double x; 
	int y; 
}; 

//typedef teste Teste;

int main( void )
{
	union teste uniao;
	uniao.y = 70;
	uniao.x = 100.35;
	printf("%.2f\n", uniao.x);
	printf("%d\n", uniao.y);
		
}
