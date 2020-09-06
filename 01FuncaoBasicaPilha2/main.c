#include "01FuncaoBasicaPilha2.h"
int main()
{
    int op;
    head *h=criaHead();
    no *novo;

    op=3;
    novo=criaNo(op);
    push(h,novo);
    printf("Topo: %d ",topo(h));
    printf("\nAltura: %d ",altura(h));

    op=1;
    novo=criaNo(op);
    push(h,novo);
    pop(h);
    printf("\nTopo: %d ",topo(h));
    printf("\nAltura: %d ",altura(h));

    op=4;
    novo=criaNo(op);
    push(h,novo);
    printf("\nTopo: %d ",topo(h));
    printf("\nAltura: %d ",altura(h));



    return 0;
}
