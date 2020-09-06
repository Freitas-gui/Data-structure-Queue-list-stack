#include "09DecodificaCriptografiaListaDupla.h"

info *criaInfo(char i){
    info *novo=(info*)malloc(sizeof(info));
    if (novo){
        novo->i=i;
        return novo;
    }
    else return NULL;
}

no *criaNo(char i){
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


void inverte(List *lst , no *a , no *b){//inverte uma lista entre os limites apontados por a e b.
    if(!lst || !lst->first || !lst->first->prox || !a || !b || a==b) return;// Lista deve ter + de 1 elemento
    char str[lst->size];
    no *aux=a;
    int cont;
    for(cont=0 ;aux!=b->prox; cont++,aux=aux->prox)
        str[cont]=aux->i->i;

    for(aux=b,cont=0 ;aux!=a->ant; cont++,aux=aux->ant)
        aux->i->i=str[cont];
}

void decodifica(List *lst){//inverte sequencias de nao vogais e depois inverte toda String
    if(!lst || lst->size<=1)return lst;//nao da pra codificar
    no *a=lst->first,*b=lst->first;
    while(a->prox){
        if(a->i->i== 'a' || a->i->i== 'e' || a->i->i=='i' || a->i->i=='o' || a->i->i=='u'){
            a=a->prox;
            b=a;
        }
        else if(b->prox && (b->prox->i->i != 'a' && b->prox->i->i !='e' && b->prox->i->i !='i' && b->prox->i->i !='o' && b->prox->i->i !='u'))
            b=b->prox;

        else if(a!=b){
            inverte(lst,a,b);
            b=b->prox;
            a=b;
        }
        else{
            a=a->prox;
            b=a;
        }
    }
    inverte(lst,lst->first,lst->last);
}


void imprime(List *lst){
    if(!lst || !lst->first)
        return;
    no *aux=lst->first;
    while(aux!=lst->last->prox){
        printf("%c ",aux->i->i);
        aux=aux->prox;
    }
}

