#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game status
enum Status { WON, LOST, CONTINUE };

unsigned short rollDice( void ); // rola 2 dados e faz-se a soma

// main - inicia o programa
int main( void )
{
    unsigned short sum; // soma dos dados
    unsigned short myPoint; 

    enum Status gameStatus;

    // randomiza random 
    srand( time( NULL ) );

    sum = rollDice();

    // determina status baseado na soma
    switch( sum ) {

        // win
        case 7:
        case 11:
            gameStatus = WON;
            break;

        // lose
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        
        // continua
        default:    
            gameStatus = CONTINUE;
            myPoint = sum;
            printf( "Ponto é %d\n", myPoint );
            break;
    }

    while ( CONTINUE == gameStatus ) {
        sum = rollDice();

        if ( sum == myPoint ) {
            gameStatus = WON;
        }
        else {
            if ( 7 == sum ) {
                gameStatus = LOST;
            }
        }
    }

    if ( WON == gameStatus ) {
        puts( "Player WINS!!\n" );
    }
    else {
        puts( "Player loses !!\n" );
    }
}

unsigned short rollDice( void )
{
    unsigned short die1;
    unsigned short die2;
    unsigned short workSum;

    die1 = 1 + ( rand() % 6 );
    die2 = 1 + ( rand() % 6 );
    workSum = die1 + die2;

    printf( "Player rolled %hu and %hu\n", die1, die2 );
    return workSum;
}