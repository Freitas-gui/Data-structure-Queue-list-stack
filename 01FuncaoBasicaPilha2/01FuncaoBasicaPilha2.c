#include "01FuncaoBasicaPilha2.h"

//faz alocação e retorna uma estrutura de informação criada, com o operador passado como argumento
info *criaInfo(int op){
    info *novo = (info*)malloc(sizeof(info));
    if (novo){
        novo->op=op;
        return novo;
    }
    else return NULL;
}

//faz alocacao e retorna uma estrutura de no, com um apontador para estrutura de informação que guarda um operador passado como argumento
//campo prox aponta para NULL
no *criaNo(int op){
    no *novo = (no*)malloc(sizeof(no));
    if(novo){
        novo->op=criaInfo(op);
        novo->prox=NULL;
        return novo;
    }
    else return NULL;
}

//faz alocacao e retorna uma estrutura de head, campo size recebe 0, campo first recebe NULL
head *criaHead(){
    head *novo = (head*)malloc(sizeof(head));
    if(novo){
        novo->size=0;
        novo->first=NULL;
        return novo;
    }
    else return NULL;
}

// PUSH insere, ou melhor empilha, um no na Pilha
void push(head * h, no *novo){
    if (h){
        if (h->first==NULL)
            h->first=novo;
        else{
            novo->prox=h->first;
            h->first=novo;
        }
        h->size++;
    }
}

//POP remove, ou melhor desempilha, um no na pilha. Retorna o operador que foi removido da pilha
int pop(head *h){
    if(!h || !h->first) return;
    else{
        int auxOp;
        no *aux=h->first;
        h->first=h->first->prox;
        h->size--;
        auxOp=aux->op->op;
        free(aux);
        return auxOp;
    }
}

no *topo(head *h){
    if (!h || !h->first)
        return;
    else
        return h->first->op->op;
}

int altura(head *h){
    if (!h || !h->first)
        return 0;
    else{
        return h->size;
    }
}
