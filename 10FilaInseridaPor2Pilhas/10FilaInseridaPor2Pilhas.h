
#ifndef FILAINSERIDAPOR2PILHAS_H
#define FILAINSERIDAPOR2PILHAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct info{
    int op;
}info;

//estrutura do no da pilha
typedef struct no{
    info *op;
    struct no *prox;
}no;

//estrutura de cabeça da pilha, sabe o tamanho da pilha. aponta para o primeiro no
typedef struct stack{
    no *first;
    int size;
}stack;

typedef struct queue{
    no *first,*last;
    int size;
}queue;



//faz alocação e retorna uma estrutura de informação criada, com o operador passado como argumento
info *criaInfo(int op);

//faz alocacao e retorna uma estrutura de no, com um apontador para estrutura de informação que guarda um operador passado como argumento
//campo prox aponta para NULL
no *criaNo(int op);

//faz alocacao e retorna uma estrutura de stack, campo size recebe 0, campo first recebe NULL
stack *criaStack();

// insere, ou melhor empilha, um no na Pilha
void empilha(stack * h, no *novo);

//remove, ou melhor desempilha, um no na pilha. Retorna o operador que foi removido da pilha
no *desempilha(stack *h);

void imprimeStack(stack *s);//imprime pilha

//Implementacao de filas

queue *criaqueue();

void enfileirar(queue *h , stack *s);

void desenfileirar(queue *h);

void imprimeQueue(queue *q);//imprime fila


#endif
