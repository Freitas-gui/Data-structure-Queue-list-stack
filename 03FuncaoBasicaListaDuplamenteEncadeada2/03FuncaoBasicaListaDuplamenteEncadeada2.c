
#include "03FuncaoBasicaListaDuplamenteEncadeada2.h"
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
        novo->prox , novo->ant=NULL;
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

void push(head *h , no *novo){ //adiciona no final
    if(h){
        if(h->first){
            novo->ant=h->last;
            h->last->prox=novo;
        }
        else
            h->first=novo;
        h->last=novo;
        h->size++;
    }
}
no *pop(head *h){//remove do final e retorna o no removido
    if(!h || !h->first)
        return NULL;
    no *aux=h->last;
    if(h->size==1)
        h->first,h->last=NULL;
    else{
        h->last=h->last->ant;
        h->last->prox=NULL;
    }
    h->size--;
    aux->ant , aux->prox = NULL;
    return aux;
}

head *intercala(head *h1 , head *h2){
    if((!h1 && !h2) || (!h1->first && !h2->first))
        return NULL;
    head *h3=criaHead();
    if((!h1 && h2 )|| (!h1->first && h2->first)){
        h3=h2;
        free(h1);
        free(h2);
        return h3;
    }
    if((h1 && !h2 )|| (h1->first && !h2->first)){
        h3=h1;
        free(h1);
        free(h2);
        return h3;
    }

    while(h1->size>0 || h2->size>0){
        if(h1->size>0){
            push(h3,pop(h1));
        }
        if(h2->size>0)
            push(h3,pop(h2));
    }
    free(h1);
    free(h2);
    return h3;
}

no *buscaDesordenada(head *h , int i){//retorna a posicao do no que contem o valor buscado
    if(!h || !h->first)
        return NULL;
    no *aux;
    int posicao=0;
    for (aux=h->first;posicao<h->size;posicao++){
        if(aux->i->i==i)
            return aux;
        aux=aux->prox;
    }
    printf("\nLista nao possui valor buscado");
    return NULL;
}

void ordenaCrescente(head *h){
    if(!h || !h->first || h->size==1)
        return;
    no *i,*j;
    int aux;
    for(i=h->first->prox; i ;i=i->prox){

        for(j=h->first; j->prox ;j=j->prox){

            if(j->i->i > j->prox->i->i){
                aux=j->i->i;
                j->i->i = j->prox->i->i;
                j->prox->i->i = aux;
            }
        }
    }
}

void removeDuplicado(head *h){
    if(!h || h->size<2)
        return;
    no *aux=h->first , *auxBusca=h->first->prox ;
    while(aux->prox){
        while(auxBusca){
            if(aux->i->i==auxBusca->i->i){
                no *remove;
                remove=auxBusca;
                auxBusca=auxBusca->prox;
                remove->ant->prox=auxBusca;
                if(auxBusca)
                    auxBusca->ant=remove->ant;
                free(remove);
            }
            else
                auxBusca=auxBusca->prox;
        }
        if(aux->prox){
            aux=aux->prox;
            auxBusca=aux->prox;
        }
    }
}

void ordenaDecrescente(head *h){
    if(!h || !h->first || h->size==1)
        return;
    no *i,*j;
    int aux;
    for(i=h->first->prox; i ;i=i->prox){

        for(j=h->first; j->prox ;j=j->prox){

            if(j->i->i < j->prox->i->i){
                aux=j->i->i;
                j->i->i = j->prox->i->i;
                j->prox->i->i = aux;
            }
        }
    }
}

void imprime(head *h){
    if(!h || !h->first)
        return;
    no *aux=h->first;
    while(aux!=h->last->prox){
        printf("%d ",aux->i->i);
        aux=aux->prox;
    }
}
