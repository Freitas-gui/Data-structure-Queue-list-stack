

no *criaNo(int c , p){
    no *novo=(no*)malloc(sizeof(no));
    if(novo){
        novo->c=c;
        novo->p=p;
        novo->prox=NULL;
        return novo;
    }
    else return NULL;
}


no *insere(no *lista, no *novo){
    if(lista)
        novo->prox=lista;
    lista=novo;
    return lista;
}

int (head *h){
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
