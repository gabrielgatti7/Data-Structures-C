#ifndef Pilha_h
#define Pilha_h

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct pilha Pilha;

Pilha* inicializaPilha();
void push(Pilha* pilha, Aluno* aluno);
Aluno* pop(Pilha* pilha);
int EstaVazia(Pilha* pilha);
void imprimePilha(Pilha* pilha);
void destroiPilha(Pilha* pilha);

#endif /*PIlha_h*/