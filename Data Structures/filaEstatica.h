#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node prox;
} node;

typedef struct lista {
    node head;
    node tail;
} LISTCIRC;