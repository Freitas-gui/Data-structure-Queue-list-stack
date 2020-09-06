#include "03FuncaoBasicaListaDuplamenteEncadeada2.h"
int main()
{
    head *h=criaHead(),*h2=criaHead(),*h3;
    no *novo;

    novo=criaNo(2);
    push(h,novo);
    printf("%d",h->last->i->i);

    novo=criaNo(5);
    push(h,novo);
    printf("\n%d",h->last->i->i);

    novo=criaNo(2);
    push(h,novo);
    printf("\n%d",h->last->i->i);

    //h2
    novo=criaNo(3);
    push(h2,novo);
    printf("\n%d",h2->last->i->i);

    novo=criaNo(5);
    push(h2,novo);
    printf("\n%d",h2->last->i->i);

    novo=criaNo(3);
    push(h2,novo);
    printf("\n%d\n",h2->last->i->i);

    h3=intercala(h,h2);
    imprime(h3);
    ordenaCrescente(h3);
    printf("\n");
    imprime(h3);
    ordenaDecrescente(h3);
    printf("\n");
    imprime(h3);

    removeDuplicado(h3);
    printf("\n");
    imprime(h3);
    //printf("\n%d",buscaDesordenada(h3,3));

    return 0;
}
