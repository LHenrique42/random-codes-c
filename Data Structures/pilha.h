#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node *prox;
} node;

typedef struct stack {
    node *head;
} STACK;

STACK* STACKinit();
int STACKempty(STACK*);
void STACKpush(STACK*, int);
void STACKpop(STACK*);