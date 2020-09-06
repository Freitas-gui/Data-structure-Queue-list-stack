#include<stdio.h>
#include<stdlib.h>

#ifndef LISTWINDOW_H
#define LISTWINDOW_H

typedef struct info {
    int i;
}info;

typedef struct no{
    struct no *prox,*ant;
    info *i;
}no;

typedef struct List{
    no *first,*last;
    no *window;
    int size;
}List;

info *criaInfo(int i);

no *criaNo(int i);

List *criaList();

void insere(List *lst , no *novo); //adiciona no final

void posList(List *lst, int pos);//posiciona a janela (window) da lista no posésimo elemento da lista.

info *infoList(List *lst);//retorna o elemento de informação da janela (window) eliminando-o da lista. O acesso aos elementos da lista SOMENTE pode ser feito através dessa função.

void troca(List *lst , no *a , no *b);

void ordenaCrescente(List *lst);

void imprime(List *lst);
#endif
