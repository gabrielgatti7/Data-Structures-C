#include <stdio.h>
#include <stdlib.h>
#include "ListaComSentinela.h"

struct celula{
    Aluno* aluno;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Celula* inicializaCelula(Aluno* aluno){
    Celula* cel = malloc(sizeof(Celula));
    cel->aluno = aluno;
    cel->prox = NULL;

    return cel;
}

Lista* inicializaLista(){
    Lista* lista = malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereAluno_finalLista(Lista* lista, Aluno* aluno){
    Celula* nova = inicializaCelula(aluno);

    // Se lista vazia
    if(lista->prim == NULL){
        lista->prim = nova;
        lista->ult = nova;
    }
    else{
        lista->ult->prox = nova;
        lista->ult = nova;
    }
}

Aluno* retiraAluno(Lista* lista, char* nome){
    Celula* p = lista->prim;
    Celula* ant = NULL;
    Aluno* aluno;

    while(p != NULL && strcmp(retornaNome(p->aluno), nome) != 0){
        ant = p;
        p = p->prox;
    }

    // se nao encontrou o aluno
    if(p == NULL){
        return NULL;
    }

    aluno = p->aluno;

    // se eh o unico da lista
    if(p == lista->prim && p == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    // se eh o ultimo da lista
    else if(p == lista->ult){
        ant->prox = NULL;
        lista->ult = ant;
    }
    // se eh o primeiro da lista
    else if(p == lista->prim){
        lista->prim = p->prox;
    }
    // outros casos
    else{
        ant->prox = p->prox;
    }

    free(p);

    return aluno;
}

void imprimeLista(Lista* lista){
    Celula* p = NULL;

    for(p = lista->prim; p != NULL; p = p->prox){
        printf("\n");
        imprimeAluno(p->aluno);
    }
    printf("\n");
}

void destroiLista(Lista* lista){
    Celula* p = lista->prim;
    Celula* t = NULL;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}