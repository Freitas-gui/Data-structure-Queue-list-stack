#include "ListaCircularDuplamenteEncadeada.h"
int main()

{
    head *h1=criaHead();
    no *novo;

    novo=criaNo(4);
    pushIni(h1,novo);

    novo=criaNo(1);
    pushIni(h1,novo);

    novo=criaNo(3);
    pushIni(h1,novo);

    novo=criaNo(9);
    pushIni(h1,novo);

    popIni(h1);

    novo=criaNo(1);
    pushFim(h1,novo);

    novo=criaNo(99);
    pushFim(h1,novo);

    novo=criaNo(5);
    pushFim(h1,novo);

    novo=criaNo(9);
    pushFim(h1,novo);

    popFim(h1);

    popBusca(h1,99);

    imprime(h1);

    return 0;
}
