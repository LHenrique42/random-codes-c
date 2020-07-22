#include "pilha.h"

int main(void){
    system("clear");
    return 0;
}

STACK* STACKinit(){
    STACK *new = (STACK *)malloc(sizeof(STACK));
    return new;
}

int STACKempty(STACK* pilha){
    return (pilha -> head == NULL );
}

void STACKpush(STACK* pilha, int chave){
    if ( pilha -> head == NULL ){
        pilha -> head = (node *)malloc(sizeof(node));
        pilha -> head -> chave = chave;
        return;
    }
    node *head = (node *)malloc(sizeof(node));
    head -> chave = chave;
    head -> prox = pilha -> head;
    pilha -> head = head;
}

void STACKpop(STACK* pilha){
    node *t = pilha -> head -> prox;
    free(pilha -> head);
    pilha -> head = t;
}