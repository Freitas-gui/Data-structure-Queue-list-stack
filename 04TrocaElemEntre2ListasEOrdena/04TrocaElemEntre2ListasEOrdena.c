#include "04TrocaElemEntre2ListasEOrdena.H"

void leitura2listas(head *h1 , head *h2){//recebe 2 cabecas de size == 0. le 10 elementos para cada lista; depois imprime as 2 listas
    if(!h1 || !h2) return;
    if(h1->size>0||h2->size>0){
        printf("lista deve ser vazia para leitura de 10 novos elementos");
        return NULL;
    }
    int c,i;
    no *novo;
    for(c=0;c<4;c++){
        printf("Digite o elemento de indice %d) da primeira lista: ",c);
        scanf("%d",&i);
        novo=criaNo(i);
        push(h1,novo);
    }
    for(c=0;c<4;c++){
        printf("Digite o elemento de indice %d) da segunda lista: ",c);
        scanf("%d",&i);
        novo=criaNo(i);
        push(h2,novo);
    }
    printf("primeira lista: ");
    imprime(h1);
    printf("\nsegunda lista: ");
    imprime(h2);
}

no *popBuscado(head *h,int busca){
    if(!h || !h->first)
        return NULL;
    no *aux=buscaDesordenada(h,busca);
    if (!aux)return NULL;
    if(aux->i->i==h->first->i->i){
        h->first=h->first->prox;
        if(h->first)
            h->first->ant=NULL;
        aux->prox=NULL;
        h->size--;
    }
    else if(aux->i->i==h->last->i->i){
        aux=pop(h);
    }
    else{
        aux->prox->ant=aux->ant;
        aux->ant->prox=aux->prox;
        aux->ant=NULL;
        aux->prox=NULL;
        h->size--;
    }
    return aux;
}

void migra2elementos(head *h1 , head *h2){//solicita 2 elementos da primeira lista e faz a migrassao para a segunda lista
    if(!h1 || !h2 || !h1->first) return;//listas nao nulas e nao vazia
    int i;
    no *aux;
    printf("\nDigite o primeiro elemento: ");
    scanf("%d",&i);
    aux=popBuscado(h1,i);
    if(aux)
        push(h2,aux);
    printf("\nDigite o segundo elemento: ");
    scanf("%d",&i);
    aux=popBuscado(h1,i);
    if(aux)
        push(h2,aux);
}

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

