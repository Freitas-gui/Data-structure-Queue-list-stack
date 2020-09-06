#include"02FuncaoBasicaFilaSimplismenteEncadeada.h"
int main()
{

    head *h=criaHead();
    no *novo;

    novo=criaNo(5);
    enfileirar(h,novo);
    printf("Proximo: %d",proximo(h)->i->i);
    printf("\nComprimento: %d\n",h->size);


    novo=criaNo(1);
    int d=desenfileirar(h);
    printf("\nDesenfileirar %d",d);
    enfileirar(h,novo);
    printf("\nProximo: %d",proximo(h)->i->i);
    printf("\nComprimento: %d\n",h->size);


    novo=criaNo(7);
    enfileirar(h,novo);
    printf("\nProximo: %d",proximo(h)->i->i);
    printf("\nComprimento: %d",h->size);



    return 0;
}
