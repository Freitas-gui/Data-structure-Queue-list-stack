#ifndef EXERCICIO02_H
#define EXERCICIO02_H

#include <stdio.h>
#include <stdlib.h>
//Crie um TAD em linguagem C de uma estrutura de dados chamada fila,
//contendo as seguintes funções: enfileirar, desenfileirar, comprimento, próximo;


typedef struct info {
    int i;
}info;

typedef struct no{
    struct no *prox;
    info *i;
}no;

typedef struct head{
    no *first,*last;
    int size;
}head;

info *criaInfo(int i);

no *criaNo(int i);

head *criaHead();

void enfileirar(head *h , no *novo);

int desenfileirar(head *h);

no *proximo(head *h);
int comprimento(head *h);

#endif // EXERCICIO02_H



