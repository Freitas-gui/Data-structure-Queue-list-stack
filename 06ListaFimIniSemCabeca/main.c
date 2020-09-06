#include "06ListaFimIniSemCabeca.h"

int main()
{
    lista *h1=criaLista() , *h2=criaLista();
    no *novo;

    novo=criaNo(1);
    pushFim(h1,novo);

    novo=criaNo(4);
    pushFim(h1,novo);

    novo=criaNo(3);
    pushFim(h1,novo);

    novo=criaNo(5);
    pushFim(h1,novo);

    novo=criaNo(33);
    pushIni(h2,novo);

    novo=criaNo(15);
    pushFim(h2,novo);

    novo=criaNo(11);
    pushFim(h2,novo);

    novo=criaNo(7);
    pushFim(h2,novo);


    imprime(h1);
    printf("\n");
    imprime(h2);
    trocaChave(h1,h2,3,33);
    printf("\n");
    imprime(h1);
    printf("\n");
    imprime(h2);


}
