#include "08ListWindow.h"

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
        novo->ant=NULL;
        return novo;
    }
    else return NULL;
}

List *criaList(){
    List *novo=(List*)malloc(sizeof(List));
    if (novo){
        novo->first=NULL;
        novo->last=NULL;
        novo->window=NULL;
        novo->size=0;
        return novo;
    }
    else return NULL;
}

void insere(List *lst , no *novo){ //adiciona no final
    if(lst){
        if(lst->first){
            novo->ant=lst->last;
            lst->last->prox=novo;
        }
        else
            lst->first=novo;
        lst->last=novo;
        lst->size++;
    }
}

void posList(List *lst, int pos){//posiciona a janela (window) da lista no posésimo elemento da lista.
    if(!lst || !lst->first) return;//List vazia
    if(pos<0 || pos>lst->size)return;//posicao positiva e menor que tamanho da List
    int i=0;
    lst->window=lst->first;//window aponta para primeiro elemento
    while(i<pos){
        lst->window=lst->window->prox;
        i++;
    }
}

info *infoList(List *lst){//retorna o elemento de informação da janela (window) eliminando-o da lista. O acesso aos elementos da lista SOMENTE pode ser feito através dessa função.
    if(!lst || !lst->first) return;
    info *aux;//valor a ser retornado
    if(lst->window==lst->first){//caso window aponta para posicao 0
        lst->first=lst->first->prox;
        if(lst->first)//caso a List tiver mais de um elemento
            lst->first->ant=NULL;
        else//caso a List tiver apenas um elemento
            lst->last=NULL;

    }
    else if(lst->window==lst->last){//caso window aponta para posicao final
        lst->last=lst->last->ant;
        lst->last->prox=NULL;
    }
    else{//caso entre dois nos
        lst->window->prox->ant=lst->window->ant;
        lst->window->ant->prox=lst->window->prox;
    }
    aux=lst->window->i;
    lst->window=NULL;
    lst->size--;
    return aux;
}

void troca(List *lst , no *a , no *b){//troca de posição entre dois elementos, feita via reapontamento de ponteiros.
    if( !a || !b) return;
    if(a->ant)
        a->ant->prox=b;
    else
        lst->first=b;
    if(b->prox)
        b->prox->ant=a;
    else
        lst->last=a;
    a->prox=b->prox;
    b->prox=a;
    b->ant=a->ant;
    a->ant=b;
}

void ordenaCrescente(List *lst){
    if(!lst || !lst->first || lst->size==1)
        return;
    no *i,*j;
    int aux;
    for(i=lst->first->prox; i ;i=i->prox){

        for(j=lst->first; j->prox ;j=j->prox){

            if(j->i->i > j->prox->i->i){
                troca(lst,j,j->prox);
            }
        }
    }
}


void imprime(List *lst){
    if(!lst || !lst->first)
        return;
    no *aux=lst->first;
    while(aux!=lst->last->prox){
        printf("%d ",aux->i->i);
        aux=aux->prox;
    }
}
