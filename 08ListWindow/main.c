#include "08ListWindow.h"

int main()
{
    List *lst=criaList();
    no *novo,*aux;

    novo=criaNo(3);
    insere(lst,novo);

    novo=criaNo(1);
    insere(lst,novo);

    novo=criaNo(4);
    insere(lst,novo);

    aux=criaNo(5);
    insere(lst,aux);


    imprime(lst);

   // posList(lst,3);

   // infoList(lst);

    printf("\n");
    imprime(lst);

    printf("\n");

    ordenaCrescente(lst);

    imprime(lst);

    return 0;
}
