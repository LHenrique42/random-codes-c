#line 3000
#define NDEBUG // vir antes do assert para desabilitar
#include <stdio.h>
#include <assert.h>
#define PI 3.14
#define CIRCLE_AREA( X ) (PI * X * X)
#if !defined( TRUE )
    #define TRUE 1
#endif
#ifdef TRUE
    #undef TRUE
    #define TRUE 5
#endif

int main( void )
{
    int x = 10;
    assert( x == 11 );
    printf("%.2f\n", CIRCLE_AREA(4));
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FILE__);
    printf("%s\n", __TIME__);
    printf("%d\n", __LINE__);
    printf("%d\n", TRUE);    
} 
