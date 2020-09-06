#include<stdio.h>
#include<stdlib.h>

#ifndef TROCAELEMENTRE2LISTASEORDENA_H
#define TROCAELEMENTRE2LISTASEORDENA_H

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

void ordenaDecrescente(head *h);

void imprime(head *h);

void leitura2listas(head *h1 , head *h2);

no *popBuscado(head *h,int busca);

void migra2elementos(head *h1 , head *h2);
#endif

