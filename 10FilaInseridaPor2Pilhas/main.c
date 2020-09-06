#include "10FilaInseridaPor2Pilhas.h"

int main()
{
    stack *s=criaStack();
    queue *q=criaqueue();
    no *novo;

    novo=criaNo(3);
    empilha(s,novo);

    novo=criaNo(99);
    empilha(s,novo);


    novo=criaNo(1);
    empilha(s,novo);


    novo=criaNo(4);
    empilha(s,novo);

    imprimeStack(s);

    enfileirar(q,s);
    printf("\n");
    imprimeQueue(q);
    printf("\n");
    desenfileirar(q);
    imprimeQueue(q);
    return 0;
}
