#include "09DecodificaCriptografiaListaDupla.h"
int main()
{
    List *lst=criaList();
    no *novo,*a,*b;

    novo=criaNo('e');
    insere(lst,novo);

    novo=criaNo('s');
    insere(lst,novo);

    novo=criaNo('t');
    insere(lst,novo);

    novo=criaNo('r');
    insere(lst,novo);

    novo=criaNo('u');
    insere(lst,novo);

    novo=criaNo('t');
    insere(lst,novo);

    novo=criaNo('u');
    insere(lst,novo);

    novo=criaNo('r');
    insere(lst,novo);;

    novo=criaNo('a');
    insere(lst,novo);

    novo=criaNo('s');
    insere(lst,novo);

    novo=criaNo(' ');
    insere(lst,novo);;

    novo=criaNo('d');
    insere(lst,novo);

    novo=criaNo('e');
    insere(lst,novo);

    novo=criaNo(' ');
    insere(lst,novo);

    novo=criaNo('d');
    insere(lst,novo);

    novo=criaNo('a');
    insere(lst,novo);

    novo=criaNo('d');
    insere(lst,novo);

    novo=criaNo('o');
    insere(lst,novo);

    novo=criaNo('s');
    insere(lst,novo);

    novo=criaNo(' ');
    insere(lst,novo);

    novo=criaNo('e');
    insere(lst,novo);;

    novo=criaNo(' ');
    insere(lst,novo);

    novo=criaNo('m');
    insere(lst,novo);

    novo=criaNo('u');
    insere(lst,novo);;

    novo=criaNo('i');
    insere(lst,novo);

    novo=criaNo('t');
    insere(lst,novo);

    novo=criaNo('o');
    insere(lst,novo);

    novo=criaNo(' ');
    insere(lst,novo);

    novo=criaNo('l');
    insere(lst,novo);

    novo=criaNo('e');
    insere(lst,novo);;

    novo=criaNo('g');
    insere(lst,novo);

    novo=criaNo('a');
    insere(lst,novo);

    novo=criaNo('l');
    insere(lst,novo);

    imprime(lst);


    /*inverte(lst,a,b);
    printf("\n");
    imprime(lst); */

    decodifica(lst);
    printf("\n");
    imprime(lst);

    decodifica(lst);
    printf("\n");
    imprime(lst);
}
