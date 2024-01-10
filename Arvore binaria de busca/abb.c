#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arvore{
    Aluno* info;
    struct arvore* esq;
    struct arvore* dir;
};

Arv* abb_cria(void){
    return NULL;
}

void abb_imprime(Arv* a){
    if(a != NULL){
        abb_imprime(a->esq);
        imprimeAluno(a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca(Arv* r, int chave){
    if(r == NULL)
        return NULL;
    else if(retornaMat(r->info) > chave)
        return abb_busca(r->esq, chave);
    else if(retornaMat(r->info) < chave)
        return abb_busca(r->dir, chave);
    else
        return r;
}

Arv* abb_insere(Arv* a, Aluno* al){
    // se arvore vazia
    if(a == NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->info = al;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if(retornaMat(al) < retornaMat(a->info)){
        a->esq = abb_insere(a->esq, al);
    }
    else if(retornaMat(al) > retornaMat(a->info)){
        a->dir = abb_insere(a->dir, al);
    }
    return a;
}

Arv* abb_retira(Arv* r, int v){
    if(r == NULL)
        return NULL;
    else if(retornaMat(r->info) > v){
        r->esq = abb_retira(r->esq, v);
    }
    else if(retornaMat(r->info) < v){
        r->dir = abb_retira(r->dir, v);
    }
    else{ // achou
        // se nó folha
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        // se só tem filho à direita
        else if(r->esq == NULL){
            Arv* temp = r;
            r = r->dir;
            free(temp);
        }
        // se só tem filho à esquerda
        else if(r->dir == NULL){
            Arv* temp = r;
            r = r->esq;
            free(temp);
        }
        // nó tem dois filhos
        else{
            //acha o antecessor do nó
            Arv* t = r->esq;
            while(t->dir != NULL){
                t = t->dir;
            }
            //troca as informaçoes
            Aluno* at = t->info;
            t->info = r->info;
            r->info = at;

            r->esq = abb_retira(r->esq, v);
        }
    }
    return r;
}

Arv* abb_libera(Arv* a){
    if(a != NULL){
        abb_libera(a->esq);
        abb_libera(a->dir);
        free(a);
    }
    return NULL;
}