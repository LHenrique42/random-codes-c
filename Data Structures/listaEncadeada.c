#include "listaEncadeada.h"

int main(void){
    system("clear");
    NODE *listaA = NULL;
    NODE *listaB = NULL;
    NODEinsert(&listaA, 6);  
    NODEinsert(&listaA, 5);  
    NODEinsert(&listaA, 1);  
    NODEinsert(&listaB, 4);  
    NODEinsert(&listaB, 2);  
    NODEinsert(&listaB, 3);
    NODE *listaC =   listsIntercala(listaA, listaB);
    printf("%d\n", listaC -> chave);
    printf("%d\n", listaC -> prox -> chave);
    printf("%d\n", listaC -> prox -> prox -> chave);
    printf("%d\n", listaC -> prox -> prox -> prox -> chave);
    printf("%d\n", listaC -> prox -> prox -> prox -> prox -> chave);
    printf("%d\n", listaC -> prox -> prox -> prox -> prox -> prox -> chave);
    return 0;
}

void NODEinsert(NODE** list, int chave){
    if ( *list == NULL ){
        *list = (NODE *)malloc(sizeof(NODE));
        (*list) -> chave = chave;
        return;
    }
    NODE *percorre = *list;
    NODE *anterior = NULL;
    while ( percorre != NULL && percorre -> chave < chave){
        anterior = percorre;
        percorre = percorre -> prox;
    }
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    novo -> chave = chave;
    if ( anterior == NULL ){
        novo -> prox = percorre;
        *list = novo;
    }else {
        novo -> prox = percorre;
        anterior -> prox = novo;
    }
}

NODE *listsIntercala(NODE* lista1, NODE* lista2){
    NODE *listaC = NULL;
    NODE *listaA = lista1, *listaB = lista2;
    while ( listaA != NULL && listaB != NULL ){
        if (listaA != NULL) NODECinsert(&listaC, listaA -> chave);
        if (listaB != NULL) NODECinsert(&listaC, listaB -> chave);
        if (listaA != NULL) listaA = listaA->prox;
        if (listaB != NULL) listaB = listaB->prox;
    }
    return listaC;
}

void NODECinsert(NODE** list, int chave){
    if ( *list == NULL ){
        *list = (NODE *)malloc(sizeof(NODE));
        (*list) -> chave = chave;
        return;
    }
    NODE *percorre = *list;
    NODE *anterior = NULL;
    while ( percorre != NULL && percorre -> chave > chave){
        anterior = percorre;
        percorre = percorre -> prox;
    }
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    novo -> chave = chave;
    if ( anterior == NULL ){
        novo -> prox = percorre;
        *list = novo;
    }else {
        novo -> prox = percorre;
        anterior -> prox = novo;
    }
}