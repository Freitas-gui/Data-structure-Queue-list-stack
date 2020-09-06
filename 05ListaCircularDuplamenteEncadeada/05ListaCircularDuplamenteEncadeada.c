#include"05ListaCircularDuplamenteEncadeada.h"
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
        novo->prox =NULL;
        novo->ant=NULL;
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

void pushIni(head *h , no *novo){//insere no inicio
    if(h){
        if(h->first){
            h->first->ant=novo;
            h->last->prox=novo;
            novo->prox=h->first;
            h->first=novo;
            novo->ant=h->last;
        }
        else{
            h->first=novo;
            h->last=novo;
        }
    h->size++;
    }
}

int popIni(head *h){//remove inicio
    if(!h || !h->first)return NULL;
    no *aux=h->first;
    if(h->size==1){
        h->first=NULL;
        h->last=NULL;

    }
    else if(h->size==2){
        h->first=h->first->prox;
        h->first->ant=NULL;
        h->first->prox=NULL;
    }
    else{
        h->last->prox=h->first->prox;
        h->first=h->first->prox;
        h->first->ant=h->last;
    }
    int i;
    i=aux->i->i;
    h->size--;
    return i;
}

void pushFim(head *h , no *novo){//insere no final
    if(h){
        if(h->first){
            novo->ant=h->last;
            novo->prox=h->first;
            h->first->ant=novo;
            h->last->prox=novo;
            h->last=novo;
        }
        else{
            h->first=novo;
            h->last=novo;
        }
        h->size++;
    }
}
int popFim(head *h){//remove Fim
    if(!h || !h->first)return NULL;
    no *aux=h->last;
    if(h->size==1){
        h->first=NULL;
        h->last=NULL;
    }
    else if(h->size==2){
        h->last=h->last->ant;
        h->first->ant=NULL;
        h->first->prox=NULL;
    }
    else{
        h->first->ant=h->last->ant;
        h->last->prox=h->first;
        h->last=h->last->ant;
    }
    h->size--;
    int i;
    i=aux->i->i;
    free(aux);
    return i;

}

int popBusca(head *h,int i){//remove no informado
    if(!h || !h->first)return NULL;
    no *aux=h->first;
    int cont=0;
    while(cont<h->size){
        if(aux->i->i==i)
            break;
        aux=aux->prox;
        cont++;
    }
    if(cont==h->size)
        return NULL;
    if(aux==h->first)
        return popIni(h);
    if(aux==h->last)
        return popFim(h);
    aux->ant->prox=aux->prox;
    aux->prox->ant=aux->ant;
    h->size--;
    free(aux);
    return i;
}

void imprime(head *h){
    if(!h || !h->first)
        return;
    no *aux=h->first;
    int posicao=0;
    while(posicao<h->size){
        printf("%d ",aux->i->i);
        aux=aux->prox;
        posicao++;
    }
}
