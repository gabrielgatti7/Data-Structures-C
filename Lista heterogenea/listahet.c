#include <stdio.h>
#include <stdlib.h>
#include "listahet.h"

typedef struct listaHet ListaHet;

ListaHet* inicLista(void);

void insereAluno(ListaHet* l, Aluno* al);

void insereProf(ListaHet* l, Prof* p);

void retiraLista(ListaHet* l);

void imprimeLista(ListaHet* l);

void destroiLista(ListaHet* l);