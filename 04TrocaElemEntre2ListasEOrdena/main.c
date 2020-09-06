#include "04TrocaElemEntre2ListasEOrdena.h"
int main()
{
    head *h1=criaHead(), *h2=criaHead(), *h3=criaHead();
    leitura2listas(h1,h2);


    printf("\n");

    printf("akii");
    migra2elementos(h1,h2);
    printf("\n");
    imprime(h1);
    printf("\n");
    imprime(h2);
    ordenaDecrescente(h2);
    printf("\n");
    imprime(h2);
    h3=intercala(h1,h2);
    printf("\n");
    imprime(h3);
    return 0;
}
