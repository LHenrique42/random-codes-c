#include "arvore.h"

int main(void){
    ARVB* raiz = NULL;
    insere(&raiz, 10);
    insere(&raiz, 8);
    insere(&raiz, 6);
    insere(&raiz, 6);
    insere(&raiz, 12);
    insere(&raiz, 9);
    remover(&raiz, 10);
    //printf("altura: %d", altura(raiz));
    imprime(raiz);
    return 0;
}