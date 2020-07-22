#include "arvore.h"

ARVB* busca(ARVB* raiz, int x){
    if ( raiz == NULL ) return NULL;
    else if ( raiz -> num == x ) return raiz;
    else if ( raiz -> num < raiz -> num ) return busca(raiz->esq, x);
    else return busca(raiz->dir, x);
}

ARVB* cria(int x){
    ARVB* raiz = (ARVB* )malloc(sizeof(ARVB));
    raiz -> num = x;
    raiz -> esq = NULL;
    raiz -> dir = NULL;
    return raiz;
}

void insere(ARVB** raiz, int x){
    if ( *raiz == NULL ){
        *raiz = cria(x);
        return;
    }
    else if((*raiz)->num > x){
        insere(&((*raiz)->esq), x);
    }
    else{
        insere(&((*raiz)->dir), x);
    }
}

void imprime(ARVB* arv){
    if ( arv == NULL ) return;
    imprime(arv -> esq);
    printf("%d\n", arv -> num);
    imprime(arv -> dir);
}

// void remover(ARVB** raiz, int x){
//     if( raiz == NULL ) return;
//     if((*raiz) -> num == x) {
//         ARVB *no;
//         if((*raiz)->esq == NULL ){
//             no = *raiz;
//             *raiz = (*raiz)->dir;
//             free(no);
//         }else if((*raiz)->dir == NULL){
//             no = *raiz;
//             *raiz = (*raiz)->esq;
//             free(no);           
//         }else{
//             substituiMenorADireita(raiz, &(*raiz)->dir);
//         }
//         return;
//     }
//     if((*raiz)->num < x) return remover(&(*raiz)->dir, x);
//     else return remover(&(*raiz)->esq, x);
// }

// void substituiMenorADireita(ARVB** raiz, ARVB** sucessor){
//     ARVB *no;
//     if((*sucessor)->esq == NULL ){
//         (*raiz)->num = (*sucessor)->num;
//         no = *sucessor;
//         (*sucessor) = (*sucessor)->dir;
//         free(no);
//     }else{
//         substituiMenorADireita(raiz,&(*sucessor)->esq);
//     }
// }

void remover(ARVB** raiz, int x){
    if ( (*raiz) == NULL ) return;
    if ((*raiz)->num == x){
        if((*raiz)->esq == NULL){
            ARVB* no = *raiz;
            (*raiz) = (*raiz)->dir;
            free(no);
            return;
        }else if((*raiz)->dir == NULL){
            ARVB* no1 = *raiz;
            *raiz = (*raiz)->esq;
            free(no1);
            return;
        }else{
            substituiMenorADireita(raiz, &(*raiz)->dir);
        }
        return;
    }
    if( (*raiz)->num < x ) return remover(&(*raiz)->dir, x);
    else return remover(&(*raiz)->esq, x);
}

void substituiMenorADireita(ARVB** raiz, ARVB** sucessor){
    ARVB* no;
    if((*sucessor)->esq == NULL ){
        (*raiz)->num = (*sucessor)->num;
        no = *sucessor;
        (*sucessor) = (*sucessor)->dir;
        free(no);
    }else{
        substituiMenorADireita(raiz,&(*sucessor)->esq);
    }
}

int altura(ARVB* arv){
    if( arv == NULL ) return -1;
    else{
        int he = altura(arv->esq);
        int hd = altura(arv->dir);
        if( he < hd ) return hd + 1;
        else return he + 1;
    }
}