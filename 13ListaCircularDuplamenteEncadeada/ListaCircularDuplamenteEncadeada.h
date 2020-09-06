#ifndef LISTACIRCULARDUPLAMENTEENCADEADA_H
#define LISTACIRCULARDUPLAMENTEENCADEADA_H


#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int i;
}info;

typedef struct no{
    struct no *prox,*ant;
    info *i;
}no;

typedef struct head{
    no *first,*last;
    int size;
}head;

info *criaInfo(int i);

no *criaNo(int i);

head *criaHead();

void pushIni(head *h , no *novo);

int popIni(head *h);

void pushFim(head *h , no *novo);

int popFim(head *h);

int popBusca(head *h,int i);

void imprime(head *h);

#endif


