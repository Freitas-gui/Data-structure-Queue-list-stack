
#ifndef FUNCAOBASICALISTADUPLAMENTEENCADEADA_H
#define FUNCAOBASICALISTADUPLAMENTEENCADEADA_H

#include<stdio.h>
#include<stdlib.h>
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

void push(head *h , no *novo);

no *pop(head *h);

head *intercala(head *h1 , head *h2);

no *buscaDesordenada(head *h , int i);

void ordenaCrescente(head *h);

void removeDuplicado(head *h);

void ordenaDecrescente(head *h);

void imprime(head *h);


#endif
