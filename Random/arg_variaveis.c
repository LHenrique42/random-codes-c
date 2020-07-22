#include <stdio.h>
#include <stdarg.h>

double media( unsigned int n, ... );

int main( void )
{
    double var1 = 30.00;
    double var2 = 40.00;
    double var3 = 50.00;
    double var4 = 60.00;

    printf("%s%.2f\n", "Media de 30 + 40 = ", media(2, var1, var2));
    printf("%s%.2f\n", "Media de 30 + 40 + 50 = ", media(3, var1, var2, var3));
    printf("%s%.2f\n", "Media de 30 + 40 + 50 + 60 = ", media(4, var1, var2, var3, var4));
}

double media( unsigned int n, ... )
{
    double total = 0.00;
    int counter;

    va_list ap; // stores information needed by va_start and va_end

    va_start( ap, n ); // initializes the va_list object

    for( counter = 0; counter < n; ++counter ) {
        total += va_arg( ap, double );
    }

    va_end( ap );  // clean up variable-length argument list
    return total / n;
}