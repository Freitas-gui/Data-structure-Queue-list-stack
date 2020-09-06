#include "07ListaCircularFimIniSemCabeca.h"

int main()
{

    no *novo,*ini=NULL,*fim=NULL;

    novo=criaNo(4);
    pushIni(&ini,&fim,novo);

    novo=criaNo(7);
    pushIni(&ini,&fim,novo);

    novo=criaNo(3);
    pushIni(&ini,&fim,novo);

    novo=criaNo(99);
    pushIni(&ini,&fim,novo);

    novo=criaNo(2);

    pushFim(&ini,&fim, novo);


    //pop
    popIni(&ini,&fim);

    popFim(&ini,&fim);

    popBusca(&ini,&fim,4);

    imprime(ini,fim);

    return 0;
}
