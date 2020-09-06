#include "10FilaInseridaPor2Pilhas.h"

//Implementacao de pilhas

//faz alocação e retorna uma estrutura de informação criada, com o operador passado como argumento
info *criaInfo (int op){
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

//faz alocacao e retorna uma estrutura de stack, campo size recebe 0, campo first recebe NULL
stack *criaStack(){
    stack *novo = (stack*)malloc(sizeof(stack));
    if(novo){
        novo->size=0;
        novo->first=NULL;
        return novo;
    }
    else return NULL;
}

// insere, ou melhor empilha, um no na Pilha
void empilha(stack * h, no *novo){
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

//remove, ou melhor desempilha, um no na pilha. Retorna o operador que foi removido da pilha
no *desempilha(stack *h){
    if(!h || !h->first) return;
    else{
        no *aux=h->first;
        h->first=h->first->prox;
        h->size--;
        aux->prox=NULL;
        return aux;
    }
}

//Implementacao de filas

queue *criaqueue(){
    queue *novo=(queue*)malloc(sizeof(queue));
    if (novo){
        novo->first=NULL;
        novo->last=NULL;
        novo->size=0;
        return novo;
    }
    else return NULL;
}

void enfileirar(queue *q , stack *s){//insere a partir de uma pilha dada e com auxilio de uma nova pilha //Complexidade n=s->size
    if(q && s){
        stack *auxS=criaStack();
        no *auxNO;
        while(s->size>0){
            auxNO=desempilha(s);
            empilha(auxS,auxNO);
        }

        while(auxS->size>0){
            auxNO=desempilha(auxS);
            if(!q->first)
                q->last=auxNO;
            else
                auxNO->prox=q->first;
            q->first=auxNO;
            q->size++;
        }
    }
}

void desenfileirar(queue *q){
    if(!q || !q->first)
        return NULL;
    if(!q->first->prox){
        q->first=NULL;
        q->last=NULL;
    }
    else{
        no *aux;
        for(aux=q->first; aux->prox!=q->last ; aux=aux->prox);
        aux->prox=NULL;
        q->last=aux;
    }
    q->size--;
}


void imprimeStack(stack *s){//imprime pilha
    if(!s || !s->first) return;
    no *aux=s->first;
    while(aux){
        printf("%d ",aux->op->op);
        aux=aux->prox;
    }
}

void imprimeQueue(queue *q){//imprime fila
    if(!q || !q->first) return;
    no *aux=q->first;
    while(aux){
        printf("%d ",aux->op->op);
        aux=aux->prox;
    }
}

