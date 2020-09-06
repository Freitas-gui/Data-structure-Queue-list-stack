#ifndef LISTAFIMSEMCABECA_H
#define LISTAFIMSEMCABECA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    struct no *prox,*ant;
    int i;
}no;

typedef struct lista{
    no *first , *last;
}lista;


no *criaNo(int i);

lista *criaLista();

void pushIni(lista *h,no *novo);

void pushFim(lista *h,no *novo);

int popBusca(lista *h , int i);//remove item buscado

no *Busca(lista *h , int i);//busca chave na lista, retorna no

void trocaChave(lista *h1,lista *h2,int c1,int c2);//troca chave entre 2 listas      //f)complexidade linear O(n)


void imprime(lista *h);



#endif
