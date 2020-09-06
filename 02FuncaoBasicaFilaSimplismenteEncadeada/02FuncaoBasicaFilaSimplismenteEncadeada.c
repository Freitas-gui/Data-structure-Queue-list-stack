
#include "02FuncaoBasicaFilaSimplismenteEncadeada.h"

info *criaInfo(int i){
    info *novo=(info*)malloc(sizeof(info));
    if (novo){
        novo->i=i;
        return novo;
    }
    else return NULL;
}

no *criaNo(int i){
    no *novo=(no*)malloc(sizeof(no));
    if(novo){
        novo->i=criaInfo(i);
        novo->prox=NULL;
        return novo;
    }
    else return NULL;
}

head *criaHead(){
    head *novo=(head*)malloc(sizeof(head));
    if (novo){
        novo->first=NULL;
        novo->last=NULL;
        novo->size=0;
        return novo;
    }
    else return NULL;
}

void enfileirar(head *h , no *novo){
    if(h){
        if(h->size==0)
            h->first=novo;

        else
            h->last->prox=novo;
        h->last=novo;
        h->size++;

    }
}

int desenfileirar(head *h){
    if(!h || !h->first)
        return NULL;
    int i;
    if(!h->first->prox){
        i=h->first->i->i;
        h->first=NULL;
        h->last=NULL;
    }
    else{
        no *aux;
        for(aux=h->first; aux->prox!=h->last ; aux=aux->prox);
        i=aux->prox->i->i;
        aux->prox=NULL;
        h->last=aux;
    }
    h->size--;
    return i;
}

no *proximo(head *h){
    if(!h || !h->first)
        return NULL;
    return h->first;
}

int comprimento(head *h){
    if(!h || !h->first)
        return NULL;
    return h->size;
}

