#include "06ListaFimIniSemCabeca.h"

no *criaNo(int i){
    no *novo=(no*)malloc(sizeof(no));
    if(novo){
        novo->i=i;
        novo->prox =NULL;
        novo->ant=NULL;
        return novo;
    }
    else return NULL;
}

lista *criaLista(){
    lista *novo=(lista*)malloc(sizeof(lista));
    if (novo){
        novo->first=NULL;
        novo->last=NULL;
        return novo;
    }
    else return NULL;
}

void pushIni(lista *h,no *novo){
    if(!h) return;
    if(!h->first){
        h->first=novo;
        h->last=novo;
    }
    else {
        novo->prox=h->first;
        h->first->ant=novo;
        h->first=novo;
    }
}

void pushFim(lista *h,no *novo){
    if(!h)return;
    if(!h->first){
        h->first=novo;
        h->last=novo;
    }
    else{
        novo->ant=h->last;
        h->last->prox=novo;
        h->last=h->last->prox;
    }
}

int popBusca(lista *h , int i){//remove item buscado
    if(!h || !h->first) return NULL;
    int posicao=0;
    no *aux=h->first;
    while(aux){
        if(aux->i==i)
            break;
        aux=aux->prox;
        posicao++;
    }
    if (!aux)return NULL;
    else if(aux==h->first){
        h->first=h->first->prox;
        h->first->ant=NULL;
    }
    else if(aux==h->last){
        h->last=h->last->ant;
        h->last->prox=NULL;
    }
    else{
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    }
    free(aux);
    return posicao;
}

no *Busca(lista *h , int i){//busca chave na lista, retorna no
    if(!h || !h->first) return NULL;
    no *aux=h->first;
    while(aux){
        if(aux->i==i)
            break;
        aux=aux->prox;
    }
    if(!aux)return NULL;
    return aux;
}
void trocaChave(lista *h1,lista *h2,int c1,int c2){//troca chave entre 2 listas      //f)complexidade linear O(n)
    if(!h1 || !h2 || !h1->first ||!h2->first) return;
    no *aux1=Busca(h1,c1), *aux2=Busca(h2,c2);//aponta para chave buscada
    if(aux1 && aux2){//se as duas existirem. troca chave
        aux1->i=c2;
        aux2->i=c1;
    }
}

void imprime(lista *h){
    if(!h || !h->first) return;
    no *aux=h->first;
    while(aux){
        printf("%d ",aux->i);
        aux=aux->prox;
    }
}



