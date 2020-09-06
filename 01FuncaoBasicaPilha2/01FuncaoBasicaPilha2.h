
//Exercicio 01
//Crie um TAD em linguagem C de uma estrutura de dados chamada pilha,
//contendo as seguintes funções: empilhar, desempilhar, altura, topo;


#ifndef EXERCICIO01_H
#define EXERCICIO01_H

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
typedef struct head{
    int size;
    no *first;
}head;

//faz alocação e retorna uma estrutura de informação criada, com o operador passado como argumento
info *criaInfo(int op);

//faz alocacao e retorna uma estrutura de no, com um apontador para estrutura de informação que guarda um operador passado como argumento
//campo prox aponta para NULL
no *criaNo(int op);

//faz alocacao e retorna uma estrutura de head, campo size recebe 0, campo first recebe NULL
head *criaHead();

// PUSH insere, ou melhor empilha, um no na Pilha
void push(head * h, no *novo);

//POP remove, ou melhor desempilha, um no na pilha. Retorna o operador que foi removido da pilha
int pop(head *h);

no *topo(head *h);

int altura(head *h);

#endif
