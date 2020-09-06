#include "07ListaCircularFimIniSemCabeca.h"

no *criaNo(int i){
    no *novo=(no*)malloc(sizeof(no));
    if(novo){
        novo->i=i;
        novo->prox=novo;
        return novo;
    }
    else return NULL;
}


void pushIni(no **ini , no **fim , no *novo){//insere no inicio da lista
    if(!novo) return;
    if(!(*ini)){
        *fim=novo;
        *ini=novo;
    }
    else{
        novo->prox=(*ini);
        (*fim)->prox=novo;
        *ini=novo;
    }
}

void pushFim(no **ini, no **fim, no* novo){//insere no fim da lista
    if(!novo) return;
    if(!(*ini)){
        *ini=novo;
        *fim=novo;
    }
    else{
        novo->prox=(*ini);
        (*fim)->prox=novo;
        (*fim)=novo;
    }
}

void popIni(no **ini , no **fim){
    if(!(*ini)) return;
    if (*ini==(*fim)){
        free(*ini);
        free(*fim);
    }
    else{
        (*fim)->prox=(*ini)->prox;
        *ini=(*ini)->prox;
    }
}

void popFim(no **ini,no **fim){
    if(!(*ini)) return;
    if (*ini==(*fim)){
        free(*ini);
        free(*fim);
    }
    else{
        no *aux=(*ini);
        while(aux->prox!=(*fim))
            aux=aux->prox;
        aux->prox=(*ini);
        *fim=aux;
    }
}

void popBusca(no **ini , no **fim , int chave){//remove no de chave informada
    if(!(*ini)) return;
    if((*ini)->i==chave) popIni((&(*ini)),(&(*fim)));
    else if((*fim)->i==chave) popFim((&(*ini)),(&(*fim)));
    else{
        no *aux=(*ini);
        while(aux->prox != (*fim) && aux->prox->i!=chave)
            aux=aux->prox;
        if(aux->prox!=(*fim)){
            aux->prox=aux->prox->prox;
        }
    }
}
void imprime(no *ini , no *fim){
    if(!ini) return;
    no *aux=ini;
    while(aux!=fim){
        printf("%d ",aux->i);
        aux=aux->prox;
    }
    printf("%d ",aux->i);
}
