#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DECODIFICACRIPTOGRAFIALISTADUPLA_H
#define DECODIFICACRIPTOGRAFIALISTADUPLA_H

typedef struct info {
    char i;
}info;

typedef struct no{
    struct no *prox,*ant;
    info *i;
}no;

typedef struct List{
    no *first,*last;
    int size;
}List;



info *criaInfo(char i);

no *criaNo(char i);

List *criaList();

void insere(List *lst , no *novo); //adiciona no final

void troca(List *lst , no *a , no *b);//troca de posição entre dois elementos, feita via reapontamento de ponteiros.

void inverte(List *lst , no *a , no *b);//inverte uma lista entre os limites apontados por a e b.

void decodifica(List *lst);//inverte sequencias de nao vogais e depois inverte toda String

void imprime(List *lst);


#endif // DECODIFICACRIPTOGRAFIALISTADUPLA_H
