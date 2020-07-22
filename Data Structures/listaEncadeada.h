#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node *prox;
} NODE;

void NODEinsert(NODE**, int);
NODE *listsIntercala(NODE*, NODE*);
void NODECinsert(NODE**, int);