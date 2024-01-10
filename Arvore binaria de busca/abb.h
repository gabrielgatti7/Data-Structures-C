#ifndef ABB_H
#define ABB_H
#include "aluno.h"

typedef struct arvore Arv;

Arv* abb_cria(void);

void abb_imprime(Arv* a);

Arv* abb_busca(Arv* r, int chave);

Arv* abb_insere(Arv* a, Aluno* al);

Arv* abb_retira(Arv* r, int v);

Arv* abb_libera(Arv* a);

#endif