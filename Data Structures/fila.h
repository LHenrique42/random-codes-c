#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node *prox;
} node;

typedef struct QUEUEnode {
    node *head;
    node *tail;
} QUEUEnode;

QUEUEnode* QUEUEinit();
int QUEUEempty(QUEUEnode* );
void QUEUEput(QUEUEnode*, int);
void QUEUEget(QUEUEnode* );