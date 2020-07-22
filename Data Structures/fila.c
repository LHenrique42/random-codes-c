#include "fila.h"

int main(void){
    system("clear");
    QUEUEnode* fila = QUEUEinit();
    QUEUEput(fila, 2);
    QUEUEget(fila);
    QUEUEput(fila, 3);
    QUEUEput(fila, 4);
    QUEUEput(fila, 5);
    printf("%d\n", fila -> head -> chave);
    printf("%d\n", fila -> tail -> chave);
    return 0;
}

QUEUEnode* QUEUEinit(){
    QUEUEnode *new = (QUEUEnode *)malloc(sizeof(QUEUEnode));
    return new;
} 

int QUEUEempty(QUEUEnode* fila){
    return ( fila -> head == NULL );
}

void QUEUEput(QUEUEnode* fila, int chave){
    if ( fila -> head == NULL ){
        fila -> head = fila -> tail = (node *)malloc(sizeof(node));
        fila -> head -> chave = fila -> tail -> chave = chave;
        return;
    }
    fila -> tail -> prox = (node *)malloc(sizeof(node));
    fila -> tail -> prox -> chave = chave;
    fila -> tail = fila -> tail -> prox;
}

void QUEUEget(QUEUEnode *fila){
    //node *item = fila -> head;
    node *t = fila -> head -> prox;
    free(fila -> head);
    fila -> head = t;
}