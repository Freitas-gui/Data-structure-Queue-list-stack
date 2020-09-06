#ifndef LISTACIRCULARFIMINISEMCABECA_H
#define LISTACIRCULARFIMINISEMCABECA_H
#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    struct no *prox;
    int i;
}no;

no *criaNo(int i);

void pushIni(no **ini , no **fim , no *novo);//insere no inicio da lista

void pushFim(no **ini,no **fim,no* novo);//insere no fim da lista

void popIni(no **ini,no **fim);

void popFim(no **ini,no **fim);

void popBusca(no **ini , no **fim , int chave);//remove no de chave informada

void imprime(no *ini , no *fim);

#endif
